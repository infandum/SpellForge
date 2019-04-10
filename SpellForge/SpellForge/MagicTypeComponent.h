#pragma once
#include "SpellComponent.h"
#include "DataStructs.h"

namespace SpellForge
{
	//TODO: Magic type read from file
	//TODO: Magic type damage range
	//TODO: Magic type time modifier
	//TODO: Magic type range modifier
	//TODO: Magic type duration modifier
	//TODO: Magic type after effects?
	//TODO: Magic type tiers
	class MagicTypeComponent : public SpellComponent
	{
		//friend class SpellObject;
	public:
		MagicTypeComponent();
		explicit MagicTypeComponent(const MagicType type);
		virtual ~MagicTypeComponent() = default;

		void Update(float deltaTime) override;
		void Render() const override;

		MagicTypeComponent(const MagicTypeComponent& other) = delete;
		MagicTypeComponent(MagicTypeComponent&& other) noexcept = delete;
		MagicTypeComponent& operator=(const MagicTypeComponent& other) = delete;
		MagicTypeComponent& operator=(MagicTypeComponent&& other) noexcept = delete;

	//protected:
		void BuildSpell() override;

		MagicType GetMagicType() const { return m_MagicType; }
		void SetMagicType(const MagicType type) { m_MagicType = type; }

	private:
		MagicType m_MagicType = MagicType::MAGIC_TYPE_MAX_COUNT;
	};
}