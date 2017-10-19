#pragma once





/*Circular Linkedlist: The last element has a pointer to the first element
and the elements make a cycle*/


template <class T>
class LinkedList
{
private:
	struct Node
	{
		T data;
		Node* next;
	};
	Node* head;
	Node* tail;
	int size;
	int remove_count;
public:
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList &);
	LinkedList & operator=(const LinkedList &);
	void Copy(const LinkedList &);
	void DeleteList();
	void Insert(T);
	void Remove(Node*);
	void PrintSequence(int gap);
	void Print();
};


template <class T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
	tail = nullptr;
	size = 0;
	remove_count = 0;
}


template <class T>
LinkedList<T>::LinkedList(const LinkedList & other)
{
	Copy(other);
}


template <class T>
LinkedList<T>::~LinkedList()
{
	DeleteList();
}


template <class T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList & other)
{
	if (this != &other)
	{
		DeleteList();
		Copy(other);
	}
	return *this;
}


template <class T>
void LinkedList<T>::DeleteList()
{
	Node* to_destroy;
	tail->next = nullptr;
	while (head != nullptr)
	{
		to_destroy = head;
		head = head->next;
		delete to_destroy;
	}
}


template <class T>
void LinkedList<T>::Copy(const LinkedList & other)
{
	head = new Node;
	head->data = other.head->data;
	Node* to_copy = other.head;
	Node* copier = head;
	while (to_copy->next != other.head)
	{
		to_copy = to_copy->next;
		copier->next = new Node;
		copier->data = to_copy->data;
		copier = copier->next;
	}
	tail = copier;
}


template <class T>
void LinkedList<T>::Insert(T new_data)
{
	Node* new_node = new Node;
	new_node->data = new_data;
	new_node->next = nullptr;
	tail = new_node;
	if (head == nullptr)
	{
		head = new_node;
	}
	else
	{
		Node* current = head;
		while (current != nullptr)
		{
			if (current->next == nullptr)
			{
				current->next = new_node;
				break;
			}
			current = current->next;
		}
	}
	size++;
}


template <class T>
void LinkedList<T>::Remove(Node* to_remove)
{
	Node* current = head;
	if (current == to_remove)
	{
		tail->next = current->next;
		head = current->next;
		delete current;
	}
	else
	{
		while (current != to_remove)
		{
			if (current->next == to_remove)
			{
				if (current->next == tail)
				{
					tail = current;
				}
				Node* temp = to_remove;
				current->next = temp->next;
				delete temp;
				break;
			}
			current = current->next;
		}
	}
	size--;
}


template <class T>
void LinkedList<T>::PrintSequence(int gap)
{
	Print();
	Node* current = head;
	int counter = gap;
	while (size > 2)
	{
		if (counter == gap)
		{
			Node* temp = current->next;
			Remove(current);
			counter = 1;
			current = temp;
			Print();
			continue;
		}
		counter++;
		current = current->next;
	}
}


template <class T>
void LinkedList<T>::Print()
{
	std::cout << remove_count << ": ";
	remove_count++;
	Node* current = head;
	while (current != tail)
	{
		std::cout << current->data << " ";
		current = current->next;
	}
	std::cout << tail->data << std::endl;
}