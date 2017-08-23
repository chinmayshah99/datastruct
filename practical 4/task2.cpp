/*
	Write a C/C++  program to implement the following operations on a Doubly linked list
        i)  Create a new node
		ii)  Modify the info of a node (position to be specified by the user)
        iii) Delete a node
        iv) Traverse the list in forward direction
		v)  Traverse the list in Reverse direction
*/


#include <iostream>
#include <cstdlib>

typedef struct node
{
    int data;
    node *front1, *back1;
}node;

node *start = NULL;


// adds node to start if start is null
// else it adds node to end of list.
void create_node(int data)
{
    node *temp;
    temp = new(node);
    temp->data = data;
    temp->front1 = NULL;
    temp->back1 = NULL;

    // check if linked list is empty
    if (start == NULL)
    {
        start = temp;
    }
    else
    {
        node *s,*track;
        s = start;
        // loop till reaches the last element of current list
        while(s->front1!= NULL)
        {
            track = s;
            s = s->front1;
        }
        //s->back1 = track;
        s->front1 = temp;
        temp->back1 = s;
    }
}


// function takes in position at which it needs to be chaneged along with the new data
// returns true if operation is successful and returns false in all other cases.
bool modify(int pos,int new_data)
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
        while(s->front1!= NULL)
        {
            // when the position that needs to be changed matches with the cuurent position
            // update data and exit the function
            if(flag == pos)
            {
                s->data = new_data;
                return true;
            }
            else
            {
                s = s->front1;
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
        while(s->front1!= NULL)
        {

            if(flag == pos)
            {
                node *zz = s;
                s = s->front1;
                delete(zz);
                s->back1 = temp;
                temp->front1 = s;
                return true;
            }
            else
            {
                temp = s; // to keep track of the node before the node that is about to be deleted.
                s = s->front1;
                flag++;
            }
        }
        return false;
    }
}


void display_forward()
{

    if (start == NULL)
    {
        std::cout<<"empty"<<std::endl;
    }
    else
    {
        node *s;
        s = start;
        while(s->front1!= NULL)
        {
            std::cout<<s->data;
            s = s->front1;
        }
        std::cout<<s->data;
    }

}

void display_reverse()
{
    if (start == NULL)
    {
        std::cout<<"empty"<<std::endl;
    }

    else
    {
        node *s;
        s = start;
        while(s->front1!= NULL)
        {
            //std::cout<<s->data;
            s = s->front1;
        }
        while(s->back1 != NULL)
        {
            std::cout<<s->data;
            s = s->back1;
        }
        std::cout<<s->data;
    }

}


void greet(bool what)
{
    if ( what == true)
        std::cout<<"yeah"<<std::endl;
    else
        std::cout<<"boo"<<std::endl;
}

int main()
{
    //start = NULL;
    using namespace std;
    int z,change;
    for(int i = 0 ; i<5;i++)
    {
        cin>>z;
        create_node(z);
    }
    /*
    cout<<"enter pos you want to change"<<endl;
    cin>>z;
    cin>>change;
    bool if_change = modify(z,change);
    greet(if_change);

    cout<<"enter pos you want to delete"<<endl;
    cin>>z;
    bool _delete_ = _delete(z);
    greet(_delete_);
    */
    //display_forward();
    display_reverse();

}
