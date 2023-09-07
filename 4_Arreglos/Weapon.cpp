#include "Weapon.h"

void Weapon::attack(Entity entiti)
{
}

void Weapon::giveAmmo(int newAmmo)
{
}

Weapon::Weapon()
{
	name = "weapon";
	Ammo = 0;
	Damage = 0;
	type = EType::ranged;
}

Weapon::Weapon(const char* _name, int _ammo, EType _type, int _damage)
{
	name = _name;
	Ammo = _ammo;
	Damage = _damage;
	type = _type;
}


