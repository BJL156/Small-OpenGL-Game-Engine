#pragma once

namespace Engine {
	class Entity {
	public:
		Entity(float x, float y, float w, float h);

		float x = 0.0f, y = 0.0f;
		float w = 0.0f, h = 0.0f;
	};
}