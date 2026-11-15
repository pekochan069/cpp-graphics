export module lib.math;

import std;

export namespace math {
    struct vec3 {
        float x;
        float y;
        float z;



        auto operator+(float s) -> vec3 {
            return vec3{ this->x + s, this->y + s, this->z + s };
        }

        auto operator-(float s) -> vec3 {
            return vec3{ this->x - s, this->y - s, this->z - s };
        }

        auto operator*(float s) -> vec3 {
            return vec3{ this->x * s, this->y * s, this->z * s };
        }

        auto operator/(float s) -> vec3 {
            return vec3{ this->x / s, this->y / s, this->z / s };
        }

        auto operator+(vec3 other) -> vec3 {
            return vec3{ this->x + other.x, this->y + other.y, this->z + other.z };
        }

        auto operator-(vec3 other) -> vec3 {
            return vec3{ this->x - other.x, this->y - other.y, this->z - other.z };
        }

        auto operator*(vec3 other) -> vec3 {
            return vec3{ this->x * other.x, this->y * other.y, this->z * other.z };
        }

        auto operator/(vec3 other) -> vec3 {
            return vec3{ this->x / other.x, this->y / other.y, this->z / other.z };
        }

        auto operator+=(float s) -> vec3& {
            return *this = *this + s;
        }

        auto operator-=(float s) -> vec3& {
            return *this = *this - s;
        }

        auto operator*=(float s) -> vec3& {
            return *this = *this * s;
        }

        auto operator/=(float s) -> vec3& {
            return *this = *this / s;
        }

        auto operator+=(vec3 other) -> vec3& {
            return *this = *this + other;
        }

        auto operator-=(vec3 other) -> vec3& {
            return *this = *this - other;
        }

        auto operator*=(vec3 other) -> vec3& {
            return *this = *this * other;
        }

        auto operator/=(vec3 other) -> vec3& {
            return *this = *this / other;
        }

        auto add_x(float s) -> vec3 {
            return vec3{ this->x + s, this->y, this->z };
        }

        auto add_y(float s) -> vec3 {
            return vec3{ this->x, this->y + s, this->z };
        }

        auto add_z(float s) -> vec3 {
            return vec3{ this->x, this->y, this->z + s };
        }

        auto sub_x(float s) -> vec3 {
            return vec3{ this->x - s, this->y, this->z };
        }

        auto sub_y(float s) -> vec3 {
            return vec3{ this->x, this->y - s, this->z };
        }

        auto sub_z(float s) -> vec3 {
            return vec3{ this->x, this->y, this->z - s };
        }

        auto mul_x(float s) -> vec3 {
            return vec3{ this->x * s, this->y, this->z };
        }

        auto mul_y(float s) -> vec3 {
            return vec3{ this->x, this->y * s, this->z };
        }

        auto mul_z(float s) -> vec3 {
            return vec3{ this->x, this->y, this->z * s };
        }

        auto div_x(float s) -> vec3 {
            return vec3{ this->x / s, this->y, this->z };
        }

        auto div_y(float s) -> vec3 {
            return vec3{ this->x, this->y / s, this->z };
        }

        auto div_z(float s) -> vec3 {
            return vec3{ this->x, this->y, this->z / s };
        }



        auto abs() -> vec3 {
            return vec3{ std::abs(this->x), std::abs(this->y), std::abs(this->z) };
        }

        auto sin() -> vec3 {
            return vec3{ std::sin(this->x), std::sin(this->y), std::sin(this->z) };
        }

        auto cos() -> vec3 {
            return { std::cos(this->x), std::cos(this->y), std::cos(this->z) };
        }

        auto tan() -> vec3 {
            return { std::tan(this->x), std::tan(this->y), std::tan(this->z) };
        }

        auto sinh() -> vec3 {
            return { std::sinh(this->x), std::sinh(this->y), std::sinh(this->z) };
        }

        auto cosh() -> vec3 {
            return { std::cosh(this->x), std::cosh(this->y), std::cosh(this->z) };
        }

        auto tanh() -> vec3 {
            return { std::tanh(this->x), std::tanh(this->y), std::tanh(this->z) };
        }

        auto exp() -> vec3 {
            return { std::exp(this->x), std::exp(this->y), std::exp(this->z) };
        }

        auto length() -> float {
            return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
        }

        auto fract() -> vec3 {
            return vec3{ this->x - std::floor(this->x), this->y - std::floor(this->y), this->z - std::floor(this->z) };
        }

        auto dot(vec3 other) -> float {
            return this->x * other.x + this->y + other.y + this->z * other.z;
        }



        auto denormalize(float multiplier) -> vec3 {
            return vec3{ this->x * multiplier, this->y * multiplier, this->z * multiplier };
        }



        auto ceil(float value) -> vec3 {
            return vec3{ this->x < value ? this->x : value, this->y < value ? this->y : value, this->z < value ? this->z : value };
        }

