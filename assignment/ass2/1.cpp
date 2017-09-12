// Program to duplicate a linked list

#include<iostream>

typedef struct Node{
char element;
Node *next;
}node;
node *start1 = NULL, *start2 = NULL;


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
        init(start1,value);
	}

	std::cout<<"\n\nCreating new LL...\n";


	//iter = head[listno];
	node *orig = start1;
	while(orig->next!=NULL){
	    value=orig->element;
        node *temp;
        temp = new(node);
        temp->element = value;
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
        init(start2,value);

	    orig=orig->next;
	}

	std::cout<<"\nCopied LL:\n";

	node *iter = start2;
	while(iter!=NULL){
	    std::cout<<iter->element;
	    iter = iter->next;
	}

	return 0;
}
