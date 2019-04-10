#pragma once
#include "SpellComponent.h"
#include "DataStructs.h"


namespace SpellForge
{
	//TODO: Cast type read from file
	//TODO: Cast type create target Types
	//TODO: Cast type tiers
	class CastTypeComponent : public SpellComponent
	{
		//friend class SpellObject;
	public:
		CastTypeComponent();
		explicit CastTypeComponent(const CastType type);
		virtual ~CastTypeComponent() = default;

		void BuildSpell() override;

		void Update(float deltaTime) override;
		void Render() const override;

		CastTypeComponent(const CastTypeComponent& other) = delete;
		CastTypeComponent(CastTypeComponent&& other) noexcept = delete;
		CastTypeComponent& operator=(const CastTypeComponent& other) = delete;
		CastTypeComponent& operator=(CastTypeComponent&& other) noexcept = delete;

	//protected:
		CastType GetCastType() const { return m_Casttype; }
		void SetCastType(CastType& type) { m_Casttype = type; }

	private:
		CastType m_Casttype = CastType::CAST_TYPE_MAX_COUNT;
	};
}