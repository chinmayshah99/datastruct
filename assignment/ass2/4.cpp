//Program to reverse a linked list

#include<iostream>
#define lnum 2   //No. of lists
int listno = 0;
//Data in node
typedef struct node{
char value;
node *next;
}node;
node *start = NULL;
using namespace std;


void reverse()
{
    int pos = 0;
    node *temp, *s = start;
    while(s->next != NULL)
    {
        pos++;
        s = s->next;
    }
    cout<<endl<<pos<<endl;
    for(int i = pos;i>=0;i--)
    {
        temp = start;
        int flag = 0;cout<<endl;

        while(temp->next != NULL)
        {
            //cout<<i<<" "<<flag<<endl;
            if(i == flag)
            {
                cout<<temp->value;
                break;
            }
            else
            {
                temp = temp->next;
                flag++;
            }
        }
    }
}

int main()
{
    char value;
	std::cout<<"\nEnter characters into linked list (Enter '.' to stop)\n";

	while (value!='.'){
        std::cin>>value;
        if(value == '.')
            break;
        node *temp;
        temp = new(node);
        temp->value = value;
        temp->next = NULL;

        // check if linked list is empty
        if (start == NULL)
        {
            start = temp;
        }
        else
        {
            node *s;
            s = start;
            // loop till reaches the last element of current list
            while(s->next!= NULL)
            {
                s = s->next;
            }
            s->next = temp;
        }
    }
    reverse();
}
