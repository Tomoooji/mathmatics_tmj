/**
 * @file Radian.h
 * @brief ちゃんとコンポジションにしたラジアンのクラス
 * 
 * @author Tomoooji (https://github.com/Tomoooji)
 * @version 1.0.0
 * @date 2026-10-02
 * @copyright Copyright (c) 2026
 */
#pragma once
#include <cmath>
#if __cplusplus >= 202002L
#include <numbers>
#endif

template <typename T>
class Radian2Pi;

template <typename T>
class RadianAbsPi;

template <typename T = float>
class Radian2Pi {
private:
  T value;
public:
#if __cplusplus >= 202002L
  static constexpr T PI_FOR_RADIAN_ = std::numbers::pi_v<T>;
  static constexpr T TWO_PI_FOR_RADIAN_ = std::numbers::pi_v<T> * 2;
#else
  static constexpr T PI_FOR_RADIAN_ = T(3.14159265358979323846);
  static constexpr T TWO_PI_FOR_RADIAN_ = T(6.28318530717958647692);
#endif
  constexpr Radian2Pi(T rad = 0.0f) : value(rad) {}
  constexpr Radian2Pi normalize() const {
    T normalized = fmod(this->value, TWO_PI_FOR_RADIAN_);
    while (normalized < 0) {
      normalized += TWO_PI_FOR_RADIAN_;
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
  constexpr RadianAbsPi<T> toAbsPi() const;
};

template <typename T = float>
class RadianAbsPi {
private:
  T value;
public:
#if __cplusplus >= 202002L
  static constexpr T PI_FOR_RADIAN_ = std::numbers::pi_v<T>;
  static constexpr T TWO_PI_FOR_RADIAN_ = std::numbers::pi_v<T> * 2;
#else
  static constexpr T PI_FOR_RADIAN_ = T(3.14159265358979323846);
  static constexpr T TWO_PI_FOR_RADIAN_ = T(6.28318530717958647692);
#endif
  constexpr RadianAbsPi(T rad = 0.0f) : value(rad) {}
  constexpr RadianAbsPi normalize() const {
    T prenormalized = fmod(this->value + PI_FOR_RADIAN_, 2 * PI_FOR_RADIAN_);
    while (prenormalized < 0) {
      prenormalized += TWO_PI_FOR_RADIAN_;
    }
    return RadianAbsPi(prenormalized - PI_FOR_RADIAN_);
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
  constexpr Radian2Pi<T>  to2Pi() const;
};

template <typename T>
constexpr RadianAbsPi<T> Radian2Pi<T>::toAbsPi() const {
    return RadianAbsPi<T>(value);
}

template <typename T>
constexpr Radian2Pi<T> RadianAbsPi<T>::to2Pi() const {
    return Radian2Pi<T>(value);
}

constexpr Radian2Pi<float> PI_FOR_RADIAN = Radian2Pi<float>(Radian2Pi<float>::PI_FOR_RADIAN_);
constexpr Radian2Pi<float> TWO_PI_FOR_RADIAN = Radian2Pi<float>(Radian2Pi<float>::TWO_PI_FOR_RADIAN_);