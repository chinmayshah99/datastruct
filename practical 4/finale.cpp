/*
    Write an algorithm and C\C++ program that swaps (exchanges) two nodes in a list. 
    The nodes are identified by number and are passed as parameters. 
    For example, to exchange nodes 5 and 8, you would call swap(5,8). 
    If the exchange is successful, the algorithm is to return true. 
    If it encounters an error, such as an invalid node number, it returns false. 
    Use linked list implementation. 
*/

// Chinmay Shah

#include <iostream>
#include <cstdlib>

typedef struct node
{
    int value;
    node *link;
} node;

node *start = NULL;

bool swap(int pos1, int pos2)
{
    pos1--;
    pos2--;
    node *pos_1 = NULL, *pos_2 = NULL, *traverse = NULL;
    int flag = 0;
    traverse = start;
    while (traverse->link != NULL)
    {
        if (flag == pos1)
        {
            pos_1 = traverse;
        }
        else if (flag == pos2)
        {
            pos_2 = traverse;
        }
        flag++;
        traverse = traverse->link;
    }
    if (pos_1 == NULL || pos_2 == NULL)
        return false;

    // just swapping the int values
    // actual swapping is done here
    {
        int temp_int;
        temp_int = pos_1->value;
        pos_1->value = pos_2->value;
        pos_2->value = temp_int;
        return true;
    }

    return false;
}

void create_node(int value)
{
    node *temp;
    temp = new (node);
    temp->value = value;
    temp->link = NULL;

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
        while (s->link != NULL)
        {
            s = s->link;
        }
        s->link = temp;
    }
}

void display()
{

    if (start == NULL)
    {
        std::cout << "empty" << std::endl;
    }
    else
    {
        node *s;
        s = start;
        while (s->link != NULL)
        {
            std::cout << s->value;
            s = s->link;
        }
        std::cout << s->value;
    }
}
void greet(bool what)
{
    if (what == true)
        std::cout << "yeah" << std::endl;
    else
        std::cout << "boo" << std::endl;
}

int main()
{
    int z;
    for (int i = 0; i < 5; i++)
    {
        std::cin >> z;
        create_node(z);
    }
    int pos1, pos2;
    std::cin >> pos1 >> pos2;
    bool swap_ = swap(pos1, pos2);
    greet(swap_);
    display();
}