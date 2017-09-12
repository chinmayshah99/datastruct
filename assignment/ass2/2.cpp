// Program to join  linked list

#include<iostream>

typedef struct Node{
char element;
Node *next;
}node;
node *start1 = NULL, *start2 = NULL;

using namespace std;


void init(node* start, char value)
{
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

int main()
{
	char value;
	std::cout<<"\nEnter characters into linked list (Enter '.' to stop)\n";

	while (value!='.'){
        std::cin>>value;
        if(value == '.')
            break;

        init(start1, value);
	}

    std::cout<<"\nEnter characters into linked list (Enter '.' to stop)\n";
        char zz;
        while (zz!='.'){
            std::cin>>zz;
            if(zz == '.')
                break;

            init(start2,zz);
        }

	std::cout<<"\njoining new LL...\n";

    node *s = start1;
    while(s->next != NULL)
    {
        s = s->next;
    }
    s->next = start2;


	std::cout<<"\new LL:\n";

	node *iter = start1;
	while(iter!=NULL){
	    std::cout<<iter->element;
	    iter = iter->next;
	}

	return 0;
}
