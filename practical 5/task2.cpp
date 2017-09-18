#include <iostream>
#include <stack>

using namespace std;

typedef struct node{
    char data;
    node *left, *right;

    node()
    {
        
        left = nullptr;
        right = nullptr;
    }
}node;

node *root = nullptr;


node* insert(char data)
{
    node *temp = new(node);
    temp->data = data;
}

void inorder(node *root1)
{
    if (root1 != nullptr)
    {
        inorder(root1->left);
        cout<<root1->data;
        inorder(root1->right);
    }
}
int main()
{
    stack<node*> current;
    char data;
    while(true)
    {
        cin>>data;
        if(data== '.')
            break;
        node *z;
        node *temp = insert(data);
        // if operator
        if(data> 64 && data < 91)
            current.push(temp);

        // pop the elements
        else
        {
            node *left_curr = new(node);
            node *right_curr = new(node);
            right_curr = current.top();
            current.pop();
            left_curr = current.top();

            current.pop();
            if(root == nullptr)
                root = temp;
            temp->left = left_curr;
            temp->right = right_curr;
            current.push(temp);
        }
    }
    root = current.top();
    inorder(root);

}
