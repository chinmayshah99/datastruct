/*
    Checking for palindrome string
    Suppose characters are arriving on a stream reader.
    Suggest an algorithm to see if the string forms a palindrome.
    Capitalization, spacing, and punctuation are ignored
*/

#include <iostream>
#include <stdlib.h>
using namespace std;


int top = -1;
void push(char [], char ch, int size);
void pop(char [], int size);
void disp(char []);
void check(char []);


int main()
{
    int size;
    cout<<"enter size of stack";
    cin>>size;
    char arr[size];
    int op;

    do{
        char ch;
        cout<<"1. push, 2. pop, 3. check palindrome, 4. exit 5. display"<<endl;
        cin>>op;
        if(op == 1 )
            {
                cout<<"enter character"<<endl;
                cin>>ch;
                push(arr,ch,size);
            }
        else if(op ==2)
            pop(arr,size);
        else if (op == 3)
            check(arr);
        else if(op == 5)
            disp(arr);



    }while(op != 4);

    return 0;
}


void push(char arr[], char ch, int size)
{
    top++;
    if (top == size)
    {
        cout<<"over flowed"<<endl;
        exit(-1);
    }
    else
    {

        arr[top] = ch;
    }
    cout<<top;

}
void pop(char arr[], int size)
{
    if(top == -1)
    {
        cout<<"stack already empty"<<endl;
        exit(-1);
    }
    else
    {
        top--;
    }
}

void check(char arr[])
{
    for (int i = 0; i < top/2;i++)
    {
        if(arr[0] != arr[top])
            cout<<"not palindrome"<<endl;
        exit(0);
    }
    cout<<"is a palindrome"<<endl;
}
void disp(char arr[])
{
    for (int i = 0 ; i <= top; i++)
    {
        cout<<"\n"<<arr[i]<<" "<<endl;
    }
}