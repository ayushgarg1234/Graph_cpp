#include <iostream>
#include <string.h>
#include <fstream>
#include <algorithm>
#include "Vertex.h"
#include "linearList_Sequential.h" 
#include "LinkList.h"
#include "Stack.h"
#include "Queue.h"
#include "Disjoint-Set.h"
#include "Graph.h"

using namespace std;

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		ifstream inputfile;
		cout << argv[1] << endl;
		inputfile.open(argv[1]);
		char a = '\0';
		int count = 0;
		if (!inputfile.eof())
		{
			inputfile.get(a);
		}
		while (a != '\n' && a != '\0')
		{
			if (a == ' ')
				count++;
			if (!inputfile.eof())
			{
				inputfile.get(a);
			}
			else
			{
				a = '\0';
				break;
			}
		}
		inputfile.close();
		inputfile.open(argv[1]);
		if (count > 0)
		{
			count++;
			graph G(count);
			int **inputarray = new int*[count];
			for (int i = 0; i < count; ++i)
			{
				inputarray[i] = new int[count];
			}
			int edgecount = 0;
			G.inputarray1 = inputarray;
			for (int i = 0; i < count; i++)
			{
				for (int j = 0; j < count; j++)
				{
					inputfile >> inputarray[i][j];
					if (inputarray[i][j] != 0)
					{
						edgecount++;
						G.graphinsert(i, j);
					}
				}
			}
			G.edgecount1 = edgecount;
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
				cout << "What do you want to do ? Press 'b' for BFS, 'd' for DFS and 'k' for Kruskal's." << endl;
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
				else if (userin == 'k')
				{
					G.Kruskal();
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
