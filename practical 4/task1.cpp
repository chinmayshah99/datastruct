/*
     Write a C/C++  program to implement the following operations on a Singly linked list
        i)   Create a new node
        ii)  Modify the info of a node (position to be specified by the user)
        iii) Delete a node (position to be specified by the user)
        iv)  Traverse the list
*/
#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct node{
    int value;
    node *next;
}node;

// default node pointing to null. 
node *start = NULL;

// adds node to start if start is null
// else it adds node to end of list.
void create_node(int value)
{
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

// function takes in position at which it needs to be chaneged along with the new value
// returns true if operation is successful and returns false in all other cases.
bool modify(int pos,int new_value)
{
    int flag = 0;
    pos--;
    if (start == NULL)
    {
        std::cout<<"already empty";
        return false;
    }
    else
    {
        node *s = start;
        while(s->next!= NULL)
        {
            // when the position that needs to be changed matches with the cuurent position
            // update value and exit the function
            if(flag == pos)
            {
                s->value = new_value;
                return true;
            }
            else
            {
                s = s->next;
                flag++;
            }
        }
        return false;
    }
}


// function deletes the element at the position given as argument
// returns true if operation is successful and returns false in all other cases.
bool _delete(int pos)
{
    pos--;
    int flag = 0;
    if (start == NULL)
    {
        std::cout<<"already empty";
        return false;
    }
    else
    {
        node *s = start,*temp;
        while(s->next!= NULL)
        {

            if(flag == pos)
            {
                node *zz = s;
                s = s->next;
                delete(zz);
                temp->next = s;
                return true;
            }
            else
            {
                temp = s; // to keep track of the node before the node that is about to be deleted.
                s = s->next;
                flag++;
            }
        }
        return false;
    }
}
void display()
{

    if (start == NULL)
    {
        std::cout<<"empty"<<endl;
    }
    else
    {
        node *s;
        s = start;
        while(s->next!= NULL)
        {
            cout<<s->value;
            s = s->next;
        }
        cout<<s->value;
    }

}

void greet(bool what)
{
    if ( what == true)
        cout<<"yeah"<<endl;
    else
        cout<<"boo"<<endl;
}

int main()
{
    //start = NULL;
    int z,change;
    for(int i = 0 ; i<5;i++)
    {
        cin>>z;
        create_node(z);
    }

    cout<<"enter pos you want to change"<<endl;
    cin>>z;
    cin>>change;
    bool if_change = modify(z,change);
    greet(if_change);
    
    cout<<"enter pos you want to delete"<<endl;
    cin>>z;
    bool _delete_ = _delete(z);
    greet(_delete_);
    
    display();

}
