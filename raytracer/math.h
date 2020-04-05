#pragma once
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>

template <size_t DIM, typename T> struct vec {
	vec() {
		for (size_t i = DIM; i--; data_[i] = T());
	}
	T& operator[](const size_t i) { assert(i < DIM); return data_[i]; }
	const T& operator[](const size_t i) const { assert(i < DIM); return data_[i]; }
private:
	T data_[DIM];
};

typedef vec<2, float> Vec2f;
typedef vec<3, float> Vec3f;
typedef vec<4, float> Vec4f;
typedef vec<3, int> Vec3i;

template<typename T>struct vec<2, T> {
	vec() :x(T()), y(T()) {}
	vec(T X, T Y) :x(X), y(Y) {}
	template<class U> vec<2, T>(const vec<2, U>& v);
	T& operator[](const size_t i) { assert(i < 2); return i <= 0 ? x : y; }
	const T& operator[](const size_t i) const { assert(i < 2); return i <= 0 ? x : y; }
	T x, y;
};

template<typename T>struct vec<3, T> {
	vec() :x(T()), y(T()), z(T()) {}
	vec(T X, T Y, T Z) :x(X), y(Y), z(Z) {}
	T& operator[](const size_t i) { assert(i < 3); return i <= 0 ? x : (i == 1 ? y : z); }
	const T& operator[](const size_t i) const { assert(i < 3); return i <= 0 ? x : (i == 1 ? y : z); }
	float norm() {
		return std::sqrt(x * x + y * y + z * z);
	}
	vec<3, T>& normalize(T len = 1) {
		*this = (*this) * (len / norm());
		return *this;
	}
	T x, y, z;
};

template<typename T>struct vec<4, T> {
	vec() :x(T()), y(T()), z(T()), w(T()) {}
	vec(T X, T Y, T Z, T W) :x(X), y(Y), z(Z), w(W) {}
	T& operator[](const size_t i) { assert(i < 4); return i <= 0 ? x : (i == 1 ? y : (i == 2 ? z : w));}
	const T& operator[](const size_t i) const { assert(i < 4); return i <= 0 ? x : (i == 1 ? y : (i == 2 ? z : w)); }
	T x, y, z, w;
};

template<size_t DIM, typename T> std::ostream& operator<<(std::ostream& os, const vec<DIM, T>& v) {
	for (size_t i = 0; i < DIM; ++i) os << v[i] << " ";
	return os;
}


