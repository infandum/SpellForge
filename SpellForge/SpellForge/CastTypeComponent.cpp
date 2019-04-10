#include "pch.h"
#include "CastTypeComponent.h"
#include "SpellObject.h"

SpellForge::CastTypeComponent::CastTypeComponent() = default;

SpellForge::CastTypeComponent::CastTypeComponent(const CastType type)
{
	m_Casttype = type;
}

void SpellForge::CastTypeComponent::BuildSpell()
{
	if (m_Casttype != CastType::CAST_TYPE_MAX_COUNT)
		return;

	if (GetSpellObject()->UseSeed())
		srand(GetSpellObject()->GetSeed());

	m_Casttype = CastType(rand() % int(CastType::CAST_TYPE_MAX_COUNT));
}

void SpellForge::CastTypeComponent::Update(float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);
}

void SpellForge::CastTypeComponent::Render() const
{

}