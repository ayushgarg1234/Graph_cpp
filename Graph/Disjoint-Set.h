using namespace std;

class rootedtreenode
{
public:
	int parent;
	int rank;
};

class rootedtree   //disjoint-set
{
public:
	int size;
	rootedtreenode* disjoint_set;

	rootedtree(int graphsize);
	void Make_Set(int V);
	int Find_Set(int V);
	void Union(int x, int y);
	void Link(int x, int y);
};

rootedtree::rootedtree(int graphsize)
{
	size = graphsize;
	disjoint_set = new rootedtreenode[graphsize];
}

void rootedtree::Union(int x, int y)
{
	Link(Find_Set(x), Find_Set(y));
}

void rootedtree::Link(int x, int y)
{
	if (disjoint_set[x].rank > disjoint_set[y].rank)
		disjoint_set[y].parent = x;
	else
	{
		disjoint_set[x].parent = y;
		if (disjoint_set[x].rank == disjoint_set[y].rank)
			disjoint_set[y].rank++;
	}
}

int rootedtree::Find_Set(int V)
{
	if (disjoint_set[V].parent != V)
	{
		return Find_Set(disjoint_set[V].parent);
	}
	else
		return disjoint_set[V].parent;
}

void rootedtree::Make_Set(int V)
{
	disjoint_set[V].parent = V;
	disjoint_set[V].rank = 0;
}