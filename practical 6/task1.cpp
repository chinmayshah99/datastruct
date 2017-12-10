// THERE ARE SOME KNOWN BUGS

/*
    Given a directed weighted graph.
     You are also given the shortest path from a source vertex ‘s’ to a destination vertex ‘t’.  
     If weight of every edge is increased/multiplied by 10 units, 
     does the shortest path remain same in the modified graph?

*/

#include <iostream>
#include <vector>

using namespace std;
typedef struct node
{
    char name;
    int weigh;
} node;

typedef struct sum
{
    int value;
    vector<int> path;
    sum()
    {
        value = 0;
    }
} sum;

#define max_size 5

// hardcodes in this  case
// can be:
// int matrix[max_size][max_size] = {0};
int matrix[5][5] = {
    {0, 2, 0, 2, 0},
    {2, 0, 3, 1, 0},
    {0, 3, 0, 2, 0},
    {4, 1, 2, 0, 4},
    {0, 0, 0, 4, 0}};

void insert(char ch)
{
    //cout<<"insert for"<<ch<<endl;

    // converting the character to integer number; helps in easy accessing of matrix
    int index = toupper(ch) - 65;

    int no_of_nodes;
    cin >> no_of_nodes;
    for (int i = 0; i < no_of_nodes; i++)
    {
        //cout<<"enter for"<<i+1<<endl;
        // just a fancy way to do take input
        node *temp = new (node);
        cin >> temp->name;
        cin >> temp->weigh;
        int current = toupper(temp->name);
        current -= 65;

        matrix[index][current] = temp->weigh;
        delete (temp); // making sure memory is cleared
    }
}

sum s1[5];

void shortest_path()
{
    char source, destination;
    std::cin >> source >> destination;

    int destination_1 = toupper(destination) - 65;
    int current = toupper(source) - 65;

    /*
		rough flow of steps:

        check if current element = destination

        if not then go to the element in row
        if(this element has already occured)
            go to the next element
        else
            increase sum for this occurance and move on.
    */

    //cout<<endl<<current<<destination_1<<endl;

    // for ensuring that path are not repeated during computation.
    // it makes sure that that path selection in matrix is started from the ones not taken till now
    int start_len = 0;
    int k = 0; // track of no_of_path

    for (int n = 0; n < 3; n++)
    {
        if (current == destination_1)
            break;
        do
        {
        //cout<<"line 78"<<endl;
        def:

            // checks if current position = destination
            if (matrix[current][destination_1] != 0)
            {
                s1[k].value += matrix[current][destination_1];
                break;
            }

            //cout<<"line 88"<<endl;
            for (int i = start_len; i < max_size; i++)
            {
            abc:
                if (matrix[current][i] != 0)
                {
                    //cout<<"line94"<<endl;
                    //cout<<matrix[current][i]<<endl;
                    // to check if the path is already taken
                    // basically cyclic loop formation check
                    //cout<<"\n\t"<<s1[k].path.size()<<endl;
                    // if the path is already taken, i.e., the node is already visited
                    // it moves on to check for new node
                    for (int j = 0; j < s1[k].path.size(); j++)
                    {
                        //cout<<"line100"<<endl;
                        //cout<<"\t"<<i<<" "<<s1[k].path[j]<<endl;
                        if (i == s1[k].path[j])
                        {
                            //cout<<"comparing: "<<s1[k].path[j]<<endl;
                            i += 1;
                            goto abc;
                        }
                    }
                    //cout<<"line 106  "<<i<<endl;
                    s1[k].value += matrix[current][i]; // adding to the current path length
                    //cout<<"distance as of now: "<<s1[k].value<<endl;
                    s1[k].path.push_back(current); // pushing the current node to path
                    current = i;
                    //cout<<current;
                    goto def;
                }
            }

        } while (current == destination_1);
        //cout<<endl<<s1[k].value<<endl;
        //cout<<k<<"done"<<endl;
        s1[k].path.push_back(destination_1);
        start_len = s1[k].path[k++] + 1; // making sure that nodes path are not repeated
        current = toupper(source) - 65;
    }
}

int main()
{
    /*
	char ch;
    for(int i = 0; i < 10; i++)
    {
    	cin>>ch;
    	insert(ch);
    }
    */

    for (int i = 0; i < max_size; i++)
    {
        for (int j = 0; j < max_size; j++)
        {
            cout << matrix[i][j] << " ";
            //matrix[i][j]*=10;
        }
        cout << endl;
    }
    shortest_path();

    for (int i = 0; i < 3; i++)
    {
        cout << s1[i].value << endl;
        for (int j = 0; j < s1[i].path.size(); j++)
            cout << char((s1[i].path[j]) + 65) << " ";
        cout << endl;
    }
}
