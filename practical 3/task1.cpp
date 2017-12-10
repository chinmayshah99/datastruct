/*
  Write an algorithm\Program that creates a queue from a stack. 
  After the queue has been created, the top of the stack should be the front of the queue and 
  the base of the stack should be the rear of the queue. 
  At the end of the algorithm, the stack should be empty.
*/
// Chinmay Shah

#include <iostream>

using namespace std;

int size;
int top_1 = -1, top_2 = -1;
int pop(int a[], int &top);
void push(int a[], int &top, int element);

int main()
{
    cout << "enter size" << endl;
    cin >> size;
    int a[size], b[size];
    cout << "enter elements" << endl;
    for (int i = 0; i < size; i++)
    {
        int temp;
        cin >> temp;
        push(a, top_1, temp);
    }

    for (int i = 0; i < size; i++)
        push(b, top_2, pop(a, top_1));

    for (int i = 0; i < size; i++)
        cout << pop(b, top_2);
}

// pop operation of stack
int pop(int a[], int &top)
{
    if (top == -1)
        cerr << "under flow" << endl;
    else
    {
        top--;
        return a[(top + 1)];
    }
}

// push operation of stack
void push(int a[], int &top, int element)
{
    if (top == size - 1)
        cerr << "stack overflow" << endl;
    else
    {
        top++;
        a[top] = element;
    }
}
