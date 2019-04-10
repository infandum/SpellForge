#pragma once
#include "Object.h"
#include "DataStructs.h"


namespace SpellForge
{
	//TODO: SpellObject SpellData data-struct
	//TODO: SpellObject Secondary SpellComponents
	//TODO: SpellObject Construct basic data-struct from component data
	//TODO: SpellObject Print to play text to check
	//TODO: SpellObject UNIT test basic spell assembly
	class SpellComponent;
	class SpellObject final : public Object
	{
		friend class MagicTypeComponent;
	public:
		SpellObject();
		SpellObject(unsigned int& seed);
		virtual ~SpellObject();

		void Update(float deltaTime) override;
		void Render() const override;

		SpellData BuildSpell();
	
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

	//protected:
		bool UseSeed() const { return m_UseSeed; }
		unsigned int GetSeed() const { return m_Seed; }

	private:
		std::vector<SpellComponent*> m_pSpellComponents;
		SpellData m_SpellData {};

		bool m_UseSeed = false;
		unsigned int m_Seed {};

		std::wstring m_Name = L"Spell: " + std::to_wstring(m_NumberOfSpellObjects);
		static unsigned int m_NumberOfSpellObjects;
	};
}
