export module lib.math;

import std;

export namespace math {
    struct vec3 {
        float x;
        float y;
        float z;
    };

    struct vec4 {
        float x;
        float y;
        float z;
        float w;



        auto operator+(float s) -> vec4 {
            return vec4{ this->x + s, this->y + s, this->z + s, this->w + s };
        }

        auto operator-(float s) -> vec4 {
            return vec4{ this->x - s, this->y - s, this->z - s, this->w - s };
        }

        auto operator*(float s) -> vec4 {
            return vec4{ this->x * s, this->y * s, this->z * s, this->w * s };
        }

        auto operator/(float s) -> vec4 {
            return vec4{ this->x / s, this->y / s, this->z / s, this->w / s };
        }

        auto operator+(vec4 other) -> vec4 {
            return vec4{ this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w };
        }

        auto operator-(vec4 other) -> vec4 {
            return vec4{ this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w };
        }

        auto operator*(vec4 other) -> vec4 {
            return vec4{ this->x * other.x, this->y * other.y, this->z * other.z, this->w * other.w };
        }

        auto operator/(vec4 other) -> vec4 {
            return vec4{ this->x / other.x, this->y / other.y, this->z / other.z, this->w / other.w };
        }



        auto abs() -> vec4 {
            return vec4{ std::abs(this->x), std::abs(this->y), std::abs(this->z), std::abs(this->w) };
        }

        auto sin() -> vec4 {
            return vec4{ std::sin(this->x), std::sin(this->y), std::sin(this->z), std::sin(this->w) };
        }

        auto cos() -> vec4 {
            return { std::cos(this->x), std::cos(this->y), std::cos(this->z), std::cos(this->z) };
        }

        auto tan() -> vec4 {
            return { std::tan(this->x), std::tan(this->y), std::tan(this->z), std::tan(this->w) };
        }

        auto sinh() -> vec4 {
            return { std::sinh(this->x), std::sinh(this->y), std::sinh(this->z), std::sinh(this->w) };
        }

        auto cosh() -> vec4 {
            return { std::cosh(this->x), std::cosh(this->y), std::cosh(this->z), std::cosh(this->w) };
        }

        auto tanh() -> vec4 {
            return { std::tanh(this->x), std::tanh(this->y), std::tanh(this->z), std::tanh(this->w) };
        }

        auto exp() -> vec4 {
            return { std::exp(this->x), std::exp(this->y), std::exp(this->z), std::exp(this->w) };
        }

        auto dot(vec4 other) -> float {
            return this->x * other.x + this->y + other.y + this->z * other.z + this->w * other.w;
        }
    };

    struct vec2{
        float x;
        float y;



        auto operator+(float s) -> vec2 {
            return vec2{ this->x + s, this->y + s };
        }

        auto operator-(float s) -> vec2 {
            return vec2{ this->x - s, this->y - s };
        }

        auto operator*(float s) -> vec2 {
            return vec2{ this->x * s, this->y * s };
        }

        auto operator/(float s) -> vec2 {
            return vec2{ this->x / s, this->y / s };
        }

        auto operator+(vec2 other) -> vec2 {
            return vec2{ this->x + other.x, this->y + other.y };
        }

        auto operator-(vec2 other) -> vec2 {
            return vec2{ this->x - other.x, this->y - other.y };
        }

        auto operator*(vec2 other) -> vec2 {
            return vec2{ this->x * other.x, this->y * other.y };
        }

        auto operator/(vec2 other) -> vec2 {
            return vec2{ this->x / other.x, this->y / other.y };
        }



        auto abs() -> vec2 {
            return vec2{ std::abs(this->x), std::abs(this->y) };
        }

        auto sin() -> vec2 {
            return { std::sin(this->x), std::sin(this->y) };
        }

        auto cos() -> vec2 {
            return { std::cos(this->x), std::cos(this->y) };
        }

        auto tan() -> vec2 {
            return { std::tan(this->x), std::tan(this->y) };
        }

