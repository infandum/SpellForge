#include "pch.h"
#include "MagicTypeComponent.h"
#include "SpellObject.h"

SpellForge::MagicTypeComponent::MagicTypeComponent() = default;

SpellForge::MagicTypeComponent::MagicTypeComponent(const MagicType type)
{
	m_MagicType = type;
}

void SpellForge::MagicTypeComponent::Update(float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);
}

void SpellForge::MagicTypeComponent::Render() const
{

}

void SpellForge::MagicTypeComponent::BuildSpell()
{
	if(m_MagicType != MagicType::MAGIC_TYPE_MAX_COUNT)
		return;
	
	if (GetSpellObject()->UseSeed())
		srand(GetSpellObject()->GetSeed());

	m_MagicType = MagicType(rand() % int(MagicType::MAGIC_TYPE_MAX_COUNT));
}