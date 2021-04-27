#pragma once

#include "../List/List.h"
#include <iostream>
#include <exception>

template <typename Type, typename Key>
class HashTable
{
private:
	int elemSize;
	int hashSize;
	List<Type>* hashArray;
	int(*hashfunc)(Key keyval);
	Key(*keyfunc)(Type data);
public:
	HashTable(int _hashSize, int(*hf)(Key), Key(*kf)(Type));
	~HashTable();
	void insert(const Type& data);
	bool remove(const Type& data);
	bool find(const Type& data, Type& result);
	void print();
};

template <typename Type, typename Key>
HashTable<Type, Key>::HashTable(int _hashSize,
	int(*hf)(Key),
	Key(*kf)(Type))
{
	if (_hashSize < 1)
		throw std::runtime_error("Wrong hash array size");

	elemSize = 0;
	hashSize = _hashSize;
	hashfunc = hf;
	keyfunc = kf;
	hashArray = new List<Type>[hashSize];
}

template <typename Type, typename Key>
HashTable<Type, Key>::~HashTable()
{
	delete[] hashArray;
}

template <typename Type, typename Key>
void HashTable<Type, Key>::insert(const Type& data)
{
	Key keyval = keyfunc(data);
	hashArray[hashfunc(keyval)].push_back(data);
}

template <typename Type, typename Key>
bool HashTable<Type, Key>::remove(const Type& data)
{
	Key keyval = keyfunc(data);
	return hashArray[hashfunc(keyval)].remove(data);
}

template <typename Type, typename Key>
bool HashTable<Type, Key>::find(const Type& data, Type& result)
{
	Key keyval = keyfunc(data);
	int h = hashfunc(keyval);
	auto it = hashArray[h].find(data);
	if (it == hashArray[h].end())
		return false;
	result = *it;
	return true;
}

template <typename Type, typename Key>
void HashTable<Type, Key>::print()
{
	for (int i = 0; i < hashSize; ++i)
	{
		std::cout << "[" << i << "]: ";
			for (auto const& elem : hashArray[i])
				std::cout << elem << " ";
		std::cout << "\n";
	}
}