import std;

import lib.math;
import lib.ppm;
import lib.video;

auto palette(float t, math::vec3 a, math::vec3 b, math::vec3 c, math::vec3 d) -> math::vec3 {
    return a + b * (6.28318f * (c * t + d)).cos();
}

int main(int argc, char **argv) {
    const std::size_t fps = 60;
    const std::size_t max_frames = 600;
    static constexpr std::size_t width = 16 * 60;
    static constexpr std::size_t height = 16 * 60;
    static constexpr float ratio = static_cast<float>(width) / static_cast<float>(height);

    video::video shader_video(fps, max_frames, width, height);

    shader_video.render_video([](const std::size_t _frame, const std::size_t _x, const std::size_t _y){
        const float frame = static_cast<float>(_frame);
        const float time = frame / fps;
        const float x = static_cast<float>(_x);
        const float y = static_cast<float>(_y);
        const float normalized_frame = static_cast<float>(frame / max_frames);

        math::vec2 frag_chord{ x, y };

        math::vec2 uv = (frag_chord.normalize_xy(width, height) * 2.0f - 1.0f).mul_x(ratio);
        math::vec2 uv0 = uv;

        math::vec3 final_color{ 0.0f, 0.0f, 0.0f };

        for (float i = 0.0f; i < 4.0f; ++i) {
            uv = (uv * 1.5f).fract() - 0.5f;

            float d = uv.length() * std::exp(-uv0.length());
            math::vec3 color = palette(uv0.length() + i * 0.4f + time * 0.4f, math::vec3{ 0.5f, 0.5f, 0.5f }, math::vec3{ 0.5f, 0.5f, 0.5f }, math::vec3{ 1.0f, 1.0f, 1.0f }, math::vec3{ 0.263f, 0.416f, 0.557f });
            d = std::sin(d * 8.0f + frame / 60.0f) / 8.0f;
            d = std::abs(d);
            d = std::pow(0.01f / d,1.2f);

            final_color += color * d;
        }

        math::vec3 frag_color = final_color.floor_ceil(0.0f, 1.0f).denormalize(255.0f);

        return ppm::ppm::pixel::from_vec3(frag_color);
    }, 12);



    const char* out_dir = "shader4-out";
    std::filesystem::create_directory(out_dir);

    shader_video.save_file(std::format("{}/output.mp4", out_dir));

    return 0;
}
