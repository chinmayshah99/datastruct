// program to sort a stack in ascending using a temporary stack.

// NOT WORKING

/*
    The code doesn’t work as expected. 
    There is some problem in dealing with copying data 
    from one array to other resulting in duplication of data.    
*/

#include <iostream>

#define size 5

using namespace std;
int arr_top = -1, temp_top = -1;

int arr[size] ;
int temp[size];
void push(int arr[], int ch, int &top);
int pop(int arr[], int &top);
void sort1();



void disp(int arr[])
{
    for (int i = 0 ; i <= size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{

    int tem []={34,3,31,98,23};
    for(int i = 0 ; i <size; i++ )
        push(arr,tem[i], arr_top);

    for(int i = 0 ; i <size; i++ )
        cout<<arr[i]<<" ";

    sort1();

    return 0;
}


void push(int arr[], int ch, int &top)
{
    cout<<"\n\t"<<top<<endl;
    top++;
    if (top == size)
    {
        cout<<"over flowed"<<endl;
        //exit(-1);
    }
    else
        arr[top] = ch;
}

int pop(int arr[], int &top)
{
    if(top == -1)
    {
        cout<<"stack already empty"<<endl;
//        exit(-1);
    }
    else
    {
        top--;
        return arr[top+1];
    }
}


void sort1()
{
    int r1;
    push(temp,pop(arr,arr_top),temp_top);

    for( int i = 1; i < size; i++)
    {
        int temp1 = pop(arr,arr_top);
        //cout<<temp1<<endl;
        //temp[r1] = temp1;
        cout<<"\n\n\n"<<temp1;
        do{
//            int r1 =i;
            cout<<" temp::  ";
            disp(temp);
            cout<<" arr::  ";
            disp(arr);
            if (temp_top == -1)
                push(temp,temp1,temp_top);
            //cout<<temp1<<" "<<temp[i]<<endl;
            else if (temp1 < temp[temp_top])
            {
                push(arr, pop(temp,temp_top), arr_top);
            }
            else
                push(temp,temp1, temp_top);

        }while(temp1 > temp[i]);
    }
}


