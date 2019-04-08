#pragma once

namespace SpellForge
{
	class SpellObject;
	class SpellComponent
	{
		friend class SpellObject;
	public:
		SpellComponent() = default;
		virtual ~SpellComponent() = default;

		virtual void Update(float deltaTime) = 0;
		virtual void Render() const = 0;

		void SetOwner(SpellObject* owner) { m_pOwner = owner; }
		SpellObject* GetSpellObject() const { return m_pOwner; }

		SpellComponent(const SpellComponent& other) = delete;
		SpellComponent(SpellComponent&& other) noexcept = delete;
		SpellComponent& operator=(const SpellComponent& other) = delete;
		SpellComponent& operator=(SpellComponent&& other) noexcept = delete;
		
	protected:
		SpellObject* m_pOwner{};
	};
}