        auto sinh() -> vec2 {
            return { std::sinh(this->x), std::sinh(this->y) };
        }

        auto cosh() -> vec2 {
            return { std::cosh(this->x), std::cosh(this->y) };
        }

        auto tanh() -> vec2 {
            return { std::tanh(this->x), std::tanh(this->y) };
        }

        auto exp() -> vec2 {
            return { std::exp(this->x), std::exp(this->y) };
        }

        auto dot(vec2 other) -> float {
            return this->x * other.x + this->y * other.y;
        }



        auto yx() -> vec2 {
            return vec2{ this->y, this->x };
        }

        auto xyyx() -> vec4 {
            return vec4{ this->x, this->y, this->y, this->x };
        }
    };



    auto operator+(float s, vec2 v) -> vec2 {
        return vec2{ s + v.x, s + v.y };
    }

    auto operator-(float s, vec2 v) -> vec2 {
        return vec2{ v.x - s, v.y - s };
    }

    auto operator*(float s, vec2 v) -> vec2 {
        return vec2{ v.x * s, v.y * s };
    }

    auto operator/(float s, vec2 v) -> vec2 {
        return vec2{ s / v.x, s/ v.y };
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

    auto tan(vec2 v) -> vec2 {
        return vec2{ std::tan(v.x), std::tan(v.y) };
    }

    auto sinh(vec2 v) -> vec2 {
        return vec2{ std::sinh(v.x), std::sinh(v.y) };
    }

    auto cosh(vec2 v) -> vec2 {
        return vec2{ std::cosh(v.x), std::cosh(v.y) };
    }

    auto tanh(vec2 v) -> vec2 {
        return vec2{ std::tanh(v.x), std::tanh(v.y) };
    }

    auto exp(vec2 v) -> vec2 {
        return vec2{ std::exp(v.x), std::exp(v.y) };
    }

    auto dot(vec2 v1, vec2 v2) -> float {
        return v1.x * v2.x + v1.y * v2.y;
    }



    auto operator+(float s, vec4 v) -> vec4 {
        return vec4{ v.x + s, v.y + s, v.z + s, v.w + s };
    }

    auto operator-(float s, vec4 v) -> vec4 {
        return vec4{ s - v.x, s - v.y, s - v.z, s - v.w };
    }

    auto operator*(float s, vec4 v) -> vec4 {
        return vec4{ v.x * s, v.y * s, v.z * s, v.w * s };
    }
    
    auto operator/(float s, vec4 v) -> vec4 {
        return vec4{ s / v.x, s / v.y, s / v.z, s / v.w };
    }

    auto abs(vec4 v) -> vec4 {
        return vec4{ std::abs(v.x), std::abs(v.y), std::abs(v.z), std::abs(v.w) };
    }

    auto sin(vec4 v) -> vec4 {
        return vec4{ std::sin(v.x), std::sin(v.y), std::sin(v.z), std::sin(v.w) };
    }

    auto cos(vec4 v) -> vec4 {
        return vec4{ std::cos(v.x), std::cos(v.y), std::cos(v.z), std::cos(v.w) };
    }

    auto tan(vec4 v) -> vec4 {
        return vec4{ std::tan(v.x), std::tan(v.y), std::tanh(v.z), std::tan(v.w) };
    }

    auto sinh(vec4 v) -> vec4 {
        return vec4{ std::sinh(v.x), std::sinh(v.y), std::sinh(v.z), std::sinh(v.w) };
    }

    auto cosh(vec4 v) -> vec4 {
        return vec4{ std::cosh(v.x), std::cosh(v.y), std::cosh(v.z), std::cosh(v.w) };
    }

    auto tanh(vec4 v) -> vec4 {
        return vec4{ std::tanh(v.x), std::tanh(v.y), std::tanh(v.z), std::tanh(v.w) };
    }

    auto exp(vec4 v) -> vec4 {
        return vec4 { std::exp(v.x), std::exp(v.y), std::exp(v.z), std::exp(v.w) };
    }

    auto dot(vec4 v1, vec4 v2) -> float {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
    }
}