        auto floor(float value) -> vec3 {
            return vec3{ this->x > value ? this->x : value, this->y > value ? this->y : value, this->z > value ? this->z : value };
        }

        auto floor_ceil(float floor_value, float ceil_value) -> vec3 {
            float x, y, z;

            if (this->x < floor_value) {
                x = floor_value;
            } else if (this->x < ceil_value) {
                x = this->x;
            } else {
                x = ceil_value;
            }
            if (this->y < floor_value) {
                y = floor_value;
            } else if (this->y < ceil_value) {
                y = this->y;
            } else {
                y = ceil_value;
            }
            if (this->z < floor_value) {
                z = floor_value;
            } else if (this->z < ceil_value) {
                z = this->z;
            } else {
                z = ceil_value;
            }

            return vec3{ x, y, z };
        }
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

        auto operator+=(float s) -> vec4& {
            return *this = *this + s;
        }

        auto operator-=(float s) -> vec4& {
            return *this = *this - s;
        }

        auto operator*=(float s) -> vec4& {
            return *this = *this * s;
        }

        auto operator/=(float s) -> vec4& {
            return *this = *this / s;
        }

        auto operator+=(vec4 other) -> vec4& {
            return *this = *this + other;
        }

        auto operator-=(vec4 other) -> vec4& {
            return *this = *this - other;
        }

        auto operator*=(vec4 other) -> vec4& {
            return *this = *this * other;
        }

        auto operator/=(vec4 other) -> vec4& {
            return *this = *this / other;
        }

        auto add_x(float s) -> vec4 {
            return vec4{ this->x + s, this->y, this->z, this->w };
        }

        auto add_y(float s) -> vec4 {
            return vec4{ this->x, this->y + s, this->z, this->w };
        }

        auto add_z(float s) -> vec4 {
            return vec4{ this->x, this->y, this->z + s, this->w };
        }

        auto add_w(float s) -> vec4 {
            return vec4{ this->x, this->y, this->z, this->w + s };
        }

        auto sub_x(float s) -> vec4 {
            return vec4{ this->x - s, this->y, this->z, this->w };
        }

        auto sub_y(float s) -> vec4 {
            return vec4{ this->x, this->y - s, this->z, this->w };
        }

        auto sub_z(float s) -> vec4 {
            return vec4{ this->x, this->y, this->z - s, this->w };
        }

        auto sub_w(float s) -> vec4 {
            return vec4{ this->x, this->y, this->z, this->w - s };
        }

        auto mul_x(float s) -> vec4 {
            return vec4{ this->x * s, this->y, this->z, this->w };
        }

        auto mul_y(float s) -> vec4 {
            return vec4{ this->x, this->y * s, this->z, this->w };
        }

        auto mul_z(float s) -> vec4 {
            return vec4{ this->x, this->y, this->z * s, this->w };
        }

        auto mul_w(float s) -> vec4 {
            return vec4{ this->x, this->y, this->z, this->w * s };
        }

        auto div_x(float s) -> vec4 {
            return vec4{ this->x / s, this->y, this->z, this->w };
        }

        auto div_y(float s) -> vec4 {
            return vec4{ this->x, this->y / s, this->z, this->w };
        }

        auto div_z(float s) -> vec4 {
            return vec4{ this->x, this->y, this->z / s, this->w };
        }

