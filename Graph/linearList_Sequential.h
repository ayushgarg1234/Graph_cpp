using namespace std;

class LinearList{
public:
	int MaxSize;
	int len;
	Vertex *element;
	LinearList(int  MaxSize);
	LinearList(const LinearList& temp);
	~LinearList();
	bool isEmpty();
	int  length();
	int  maxSize();
	int returnListElement(int k);
	bool find(int  k);
	int  search(int key);
	void deleteElement(int  k);
	LinearList  insert(int  k, Vertex x);
};

LinearList::LinearList(int MaxListSize)
{ // Constructor for the sequential linear list
	MaxSize = MaxListSize;
	element = new  Vertex[MaxSize];
	len = 0;
}

LinearList::LinearList(const LinearList& temp)
{ // Copy constructor
	MaxSize = temp.MaxSize;
	element = new Vertex[MaxSize];
	len = temp.len;
	memcpy(element, temp.element, MaxSize);
}

LinearList::~LinearList()
{ // Distructor for the sequential linear list
	delete[] element;
}

bool  LinearList::isEmpty()
{ // Function that checks whether the list is empty
	return   len == 0;
}

int  LinearList::length()
{ // Function that returns the length of the list
	return   len;
}

int  LinearList::maxSize()
{ // Function that returns the length of the list
	return   MaxSize;
}

int  LinearList::returnListElement(int k)
{ //Function that returns the k-th element of the list
	return element[k].vertex;
}
bool  LinearList::find(int  k)
{ // Set x to the kth element and return true if kth element is present otherwise return false. 
	if (k >= len)   return   false;
	return   true;
}

int  LinearList::search(int key)
{ // Search for x and return the position if found, else return 0.
	for (int i = 0; i < len; i++)
		if (element[i].vertex == key)    return   ++i;
	return   0;
}

void LinearList::deleteElement(int  k)
{
	element[k].vertex = NULL;       //flag
	element[k].color = NULL;
	/*for (int i = k; i < len; i++)
		element[i - 1] = element[i];*/
	len--;
}

LinearList  LinearList::insert(int  k, Vertex x)
{ // Insert x after kth element. 
	/*for (int i = len - 1; i >= k; i--){
		element[i + 1] = element[i];
		}*/
	element[k] = x;
	len++;
	return   *this;
}