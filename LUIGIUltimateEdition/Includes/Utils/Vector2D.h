#pragma once

#include <iostream>
template<typename T>

struct Vector2D 
{
    Vector2D() : x(0), y(0){};
    Vector2D(T xy) : x(xy), y(xy) {};
    Vector2D(T x_, T y_) : x(x_), y(y_) {};
    T x;
    T y;
    /*<----------------------------------------------->*/
    /* Operator for same type */
    inline Vector2D operator+(const Vector2D& other) const {
        return Vector2D((x + other.x), (y + other.y));
    }
    inline Vector2D operator-(const Vector2D& other) const {
        return Vector2D((x - other.x), (y - other.y));
    }
    inline Vector2D operator*(const Vector2D& other) const {
        return Vector2D((x * other.x), (y * other.y));
    }
    inline Vector2D operator/(const Vector2D& other) const {
        return Vector2D((x / other.x), (y / other.y));
    }
    /*<----------------------------------------------->*/
    /* Operator for different type */
    inline Vector2D operator+(const T& other) const {
        return *this + Vector2D(other);
    }
    inline Vector2D operator-(const T& other) const {
        return *this - Vector2D(other);
    }
    inline Vector2D operator*(const T& other) const {
        return *this * Vector2D(other);
    }
    inline Vector2D operator/(const T& other) const {
        return *this / Vector2D(other);
    }
    /*<----------------------------------------------->*/
    /* Operator for Same type with equal */
    inline Vector2D operator+=(const Vector2D& other) {
        x += other.x;
        y += other.y;
        return *this;
    }
    inline Vector2D operator-=(const Vector2D& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }
    inline Vector2D operator*=(const Vector2D& other) {
        x *= other.x;
        y *= other.y;
        return *this;
    }
    inline Vector2D operator/=(const Vector2D& other) {
        x /= other.x;
        y /= other.y;
        return *this;
    }
    /*<----------------------------------------------->*/
    /* Operator for other type with equal */
    inline Vector2D operator+=(const T& other) {
        x += other;
        y += other;
        return *this;
    }
    inline Vector2D operator-=(const T& other) {
        x -= other;
        y -= other;
        return *this;
    }
    inline Vector2D operator*=(const T& other) {
        x *= other;
        y *= other;
        return *this;
    }
    inline Vector2D operator/=(const T& other) {
        x /= other;
        y /= other;
        return *this;
    }
    /*<----------------------------------------------->*/
    /* Compare operator */
    inline bool operator==(const Vector2D& other) const
    {
        return (x == other.x) && (y == other.y);
    }

    inline bool operator!=(const Vector2D& other) const
    {
        return (x != other.x) || (y != other.y);
    }
    /*<----------------------------------------------->*/
    /* Function Vector */
    inline float Lenght() {
        return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
    };
    inline Vector2D Normalize()
    {
        return *this = *this / Lenght();
    }
    inline Vector2D SafeNormalize() {
        if (Lenght()) {
            Normalize();
        }
    }
    inline float Dot(Vector2D& other) {
        return  x * other.x + y * other.y;
    }
    static inline float Dot(Vector2D& a, Vector2D& b) {
        return  a.Dot(b);
    }

};

using FVector2D = Vector2D<float>;
using DVector2D = Vector2D<double>;
using IVector2D = Vector2D<int>;
using UVector2D = Vector2D<unsigned int>;