#pragma once
#include "Object.h"



namespace SpellForge
{
	class SpellComponent;
	class SpellObject final : public Object
	{
	public:
		SpellObject();
		virtual ~SpellObject();

		void Update(float deltaTime) override;
		void Render() const override;
	
		SpellObject(const SpellObject& other) = delete;
		SpellObject(SpellObject&& other) = delete;
		SpellObject& operator=(const SpellObject& other) = delete;
		SpellObject& operator=(SpellObject&& other) = delete;

		void SetName(std::wstring& name) { m_Name = name; }
		std::wstring GetName() const { return m_Name; }
		static unsigned int GetObjectCount() { return m_NumberOfSpellObjects; }

		void AddComponent(SpellComponent* pComp);
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
		std::vector<SpellComponent*> m_pSpellComponents;

		std::wstring m_Name = L"Spell: " + std::to_wstring(m_NumberOfSpellObjects);
		static unsigned int m_NumberOfSpellObjects;
	};
}
