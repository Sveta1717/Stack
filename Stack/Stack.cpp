// Stack.

#include "Stack.h"


   // Stack::Stack();

   void  Stack::Clear()
    {
       count = 0;
    }    

    bool  Stack::IsEmpty()
    {
        return count == 0;
    }

    bool  Stack::IsFull()
    {
        return count == size;
    }

    int  Stack::GetCount()
    {
        return count;
    }

    void  Stack::Push(int value)
    {
        if (!IsFull())
        {
            head.AddToTail(value);
            count++;
        }

        else
        {
            throw "Stack overflow!";
        }
    }

    int  Stack::Pop()
    {
        if (!IsEmpty())
        {
            return head[--count];
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
            return head[count - 1];
        }
        else
        {
            throw "Stack overflow!";
        }
    }

    bool  Stack::Contains(int value)
    {
        return head.Contains(value);
    }

   
   





