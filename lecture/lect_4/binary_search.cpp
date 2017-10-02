// Binary Search
// makes sure of error handling
// inputs stops when user enters non-integer
// the search finds the number if valid input is given
// false in all other cases

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iomanip>

std::vector<int> myarray;

bool binary_search(int number)
{
    time_t start_time;
    time(&start_time);
    int higher = myarray.size();
    int lower = 0;
    int mid;
   

    do{
        mid = (higher+lower) /2;
        std::cout<<myarray[mid]<<std::endl;
        if(number == myarray[mid])
            {
                std::cout<<"found at pos: "<<mid+1<<std::endl;
                return true;
            }
        else if(number > myarray[mid])
            lower = mid;
        else if(number < myarray[mid])
            higher = mid;

        if(higher - lower == 1)
            return false;
    }while(true);
}

bool linear_search(long int number)
{

    for(int i = 0; i < myarray.size(); i++)
    {   
        if(number == myarray[i])
        {
            std::cout<<"found at pos: "<<i+1<<std::endl;
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

int main()
{
    std::string z;

    while(true)
    {
        std::getline(std::cin,z);        
        bool is_only_digit = is_digits(z);
        if(is_only_digit == true){
            myarray.push_back(std::stoi(z));
            std::cout<<std::stoi(z);
        }
        else
            break;
    }

    bool found = false;
    

/*
    {
        time_t start_time;
        time(&start_time);

        linear_search(no-3);
        

        time_t end_time;
        time (&end_time);
        double search_time = difftime(end_time, start_time);
        std::setprecision(30);
        std::cout<<start_time<<" "<<end_time<<std::endl;  
        std::cout<<"it took ";
        std::cout<<std::setprecision(30)<<search_time;
        std::cout<<"to run"<<std::endl;
    }
*/
    std::cout<<"enter number to be found: ";
    std::cin>>z;
    if(is_digits(z))
    {
        time_t start_time;
        time(&start_time);

        found = binary_search(std::stoi(z));      

        time_t end_time;
        time (&end_time);
        double search_time = difftime(end_time, start_time);
        std::setprecision(30);
        std::cout<<start_time<<" "<<end_time<<std::endl;  
        std::cout<<"it took ";
        std::cout<<std::setprecision(30)<<search_time;
        std::cout<<"to run"<<std::endl;
        
    }

    if(found == false)
        std::cout<<"number can't be located"<<std::endl;

    return 0;
}