// Program to duplicate a linked list

#include<iostream>

typedef struct Node{
char element;
Node *next;
}node;
node *start1 = NULL, *start2 = NULL;

using namespace std;


//Function to compare length of two lists
void compare(node* one,node* two){
    int co1 = 0, co2 = 0;
    node* iter = one;
    while(iter!=NULL){
        co1++;
        iter = iter->next;
    }
    iter = two;
    while(iter!=NULL){
        co2++;
        iter = iter->next;
    }
    std::cout<<"\nLength of first list: "<<co1;
    std::cout<<"\nLength of second list: "<<co2;
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
        temp->element = value;
        temp->next = NULL;

        // check if linked list is empty
        if (start1 == NULL)
        {
            start1 = temp;
        }
        else
        {
            node *s;
            s = start1;
            // loop till reaches the last element of current list
            while(s->next!= NULL)
            {
                s = s->next;
            }
            s->next = temp;
        }
	}

    std::cout<<"\nEnter characters into linked list (Enter '.' to stop)\n";

        char zz;
        while (zz!='.'){
            std::cin>>zz;
            if(zz == '.')
                break;
            node *temp;
            temp = new(node);
            temp->element = zz;
            temp->next = NULL;

            // check if linked list is empty
            if (start2 == NULL)
            {
                start2 = temp;
            }
            else
            {
                node *s;
                s = start2;
                // loop till reaches the last element of current list
                while(s->next!= NULL)
                {
                    s = s->next;
                }
                s->next = temp;
            }
        }

	compare(start1,start2);

	return 0;
}
