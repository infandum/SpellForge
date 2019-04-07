#pragma once
#include <memory>

namespace SpellForge
{
	class SpellComponent
	{
		friend class SpellObject;
	public:
		virtual void Update(float deltaTime) = 0;
		virtual void Render() const = 0;

		SpellComponent() = default;
		virtual ~SpellComponent() = default;
		SpellComponent(const SpellComponent& other) = delete;
		SpellComponent(SpellComponent&& other) noexcept = delete;
		SpellComponent& operator=(const SpellComponent& other) = delete;
		SpellComponent& operator=(SpellComponent&& other) noexcept = delete;

		std::shared_ptr<SpellObject> GetSpellObject() const { return m_pSpellObject; }
	protected:
		std::shared_ptr<SpellObject> m_pSpellObject{};
	};
}
