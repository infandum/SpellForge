#include "pch.h"
#include "SpellObject.h"
#include "SpellComponent.h"


unsigned int SpellForge::SpellObject::m_NumberOfSpellObjects = 0;

SpellForge::SpellObject::SpellObject()
{
	++m_NumberOfSpellObjects;
}

SpellForge::SpellObject::~SpellObject()
{
	for (auto& m_pSpellComponent : m_pSpellComponents)
		delete m_pSpellComponent;
	m_pSpellComponents.clear();
}

void SpellForge::SpellObject::Update(float deltaTime)
{
	UNREFERENCED_PARAMETER(deltaTime);
}

void SpellForge::SpellObject::Render() const
{

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
