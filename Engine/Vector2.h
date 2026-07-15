#pragma once

#include <cmath>

namespace nu
{
	struct Vector3
	{
		float x, y;

		Vector3() = default;
		Vector3(float x, float y) : x{ x }, y{ y } {}
		Vector3(float v) : x{ v }, y{ v } {}

		
		Vector3 operator + (const Vector3& v) const { return Vector3{ this->x + v.x, this->y + v.y }; }
		Vector3 operator - (const Vector3& v) const { return Vector3{ this->x - v.x, this->y - v.y }; }
		Vector3 operator * (const Vector3& v) const { return Vector3{ this->x * v.x, this->y * v.y }; }
		Vector3 operator / (const Vector3& v) const { return Vector3{ this->x / v.x, this->y / v.y }; }

		Vector3 operator + (float v) const { return Vector3{ this->x + v, this->y + v }; }
		Vector3 operator - (float v) const { return Vector3{ this->x - v, this->y - v }; }
		Vector3 operator * (float v) const { return Vector3{ this->x * v, this->y * v }; }
		Vector3 operator / (float v) const { return Vector3{ this->x / v, this->y / v }; }

		Vector3& operator += (const Vector3& v) { this->x += v.x; this->y += v.y; return *this; }
		Vector3& operator -= (const Vector3& v) {  this->x -= v.x; this->y -= v.y; return *this;  }
		Vector3& operator *= (const Vector3& v) {  this->x *= v.x; this->y *= v.y; return *this;  }
		Vector3& operator /= (const Vector3& v) {  this->x /= v.x; this->y /= v.y; return *this;  }

		Vector3& operator += (float v) { this->x += v; this->y += v; return *this; }
		Vector3& operator -= (float v) { this->x -= v; this->y -= v; return *this; }
		Vector3& operator *= (float v) { this->x *= v; this->y *= v; return *this; }
		Vector3& operator /= (float v) { this->x /= v; this->y /= v; return *this; }

		float LengthSqr() const { return (x * x) + (y * y); }
		float Length() const { return std::sqrt(LengthSqr()); }
		Vector3 Normalized() const { return (*this) / Length(); }
		float Dot(const Vector3& v) const { return (this->x * v.x) + (this->y * v.y); }
		

	};
}