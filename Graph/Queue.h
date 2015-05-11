using namespace std;

class Queue :public LinkList
{
public:
	void enqueue(Vertex V);
	Vertex dequeue();
};

void Queue::enqueue(Vertex V)
{
		Node* temp = new Node;
		temp->element1 = V;
		if (Tail == NULL)
		{
			Tail = temp;
			Tail->next = NULL;
		}
		else
		{
			Tail->next = temp;
			Tail = temp;
			Tail->next = NULL;
		}
		length++;
}

Vertex Queue::dequeue()
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