#pragma once
#pragma once
#include "Library.h"


class SinglyLinkedList
{
public:
	struct Node
	{
		int data = 0; // поле данных
		Node* next = nullptr; // указатель на следующий элемент
	};

private:
	Node* head = nullptr; // голова
	Node* tail = nullptr; // хвост
	int count = 0;

public:
	SinglyLinkedList();
	SinglyLinkedList(const SinglyLinkedList& original);
	~SinglyLinkedList();
	void AddToHead(int data);
	void AddToTail(int data);
	void InsertInto(int data, int position);
	void DeleteFromHead();
	void DeleteFromTail();
	void DeleteByIndex(int position);
	void Clear();
	void Print() const;
	int GetCount() const;
	int GetElementByIndex(int index);
	int IndexOf(int data) const;
	bool IsEmpty() const;
	int LastIndexOf(int data);
	void Reverse();
	void SortAsc();
	void SortDesc();
	void Shuffle();
	bool Equals(const SinglyLinkedList* list) const;
	SinglyLinkedList Clone() const;
	bool Contains(int data) const;
	void SetAt(int position, int d);
	int* ToArray();
	SinglyLinkedList MergeWith(const SinglyLinkedList& list);
	bool operator <(const SinglyLinkedList& list);
	bool operator >(const SinglyLinkedList& list);
	bool operator <=(const SinglyLinkedList& list);
	bool operator >=(const SinglyLinkedList& list);
	bool operator ==(const SinglyLinkedList& list);
	bool operator !=(const SinglyLinkedList& list);
	SinglyLinkedList& operator =(const SinglyLinkedList& list);
	const int& operator [](int index) const;
	SinglyLinkedList& operator +(const SinglyLinkedList& list);
	operator int* ();
};

