using namespace std;

class Stack :public LinkList
{
public:
	void push(Vertex V);
	Vertex pop();
};

void Stack::push(Vertex V)
{
	Node* temp = new Node;
	temp->element1 = V;
	if (Head == NULL)
	{
		Head = temp;
		Head->next = NULL;
	}
	else
	{
		temp->next = Head;
		Head = temp;
	}
	length++;
}

Vertex Stack::pop()
{
	Vertex temp;
	temp.vertex = NULL;
	if (Head)
	{
		temp = Head->element1;
		Head = Head->next;
		length--;
	}
	return temp;
}