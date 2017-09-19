/*
    LOVE PEOPLE USE THINGS
    NOT USE PEOPLE LOVE THINGS
*/

#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <sstream>
using namespace std;

int total_freq = 0;

typedef struct node{
    string s;
    float probablity;
    int frequency;
    bool code;
    node *left, *right;
    node()
    {
    	code = true;
        s = "";
        left = nullptr;
        right = nullptr;
    }
}node;

std::vector<node*> track;

// sorts in ascending order
void sort()
{   
    cout<<"sorted"<<endl;
    int n = track.size();
    cout<<n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (track[j]->frequency > track[j + 1]->frequency) {
                node* temp = track[j];
                track[j] = track[j + 1];
                track[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i < n;i++)
    {
        cout<<track[i]->s<<" "<<track[i]->frequency<<endl;
    }
}
void probablity()
{
    cout<<endl<<total_freq;
    cout<<"done  with probabliity";
    for(int i = 0; i < track.size(); i++)
    {
        track[i]->probablity = (float(track[i]->frequency)/(float)total_freq);
    }
    for(int i = 0; i <  track.size();i++)
    {
        cout<<track[i]->s<<" "<<track[i]->probablity<<endl;
    }
}

void insert(string the)
{
    total_freq++;
    for(int i = 0; i<track.size() ; i++)
    {
        string k = track[i]->s;
        //strcpy(k,track[i]->s);
        //if (strcmp(k,the) == 0)
        if(k == the)
            {
                track[i]->frequency+=1;
                return;
            }
    }
        node *temp = new(node);
        temp->frequency =1;
        temp->s = the;
        track.push_back(temp);
        //strcpy(temp->s,the);

    cout<<the<<"inserted"<<endl;

}

node *root = nullptr;
/*void generate()
{
    root =new(node);
    root->probablity= 1.0;

    int len = track.size();
    root->left = track[len-1];

}*/

void tree()
{
    node  *temp = new(node);

    int n = track.size();
    temp->probablity = track[0]->probablity + track[1]->probablity;
    temp->left = track[0];
    temp->right = track[1];
    int  i =2;

    do{
        node *temp2 = new(node);
        temp2->probablity = track[i]->probablity + temp->probablity;
        cout<<temp2->probablity<<endl;
        temp2->left = track[i];
        temp2->code = false;
        temp2->right = temp;
        temp = temp2;
        i++;
    }while(i<n);
    root = temp;
    cout<<"tree genereated;"<<endl;

}

void display(node *temp)
{
    cout<<"let's display"<<endl;
    if(root == nullptr)
    {
        cout<<"eroor";
        return;
    }
    /*else
    {
        while(temp != nullptr)
        {
            cout<<temp->s<<" "<<temp->probablity<<endl;
            temp = temp->right;
            //display(temp);
        }
    }

    node *temp2;
    temp2 = temp->left;
    cout<<temp2->s<<temp2->probablity;
    */
    int sum =0;
    while(temp->right != nullptr)
    {
        node *temp2;
        temp2 = temp->left;
        if(temp2->code == true)
        	{	sum+=1;
        		for(int i = 1; i < sum; i++)
        			cout<<"1";
        	}
        cout<<"0 "<<temp2->s<<" "<<temp2->probablity<<" "<<endl ;
        temp= temp->right;
    }

}


int main()
{
    string input1;
    /*while(true)
    {
        getline(std::cin,input1);
        if(input1 == ".")
            break;
        insert(input1);
    }*/
	   /* insert("LOVE");
		insert("PEOPLE");
		insert("USE");
		insert("THINGS");
	    insert("NOT");
		insert("USE"); 
		insert("PEOPLE"); 
		insert("LOVE");
		insert("THINGS");
	getline(cin,input1);*

	char *pch;
	pch = strtok (input1," ");
	  while (pch != NULL)
	  {
	    insert(pch);
	    pch = strtok (NULL, " ");
	  }*/
	//istringstream f("love ass me sdfsd love kko kko love");
	

	string st;
	getline(cin,st);

	stringstream f(st);
	
	while(getline(f,st,' '))
	{
		f >> st;
		insert(st);
	}


    sort();
    probablity();
    tree();
    display(root);

}
