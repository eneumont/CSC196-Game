#pragma once
#include <cmath>

namespace bunny {
	constexpr float PI = 3.14159265359f;
	constexpr float TwoPI = 6.28318530718f;
	constexpr float HalfPI = 1.57079632679f;

	constexpr float RadiansToDegrees(float radians) { return radians * (180.0f / PI); }
	constexpr float DegreesToRadians(float degrees) { return degrees * (PI / 180.0f); }

	constexpr int Wrap(int value, int max) {
		return (value % max) + ((value < 0) ? max : 0);
	}
}