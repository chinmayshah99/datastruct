/*
    Rank the students as per their percentage of the scores provided in 6 courses (subjects). 
    Find the top three course (subject) wise performers of the class and print. 
    
    Constraints: User friendly Program with all possible input validations. It should run for any number of students in the college. 
    
    Apply both linear and Binary search techniques and compare the time taken to search the required elements in both search approaches.

*/
// Chinmay Shah

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef struct node
{
    string name;
    int course[6];
    float average;
    node()
    {
        average = 0;
    }
} node;

// the actual database
std::vector<node> myarray;


// implements binary search
bool binary_search(int number, float temp[][2], int n)
{

    int higher = n;
    int lower = 0;
    int mid;

    do
    {
        mid = (higher + lower) / 2;
        std::cout << temp[mid][0] << std::endl;
        if (number == temp[mid][0])
        {
            std::cout << "found at pos: " << mid + 1 << std::endl;
            cout << myarray[int(temp[mid][1])].name << endl;
            return true;
        }
        else if (number > temp[mid][0])
            lower = mid;
        else if (number < temp[mid][0])
            higher = mid;

        if (higher - lower == 1)
            return false;
    } while (true);
}
// implements linear search
bool linear_search(int number, float temp[][2], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (number == temp[i][0])
        {
            std::cout << "found at pos: " << i + 1 << std::endl;
            cout << myarray[int(temp[i][1])].name << endl;
            return true;
        }
    }
    return false;
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
    int x;

    do{
        cin>>x;
    }while(cin.fail());
    return x;
    /*
    std::string z;
    while(true)
    {
        std::cin.clear();
        std::cin.ignore();
        std::getline(std::cin, z);
        if (is_digits(z))
        {
            return stoi(z);
        }
        else
            std::cout<<"seems invalid input; enter again"<<std::endl;
    }*/
}

/*
    takes the 2-d array and it's size as input
    ask users what element to search for
    calculates the time to run for both linear and binary search
*/
void search(float temp[][2], int n)
{
    std::cout << "enter number to search for" << std::endl;
    int input = vaildates_input();
    {
        time_t start_time, end_time;
        time(&start_time);

        linear_search(input,temp,n);
        time(&end_time);
        double search_time = difftime(end_time, start_time);
        std::setprecision(30);
        std::cout << start_time << " " << end_time << std::endl;
        std::cout << "it took " << std::setprecision(30) << search_time << "to run" << std::endl;
    }

    {
        time_t start_time, end_time;
        time(&start_time);
        binary_search(input,temp,n);
        time(&end_time);
        double search_time = difftime(end_time, start_time);
        std::setprecision(30);
        std::cout << start_time << " " << end_time << std::endl;
        std::cout << "it took " << std::setprecision(30) << search_time << "to run" << std::endl;
    }
}

/*
    creates a new array temporary array and sorts them in ascending order
    the item to be copied is passed as argument to function
    sort is implemented using bubble sort
    2-d array temp[n[[2] is created
        temp[n][0] has the actual data
        temp[n][1] has the corresponding index number(address) of the above data in the database
    displays the top 3 students
    calls the search function

*/

void sort(int choice)
{
    int n = myarray.size();
    float temp[n][2];
    if (choice >= 0 && choice < 6)
    {
        for (int i = 0; i < n; i++)
        {
            temp[i][0] = myarray[i].course[choice];
            temp[i][1] = i;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            temp[i][0] = myarray[i].average;
            temp[i][1] = i;
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++)
        {
            if (temp[j][0] > temp[j + 1][0])
            {
                float k[2];
                for (int kj = 0; kj < 2; kj++)
                {
                    k[kj] = temp[j][kj];
                    temp[j][kj] = temp[j + 1][kj];
                    temp[j][kj] = k[kj];
                }
            }
        }
    }

    // displays the topper
    for (int k = n - 1; k > n - 4; k--)
    {
        cout << temp[k][0];
        int l = int(temp[k][1]);
        cout << myarray[l].name << endl;
    }
    search(temp,n);
}

int main()
{
    std::string z;
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        cout <<"enter for" << i+1 << endl;
        node premal;
        {
            cin >> premal.name;
            for (int i = 0; i < 6; i++)
            {
                premal.course[i] = vaildates_input();
                premal.average += premal.course[i];
            }
            premal.average /= 6;
        }
        myarray.push_back(premal);
    }

    cout<<"enter by which paramters would you like to search\n 1-6 for  marks , 8 for average"<<endl;
    int choice = vaildates_input();
    choice-=1;
    if((choice) >= 0 && choice < 6)
        sort(choice);
    else
        sort(7);

    return 0;
}
