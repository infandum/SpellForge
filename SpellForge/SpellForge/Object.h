#pragma once
#include "Target.h"

namespace SpellForge
{
	class Object : public Target
	{
	public:
		virtual void Update(float deltaTime) = 0;
		virtual void Render() const = 0;

		Object() = default;
		virtual ~Object() = default;
		Object(const Object& other) = delete;
		Object(Object&& other) = delete;
		Object& operator=(const Object& other) = delete;
		Object& operator=(Object&& other) = delete;
	};
}
