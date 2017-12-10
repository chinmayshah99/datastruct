/*
    Implement operations of stack such as push and pop
------------------------------------------------------------------------
    Checking for palindrome string
    Suppose characters are arriving on a stream reader.
    Suggest an algorithm to see if the string forms a palindrome.
    Capitalization, spacing, and punctuation are ignored
*/
// Chinmay Shah

#include <iostream>
#include <stdlib.h>
using namespace std;

int top = -1;
void push(char[], char ch, int size);
void pop(char[]);
void disp(char[]);
void check(char[]);

int main()
{
    int size;
    cout << "enter size of stack";
    cin >> size;
    char arr[size];
    int op;

    do
    {
        char ch;
        cout << "1. push, 2. pop, 3. check palindrome, 4. exit 5. display" << endl;
        cin >> op;
        if (op == 1)
        {
            cout << "enter character" << endl;
            cin >> ch;
            push(arr, ch, size);
        }
        else if (op == 2)
            pop(arr);
        else if (op == 3)
            check(arr);
        else if (op == 5)
            disp(arr);

    } while (op != 4);

    return 0;
}

// push operation of stack
/*
    if the stack overflows, then exits the program
    in all other cases, it adds the data to the stack
*/
void push(char arr[], char ch, int size)
{
    top++;
    if (top == size)
    {
        cout << "over flowed" << endl;
        return;
    }
    else
    {
        arr[top] = ch;
    }
    cout << "current size " << top + 1 << endl;
}

// pop operation of stack
/*
    if the stack if already empty then program exits
    else just update top pointer to the next element, so that pop operation is done
    doesn't actually remove the data from stack
*/
void pop(char arr[])
{
    if (top == -1)
    {
        cout << "stack already empty" << endl;
        return;
    }
    else
    {
        cout << " " << arr[top--];
    }
}

// checks for palindrome
// does not use concepts of stacks though
void check(char arr[])
{
    for (int i = 0; i < top / 2; i++)
    {
        if (arr[i] != arr[top])
            cout << "not palindrome" << endl;
        return;
    }
    cout << "is a palindrome" << endl;
}

// displays all the elements of stack
// pops all element of stack basically
void disp(char arr[])
{
    while (top != -1)
    {
        pop(arr);
        cout << endl;
    }
}