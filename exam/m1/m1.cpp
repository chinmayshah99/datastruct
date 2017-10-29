/*
    Data Structures m1
    The program was the question given in M1 to 
    E2 batch, class of 2020
    C++  program to implement the maze
    user should also be able to backtrack

    MIT LICENSE


    The program was my implementation in the given stipulated amount of time
    There may be a better solution 
*/



#include <iostream>

typedef struct node
{
    int data;
    node *back;
    node *front[2]; // front[0] for  left and front[1] right
    // you can't make it two seprate pointers because it becomes binary tree
}node;

node *start = NULL; //the start pointer
node *current = NULL; // pointer to keep track during game development
node *game = NULL; // pointer to keep track of player position


/*
    adds node to start if start is null
    else it adds node according to position
    left if the position is 0
    at right in all other cases
*/
void create_node(int data, int pos)
{
    node *temp;
    temp = new(node);
    temp->data = data;
    //making all pointer references to null
    temp->front[0] = NULL;
    temp->front[1] = NULL;
    temp->back = NULL;

    // check if linked list is empty
    // then insert the pointer at start and game devlopment pointer points to this new pointer
    if (start == NULL)
    {
        start = temp;
        current = start;
    }

    // if poistion if given left
    // the left of previous node points to this new node
    // because it's doubly linked list, the back pointer of this new node points to previous node
    else if (pos == 0)
    {
        current ->front[0] = temp;
        temp->back = current;
        current = temp;
    }

    // just change the left to right in the above function
    else
    {
        current ->front[1] = temp;
        temp->back = current;
        current = temp;
    }
}

/*
    function to play the game
    the move whether left/right is given as parameter
    if the move is successfull, the game pointer is updated
    else the player stands at the same poistion on all other cases
    also at last, it's checked that player wins or not
    if player wins, the program is exited
*/

void  play(int pos)
{
    // left move
    if(pos == 0)
    {
        //if the left division doesn;t exist then stay at the same position
        if(game->front[0] == NULL)
        {
            std::cout<<"invalid move"<<std::endl;
            return;
        }
        else
            game = game->front[0];
    }

    // right move
    else if(pos == 1)
    {
        if(game->front[1] == NULL)
        {
            std::cout<<"invalid move"<<std::endl;
            return;
        }
        else
            game = game->front[1];
    }

    // for the backtrack
    // if user is at start then's its dispalyed 
    // else user is allowed to back to the previous position at all time
    else if(pos == -1)
    {
        if(game->back == NULL)
        {
            std::cout<<"you're already at start"<<std::endl;
            return;
        }
        else
            game = game->back;
    }

    //checks if winning condition is met
    if(game->data == 77)
    {
        std::cout<<"you win"<<std::endl;
        exit(0);
    }
}

int main()
{
    using namespace std;
    int z,mpos;
    
    create_node(0,99); // random 99 argument
    cout<<"make maze"<<endl;
    cout<<"77 for victory, 0 in other case"<<endl;
    cout<<"enter 0 for  left, 1 for right"<<endl;
    do{
        cout<<"enter no ";
        cin>>z;
        cout<<"enter pos ";
        cin>>mpos;
        create_node(z,mpos);
    }while(z!=77);

    game = start;
    cout<<"let's  start"<<endl;
    cout<<"enter 0 for  left, 1 for right and -1 for backtrack"<<endl;
    while(true)
    {
        cin>>mpos;
        play(mpos);
    }

    return 0;
}
