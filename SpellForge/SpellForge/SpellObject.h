#pragma once
#include "SpellComponent.h"
#include <typeinfo>
#include <vector>
#include <string>
#include <iostream>

namespace SpellForge
{
	class SpellObject
	{
	public:
		SpellObject() = default;
		virtual ~SpellObject() = default;
		SpellObject(const SpellObject& other) = delete;
		SpellObject(SpellObject&& other) = delete;
		SpellObject& operator=(const SpellObject& other) = delete;
		SpellObject& operator=(SpellObject&& other) = delete;

		static unsigned int GetObjectCount() { return m_NumberOfGameObjects; }
		void SetName(std::wstring& name) { m_Name = name; }
		std::wstring GetName() const { return m_Name; }

	protected:
		void AddComponent(SpellComponent* comp);
		void RemoveComponent(SpellComponent* pComp);

		template <class T>
		T* GetComponent()
		{
			const auto& ti = typeid(T);
			for (auto &component : m_pSpellComponents)
			{
				if (component && typeid(*component) == ti)
					return static_cast<T*>(component);
			}
			return nullptr;
		}
	private:
		std::wstring m_Name = L"Spell: " + std::to_wstring(m_NumberOfGameObjects);
		std::vector<SpellComponent*> m_pSpellComponents;
		static unsigned int m_NumberOfGameObjects;
	};
}
