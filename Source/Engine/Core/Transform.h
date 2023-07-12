#pragma once
#include "Core/Vector2.h"

namespace bunny {
	class Transform {
	public:
		vec2 position;
		float rotation = 0;
		float scale = 1;

		Transform() = default;
		Transform(const vec2& p, float r, float s = 1) : 
			position{ p }, 
			rotation{ r }, 
			scale{ s } 
		{}
	};
}