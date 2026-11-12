import std;

import lib.math;

int main(int argc, char **argv) {
    static constexpr std::size_t image_width = 16 * 60;
    static constexpr std::size_t image_height = 16 * 60;

    static constexpr std::size_t max_color_val = 255;

    std::filesystem::create_directory("shader2-out");

    for (std::size_t t = 0; t < 60; ++t) {
        std::string ppm = std::format("P3\n{} {}\n{}\n", image_width, image_height, max_color_val);

        const math::vec2 r = math::vec2{ static_cast<float>(image_width), static_cast<float>(image_height) };

        for (std::size_t y = 0; y < image_height; ++y) {
            for (std::size_t x = 0; x < image_width; ++x) {
                const float float_x = static_cast<float>(x);
                const float float_y = static_cast<float>(y);
                const float float_t = static_cast<float>(t);

                math::vec4 o{};
                math::vec2 FC{ float_x, float_y };
                math::vec2 p = (FC * 2.0f - r) / r.y;
                math::vec2 l{};
                math::vec2 i{};
                math::vec2 v = p * (l = l + 4.0f-4.0f * std::abs(0.7f-p.dot(p)));

                for (; i.y++ < 8.0f; o = o + (v.xyyx().sin() + 1.0f) * std::abs(v.x-v.y)) {
                    v = v + (v.yx() * i.y + i + float_t / 60).cos() / i.y + 0.7f;
                }

                o = (5.0f * (l.x-4.0f - p.y * math::vec4{-1.0f,1.0f,2.0f,0.0f}).exp() / o).tanh();

                ppm += std::format("{} {} {}", static_cast<std::uint8_t>(o.x * 255), static_cast<std::uint8_t>(o.y * 255), static_cast<std::uint8_t>(o.z * 255));

                if (x != image_width - 1) {
                    ppm += ' ';
                }
            }
            ppm += '\n';
        }

        const std::string file_name = std::format("shader2-out/out-{:02d}.ppm", t);

        std::ofstream ofs{file_name};

        if (ofs.is_open()) {
            ofs << ppm;

            ofs.close();
        } else {
            std::println(std::cerr, "Cannot write ppm file to {}", file_name);
        }
    }

    return 0;
}
