using namespace std;

class LinearList{
public:
	int MaxSize;
	int len;
	char *element;
	LinearList(int  MaxSize);
	LinearList(const LinearList& temp);
	~LinearList();
	bool isEmpty();
	int  length();
	int  maxSize();
	char returnListElement(int k);
	bool find(int  k);
	int  search(char key);
	void deleteElement(int  k);
	LinearList  insert(int  k, char x);
};

LinearList::LinearList(int MaxListSize)
{ // Constructor for the sequential linear list
	MaxSize = MaxListSize;
	element = new  char[MaxSize];
	len = 0;
}

LinearList::LinearList(const LinearList& temp)
{ // Copy constructor
	MaxSize = temp.MaxSize;
	element = new char[MaxSize];
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

char  LinearList::returnListElement(int k)
{ //Function that returns the k-th element of the list
	return element[k];
}
bool  LinearList::find(int  k)
{ // Set x to the kth element and return true if kth element is present otherwise return false. 
	if (k >= len)   return   false;
	return   true;
}

int  LinearList::search(char key)
{ // Search for x and return the position if found, else return 0.
	for (int i = 0; i < len; i++)
		if (element[i] == key)    return   ++i;
	return   0;
}

void LinearList::deleteElement(int  k)
{
	element[k] = NULL;       //flag
	/*for (int i = k; i < len; i++)
		element[i - 1] = element[i];*/
	len--;
}

LinearList  LinearList::insert(int  k, char x)
{ // Insert x after kth element. 
	/*for (int i = len - 1; i >= k; i--){
		element[i + 1] = element[i];
		}*/
	element[k] = x;
	len++;
	return   *this;
}