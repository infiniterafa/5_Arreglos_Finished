#pragma once
#include "Entity.h"
#include "Weapon.h"

typedef GenericArray<Weapon> Inventory;
class Character :public Entity
{
public: 

	enum EChartype {
		player, npc
	} CharType = EChartype::npc;

	int karma;
	Inventory *weapons;

	//GenericArray<Weapon> myweapons;
	Character();
	Character(const char * _name);

	~Character();

	void SetType(EChartype _type);
	const char* GetType();

	bool hasWeapons();
	void GiveWeapon(Weapon newWeapon);
	
};

template<>
inline void GenericArray<Character>::listContents()
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "[" << i << "] = "
			<< array[i].toString()
			<< "(" << array[i].GetType() << ")";
		if (array[i].hasWeapons())
		{
			std::cout << "trae fierros: ";
			for (int j = 0; j < array[i].weapons->getsize(); j++)
			{
				std::cout << array[i].weapons->get(j).toString() << ", ";
			}
			std::cout << std::endl;
		}
		else
		{
			std::cout << "\n";
		}
	}
}
