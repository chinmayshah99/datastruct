#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
int front = -1, rear = -1;

bool check(string a[], int pos);

int main(int argc, char const *argv[])
{
	string a[15], b[15];
	front = 0;
	for (int i = 0; i < 7; i++)
	{
		std::cin >> a[i];
		rear++;
    }
	int pos1, pos2, pos = 0;
	pos1 = pos2 = front;

	//nest this whole thing till rear = front
	do {
            pos = 0;
            pos2= pos;

		do {
			pos1 = pos2;

			if (check(a, pos1) && !check(a, pos1 + 1) && !check(a, pos1 + 2))
			{
				//do the calculcation
				int result;
				int v1 = stoi(a[pos1 + 1]);
				int v2 = stoi(a[pos1 + 2]);

				string operation = a[pos1];
				if (operation == "+")
					result = v1 + v2;
				else if (operation == "-")
					result = v1 - v2;
				else if (operation == "*")
					result = v1*v2;
				else
					result = v1 / v2;

				b[pos++] = to_string(result);
				pos1+=2;
				pos2 = pos1;
			}
			else
			{
			    b[pos++] = a[pos1];
                //pos++;
				pos2++;
			}


		} while (pos2 < rear - 1);
		for(int i = 0 ; i < 5; i++)
        {
            a[i] ="";
        }
		for(int i = 0 ; i < pos; i++)
        {
            a[i] = b[i];
        }
        rear = pos;
        if (pos == 1)
            break;
	} while (front != pos);

	cout<<a[0];




	return 0;
}


bool check(string a[], int pos)
{
	if (a[pos] == "+" ||
		a[pos] == "-" ||
		a[pos] == "*" ||
		a[pos] == "/")
		return true;
	else
		return false;
}
