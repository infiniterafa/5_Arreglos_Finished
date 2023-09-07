#include "Entity.h"

Entity::Entity()
{
	health = 100;
	//std::string e = "Entity";
	//nums aleatorios
	//std::random_device randomizer;
	//std::mt19937 gen(randomizer());
	//std::uniform_int_distribution<int> dist(10000, 99999);
	//name = e.append(std::to_string(dist(gen)));
	name = "entidad";
}

Entity::~Entity()
{
	//puts("destruyendo entidad");
}

const char* Entity::toString()
{
	return name.c_str();
}
