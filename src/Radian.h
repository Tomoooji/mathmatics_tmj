/**
 * @file Radian.h
 * @brief たぶんYAGNIだけど自己満なのでヨシ!
 * 
 * @author Tomoooji (https://github.com/Tomoooji)
 * @version 0.1
 * @date 2026-09-21
 * @copyright Copyright (c) 2026
 */
#pragma once
#include <cmath>
#if __cplusplus >= 202002L
#include <numbers>
#endif

template <typename T = float>
class Radian2Pi : public T {
public:
#if __cplusplus >= 202002L
  static constexpr T PI = std::numbers::pi_v<T>;
  static constexpr T TWO_PI = std::numbers::pi_v<T> * 2;
#else
  static constexpr T PI = T(3.14159265358979323846);
  static constexpr T TWO_PI = T(6.28318530717958647692);
#endif
  Radian2Pi(T rad = 0.0f) : T(rad) {}
  Radian2Pi normalize() const {
    T normalized = fmod(T(*this), TWO_PI);
    if (normalized < 0) {
      normalized += TWO_PI;
    }
    return Radian2Pi(normalized);
  }
  Radian2Pi operator+(const Radian2Pi &other) const {
    return Radian2Pi(fmod(T(*this) + T(other), TWO_PI) + (T(*this) + T(other) < 0 ? TWO_PI : 0));
  }
  Radian2Pi operator-(const Radian2Pi &other) const {
    return Radian2Pi(fmod(T(*this) - T(other), TWO_PI) + (T(*this) - T(other) < 0 ? TWO_PI : 0));
  }
  Radian2Pi operator*(T scalar) const {
    return Radian2Pi(fmod(T(*this) * scalar, TWO_PI) + (T(*this) * scalar < 0 ? TWO_PI : 0));
  }
  Radian2Pi operator/(T scalar) const {
    return Radian2Pi(fmod(T(*this) / scalar, TWO_PI) + (T(*this) / scalar < 0 ? TWO_PI : 0));
  }
  Radian2Pi operator+=(const Radian2Pi &other) {
    T::operator+=(T(other));
    if (T(*this) < 0) {
      T::operator+=(TWO_PI);
    } else if (T(*this) >= TWO_PI) {
      T::operator-=(TWO_PI);
    }
    return *this;
  }
  Radian2Pi operator-=(const Radian2Pi &other) {
    T::operator-=(T(other));
    if (T(*this) < 0) {
      T::operator+=(TWO_PI);
    } else if (T(*this) >= TWO_PI) {
      T::operator-=(TWO_PI);
    }
    return *this;
  }
  Radian2Pi operator*=(T scalar) {
    T::operator*=(scalar);
    if (T(*this) < 0) {
      T::operator+=(TWO_PI);
    } else if (T(*this) >= TWO_PI) {
      T::operator-=(TWO_PI);
    }
    return *this;
  }
  Radian2Pi operator/=(T scalar) {
    T::operator/=(scalar);
    if (T(*this) < 0) {
      T::operator+=(TWO_PI);
    } else if (T(*this) >= TWO_PI) {
      T::operator-=(TWO_PI);
    }
    return *this;
  }
};

template <typename T = float>
class RadianAbsPi : public T {
public:
#if __cplusplus >= 202002L
  static constexpr T PI = std::numbers::pi_v<T>;
#else
  static constexpr T PI = T(3.14159265358979323846);
#endif
  RadianAbsPi(T rad = 0.0f) : T(rad) {}
  RadianAbsPi normalize() const {
    T normalized = fmod(T(*this) + PI, 2 * PI) - PI;
    return RadianAbsPi(normalized);
  }
  RadianAbsPi operator+(const RadianAbsPi &other) const {
    return RadianAbsPi(fmod(T(*this) + T(other) + PI, 2 * PI) - PI);
  }
  RadianAbsPi operator-(const RadianAbsPi &other) const {
    return RadianAbsPi(fmod(T(*this) - T(other) + PI, 2 * PI) - PI);
  }
  RadianAbsPi operator*(T scalar) const {
    return RadianAbsPi(fmod(T(*this) * scalar + PI, 2 * PI) - PI);
  }
  RadianAbsPi operator/(T scalar) const {
    return RadianAbsPi(fmod(T(*this) / scalar + PI, 2 * PI) - PI);
  }
  RadianAbsPi operator+=(const RadianAbsPi &other) {
    T::operator+=(T(other));
    T::operator-=(PI);
    T::operator-=(floor(T(*this) / (2 * PI)) * (2 * PI));
    T::operator+=(PI);
    return *this;
  }
  RadianAbsPi operator-=(const RadianAbsPi &other) {
    T::operator-=(T(other));
    T::operator-=(PI);
    T::operator-=(floor(T(*this) / (2 * PI)) * (2 * PI));
    T::operator+=(PI);
    return *this;
  }
  RadianAbsPi operator*=(T scalar) {
    T::operator*=(scalar);
    T::operator-=(PI);
    T::operator-=(floor(T(*this) / (2 * PI)) * (2 * PI));
    T::operator+=(PI);
    return *this;
  }
  RadianAbsPi operator/=(T scalar) {
    T::operator/=(scalar);
    T::operator-=(PI);
    T::operator-=(floor(T(*this) / (2 * PI)) * (2 * PI));
    T::operator+=(PI);
    return *this;
  }
};