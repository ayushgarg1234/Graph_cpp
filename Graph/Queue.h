using namespace std;

class Queue
{
public:
	LinkList* LQ;
	Queue();
	bool Isempty();
	void enqueue(Vertex V);
	Vertex dequeue();
};


Queue::Queue()
{
	LQ = new LinkList();
}

bool Queue::Isempty()
{
	return LQ->Isempty1();
}

void Queue::enqueue(Vertex V)
{
		Node* temp = new Node;
		temp->element1 = V;
		if (LQ->Tail == NULL)
		{
			LQ->Tail = temp;
			LQ->Tail->next = NULL;
			LQ->Head = LQ->Tail;
		}
		else
		{
			LQ->Tail->next = temp;
			LQ->Tail = temp;
			LQ->Tail->next = NULL;
		}
		LQ->length++;
}

Vertex Queue::dequeue()
{
	Vertex temp;
	temp.vertex = NULL;
	if (LQ->Head)
	{
		if (LQ->Head == LQ->Tail)
		{
			temp = LQ->Head->element1;
			LQ->Head = LQ->Head->next;
			LQ->Tail = LQ->Head;
		}
		else
		{
			temp = LQ->Head->element1;
			LQ->Head = LQ->Head->next;
		}
		LQ->length--;
	}
	return temp;
}