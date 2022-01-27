#include "Stack.h"

int main()
{
    //stack<int, SinglyLinkedList> st;
    Stack st;
    cout << "Empty? " << st.IsEmpty() << "\n";
    /* st.push(1);
     st.push(2);
     st.push(3);
     st.push(4);
     st.push(5);
     auto a = st._Get_container();*/
    while (!st.IsFull())
    {
        st.Push(rand() % 10 + 10);
    }

    cout << st.Peek() << "\n";

    while (!st.IsEmpty())
    {
        cout << st.Pop() << ",";
    }
    cout << "\n";

}