#include <iostream>
#include <vector>

using namespace std;
typedef struct node{
    char name;
    int weigh;
}node;

typedef struct sum{
    int value;
    vector<int> path;
    sum()
    {
        value = 0;
    }
}sum;

#define max_size 5

int matrix[5][5] = {
    {0,2,0,2,0},
    {2,0,3,1,0},
    {0,3,0,2,0},
    {4,1,2,0,4},
    {0,0,0,4,0}
};


void insert(char ch)
{
    //cout<<"insert for"<<ch<<endl;
    int index = ch-65;
    int no_of_nodes;
    cin>>no_of_nodes;
    for(int i = 0 ; i < no_of_nodes; i++)
    {
        //cout<<"enter for"<<i+1<<endl;
        node *temp = new(node);
        cin>>temp->name;
        cin>>temp->weigh;
        int current = toupper(temp->name);
        current-=65;
        matrix[index][current] = temp->weigh;
        delete(temp);
    }
}


sum s1[5];


void shortest_path()
{
    char source, destination;
    std::cin>>source>>destination;

    int destination_1 = toupper(destination) - 65;
    int current = toupper(source) - 65;



    /*
        check if current element = destination

        if not then go to the element in row
        if(this element has already occured)
            go to the next element
        else
            increase sum for this occurance and move on.
    */
    //cout<<endl<<current<<destination_1<<endl;
    int start_len = 0, k =0;

    for(int n = 0; n <3; n++){
        if(current == destination_1)
            break;
    do{
        //cout<<"line 78"<<endl;
        def:

        // checks if current position = destination
        if(matrix[current][destination_1] != 0)
        {
            s1[k].value+=matrix[current][destination_1];
            break;
        }

        //cout<<"line 88"<<endl;
        for(int i = start_len ; i < max_size;i++)
        {
            abc:
            if(matrix[current][i] != 0)
            {
                //cout<<"line94"<<endl;
                //cout<<matrix[current][i]<<endl;
                // to check if al
                //cout<<"\n\t"<<s1[k].path.size()<<endl;
                for(int j = 0; j < s1[k].path.size(); j++)
                {
                    //cout<<"line100"<<endl;
                    //cout<<"\t"<<i<<" "<<s1[k].path[j]<<endl;
                    if(i == s1[k].path[j])
                        {
                            //cout<<"comparing: "<<s1[k].path[j]<<endl;
                            i+=1;
                            goto abc;
                        }
                }
                //cout<<"line 106  "<<i<<endl;
                s1[k].value+=matrix[current][i];
                //cout<<"distance as of now: "<<s1[k].value<<endl;
                s1[k].path.push_back(current);
                current = i;
                //cout<<current;
                goto def;
            }
        }

    }while(current == destination_1);
    //cout<<endl<<s1[k].value<<endl;
    //cout<<k<<"done"<<endl;

    start_len = s1[k].path[k++] + 1;
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

    for(int i = 0; i < max_size; i++)
    {
        for(int j = 0; j < max_size; j++)
        {
            cout<<matrix[i][j]<<" ";
            //matrix[i][j]*=10;
        }
        cout<<endl;
    }
    shortest_path();

    cout<<s1[0].value<<endl;
    cout<<s1[1].value<<endl;
    cout<<s1[2].value<<endl;
}
