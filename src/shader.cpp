import std;

struct vec4 {
    float x;
    float y;
    float z;
    float w;
};

struct vec2{
    float x;
    float y;

    auto yx() -> vec2 {
        return vec2{ this->y, this->x };
    }

    auto xyyx() -> vec4 {
        return vec4{ this->x, this->y, this->y, this->x };
    }
};


auto operator +(vec2 v, float s) -> vec2 {
    return vec2{ v.x + s, v.y + s };
}

auto operator +(float s, vec2 v) -> vec2 {
    return vec2{ s + v.x, s + v.y };
}

auto operator +(vec2 v1, vec2 v2) -> vec2 {
    return vec2{ v1.x + v2.x, v1.y + v2.y };
}

auto operator -(vec2 v, float s) -> vec2 {
    return vec2{ v.x - s, v.y - s };
}

auto operator -(float s, vec2 v) -> vec2 {
    return vec2{ v.x - s, v.y - s };
}

auto operator -(vec2 v1, vec2 v2) -> vec2 {
    return vec2{ v1.x - v2.x, v1.y - v2.y };
}

auto operator *(vec2 v, float s) -> vec2 {
    return vec2{ v.x * s, v.y * s };
}

auto operator *(float s, vec2 v) -> vec2 {
    return vec2{ v.x * s, v.y * s };
}

auto operator *(vec2 v1, vec2 v2) -> vec2 {
    return vec2{ v1.x * v2.x, v1.y * v2.y };
}

auto operator /(vec2 v, float s) -> vec2 {
    return vec2{ v.x / s, v.y / s };
}

auto dot(vec2 v1, vec2 v2) -> float {
    return v1.x * v2.x + v1.y * v2.y;
}

auto abs(vec2 v) -> vec2 {
    return vec2{ std::abs(v.x), std::abs(v.y) };
}

auto sin(vec2 v) -> vec2 {
    return vec2{ std::sin(v.x), std::sin(v.y) };
}

auto cos(vec2 v) -> vec2 {
    return vec2{ std::cos(v.x), std::cos(v.y) };
}

auto tanh(vec2 v) -> vec2 {
    return vec2{ std::tanh(v.x), std::tanh(v.y) };
}

auto operator+(vec4 v, float s) -> vec4 {
    return vec4{ v.x + s, v.y + s, v.z + s, v.w + s };
}

auto operator+(vec4 v1, vec4 v2) -> vec4 {
    return vec4{ v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w };
}

auto operator-(float s, vec4 v) -> vec4 {
    return vec4{ s - v.x, s - v.y, s - v.z, s - v.w };
}

auto operator*(vec4 v, float s) -> vec4 {
    return vec4{ v.x * s, v.y * s, v.z * s, v.w * s };
}

auto operator*(float s, vec4 v) -> vec4 {
    return vec4{ v.x * s, v.y * s, v.z * s, v.w * s };
}

auto operator/(vec4 v1, vec4 v2) -> vec4 {
    return vec4{ v1.x / v2.x, v1.y / v2.y, v1.z / v2.z, v1.w / v2.w };
}

auto sin(vec4 v) -> vec4 {
    return vec4{ std::sin(v.x), std::sin(v.y), std::sin(v.z), std::sin(v.w) };
}

auto tanh(vec4 v) -> vec4 {
    return vec4{ std::tanh(v.x), std::tanh(v.y), std::tanh(v.z), std::tanh(v.w) };
}

auto exp(vec4 v) -> vec4 {
    return vec4 { std::exp(v.x), std::exp(v.y), std::exp(v.z), std::exp(v.w) };
}

int main(int argc, char **argv) {
    static constexpr std::size_t image_width = 16 * 60;
    static constexpr std::size_t image_height = 16 * 60;

    static constexpr std::size_t max_color_val = 255;

    for (std::size_t t = 0; t < 60; ++t) {
        std::string ppm = std::format("P3\n{} {}\n{}\n", image_width, image_height, max_color_val);

        const vec2 r = vec2{ static_cast<float>(image_width), static_cast<float>(image_height) };

        for (std::size_t y = 0; y < image_height; ++y) {
            for (std::size_t x = 0; x < image_width; ++x) {
                const float float_x = static_cast<float>(x);
                const float float_y = static_cast<float>(y);
                const float float_t = static_cast<float>(t);

                vec4 o{};
                vec2 FC{ float_x, float_y };        
                vec2 p=(FC*2.0f-r)/r.y;
                vec2 l{};
                vec2 i{};
                vec2 v=p * (l = l + 4.0f-4.0f * std::abs(0.7f-dot(p,p)));
                for(; i.y++ < 8.0f; o = o + (sin(v.xyyx()) + 1.0f) * std::abs(v.x-v.y)) {
                    v = v + cos(v.yx() * i.y + i + float_t / 60)/i.y+0.7f;
                }
                o = tanh(5.0f * exp(l.x-4.0f - p.y * vec4(-1.0f,1.0f,2.0f,0.0f)) / o);

                ppm += std::format("{} {} {}", static_cast<std::uint8_t>(o.x * 255), static_cast<std::uint8_t>(o.y * 255), static_cast<std::uint8_t>(o.z * 255));

                if (x != image_width - 1) {
                    ppm += ' ';
                }
            }
            ppm += '\n';
        }

        const std::string file_name = std::format("out/out-{:02d}.ppm", t);

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
