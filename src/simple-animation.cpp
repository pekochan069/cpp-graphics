import std;

int main(int argc, char **argv) {
    static constexpr std::size_t image_width = 16 * 60;
    static constexpr std::size_t image_height = 16 * 60;

    static constexpr std::size_t max_color_val = 255;

    std::filesystem::create_directory("simple-animation-out");

    for (std::size_t t = 0; t < 60; ++t) {
        std::string ppm = std::format("P3\n{} {}\n{}\n", image_width, image_height, max_color_val);

        for (std::size_t y = 0; y < image_height; ++y) {
            for (std::size_t x = 0; x < image_width; ++x) {
                if (((x + t) / 60 + (y + t) / 60) % 2 == 0) {
                    ppm += "0 0 0";
                } else {
                    ppm += "255 255 255";
                }

                if (x != image_width - 1) {
                    ppm += ' ';
                }
            }
            ppm += '\n';
        }

        const std::string file_name = std::format("simple-animation-out/out-{:02d}.ppm", t);

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
