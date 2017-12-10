/*
	Write a program that reads a list of names and telephone numbers from user and insert them into BST tree. 
	Once the tree has been built, present the user with a menu that allows him to search the list for a specified name, 
	insert a new name, or print the entire phone list. 
*/
// Chinmay Shah


#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef struct node
{
	char name[20];
	long long unsigned int phoneno;
	node *left, *right;
	// yes you can make a constructor within struct
	node()
	{
		left = NULL;
		right = NULL;
	}
} node;

// initializing root to null
node *start = NULL;

int compare(node *traverse, node *temp);

void insert()
{
	node *temp = new (node);

	// taking input from user
	cin >> temp->name;
	cin >> temp->phoneno;

	if (start == NULL)
	{
		start = temp;
	}
	else
	{
		node *traverse;
		traverse = start;
	abc:
		int where = compare(traverse, temp);

		if (where == 0)
		{
			if (traverse->left == NULL)
				traverse->left = temp;
			else
			{
				traverse = traverse->left;
				goto abc;
			}
		}

		else if (where == 1)
		{
			if (traverse->right == NULL)
				traverse->right = temp;
			else
			{
				traverse = traverse->right;
				goto abc;
			}
		}
	}
	cout << temp->name << " inserted successfully" << endl;
	//return true;
}

/*
    function to compare to name
    compares each letter by letter of two strings
    the first is of parent and second is word to be inserted

    the function calculates the length of parent string
    then it starts comparing two characters (ASCII CODE)
    if ascii code(parent string[i]) < given string[i] returns 0
    else returns 1

    it returns 0 in all other case

*/
int compare(node *traverse, node *temp)
{
	int len = strlen(traverse->name);
	int i = 0;

	do
	{
		if (traverse->name[i] == temp->name[i])
		{
			i++;
			continue;
		}
		else if (traverse->name[i] < temp->name[i])
			return 0;
		else
			return 1;
	} while (len != i);
	return 0;
}

/*
    search function.
    traverses through the tree like binary search tree

*/
bool search()
{
	char uname[20];
	cin >> uname;

	node *temp = new (node);

	strcpy(temp->name, uname);
	temp->left = NULL;
	temp->right = NULL;

	node *traverse;
	traverse = start;
	if (strcmp(traverse->name, temp->name) == 0)
		return true;
	else
	{
	abc:
		int where = compare(traverse, temp);

		if (where == 0)
		{
			if (traverse->left == NULL)
				return false;
			else
			{
				traverse = traverse->left;
				if (strcmp(traverse->name, temp->name) == 0)
				{
					cout << traverse->phoneno;
					return true;
				}
				goto abc;
			}
		}

		else if (where == 1)
		{
			if (traverse->right == NULL)
				return false;
			else
			{
				traverse = traverse->right;
				if (strcmp(traverse->name, temp->name) == 0)
				{
					cout << traverse->phoneno;
					return true;
				}

				goto abc;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	char ch;
	cout << "a - insert, b - search, c-display,  . exit" << endl;
	while (true)
	{
		cin >> ch;
		switch (ch)
		{
		case 'a':
		{
			insert();
			break;
		}
		case 'b':
		{
			bool z = search();
			if (z == false)
				cout << "not found" << endl;
			break;
		}
		case 'c':
		{
			/*
                    traverse function. displays binary treee
                    displays in level order
                */
			cout << "\nqueue" << endl;
			queue<node *> zz;
			zz.push(start);
			while (!zz.empty())
			{
				node *temp = zz.front();
				cout << " " << temp->phoneno << "  " << temp->name;
				if (temp->left != NULL)
					zz.push(temp->left);
				if (temp->right != NULL)
					zz.push(temp->right);
				zz.pop();
				cout << endl;
			}
			break;
		}
		case '.':
		{
			return 0;
			break;
		}
		default:
		{
			insert();
			break;
		}
		}
	}
	return 0;
}