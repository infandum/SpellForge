#pragma once
#include "SpellComponent.h"

namespace SpellForge
{
	class CastTypeComponent : public SpellComponent
	{
	public:
		CastTypeComponent();
		virtual ~CastTypeComponent() = default;

		void Update(float deltaTime) override;
		void Render() const override;

		CastTypeComponent(const CastTypeComponent& other) = delete;
		CastTypeComponent(CastTypeComponent&& other) noexcept = delete;
		CastTypeComponent& operator=(const CastTypeComponent& other) = delete;
		CastTypeComponent& operator=(CastTypeComponent&& other) noexcept = delete;
	};
}