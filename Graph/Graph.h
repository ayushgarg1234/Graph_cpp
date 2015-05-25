using namespace std;

class graph
{
private:
public:
	int** inputarray1;
	int edgecount1;
	int graphsize;
	graph(int size);
	~graph();
	LinkListarray* Graph;
	void graphinsert(int i, int j);
	void BFS();
	void DFS();
	void Kruskal();
};

graph::graph(int size)
{
	graphsize = size;
	Graph = new LinkListarray(size);
}

graph::~graph()
{

}

bool compareedge(Edge a, Edge b)
{
	return a.weight < b.weight;
}

void graph::Kruskal()
{
	Edge* array = new Edge[edgecount1];
	int temp = 0;
	for (int i = 0; i < graphsize; i++)
	{
		for (int j = 0; j < graphsize; j++)
		{
			if (inputarray1[i][j] != 0)
			{
				array[temp].initial = i;
				array[temp].final = j;
				array[temp].weight = inputarray1[i][j];
				temp++;
			}
		}
	}

	sort(array, array + edgecount1, compareedge);

	rootedtree Set(graphsize);
	for (int i = 0; i < graphsize; i++)
	{
		Set.Make_Set(i);
	}

	Queue Q;

	for (int i = 0; i < edgecount1; i++)
	{
		if (Set.Find_Set(array[i].initial) != Set.Find_Set(array[i].final))
		{
			Vertex initial, final, weight;
			initial.vertex = array[i].initial;
			final.vertex = array[i].final;
			weight.vertex = array[i].weight;
			Q.enqueue(initial);
			Q.enqueue(final);
			Q.enqueue(weight);
			Set.Union(array[i].initial, array[i].final);
		}
	}
	cout << "Minimum spanning tree is as follows." << endl;
	while (!Q.Isempty())
	{
		Vertex initial, final, weight;
		initial = Q.dequeue();
		final = Q.dequeue();
		weight = Q.dequeue();
		cout << "(" << initial.vertex << ", " << final.vertex << ")" << " weight = " << weight.vertex << endl;
	}
}

void graph::DFS()
{
	char* color = new char[graphsize];
	int* intime = new int[graphsize];
	int* outtime = new int[graphsize];
	int* temparray = new int[100];
	int temparraycount = 0;
	Vertex* predecessor = new Vertex[graphsize];
	for (int i = 0; i < graphsize; i++)
	{
		color[i] = 'w';
		predecessor[i].vertex = -1;
	}
	int time = 0;

	Stack S;
	int i = 0;
	while (i < graphsize)
	{
		if (color[i] == 'w')
		{
			cout << "Source is: " << i << endl;
			color[i] = 'g';
			time++;
			predecessor[i].vertex = -1;
			intime[i] = time;

			Vertex V;
			V.vertex = i;
			S.push(V);
			temparray[temparraycount] = V.vertex;
			temparraycount++;
			while (!S.Isempty())
			{
				V = S.top();
				int i;
				bool check = 0;
				for (i = 0; i < Graph->element[V.vertex].length; i++)
				{
					Vertex temp = Graph->returnListElement(V.vertex, i);
					if (color[temp.vertex] == 'w')
					{
						check = 1;
						color[temp.vertex] = 'g';
						predecessor[temp.vertex] = V;
						time++;
						intime[temp.vertex] = time;
						S.push(temp);
						temparray[temparraycount] = temp.vertex;
						temparraycount++;
						break;
					}
				}
				if (i == Graph->element[V.vertex].length && check == 0)
				{
					time++;
					outtime[V.vertex] = time;
					Vertex print = S.pop();
					color[print.vertex] = 'b';
					cout << print.vertex << " " << predecessor[print.vertex].vertex << " " << intime[print.vertex] << " " << outtime[print.vertex] << endl;
				}
			}
		}
		i++;
	}
	cout << "edge by edge traversal" << endl;
	for (int i = 0; i < temparraycount; i++)
	{
		if (predecessor[temparray[i]].vertex != -1)
		{
			cout << "(" << predecessor[temparray[i]].vertex << "," << temparray[i] << ")" << endl;
		}
	}
}

void graph::BFS()
{
	char* color = new char[graphsize];
	int* distance = new int[graphsize];
	Vertex* predecessor = new Vertex[graphsize];
	int* temparray = new int[100];
	int temparraycount = 0;
	for (int i = 0; i < graphsize; i++)
	{
		color[i] = 'w';
		distance[i] = 10000;
		predecessor[i].vertex = -1;
	}
	int temp = rand() % graphsize;
	cout << "Source is: " << temp << endl;
	color[temp] = 'g';
	distance[temp] = 0;

	Queue Q;
	Vertex V;
	V.vertex = temp;
	Q.enqueue(V);

	while (!Q.Isempty())
	{
		Vertex U;
		U = Q.dequeue();
		color[U.vertex] = 'b';
		cout << U.vertex << " " << distance[U.vertex] << " " << predecessor[U.vertex].vertex << endl;
		temparray[temparraycount] = predecessor[U.vertex].vertex;
		temparray[temparraycount + 1] = U.vertex;
		temparraycount = temparraycount + 2;
		for (int i = 0; i < Graph->element[U.vertex].length; i++)
		{
			Vertex temp = Graph->returnListElement(U.vertex, i);
			if (color[temp.vertex] == 'w')
			{
				color[temp.vertex] = 'g';
				distance[temp.vertex] = distance[U.vertex] + 1;
				predecessor[temp.vertex] = U;
				Q.enqueue(temp);
			}
		}
	}
	cout << "edge by edge traversal." << endl;
	for (int i = 2; i < temparraycount; i = i + 2)
	{
		cout << "(" << temparray[i] << "," << temparray[i + 1] << ")" << endl;
	}
}

void graph::graphinsert(int i, int j)
{
	Vertex temp;
	temp.vertex = j;
	//temp.color = 'w';
	Graph->insert(i, temp);
}