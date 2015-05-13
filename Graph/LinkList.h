using namespace std;

class Node{
public:
	Vertex element1;
	Node *next;
};

class LinkList{
public:
	int length;
	Node* Head;
	Node* Tail;
	LinkList();
	~LinkList();
	Vertex returnListElement(int linkindex);
	bool search1(int key);
	int insert1(Vertex x);
	void deleteElement1(int key);
	bool Isempty1();
	int lengthreturn(LinkList L);
	//void updatefile1();
};

LinkList::LinkList()
{
	Head = Tail = NULL;
	length = 0;
}

LinkList::~LinkList()
{

}

Vertex LinkList::returnListElement(int linkindex)
{
	Node* temp = Head;
	for (int i = 0; i < linkindex; i++)
	{
		temp = temp->next;
	}
	return temp->element1;
}

int LinkList::insert1(Vertex x)
{
	Node* newelement = new Node;
	newelement->element1 = x;
	newelement->next = Head;
	Head = newelement;
	length++;
	return 0;
}

bool LinkList::search1(int key)
{
	Node* temp = Head;
	while (temp && temp->element1.vertex != key)
	{
		temp = temp->next;
	}
	if (temp)
	{
		cout << temp->element1.vertex << endl;
		return true;
	}
	return false;
}

void LinkList::deleteElement1(int key)
{
	Node* temp = Head;
	Node* previous = NULL;
	while (temp && temp->element1.vertex != key)
	{
		previous = temp;
		temp = temp->next;
	}
	if (temp)
	{
		if (previous)
			previous->next = temp->next;
		if (temp->next == NULL)
		{
			Tail = previous;
		}
		if (previous == NULL)
			Head = Tail;
		length--;
	}
}

/*void LinkList::updatefile1()
{
ofstream file1;
file1.open("input.txt", std::ios_base::app);
int a = ' ';
int b = '\n';
book tempbook;
Node* temp = Head;
while (temp)
{

if (Head->element1.key[0] != 0)
{
tempbook = temp->element1;
file1 << tempbook.key << a;
file1 << tempbook.book_title << a;
file1 << tempbook.author1 << a;
file1 << tempbook.author2 << a;
file1 << tempbook.author3 << a;
file1 << tempbook.publisher << a;
file1 << tempbook.price << a;
file1 << tempbook.number_of_books << b;
}
temp = temp->next;
}
file1.close();
}*/

bool LinkList::Isempty1()
{
	if (length == 0)
		return true;
	return false;
}

int LinkList::lengthreturn(LinkList L)
{
	return L.length;
}

class LinkListarray{
public:
	int MaxSize;
	int len;
	LinkList *element;
	LinkListarray(int  MaxSize);
	LinkListarray(const LinkListarray& temp);
	~LinkListarray();
	bool isEmpty();
	int  length();
	int  maxSize();
	Vertex returnListElement(int k, int j);
	bool find(int  k);
	int  search(int key, int index);
	void deleteElement(int  k, int key);
	int insert(int  k, Vertex x);
	//void updatefile(int k);
};

LinkListarray::LinkListarray(int MaxListSize)
{ // Constructor for the sequential linear list
	MaxSize = MaxListSize;
	element = new  LinkList[MaxSize];
	len = 0;
}

LinkListarray::LinkListarray(const LinkListarray& temp)
{ // Copy constructor
	MaxSize = temp.MaxSize;
	element = new LinkList[MaxSize];
	len = temp.len;
	memcpy(element, temp.element, MaxSize);
}

LinkListarray::~LinkListarray()
{ // Distructor for the sequential linear list
	delete[] element;
}

bool  LinkListarray::isEmpty()
{ // Function that checks whether the list is empty
	return   len == 0;
}

int  LinkListarray::length()
{ // Function that returns the length of the list
	return   len;
}

int  LinkListarray::maxSize()
{ // Function that returns the length of the list
	return   MaxSize;
}

Vertex  LinkListarray::returnListElement(int k, int j)
{ //Function that returns the k-th element of the list
	return element[k].returnListElement(j);
}
bool  LinkListarray::find(int  k)
{ // Set x to the kth element and return true if kth element is present otherwise return false. 
	if (element[k].length == 0)   return   false;
	return   true;
}

int  LinkListarray::search(int key, int index)
{ // Search for x and return the position if found, else return 0.
	if (element[index].search1(key) == true)    return   1;
	return   0;
}

void LinkListarray::deleteElement(int  k, int key)
{
	element[k].deleteElement1(key);

	len--;
}

/*void LinkListarray::updatefile(int index)
{
element[index].updatefile1();
}*/

int LinkListarray::insert(int  k, Vertex x)
{ // Insert x after kth element. 

	int value = element[k].insert1(x);
	len++;
	return   value;
}

