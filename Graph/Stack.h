using namespace std;

class Stack
{
public:
	LinkList* LS;
	Stack();
	bool Isempty();
	void push(Vertex V);
	Vertex pop();
	Vertex top();
};

Stack::Stack()
{
	LS = new LinkList();
}

bool Stack::Isempty()
{
	return LS->Isempty1();
}

void Stack::push(Vertex V)
{
	Node* temp = new Node;
	temp->element1 = V;
	if (LS->Head == NULL)
	{
		LS->Head = temp;
		LS->Head->next = NULL;
	}
	else
	{
		temp->next = LS->Head;
		LS->Head = temp;
	}
	LS->length++;
}

Vertex Stack::pop()
{
	Vertex temp;
	temp.vertex = NULL;
	if (LS->Head)
	{
		temp = LS->Head->element1;
		LS->Head = LS->Head->next;
		LS->length--;
	}
	return temp;
}

Vertex Stack::top()
{
	Vertex temp = pop();
	push(temp);
	return temp;
}