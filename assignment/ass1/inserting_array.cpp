#include<iostream>
using namespace std;

int main()
{
    int i,a[5],no,pos, temp;
    cout<<"Enter data in Array one by one: ";
    for(i=0;i<5;i++)
    {
        cin>>a[i];
    }
    cout<<"\nStored Data in Array: ";
    for(i=0;i<5;i++)
    {
        cout<<a[i];
    }
    cout<<"\nEnter after which position to insert number: ";
    cin>>pos;
    if(pos>5)
    {
        cout<<"\nThis is out of range";
    }
    else
    {
        cout<<"\n\nEnter new number to be entered at position "<<pos<<" : ";
        cin>>no;
        for(i=pos;i<6;i++)
        {
            temp=a[i+1];
            a[i+1]=a[i];
            a[i]=temp;
        }
        a[pos]=no;
        cout<<"\n\nNew data in Array: ";
        for(i=0;i<6;i++)
        {
            cout<<a[i];
        }
    }
}