        auto div_w(float s) -> vec4 {
            return vec4{ this->x, this->y, this->z, this->w / s };
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

        auto length() -> float {
            return std::sqrt(this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
        }

        auto fract() -> vec4 {
            return vec4{ this->x - std::floor(this->x), this->y - std::floor(this->y), this->z - std::floor(this->z), this->w - std::floor(this->w) };
        }

        auto dot(vec4 other) -> float {
            return this->x * other.x + this->y + other.y + this->z * other.z + this->w * other.w;
        }


        auto normalize_x(float divider) -> vec4 {
            return vec4{ this->x / divider, this->y, this->z, this->w };
        }

        auto normalize_y(float divider) -> vec4 {
            return vec4{ this->x, this->y / divider, this->z, this->w };
        }

        auto normalize_z(float divider) -> vec4 {
            return vec4{ this->x, this->y, this->z / divider, this->w };
        }

        auto normalize_w(float divider) -> vec4 {
            return vec4{ this->x, this->y, this->z, this->w / divider };
        }

        auto denormalize(float multiplier) -> vec4 {
            return vec4{ this->x * multiplier, this->y * multiplier, this->z * multiplier, this->w * multiplier };
        }



        auto ceil(float value) -> vec4 {
            return vec4{ this->x < value ? this->x : value, this->y < value ? this->y : value, this->z < value ? this->z : value, this->w < value ? this->w : value };
        }

        auto floor(float value) -> vec4 {
            return vec4{ this->x > value ? this->x : value, this->y > value ? this->y : value, this->z > value ? this->z : value, this->w > value ? this->w : value };
        }

        auto floor_ceil(float floor_value, float ceil_value) -> vec4 {
            float x, y, z, w;

            if (this->x < floor_value) {
                x = floor_value;
            } else if (this->x < ceil_value) {
                x = this->x;
            } else {
                x = ceil_value;
            }
            if (this->y < floor_value) {
                y = floor_value;
            } else if (this->y < ceil_value) {
                y = this->y;
            } else {
                y = ceil_value;
            }
            if (this->z < floor_value) {
                z = floor_value;
            } else if (this->z < ceil_value) {
                z = this->z;
            } else {
                z = ceil_value;
            }
            if (this->w < floor_value) {
                w = floor_value;
            } else if (this->w < ceil_value) {
                w = this->w;
            } else {
                w = ceil_value;
            }

            return vec4{ x, y, z, w };
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

        auto operator+=(float s) -> vec2& {
            return *this = *this + s;
        }

        auto operator-=(float s) -> vec2& {
            return *this = *this - s;
        }

        auto operator*=(float s) -> vec2& {
            return *this = *this * s;
        }

        auto operator/=(float s) -> vec2& {
            return *this = *this / s;
        }

        auto operator+=(vec2 other) -> vec2& {
            return *this = *this + other;
        }

        auto operator-=(vec2 other) -> vec2& {
            return *this = *this - other;
        }

        auto operator*=(vec2 other) -> vec2& {
            return *this = *this * other;
        }

        auto operator/=(vec2 other) -> vec2& {
            return *this = *this / other;
        }

        auto add_x(float s) -> vec2 {
            return vec2{ this->x + s, this->y };
        }

        auto add_y(float s) -> vec2 {
            return vec2{ this->x, this->y + s };
        }

        auto sub_x(float s) -> vec2 {
            return vec2{ this->x - s, this->y };
        }

        auto sub_y(float s) -> vec2 {
            return vec2{ this->x, this->y - s };
        }

        auto mul_x(float s) -> vec2 {
            return vec2{ this->x * s, this->y };
        }

        auto mul_y(float s) -> vec2 {
            return vec2{ this->x, this->y * s };
        }

        auto div_x(float s) -> vec2 {
            return vec2{ this->x / s, this->y };
        }

        auto div_y(float s) -> vec2 {
            return vec2{ this->x, this->y / s };
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

        auto length() -> float {
            return std::sqrt(this->x * this->x + this->y * this->y);
        }

        auto fract() -> vec2 {
            return vec2{ this->x - std::floor(this->x), this->y - std::floor(this->y) };
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



        auto normalize_x(float divider) -> vec2 {
            return vec2{ this->x / divider, this->y };
        }

        auto normalize_y(float divider) -> vec2 {
            return vec2{ this->x, this->y / divider };
        }

        auto normalize_xy(float x_divider, float y_divider) -> vec2 {
            return vec2{ this->x / x_divider, this->y / y_divider };
        }

        auto denormalize(float multiplier) -> vec2 {
            return vec2{ this->x * multiplier, this->y * multiplier };
        }



        auto ceil(float value) -> vec2 {
            return vec2{ this->x < value ? this->x : value, this->y < value ? this->y : value };
        }

        auto floor(float value) -> vec2 {
            return vec2{ this->x > value ? this->x : value, this->y > value ? this->y : value };
        }

        auto floor_ceil(float floor_value, float ceil_value) -> vec2 {
            float x, y;

            if (this->x < floor_value) {
                x = floor_value;
            } else if (this->x < ceil_value) {
                x = this->x;
            } else {
                x = ceil_value;
            }
            if (this->y < floor_value) {
                y = floor_value;
            } else if (this->y < ceil_value) {
                y = this->y;
            } else {
                y = ceil_value;
            }

            return vec2{ x, y };
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



    auto operator+(float s, vec3 v) -> vec3 {
        return vec3{ v.x + s, v.y + s, v.z + s };
    }

    auto operator-(float s, vec3 v) -> vec3 {
        return vec3{ s - v.x, s - v.y, s - v.z };
    }

    auto operator*(float s, vec3 v) -> vec3 {
        return vec3{ v.x * s, v.y * s, v.z * s };
    }
    
    auto operator/(float s, vec3 v) -> vec3 {
        return vec3{ s / v.x, s / v.y, s / v.z };
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




    auto step(float value, float threshold, float low = 0.0f, float high = 1.0f) -> float {
        if (value < threshold) {
            return low;
        } else {
            return high;
        }
    }

    auto step_smooth(float value, float threshold1, float threshold2, float low = 0.0f, float high = 1.0f) -> float {
        if (threshold1 >= threshold2) {
            return (value < threshold1) ? low : high;
        }

        float t = std::clamp((value - threshold1) / (threshold2 - threshold1), 0.0f, 1.0f);
        float smooth_t = t * t * (3.0f - 2.0f * t);

        return low + (high - low) * smooth_t; 
    }

    auto fract(float value) -> float {
        return value - std::floor(value);
    }
}
