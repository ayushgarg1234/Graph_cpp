#include <iostream>
#include <string.h>
#include <fstream>
#include "Vertex.h"
#include "linearList_Sequential.h" 
#include "LinkList.h"
#include "Stack.h"
#include "Queue.h"
#include "Graph.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		ifstream inputfile;
		cout << argv[1] << endl;
		inputfile.open(argv[1]);
		char a = NULL;
		int count = 0;
		if (!inputfile.eof())
		{
			inputfile.get(a);
		}
		while (a != '\n' && a != NULL)
		{
			if (a != ' ')
				count++;
			if (!inputfile.eof())
			{
				inputfile.get(a);
			}
			else
			{
				a = NULL;
				break;
			}
		}
		inputfile.close();
		inputfile.open(argv[1]);
		if (count > 1)
		{
			graph G(count);
			int **inputarray = new int*[count];
			for (int i = 0; i < count; ++i)
			{
				inputarray[i] = new int[count];
			}
			for (int i = 0; i < count; i++)
			{
				for (int j = 0; j < count; j++)
				{
					inputfile >> inputarray[i][j];
					if (inputarray[i][j] == 1)
						G.graphinsert(i, j);
				}
			}
			for (int i = 0; i < count; i++)
			{
				for (int j = 0; j < count; j++)
				{
					cout << inputarray[i][j] << " ";
				}
				cout << endl;
			}

			bool matrix = 1;
			for (int i = 0; i < count; i++)
			{
				for (int j = 0; j < count; j++)
				{
					if (inputarray[i][j] != inputarray[j][i])
					{
						matrix = 0;
						break;
					}
					if (matrix == 0)
						break;
				}
			}
			if (matrix)
			{
				cout << "It's a symmetric matrix." << endl;
				cout << "What do you want to do ? Press 'b' for BFS and 'd' for DFS." << endl;
				char userin;
				cin >> userin;
				if (userin == 'b')
				{
					cout << "BFS Tree" << endl;
					G.BFS();
				}
				else if (userin == 'd')
				{
					cout << "DFS Forest" << endl;
					G.DFS();
				}
				else
					cout << "wrong input." << endl;
			}
			else
			{
				cout << "It's not a symmetric matrix." << endl;
				cout << "DFS Forest" << endl;
				G.DFS();
			}

			cin >> count;
		}
		else
		{
			cout << "very few inputs entered." << endl;
			exit(0);
		}
	}
	else
	{
		cout << "Error no arguement entered" << endl;
		exit(0);
	}

	return 0;
}
