// SpellForge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include "SpellObject.h"
#include "MagicTypeComponent.h"
#include "CastTypeComponent.h"
#include "RangeTypeComponent.h"

int main()
{
    std::cout << "\n---The Spell Forge---\n";
	auto spell = std::make_shared<SpellForge::SpellObject>();
	spell->AddComponent(new SpellForge::CastTypeComponent());
	spell->AddComponent(new SpellForge::MagicTypeComponent());
	//spell->AddComponent(new SpellForge::MagicTypeComponent(SpellForge::MagicType::MAGIC_FIRE));
	spell->AddComponent(new SpellForge::RangeTypeComponent());
	//spell->GetComponent<SpellForge::MagicTypeComponent>()->SetMagicType(SpellForge::MagicType::MAGIC_FIRE);


	auto data = spell->BuildSpell();
	//obj->AddComponent(new SpellForge::CastTypeComponent());
	//obj->RemoveComponent(new SpellForge::MagicTypeComponent());

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
