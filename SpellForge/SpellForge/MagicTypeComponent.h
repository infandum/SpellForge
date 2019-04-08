#pragma once
#include "SpellComponent.h"
namespace SpellForge
{
	class MagicTypeComponent : public SpellComponent
	{
	public:
		MagicTypeComponent();
		virtual ~MagicTypeComponent() = default;

		void Update(float deltaTime) override;
		void Render() const override;

		MagicTypeComponent(const MagicTypeComponent& other) = delete;
		MagicTypeComponent(MagicTypeComponent&& other) noexcept = delete;
		MagicTypeComponent& operator=(const MagicTypeComponent& other) = delete;
		MagicTypeComponent& operator=(MagicTypeComponent&& other) noexcept = delete;
	};
}