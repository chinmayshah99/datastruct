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


/*
void bfs(int start_element)
{
    node *parse = hash[start_element];
    std::queue <node* > q1;
    std::vector <char> visited;

    q1.push(parse); // push the start element; // REVISIT NEEDED
   // visited.push_back('A');
    while (!q1.empty())
    {
        parse = q1.front();
        parse = hash[int(parse->data1) - 65];
        std::cout<<" "<<parse->data1<<std::endl;
        visited.push_back(parse->data1);        
        //loops needs revisit
        while (parse->next != nullptr)
        {
           std::cout<<" "<<parse->data1<<" "<< visited.size()<<std::endl;
            def:
            for (int i = 0; i < visited.size() -1; i++)
            {
                std::cout<<"line 65"<<std::endl;

                if (parse->data1 == visited[i])
                {
                    if(parse->next != nullptr)
                    {
                        parse = parse->next;
                        goto def;
                    }
                    else
                        goto abc;
                }
            }
            std::cout<<"line 74"<<std::endl;
            
            

            if(parse->next != nullptr)
            {
                std::cout<<"line 80"<<std::endl;
                q1.push(parse->next);
                parse = parse->next;
            }
                
            else 
                break;
        }
        abc:
        std::cout<<"line 88"<<std::endl;
        
        q1.pop();
    }
}
*/
void dfs(int start_element)
{
    node *parse = hash[start_element];
    std::stack <node*> s1;
    std::vector <char> visited;

    s1.push(parse);

/*
    while(!s1.empty())
    {
        parse = s1.top();
        //loops needs revisit



        while (parse->next != nullptr)
        {
            for (int i = 0; i < visited.size(); i++)
            {
                if (parse->data1 == visited[i])
                    goto abc;
            }
            s1.push(parse->next);
            visited.push_back(parse->data1);
            
            parse = parse->next;

            
        }

        s1.pop();

    }


/*
    get the  first element;
    find push all the first elements till it reaches null or all visited are done
    pop the  first element and check the 2nd one and see if list makes it

*/

    while(!s1.empty())
    {
        parse  = s1.top())
        while(parse != nullptr)
        {
            for (int i = 0; i < visited.size(); i++)
            {
                if (parse->data1 == visited[i])
                    break;
            }

            s1.push(parse->next);
            std::cout<<parse->data1;
            visited.push_back(parse->data1);
            //abc:
            parse = hash[parse->data1];
            
        }

        parse = s1.pop();
        {
            while(parse != nullptr)
            {
                for (int i = 0; i < visited.size(); i++)
                {
                    if (parse->data1 == visited[i])
                        parse = parse->next;
                    else
                        s1.push(parse);
                }
                
            }
        }
        //parse= parse->next;
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
        while(parse != nullptr)
        {
            std::cout<<parse->data1;
            if(parse->next != nullptr)
                parse = parse->next;
            else 
                break;
        }
    }

    std::cout<<std::endl;std::cout<<std::endl;std::cout<<std::endl;
    bfs(0);

}