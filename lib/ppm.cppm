export module lib.ppm;

import std;

export namespace ppm {
    struct ppm {
        std::string image;
        std::string_view path;
        std::size_t width;
        std::size_t height;
        std::size_t max_color_value;
        bool rendered;

        struct pixel {
            std::uint16_t r;
            std::uint16_t g;
            std::uint16_t b;
        };

        ppm(const std::size_t width, const std::size_t height, const std::string_view file_name, const std::size_t max_color_value = 255)
            : image{std::format("P3\n{} {}\n{}\n", width, height, max_color_value)}
            , path{file_name}
            , width{width}
            , height{height}
            , max_color_value{max_color_value}
            , rendered{false}
        {}

        auto render_image(std::function_ref<pixel(const std::size_t, const std::size_t)> render_fn) {
            if (this->rendered) {
                return;
            }

            for (std::size_t y = 0; y < this->height; ++y) {
                for (std::size_t x = 0; x < this->width; ++x) {
                    const pixel p = render_fn(x, y);

                    this->image += std::format("{} {} {}", static_cast<std::uint8_t>(p.r * 255), static_cast<std::uint8_t>(p.g * 255), static_cast<std::uint8_t>(p.b * 255));

                    if (x != this->width - 1) {
                        this->image += ' ';
                    }
                }

                this->image += '\n';
            }

            this->rendered = true;
        }

        auto save_file() {
            if (!this->rendered) {
                std::println(std::cerr, "Image is not rendered so image is not saved at {}", this->path);
                return;
            }

            std::ofstream ofs{this->path.data()};

            if (ofs.is_open()) {
                ofs << this->image;

                ofs.close();
            } else {
                std::println(std::cerr, "Cannot write ppm file to {}", this->path);
            }
        }
    };
}