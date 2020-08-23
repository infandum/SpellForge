#pragma once

namespace SpellForge{
	class Target
	{
	public:
		//virtual void Update(float deltaTime) = 0;
		//virtual void Render() const = 0;

		Target();
		virtual ~Target() = default;

		Target(const Target& other) = delete;
		Target(Target&& other) = delete;
		Target& operator=(const Target& other) = delete;
		Target& operator=(Target&& other) = delete;
	};
}