/*

    MIT LICENSE

*/



#include <iostream>

typedef struct node
{
    char data;
   node *back;
    node *left, *right; // left for  left and right right
}node;

node *root = NULL; //the root pointer
node *current = NULL; // pointer to keep track during development
node *game = NULL; // pointer to keep track of player position

/*
    adds node to root if root is null
    else it adds node according to position
    left if the position is 0
    at right in all other cases
*/
void create_node(char data, int pos)
{
    node *temp;
    temp = new(node);
    temp->data = data;
    //making all pointer references to null
    temp->left = NULL;
    temp->right = NULL;
    temp->back = NULL;

    // check if linked list is empty
    // then insert the pointer at root and game devlopment pointer points to this new pointer
    if (root == NULL)
    {
        root = temp;
        current = root;
    }

    // if poistion if given left
    // the left of previous node points to this new node
    // because it's doubly linked list, the back pointer of this new node points to previous node
    else if (pos == 0)
    {
        current ->left = temp;
        temp->back = current;
        current = temp;
    }

    // just change the left to right in the above function
    else
    {
        current ->right = temp;
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
    std::cout<<game->data<<std::endl;
    // left move
    if(pos == 0)
    {
        //if the left division doesn;t exist then stay at the same position
        if(game->left == NULL)
        {
            std::cout<<"invalid move"<<std::endl;
            return;
        }
        else
            game = game->left;
    }

    // right move
    else if(pos == 1)
    {
        if(game->right == NULL)
        {
            std::cout<<"invalid move"<<std::endl;
            return;
        }
        else
            game = game->right;
    }

    // for the backtrack
    // if user is at root then's its dispalyed
    // else user is allowed to back to the previous position at all time
    else if(pos == -1)
    {
        if(game->back == NULL)
        {
            std::cout<<"you're already at root"<<std::endl;
            return;
        }
        else
            game = game->back;
    }

}


int main()
{
    using namespace std;
    int mpos,noc,counter =0;
    char z;

    // creates root node
    create_node('X',99); // random 99 argument
    cout<<"enter 0 for  left, 1 for right"<<endl;
    do{
    do{
            cout<<current->data<<endl;
        cout<<"enter value ";
        cin>>z;
        if(z == '.')
            break;
        cout<<"enter pos ";
        cin>>mpos;
        cout<<"enter no of children";
        cin>>noc;
        create_node(z,mpos);
        if(noc == 0)
        {
            current = current->back;
            //current = current->back;
        }
    }while(z!='.');
    counter++;
    current = root;
    cout<<current->data<<endl;
    }while(counter !=2);
    /*
    node *temp = start;
    cout<<"enter no of children";
    cin>>noc;
    if(noc == 0)
    {
        current = current->back;
        current = current->back;
    }
    else
    {

    }
    if(temp->left == NULL)
    {

    }
*/

    game = root;
    play(0);
    cout<<"let's  root"<<endl;
    cout<<"enter 0 for  left, 1 for right and -1 for backtrack"<<endl;
    while(true)
    {
        cin>>mpos;
        play(mpos);
    }

    return 0;
}
