/*
    Consider there are five cities connected with each other. 
    You need to travel each city in certain order so that you can find the shortest path from any one city to another city. 
    Which algorithm (DFS, BFS, MST) will be suitable to solve this problem. 
    Implement it using your programming skills and justify your answer. 
*/

#include <iostream>
#include <queue>
#include <stack>


// creating general node
typedef struct node{
    char data1;
    node *next;
    node()
    {
        next = nullptr;
    }
}node;


node *hash[26];

// implemented using combination of hash table and linked list
// argument 1- element is the vertice name
// argument 2- n is the no of edges connected to it


void generate(int element, int n)
{
    std::cout<<"enter for"<<element << " "<<n<<std::endl;
    node *prev;
    // number of nodes connected  to t he  list
    for(int  i = 0; i < n; i++)
    {
        node *temp = new(node);
        std::cin>>temp->data1;
        
        if(i ==0)
        {
            hash[element] = temp;
            prev  = temp;
        }
        else{
            prev->next = temp;
            prev = temp;
        }
        
    }
}

int main()
{
    node *parse;
    generate(0,3);
    generate(1,3);
    generate(2,5);
    generate(3,1);
    generate(4,2);
    generate(5,2);
    generate(6,2);


    for(int i = 0; i <  7; i++)
    {
        parse = hash[i];
        std::cout<<std::endl<<char(i+65);
        while(parse != nullptr)
        {
            std::cout<<parse->data1<<" ";
            if(parse->next != nullptr)
                parse = parse->next;
            else 
                break;
        }
    }

    std::cout<<std::endl;std::cout<<std::endl;std::cout<<std::endl;

}