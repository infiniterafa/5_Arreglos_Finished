#include "Character.h"

Character::Character()
{
	karma = 0;
	weapons = nullptr;
	
}

Character::Character(const char* _name)
{
	karma = 0;
	//weapons = new GenericArray<Weapon>();
	weapons = nullptr;
	name = _name;
}

Character::~Character()
{
	//delete weapons;
}

void Character::SetType(EChartype _type)
{
	CharType = _type;
}

const char* Character::GetType()
{
	if (CharType == EChartype::npc) return "NPC";
	else if (CharType == EChartype::player) return "Player";
}

void Character::GiveWeapon(Weapon newWeapon)
{
	if (weapons == nullptr)
	{
		weapons = new GenericArray<Weapon>(1);
		weapons->set(0, newWeapon);
	}
	else
	{
		weapons->Add(newWeapon);
	}
}

bool Character::hasWeapons()
{
	if (weapons != nullptr)
	{
		return weapons->getsize() > 0;
	}
	return false;
}
