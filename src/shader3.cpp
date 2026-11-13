import std;

import lib.math;
import lib.ppm;
import lib.video;

int main(int argc, char **argv) {
    static constexpr std::size_t width = 16 * 60;
    static constexpr std::size_t height = 16 * 60;

    std::filesystem::create_directory("shader3-out");

    video::video shader_video(60, 120, width, height);

    shader_video.render_video([](const std::size_t frame, const std::size_t x, const std::size_t y){
        const math::vec2 r = math::vec2{ static_cast<float>(width), static_cast<float>(height) };

        const float float_x = static_cast<float>(x);
        const float float_y = static_cast<float>(y);
        const float float_t = static_cast<float>(frame);

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

        return ppm::ppm::pixel{ static_cast<std::uint8_t>(o.x * 255), static_cast<std::uint8_t>(o.y * 255), static_cast<std::uint8_t>(o.z * 255) };
    });

    shader_video.save_file("shader3-out/output.mp4");

    return 0;
}
