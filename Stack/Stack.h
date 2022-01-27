#pragma once
#include "SinglyLinkedList.h"

class Stack
{
public:
    // Stack();
    void Clear();
    bool IsEmpty();
    bool IsFull();
    int GetCount();
    void Push(int value);
    int Pop();
    int Peek();
    bool Contains(int value);

private:
    SinglyLinkedList head; //указатель на вершину стека
    int count; // количество элементов в стеке
    int size = 10;
};
