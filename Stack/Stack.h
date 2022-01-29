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
    void Pop();
    int Peek();
    bool Contains(int value);

private:
    SinglyLinkedList list; //��������� �� ������� �����
    //int count; // ���������� ��������� � �����
    static int const size = 10;
};
