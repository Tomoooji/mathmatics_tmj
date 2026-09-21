#pragma once
#include <complex>
#include "Radian.h"

template <typename T>
class Vector2D {
private:
  std::complex<T> vec;
public:
  Vector2D(T x = 0, T y = 0) : vec(x, y) {}
  static Vector2D<T> fromXY(T x, T y) {
    return Vector2D<T>(x, y);
  }
  static Vector2D<T> fromPolar(T magnitude, RadianAbsPi<T> angle) {
    return Vector2D<T>(std::polar(magnitude, angle));
  }
  static Vector2D<T> fromComplex(const std::complex<T>& c) {
    return Vector2D<T>(c);
  }
  T getX() const {
    return vec.real();
  }
  T X() const { return this->getX(); }
  T getY() const {
    return vec.imag();
  }
  T Y() const { return this->getY(); }
  T getR() const {
    return std::abs(vec);
  }
  T R() const { return this->getR(); }
  RadianAbsPi<T> getTheta() const {
    return RadianAbsPi<T>(std::arg(vec));
  }
  RadianAbsPi<T> Theta() const { return this->getTheta(); }
  std::complex<T> getComplex() const {
    return vec;
  }
  std::complex<T> Complex() const { return this->getComplex(); }
  Vector2D<T> operator-() const {
    return Vector2D<T>::fromComplex(-vec);
  }
  Vector2D<T> operator+(const Vector2D<T>& other) const {
    return Vector2D<T>::fromComplex(vec + other.vec);
  }
  Vector2D<T> operator-(const Vector2D<T>& other) const {
    return Vector2D<T>::fromComplex(vec - other.vec);
  }
  Vector2D<T> operator*(T scalar) const {
    return Vector2D<T>::fromComplex(vec * scalar);
  }
  Vector2D<T> operator/(T scalar) const {
    return Vector2D<T>::fromComplex(vec / scalar);
  }
  Vector2D<T>& operator+=(const Vector2D<T>& other) {
    vec += other.vec;
    return *this;
  }
  Vector2D<T>& operator-=(const Vector2D<T>& other) {
    vec -= other.vec;
    return *this;
  }
  Vector2D<T>& operator*=(T scalar) {
    vec *= scalar;
    return *this;
  }
  Vector2D<T>& operator/=(T scalar) {
    vec /= scalar;
    return *this;
  }
  Vector2D<T> rotate(RadianAbsPi<T> angle) const {
    return Vector2D<T>::fromComplex(vec * std::polar(1.0, angle));
  }
  Vector2D<T> rotateAround(RadianAbsPi<T> angle, const Vector2D<T>& point) const {
    return Vector2D<T>::fromComplex((vec - point.vec) * std::polar(1.0, angle) + point.vec);
  }
  Vector2D<T> scale(T factor) const {
    return Vector2D<T>::fromComplex(vec * factor);
  }
  /* YAGNI: Not used in the project, so commented out for now.
  Vector2D<T> scaleAround(T factor, const Vector2D<T>& point) const {
    return Vector2D<T>::fromComplex((vec - point.vec) * factor + point.vec);
  }
  */
  Vector2D<T> normalize() const {
    T magnitude = std::abs(vec);
    if (magnitude == 0) {
      return Vector2D<T>(0, 0);
    }
    return Vector2D<T>::fromComplex(vec / magnitude);
  }
  T dot(const Vector2D<T>& other) const {
    return vec.real() * other.vec.real() + vec.imag() * other.vec.imag();
  }
  T cross(const Vector2D<T>& other) const {
    return vec.real() * other.vec.imag() - vec.imag() * other.vec.real();
  }
  RadianAbsPi<T> angleBetween(const Vector2D<T>& other) const {
    T dotProduct = this->dot(other);
    T magnitudeProduct = this->getR() * other.getR();
    if (magnitudeProduct == 0) {
      return RadianAbsPi<T>(0);
    }
    return RadianAbsPi<T>(std::acos(dotProduct / magnitudeProduct));
  }
  /* YAGNI: Not used in the project, so commented out for now.
  Vector2D<T> perpendicular() const {
    return Vector2D<T>::fromComplex(std::complex<T>(-vec.imag(), vec.real()));
  }
  Vector2D<T> perpendicularCCW() const {
    return Vector2D<T>::fromComplex(std::complex<T>(-vec.imag(), vec.real()));
  }
  Vector2D<T> perpendicularCW() const {
    return Vector2D<T>::fromComplex(std::complex<T>(vec.imag(), -vec.real()));
  }
  Vector2D<T> projectOnto(const Vector2D<T>& other) const {
    T dotProduct = vec.real() * other.vec.real() + vec.imag() * other.vec.imag();
    T otherMagnitudeSquared = std::norm(other.vec);
    if (otherMagnitudeSquared == 0) {
      return Vector2D<T>(0, 0);
    }
    T projectionFactor = dotProduct / otherMagnitudeSquared;
    return Vector2D<T>::fromComplex(other.vec * projectionFactor);
  }
  Vector2D<T> reflectAcross(const Vector2D<T>& normal) const {
    Vector2D<T> normalizedNormal = normal.normalize();
    T dotProduct = vec.real() * normalizedNormal.vec.real() + vec.imag() * normalizedNormal.vec.imag();
    return Vector2D<T>::fromComplex(vec - 2.0 * dotProduct * normalizedNormal.vec);
  }
  */

};


