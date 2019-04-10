#pragma once
#include "SpellComponent.h"
#include "DataStructs.h"


namespace SpellForge
{
	//TODO: Range type read from file
	//TODO: Range type ranges
	//TODO: Range type tiers
	class RangeTypeComponent : public SpellComponent
	{
		//friend class SpellObject;
	public:
		RangeTypeComponent();
		explicit RangeTypeComponent(const RangeType type);
		virtual ~RangeTypeComponent() = default;

		void BuildSpell() override;

		void Update(float deltaTime) override;
		void Render() const override;

		RangeTypeComponent(const RangeTypeComponent& other) = delete;
		RangeTypeComponent(RangeTypeComponent&& other) noexcept = delete;
		RangeTypeComponent& operator=(const RangeTypeComponent& other) = delete;
		RangeTypeComponent& operator=(RangeTypeComponent&& other) noexcept = delete;

	//protected:
		RangeType GetRangeType() const { return m_RangeType; }
		void SetRangeType(RangeType& type) { m_RangeType = type; }

	private:
		RangeType m_RangeType = RangeType::RANGE_TYPE_MAX_COUNT;
		};
	}
