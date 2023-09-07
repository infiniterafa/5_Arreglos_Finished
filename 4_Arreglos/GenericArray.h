#pragma once
#include <iostream>
//#include "Entity.h"
//#include "Weapon.h"
//#include "Character.h"	

#define OUTOFRANGE_MSG "Indice fuera de borda :v" 

template <typename T> 
class GenericArray
{
	size_t size;
	T* array;

public:

	//constructor predeterminado, hace un arr vacio
	GenericArray()
	{
		size = 0;
		array = new T[0]; //nullptr
	}
	GenericArray(size_t newsize)
	{
		size = newsize;
		array = new T[newsize];
	}
	~GenericArray()
	{
		//if (array != nullptr)
		//{
			delete[] array;
			array = nullptr;
			size = 0;
		//}
	}

	T& operator[](size_t index)
	{
		if (index >= size)
		{
			throw std::out_of_range(OUTOFRANGE_MSG);
		}
		return array[index];
	}

	T get(size_t index)
	{
		if (index >= size)
		{
			throw std::out_of_range(OUTOFRANGE_MSG);
		}
		return array[index];
	}
	void set(size_t index, const T& value)
	{
		if (index >= size)
		{
			throw std::out_of_range(OUTOFRANGE_MSG);
		}
		array[index] = value;
	}


	void resize(size_t newSize)
	{
		T* newdata = new T[newSize];
		if (newSize < size)
		{
			for (int i = 0; i < newSize; i++)
			{
				newdata[i] = array[i];
			}
			delete[] array;
			array = newdata;
			size = newSize;
		}
		else if (size == 0)
		{
			//array ya viene null, no hay que delete
			array = newdata;
			size = newSize;
		}
		else //si es mas grande 
		{
			for (int i = 0; i < size; i++)
			{
				newdata[i] = array[i];
			}
			delete[] array;
			array = newdata;
			size = newSize;
		}
	}

	size_t getsize() const
	{
		return size;
	}

	size_t sizebytes()
	{
		return sizeof(T);
	}

	//listar e imprimir el contenido del arreglo
	void listContents()
	{
		for (int i = 0; i < size; i++)
		{
			std::cout << "[" << i << "] = " << array[i] << std::endl; 
		}
	}

	//ADD
	T* Add(T newitem)

	{
		resize(size + 1);
		array[size-1] = newitem;
		return &newitem;
	}
};



