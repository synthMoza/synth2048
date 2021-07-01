#pragma once

namespace se {

    // Template class for the double-dimensional vector (x, y). The template arguments
    // is the type of the coordinates storing in this vector.
    template <typename T>
    struct Vector2 final {
        T x_;
        T y_;

        // Default constructor
        Vector2() : x_ (), y_ () {}
        // Simple constructor for initializing values
        Vector2(T x, T y) : x_ (x), y_ (y) {}
        // Copy constructor
        Vector2(const Vector2& that) : x_ (that.x_), y_ (that.y_) {}
        // Assignment operator
        Vector2& operator=(const Vector2& rhs) {
            x_ = rhs.x_;
            y_ = rhs.y_;
            return *this;
        }
        // Chained operators
        Vector2& operator+=(const Vector2& rhs) {
            x_ += rhs.x_;
            y_ += rhs.y_;
            return *this;
        }
        Vector2& operator-=(const Vector2& rhs) {
            x_ += rhs.x_;
            y_ += rhs.y_;
            return *this;
        }
        template <typename U>
        Vector2& operator*=(U value) {
            x_ *= value;
            y_ *= value;
        }
    };

    // Useful typedefs took straight from SFML
    typedef Vector2<float> Vector2f;
    typedef Vector2<unsigned int> Vector2u;
    typedef Vector2<int> Vector2i;

    // Basic operators
    template <typename T>
    Vector2<T> operator+(const Vector2<T>& lhs, const Vector2<T>& rhs) {
        Vector2<T> res{lhs};
        res += rhs;
        return res;
    } 

    template <typename T>
    Vector2<T> operator-(const Vector2<T>& lhs, const Vector2<T>& rhs) {
        Vector2<T> res{lhs};
        res -= rhs;
        return res;
    } 

    template <typename T, typename U>
    Vector2<T> operator*(const Vector2<T>& lhs, U value) {
        Vector2<T> res{lhs};
        res *= value;
        return res;
    } 
};