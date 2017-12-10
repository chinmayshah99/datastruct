/*
    In the school council election election there are 20 candidates contesting for the post of general secretary. 
    Write a program to declare the winner having his/her name on the top of the list.
*/
// Chinmay Shah

#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <algorithm>
#define n_cand 5

using namespace std;

typedef struct candidate{
    string name;
    unsigned int vote_count;

    candidate()
    {
        vote_count = 0;
    }
}cand_det;

cand_det cand[n_cand];


void insertion_sort(int temp[][2])
{
   int key[1][2], j;
   int n = n_cand;
   for (int i = 1; i < n; i++)
   {
       key[0][0] = temp[i][0];
       key[0][1] = temp[i][1];
       j = i-1;
       while (j >= 0 && temp[j][0] > key[0][0])
       {
           temp[j+1][0] = temp[j][0];
           temp[j+1][1] = temp[j][1];
           j--;
       }
       temp[j+1][0] = key[0][0];
       temp[j+1][1] = key[0][1];
   }
}




void bubble_sort(int temp[][2])
{
    int n = n_cand;
    for (int i = 0; i < n-1; i++)
    {
       for (int j = 0; j < n-i-1; j++)
       {
           if (temp[j][0] > temp[j+1][0])
           {
               int a[1][2];
               for(int k = 0 ; k < 2;k++)
               {
                   a[0][k] = temp[j][k];
                   temp[j][k] = temp[j+1][k];
                   temp[j+1][k] = a[0][k];
               }
           }
       }
    }
}



void sort1()
{
    int temp[n_cand][2];
    for(int i = 0; i < n_cand; i++)
    {
        temp[i][0] = cand[i].vote_count;
        temp[i][1] = i;
    }

    bubble_sort(temp);



    if(temp[n_cand-1][0] == temp[n_cand-2][0])
        cout<<"seems like a tie"<<endl;
    cout<<"winner is ";
    cout<<cand[int(temp[n_cand-1][1])].name;
}


void sort2()
{
    int temp[n_cand][2];
    for(int i = 0; i < n_cand; i++)
    {
        temp[i][0] = cand[i].vote_count;
        temp[i][1] = i;
    }

    insertion_sort(temp);



    if(temp[n_cand-1][0] == temp[n_cand-2][0])
        cout<<"seems like a tie"<<endl;


    cout<<"winner is "<<cand[int(temp[n_cand-1][1])].name;
}

// credit stack overflow
bool is_digits(const std::string &str)
{
    return std::all_of(str.begin(), str.end(), ::isdigit); // C++11
}

/*
    validates whether the given integer is number
*/
int vaildates_input()
{
    std::string z;
    while(true)
    {
    	cin>>z;
        //std::getline(std::cin, z);
        if (is_digits(z))
        {
            return stoi(z);
        }
        else
            std::cout<<"seems invalid input; enter again"<<std::endl;
    }
}


int main()
{

    for(int i = 0; i < n_cand; i++)
    {
        cout<<"enter details for candidate "<<i+1<<endl;
        cin>>cand[i].name;
    }
    int n = 10;
    for(int i = 0; i < n; i++)
    {
        int can_no = vaildates_input();
        if(can_no > 0 && can_no < (n_cand+1))
        {
            can_no--;
            cand[can_no].vote_count++;
            cout<<"your vote is casted to "<<cand[can_no].name<<endl;
        }
        else
        {
            cout<<"invalid vote"<<endl;
        }
    }
    {
    	time_t start_time;
        time(&start_time);

        sort1();
        

        time_t end_time;
        time (&end_time);
        double search_time = difftime(end_time, start_time);
        std::setprecision(30);
        std::cout<<"\nit took ";
        std::cout<<std::setprecision(30)<<search_time;
        std::cout<<"to run"<<std::endl;
    }
    {

    	time_t start_time;
        time(&start_time);

        sort2();
        

        time_t end_time;
        time (&end_time);
        double search_time = difftime(end_time, start_time);
        std::setprecision(30);
        std::cout<<"\nit took ";
        std::cout<<std::setprecision(30)<<search_time;
        std::cout<<"to run"<<std::endl;
    }    
}
