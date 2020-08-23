#include "pch.h"
#include "RangeTypeComponent.h"
#include "SpellObject.h"

SpellForge::RangeTypeComponent::RangeTypeComponent() = default;

SpellForge::RangeTypeComponent::RangeTypeComponent(const RangeType type)
{
	m_RangeType = type;
}

void SpellForge::RangeTypeComponent::BuildSpell()
{
	if (m_RangeType != RangeType::RANGE_TYPE_MAX_COUNT)
		return;

	if (GetSpellObject()->UseSeed())
		srand(GetSpellObject()->GetSeed());

	m_RangeType = RangeType(rand() % int(RangeType::RANGE_TYPE_MAX_COUNT));
}

void SpellForge::RangeTypeComponent::Update(float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);
}

void SpellForge::RangeTypeComponent::Render() const
{
}
