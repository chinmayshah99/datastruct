// Checking for Balanced Braces in a String
// Chinmay Shah

#include <iostream>
#include <stdlib.h>
using namespace std;

int top = -1;
char arr[100];
int push_counter = 0, pop_counter = 0;
void push(char ch)
{
    top++;
    arr[top] = ch;
    push_counter++;
}
void pop()
{

    cout << top << " " << arr[top] << endl;
    if (top == -1)
    {
        cout << "under flow";
        exit(-1);
    }
    else if (arr[top] == ']' || arr[top] == '}' || arr[top] == ')')
        pop_counter++;

    //cout<<push_counter/2<<pop_counter<<top<<endl;

    if (push_counter / 2 == pop_counter && top == 0)
    {
        cout << "Balanced Braces";
        exit(0);
    }
    top -= 1;
}
int main()
{
    char ch;
    cout << "enter string to check, q to exit" << endl;
    do
    {
        cin >> ch;
        if (ch == '[' || ch == '{' || ch == '(' || ch == ']' || ch == '}' || ch == ')')
        {
            push(ch);
        }
    } while (ch != 'q');

    while (1)
    {
        pop();
    }
    return 0;
}