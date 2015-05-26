using namespace std;

class Heap
{
private:
	int maxsize, heapsize;
public:
	Vertex* heap;
	int* indexstore;
	Heap(int size);
	int returnparent(int i);
	int returnleftchild(int i);
	int returnrightchild(int i);
	Vertex returnminimum();
	void insert(Vertex element);
	void decreasekey(int key, int index);
	void heapify(int index);
	Vertex extractminimum();
	bool Isempty();
	int search(int vertex);
};

Heap::Heap(int size)
{
	maxsize = size;
	heapsize = 0;
	indexstore = new int[size];
	heap = new Vertex[maxsize + 1];
}

bool Heap::Isempty()
{
	if (heapsize == 0)
		return true;
	return false;
}

int Heap::search(int vertex)
{
	return indexstore[vertex];
}

int Heap::returnparent(int i)
{
	return (int)(i / 2);
}

int Heap::returnleftchild(int i)
{
	return 2 * i;
}

int Heap::returnrightchild(int i)
{
	return (2 * i + 1);
}

Vertex Heap::returnminimum()
{
	return heap[1];
}

void Heap::insert(Vertex element)
{
	heapsize++;
	heap[heapsize] = element;
	indexstore[element.vertex] = heapsize;
	decreasekey(element.key, heapsize);
}

void Heap::decreasekey(int key, int index)
{
	heap[index].key = key;
	while (index > 1 && heap[returnparent(index)].key > heap[index].key)
	{
		indexstore[heap[returnparent(index)].vertex] = index;
		indexstore[heap[index].vertex] = returnparent(index);
		Vertex temp;
		temp = heap[returnparent(index)];
		heap[returnparent(index)] = heap[index];
		heap[index] = temp;
		index = returnparent(index);
	}
}

void Heap::heapify(int index)
{
	int l = returnleftchild(index);
	int r = returnrightchild(index);
	int smallest;
	if (l <= heapsize && heap[l].key < heap[index].key)
		smallest = l;
	else
		smallest = index;
	if (r <= heapsize && heap[r].key < heap[smallest].key)
		smallest = r;
	if (smallest != index)
	{
		indexstore[heap[smallest].vertex] = index;
		indexstore[heap[index].vertex] = smallest;
		Vertex temp;
		temp = heap[smallest];
		heap[smallest] = heap[index];
		heap[index] = temp;
		heapify(smallest);
	}
}

Vertex Heap::extractminimum()
{
	Vertex min = heap[1];
	heap[1] = heap[heapsize];
	heapsize--;
	heapify(1);
	return min;
}
