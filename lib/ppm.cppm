export module lib.ppm;

import std;

import lib.math;

export namespace ppm {
    struct ppm {
        std::string image;
        const std::size_t width;
        const std::size_t height;
        const std::uint16_t max_color_value;
        bool rendered;

        struct pixel {
            std::uint16_t r;
            std::uint16_t g;
            std::uint16_t b;

            static auto from_vec3(const math::vec3 vec) -> pixel {
                return pixel{ static_cast<std::uint16_t>(vec.x), static_cast<std::uint16_t>(vec.y), static_cast<std::uint16_t>(vec.z) };
            }
        };

        ppm(const std::size_t width, const std::size_t height, const std::uint16_t max_color_value = 255)
            : image{std::format("P6\n{} {}\n{}\n", width, height, max_color_value)}
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

                    for (const auto value : {p.r, p.g, p.b}) {
                        if (this->max_color_value > 255) {
                            this->image.push_back(static_cast<char>(value >> 8));
                        }

                        this->image.push_back(static_cast<char>(value & 0xff));
                    }
                }
            }

            this->rendered = true;
        }

        auto save_file(const std::string_view path) {
            if (!this->rendered) {
                std::println(std::cerr, "Image is not rendered so image is not saved at {}", path);
                return;
            }

            std::ofstream ofs{path.data()};

            if (ofs.is_open()) {
                ofs << this->image;

                ofs.close();
            } else {
                std::println(std::cerr, "Cannot write ppm file to {}", path);
            }
        }
    };
}