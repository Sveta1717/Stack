// Stack.

#include "Stack.h"


   // Stack::Stack();

   void  Stack::Clear()
    {
       list.Clear();
    }    

    bool  Stack::IsEmpty()
    {
        return list.IsEmpty();;
    }

    bool  Stack::IsFull()
    {
        return list.GetCount() == size;
    }

    int  Stack::GetCount()
    {
        return list.GetCount();
    }

    void  Stack::Push(int value)
    {
        if (!IsFull())
        {
            list.AddToTail(value);
            int count = list.GetCount();
            count++;
            list.Print();
        }

        else
        {
            throw "Stack overflow!";
        }
    }

    void  Stack::Pop()
    {
        if (!IsEmpty())
        {
           
           list.DeleteFromHead();
           int count = list.GetCount();
           count--;
           list.Print();
        }
        else
        {
            throw "Stack overflow!";
        }
    }

    int  Stack::Peek()
    {
        if (!IsEmpty())
        {
            return list.GetElementByIndex(list.GetCount() - 1);
        }
        else
        {
            throw "Stack overflow!";
        }
    }

    bool  Stack::Contains(int value)
    {
        return list.Contains(value);
    }
