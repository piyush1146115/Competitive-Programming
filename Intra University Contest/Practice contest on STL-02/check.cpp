/*3.	Write a C++ program to implement the following using an array
a) Stack ADT
*/


#include<bits/stdc++.h>
using namespace std;
class Stack
{
    int stk[10];
    int top;

    public:
    Stack()
    {
        top=-1;
    }

   void push(int x)
    {
        if(isFull())
        {
            cout <<"Stack is full";
            return;
        }
        top++;
        stk[top]=x;
        cout <<"Inserted Element:"<<" "<<x;
    }


    bool isFull()
    {
        int size=sizeof(stk)/sizeof(*stk);
        if(top == size-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }


    bool isEmpty()
    {
        if(top==-1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }


    void pop()
    {
        if(isEmpty())
        {
            cout <<"Stack is Empty";
            return;
        }
        cout <<"Deleted element is:" <<" "<<stk[top--];
    }


    void display()
    {
        if(top==-1)
        {
            cout <<" Stack is Empty!!";
            return;
        }
        for(int i=top; i>=0; i--)
        {
            cout <<stk[i] <<" ";
        }
    }
};

int main()
{
    int ch;
    Stack st;
    while(1)
    {
        cout <<"\n1.Push  2.Pop  3.Display  4.Exit \nEnter your choice:";
        cin >> ch;
        switch(ch)
        {
        case 1:
            cout <<"Enter the element you want to push:";
            cin >> ch;
            st.push(ch);
            break;
        case 2:
            st.pop();
            break;
        case 3:
            st.display();
            break;
        case 4:
            cout << "Check" << endl;
            //break;---->eikhane exit(1) dile keno kaj kore na??????
            exit(0);
        default:
            break;
        }

    }

}
