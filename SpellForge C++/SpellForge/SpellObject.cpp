#include "pch.h"
#include "SpellObject.h"
#include "SpellComponent.h"
#include "MagicTypeComponent.h"


unsigned int SpellForge::SpellObject::m_NumberOfSpellObjects = 0;

SpellForge::SpellObject::SpellObject()
{
	m_SpellData.id = m_NumberOfSpellObjects;
	++m_NumberOfSpellObjects;
}

SpellForge::SpellObject::SpellObject(unsigned int& seed)
{
	m_SpellData.id = m_NumberOfSpellObjects;
	++m_NumberOfSpellObjects;
	m_Seed = seed;
	srand(m_Seed);
	m_UseSeed = true;
}

SpellForge::SpellObject::~SpellObject()
{
	for (auto& m_pSpellComponent : m_pSpellComponents)
		delete m_pSpellComponent;
	m_pSpellComponents.clear();

	delete m_SpellData.target;
}

void SpellForge::SpellObject::Update(float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);
}

void SpellForge::SpellObject::Render() const
{

}

SpellForge::SpellData SpellForge::SpellObject::BuildSpell()
{
	for (auto& component : m_pSpellComponents)
	{
		component->BuildSpell();
	}
	m_SpellData.name = m_Name;
	m_SpellData.magicType = GetComponent<MagicTypeComponent>()->GetMagicType();
	//Range
	
	//Cast Time

	m_SpellData.target = new Target();

	//Damage

	return m_SpellData;
}

void SpellForge::SpellObject::AddComponent(SpellComponent* pComp)
{
	for (auto& component : m_pSpellComponents)
	{
		if (typeid(*component) == typeid(*pComp))
		{
			std::wcout << L"Component Add:: " << typeid(*pComp).name() << L" >> DUPLICATE!!\n";
			delete pComp;
			return;
		}
	}
	//std::wcout << L"Component Add:: " << typeid(*pComp).name() << L" >> ADDED!!\n";
	m_pSpellComponents.push_back(pComp);
	pComp->SetOwner(this);
}

void SpellForge::SpellObject::RemoveComponent(SpellComponent* pComp)
{
	for (size_t i = 0; i < m_pSpellComponents.size(); ++i)
	{
		const auto listComp = m_pSpellComponents[i];
		if (typeid(*listComp) == typeid(*pComp))
		{
			//std::cout << "Component Remove:: " << typeid(*pComp).name() << " >> REMOVED!!\n";
			delete m_pSpellComponents[i];			
			delete pComp;
			m_pSpellComponents.erase(m_pSpellComponents.begin() + i);
			return;
		}
	}
	delete pComp;
	std::wcout << L"Component Remove:: " << typeid(*pComp).name() << L" >> NOT ATTACHED!!"<< std::endl;
}
