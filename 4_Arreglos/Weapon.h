#pragma once
#include "Entity.h"

class Weapon : public Entity
{
	int Damage;
	int Ammo;

public:
	enum EType{ melee, ranged } type;

	
	void attack(Entity entiti);
	void giveAmmo(int newAmmo );

	Weapon();
	Weapon(const char* _name, int _ammo, EType _type, int _damage);
};


template<>
inline void GenericArray<Weapon>::listContents()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "[" << i << "] = " << array[i].toString() << std::endl;
	}
}
