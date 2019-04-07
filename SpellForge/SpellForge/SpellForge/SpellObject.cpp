#include "pch.h"
#include "SpellObject.h"
#include "SpellComponent.h"

void SpellForge::SpellObject::AddComponent(SpellComponent* comp)
{
	for (auto& component : m_pSpellComponents)
	{
		if (typeid(*component) == typeid(*comp))
		{
			std::cout << "Component Duplicate: " << typeid(*comp).name() << " >> Already added!!";
			return;
		}
	}
	m_pSpellComponents.push_back(comp);
	std::shared_ptr<SpellObject> owner;
	owner.reset(this);
	comp->m_pSpellObject = owner;
}

void SpellForge::SpellObject::RemoveComponent(SpellComponent * pComp)
{
	const auto comp = std::find(m_pSpellComponents.begin(), m_pSpellComponents.end(), pComp);
	if (comp == m_pSpellComponents.end())
	{
		std::wcout << L"GameObject::RemoveComponent > Component is not attached to this GameObject!" << std::endl;
		return;
	}
	m_pSpellComponents.erase(comp);
	pComp->m_pSpellObject = nullptr;
}
