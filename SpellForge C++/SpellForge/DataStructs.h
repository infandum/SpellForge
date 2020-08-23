#pragma once
#include "Target.h"

namespace SpellForge
{
	struct float2
	{
		float x;
		float y;
		float2(float a, float b)
		{
			x = a;
			y = b;
		}
	};

	enum class MagicType
	{
		MAGIC_ARCANA,
		MAGIC_FIRE,
		MAGIC_WATER,
		MAGIC_WIND,
		MAGIC_EARTH,
		/*MAGIC_SPIRITUAL,
		MAGIC_NECROMANCY,
		MAGIC_DIVINE,
		MAGIC_DEMONIC,*/
		MAGIC_TYPE_MAX_COUNT
	};

	struct MagicData
	{
		MagicType type = MagicType::MAGIC_TYPE_MAX_COUNT;
		float damage = 0.0f;
		float castModifier = 0.0f;
		float rangeModifier = 0.0f;
		float durationModifier = 0.0f;
	};

	enum class CastType
	{
		CAST_PROJECTILE,
		CAST_TARGET,
		CAST_TEMPLATE,
		CAST_SUMMON,
		/*CAST_PROJECTILE_BOLT,
		CAST_PROJECTILE_BALL,
		CAST_TARGET_BOLT,
		CAST_TARGET_BALL,
		CAST_TEMPLATE_VLINE,
		CAST_TEMPLATE_HLINE,
		CAST_TEMPLATE_CONE,
		CAST_TEMPLATE_CIRCLE,*/
		CAST_TYPE_MAX_COUNT
	};

	enum class RangeType
	{
		RANGE_SELF,
		RANGE_SHORT,
		RANGE_MEDIUM,
		RANGE_LONG,
		RANGE_TOUCH,
		RANGE_TYPE_MAX_COUNT
	};

	struct SpellData
	{
		
		int id = 0;
		std::wstring name;
		MagicType magicType;
		float range = 0.0f;
		float castTime = 0.0f;
		Target* target = nullptr;
		float2 damage {0, 0};
		//Effect?
		//Duration?
		//cooldown?
	};
}
