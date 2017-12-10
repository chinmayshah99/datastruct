/*
    Write a program to read postfix expression from user, represent it in a form of tree using concept of Stack. 
    Display expression in infix form by inorder traversal of tree.

    Rules for converting postfix expression into tree:
    1.	Create a Stack
    2.	Read next input symbol 
    3.	If the symbol is operand, create a new expression tree with single node representing value and push it into the stack.
    4.	If the symbol is an operator, pop out two trees (two nodes T1 and T2) from the Stack. Create a new tree with the operator as the root and T1 and T2as two children. Push this new tree back into the stack.
    5.	Repeat this process till the whole input is read.
    6.	At the end, the stack will contain a single tree which would be the output.

*/
// Chinmay Shah

#include <iostream>
#include <stack>

using namespace std;

typedef struct node
{
    char data;
    node *left, *right;

    node()
    {
        left = nullptr;
        right = nullptr;
    }
} node;

node *root = nullptr;

node *insert(char data)
{
    node *temp = new (node);
    temp->data = data;
}

void inorder(node *root1)
{
    if (root1 != nullptr)
    {
        inorder(root1->left);
        cout << root1->data;
        inorder(root1->right);
    }
}
int main()
{
    stack<node *> current;
    char data;
    while (true)
    {
        cin >> data;
        if (data == '.')
            break;
        node *z;
        node *temp = insert(data);
        // if operator
        if (data > 64 && data < 91)
            current.push(temp);

        // pop the elements
        else
        {
            node *left_curr = new (node);
            node *right_curr = new (node);
            right_curr = current.top();
            current.pop();
            left_curr = current.top();

            current.pop();
            if (root == nullptr)
                root = temp;
            temp->left = left_curr;
            temp->right = right_curr;
            current.push(temp);
        }
    }
    root = current.top();
    inorder(root);
}
