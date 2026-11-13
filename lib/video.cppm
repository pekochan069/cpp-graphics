module;
#include <stdio.h>

export module lib.video;

import std;

import lib.ppm;

#ifdef _WIN32
    #define POPEN _popen
    #define PCLOSE _pclose
    #define POPEN_MODE "wb" // Windows는 반드시 바이너리 모드("wb") 지정 필요!
#else
    #define POPEN popen
    #define PCLOSE pclose
    #define POPEN_MODE "w"
#endif

export namespace video {
	struct video {
		std::vector<ppm::ppm> frames{};
		const std::size_t fps;
		const std::size_t max_frames;
        const std::size_t width;
        const std::size_t height;
        const std::uint16_t max_color_value;
		bool rendered;

		video(const std::size_t fps, const std::size_t max_frames, const std::size_t width, const std::size_t height, const std::uint16_t max_color_value = 255)
			: fps{fps}
			, max_frames{max_frames}
			, width{width}
			, height{height}
			, max_color_value{max_color_value}
			, rendered{false}
		{}

		/**
		* accept `auto render_fn(const std::size_t frame, const std::size_t x, const std::size_t y) -> ppm::ppm::pixel`;
		*/
		auto render_video(std::function_ref<ppm::ppm::pixel(const std::size_t, const std::size_t, const std::size_t)> render_fn) -> void {
			if (this->rendered) {
				return;
			}

			for (std::size_t current_frame = 0; current_frame < this->max_frames; ++current_frame) {
				ppm::ppm frame(this->width, this->height, this->max_color_value);

				frame.render_image([&](const std::size_t x, const std::size_t y){
					return render_fn(current_frame, x, y);
				});

				this->frames.push_back(std::move(frame));
			}

			this->rendered = true;
		}

		auto save_file(const std::string_view path) -> void {
			const std::string ffmpeg_command = std::format("ffmpeg -y -f image2pipe -vcodec ppm -r {} -i - -c:v libx264 -pix_fmt yuv420p {}", this->fps, path).c_str();

			std::FILE* ffmpeg_pipe = POPEN(ffmpeg_command.c_str(), POPEN_MODE);

			for (std::size_t frame = 0; frame < this->max_frames; ++frame) {
				fwrite(this->frames[frame].image.data(), 1, this->frames[frame].image.size(), ffmpeg_pipe);
			}

			int ret = PCLOSE(ffmpeg_pipe);

			if (ret == 0) {
				std::println("Video rendered at {}", path);
			} else {
				std::println(std::cerr, "Failed to render video at {}", path);
			}
		}
	};
}
