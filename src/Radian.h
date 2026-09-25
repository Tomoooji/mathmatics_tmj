/**
 * @file Radian.h
 * @brief ちゃんとコンポジションにしたラジアンのクラス
 * 
 * @author Tomoooji (https://github.com/Tomoooji)
 * @version 1.0.0
 * @date 2026-09-25
 * @copyright Copyright (c) 2026
 */
#pragma once
#include <cmath>
#if __cplusplus >= 202002L
#include <numbers>
#endif

template <typename T = float>
class Radian2Pi {
private:
  T value;
public:
#if __cplusplus >= 202002L
  static constexpr T PI_FOR_RADIAN = std::numbers::pi_v<T>;
  static constexpr T TWO_PI_FOR_RADIAN = std::numbers::pi_v<T> * 2;
#else
  static constexpr T PI_FOR_RADIAN = T(3.14159265358979323846);
  static constexpr T TWO_PI_FOR_RADIAN = T(6.28318530717958647692);
#endif
  constexpr Radian2Pi(T rad = 0.0f) : value(rad) {}
  constexpr Radian2Pi normalize() const {
    T normalized = fmod(this->value, TWO_PI_FOR_RADIAN);
    if (normalized < 0) {
      normalized += TWO_PI_FOR_RADIAN;
    }
    return Radian2Pi(normalized);
  }
  constexpr Radian2Pi operator+(const Radian2Pi &other) const {
    return Radian2Pi(this->value + other.value).normalize();
  }
  constexpr Radian2Pi operator-(const Radian2Pi &other) const {
    return Radian2Pi(this->value - other.value).normalize();
  }
  constexpr Radian2Pi operator*(T scalar) const {
    return Radian2Pi(this->value * scalar).normalize();
  }
  constexpr Radian2Pi operator/(T scalar) const {
    return Radian2Pi(this->value / scalar).normalize();
  }
  constexpr Radian2Pi operator+=(const Radian2Pi &other) {
    this->value += other.value;
    return *this->normalize();
  }
  constexpr Radian2Pi operator-=(const Radian2Pi &other) {
    this->value -= other.value;
    return *this->normalize();
  }
  constexpr Radian2Pi operator*=(T scalar) {
    this->value *= scalar;
    return *this->normalize();
  }
  constexpr Radian2Pi operator/=(T scalar) {
    this->value /= scalar;
    return *this->normalize();
  }
  constexpr auto operator<=>(const Radian2Pi &other) const {
    return this->value <=> other.value;
  }
  constexpr auto operator<=>(const T &other) const {
    return this->value <=> other;
  }
  constexpr operator T() const {
    return this->value;
  }
  /*constexpr operator const T&() const {
    return this->value;
  }*/
};

template <typename T = float>
class RadianAbsPi {
private:
  T value;
public:
#if __cplusplus >= 202002L
  static constexpr T PI_FOR_RADIAN = std::numbers::pi_v<T>;
#else
  static constexpr T PI_FOR_RADIAN = T(3.14159265358979323846);
#endif
  constexpr RadianAbsPi(T rad = 0.0f) : value(rad) {}
  constexpr RadianAbsPi normalize() const {
    T normalized = fmod(this->value + PI_FOR_RADIAN, 2 * PI_FOR_RADIAN) - PI_FOR_RADIAN;
    return RadianAbsPi(normalized);
  }
  constexpr RadianAbsPi operator+(const RadianAbsPi &other) const {
    return RadianAbsPi(this->value + other.value).normalize();
  }
  constexpr RadianAbsPi operator-(const RadianAbsPi &other) const {
    return RadianAbsPi(this->value - other.value).normalize();
  }
  constexpr RadianAbsPi operator*(T scalar) const {
    return RadianAbsPi(this->value * scalar).normalize();
  }
  constexpr RadianAbsPi operator/(T scalar) const {
    return RadianAbsPi(this->value / scalar).normalize();
  }
  constexpr RadianAbsPi operator+=(const RadianAbsPi &other) {
    this->value += other.value;
    return *this->normalize();
  }
  constexpr RadianAbsPi operator-=(const RadianAbsPi &other) {
    this->value -= other.value;
    return *this->normalize();
  }
  constexpr RadianAbsPi operator*=(T scalar) {
    this->value *= scalar;
    return *this->normalize();
  }
  constexpr RadianAbsPi operator/=(T scalar) {
    this->value /= scalar;
    return *this->normalize();
  }
  constexpr auto operator<=>(const RadianAbsPi &other) const {
    return this->value <=> other.value;
  }
  constexpr auto operator<=>(const T &other) const {
    return this->value <=> other;
  }
  constexpr operator T() const {
    return this->value;
  }
  /*constexpr operator const T&() const {
    return this->value;
  }*/
};