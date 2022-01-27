#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList()
{
	head = nullptr;
	tail = nullptr;
	count = 0;
}

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& original)
{
	Node* original_current = original.head;

	while (original_current != nullptr)
	{
		AddToTail(original_current->data);
		original_current = original_current->next;
	}
}

SinglyLinkedList::~SinglyLinkedList()
{
	while (count != 0)
		Clear();
}

void SinglyLinkedList::AddToHead(int data)
{
	Node* newElem = new Node();
	newElem->data = data;
	newElem->next = head;
	if (head == nullptr)
	{
		tail = newElem;
	}
	head = newElem;
	count++;
}

void SinglyLinkedList::AddToTail(int data)
{
	Node* newElem = new Node();
	newElem->data = data;
	if (tail == nullptr)
	{
		head = newElem;
	}
	else
	{
		tail->next = newElem;
	}
	tail = newElem;
	count++;
}

void SinglyLinkedList::InsertInto(int data, int position)
{
	if (position >= count)
	{
		AddToTail(data);
		return;
	}
	else if (position <= 0)
	{
		AddToHead(data);
		return;
	}

	Node* newElem = new Node();
	newElem->data = data;
	int i = 1;
	Node* beforeNew = head;
	while (i++ != position)
	{
		beforeNew = beforeNew->next;
	}
	newElem->next = beforeNew->next;
	beforeNew->next = newElem;

	count++;
}

void SinglyLinkedList::DeleteFromHead()
{
	if (count == 0)
	{		
		return;
	}
	Node* temp = head;
	head = head->next;
	delete temp;
	count--;
	if (head == nullptr)
	{
		tail = nullptr;
	}
}

void SinglyLinkedList::DeleteFromTail()
{
	if (count == 0) {		
		return;
	}
	DeleteByIndex(count - 1);
}

void SinglyLinkedList::DeleteByIndex(int position)
{
	if (position <= 0)
	{
		DeleteFromHead();
		return;
	}

	if (position >= count)
	{
		position = count - 1;
	}

	int i = 1;
	Node* beforeDel = head;
	while (i++ != position)
	{
		beforeDel = beforeDel->next;
	}
	Node* sacrifice = beforeDel->next;
	beforeDel->next = sacrifice->next;
	delete sacrifice;
	count--;
	if (beforeDel->next == nullptr)
	{
		tail = beforeDel;
	}
}

void SinglyLinkedList::Clear()
{
	while (head != nullptr)
	{
		DeleteFromHead();
	}
}

void SinglyLinkedList::Print() const
{
	if (count == 0)
	{
		cout << "Empty list!\n";
		return;
	}
	Node* current = head;
	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->next; // переместились вправо
	}
	cout << "\n";
}

int SinglyLinkedList::GetCount() const
{
	return count;
}

int SinglyLinkedList::IndexOf(int data) const
{
	if (count == 0)
	{
		return -1;
	}
	Node* temp = head;
	int i = 0;
	while (i < count)
	{
		if (data == temp->data)
		{
			return i;
		}
		i++;
		temp = temp->next;
	}

	return -1;
}

bool SinglyLinkedList::IsEmpty() const
{

	return !count;
}

int SinglyLinkedList::LastIndexOf(int data)
{
	if (IsEmpty())
	{
		return -1;
	}

	Node* current = head;
	int* arr = new int[count];

	for (int i = 0; i < count; i++) {
		arr[i] = current->data;
		current = current->next;
	}

	for (int i = 0; i < count; i++)
	{
		if (arr[i] == data)
		{
			return i;
		}
	}

	delete[] arr;
	return -1;
}

void SinglyLinkedList::Reverse()
{

	Node* current = head;
	int* arr = new int[count];

	for (int i = 0; i < count; i++) {
		arr[i] = current->data;
		current = current->next;
	}

	for (int i = 0; i < count; i++)
	{
		arr[i] = arr[count - 1];
		count--;
	}

	current = head;
	for (int i = 0; i < count; i++)
	{
		current->data = arr[i];
		current = current->next;
	}
	delete[] arr;
}

void SinglyLinkedList::SortAsc()
{
	Node* current = head;
	int* arr = new int[count];

	for (int i = 0; i < count; i++) {
		arr[i] = current->data;
		current = current->next;
	}
	int tmp = 0;
	for (int i = 0; i < count; i++)
	{
		for (int j = (count - 1); j >= (i + 1); j--)
		{
			if (arr[j] < arr[j - 1])
			{
				tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}
	current = head;
	for (int i = 0; i < count; i++)
	{
		current->data = arr[i];
		current = current->next;
	}
	delete[] arr;
}

void SinglyLinkedList::SortDesc()
{	
	Node* current = head;
	int* arr = new int[count];

	for (int i = 0; i < count; i++) {
		arr[i] = current->data;
		current = current->next;
	}
	int tmp = 0;
	for (int i = 0; i < count; i++)
	{
		for (int j = (count - 1); j >= (i + 1); j--)
		{
			if (arr[j] > arr[j - 1])
			{
				tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}
	current = head;
	for (int i = 0; i < count; i++)
	{
		current->data = arr[i];
		current = current->next;
	}
	delete[] arr;
}

void SinglyLinkedList::Shuffle()
{
	Node* current = head;
	int* arr = new int[count];


	for (int i = 0; i < count; i++) {
		arr[i] = current->data;
		current = current->next;
	}
	random_shuffle(arr, arr + count);
	current = head;
	for (int i = 0; i < count; i++)
	{
		current->data = arr[i];
		current = current->next;
	}
	delete[] arr;
}

bool SinglyLinkedList::Equals(const SinglyLinkedList* list) const
{
	Node* temp = head;
	Node* temp_list = list->head;
	int i = 0;

	if (count == list->count)
	{
		while (i < count)
		{
			if ((temp->data != temp_list->data))
			{
				return false;
			}
			temp = temp->next;
			temp_list = temp_list->next;
			i++;
		}
	}
	else if (count != list->count)
	{
		return false;
	}

	return true;
}

SinglyLinkedList SinglyLinkedList::Clone() const
{
	SinglyLinkedList* list = new SinglyLinkedList();
	Node* temp = head;

	for (int i = 0; i < count; i++)
	{
		list->AddToTail(temp->data);
		temp = temp->next;
	}
	return *list;
}

bool SinglyLinkedList::Contains(int data) const
{
	Node* temp = head;

	int i = 0;
	while (i < count)
	{
		if (data == temp->data)
		{
			return true;
		}
		i++;
		temp = temp->next;
	}
	return false;
}

void SinglyLinkedList::SetAt(int position, int d)
{
	Node* current = head;
	for (int i = 0; i < count; i++)
	{
		if (i == position)
		{
			current->data = d;
		}
		current = current->next;
	}
}

int* SinglyLinkedList::ToArray()
{
	return operator int* ();
}

SinglyLinkedList SinglyLinkedList::MergeWith(const SinglyLinkedList& list)
{
	SinglyLinkedList current = *this;
	Node* current_list = list.head;

	while (current_list != 0)
	{
		AddToTail(current_list->data);
		current_list = current_list->next;
	}
	return current;
}

bool SinglyLinkedList::operator <(const SinglyLinkedList& list)
{
	return count < list.count;
}

bool SinglyLinkedList::operator >(const SinglyLinkedList& list)
{
	return count > list.count;
}

bool SinglyLinkedList::operator <=(const SinglyLinkedList& list)
{
	return count < list.count || count == list.count;
}

bool SinglyLinkedList::operator >=(const SinglyLinkedList& list)
{
	return count > list.count || count == list.count;
}

bool SinglyLinkedList::operator ==(const SinglyLinkedList& list)
{
	Node* temp = head;
	Node* temp_list = list.head;
	int i = 0;

	if (count == list.count)
	{
		while (i < count)
		{
			if ((temp->data != temp_list->data))
			{
				return false;
			}
			temp = temp->next;
			temp_list = temp_list->next;
			i++;
		}
	}
	else if (count != list.count)
	{
		return false;
	}

	return true;
}

bool SinglyLinkedList::operator !=(const SinglyLinkedList& list)
{
	Node* temp = head;
	Node* temp_list = list.head;
	int i = 0;

	if (count == list.count)
	{
		while (i < count)
		{
			if ((temp->data == temp_list->data))
			{
				return false;
			}
			temp = temp->next;
			temp_list == temp_list->next;
			i++;
		}
	}
	return true;
}

SinglyLinkedList& SinglyLinkedList::operator =(const SinglyLinkedList& list)
{
	if (this == &list)
		return *this;
	this->~SinglyLinkedList();

	Node* list_current = list.head;

	while (list_current != nullptr)
	{
		AddToTail(list_current->data);
		list_current = list_current->next;
	}
	return *this;
}

const int& SinglyLinkedList::operator [](int index) const
{
	Node* temp = head;
	int i = 0;
	if (index >= 0 && index < count - 1)
	{
		while (i < count)
		{
			if (i == index)
			{
				return temp->data;
			}
			temp = temp->next;
			i++;
		}
	}
	else
	{
		index = 0;
	}
}

SinglyLinkedList& SinglyLinkedList::operator +(const SinglyLinkedList& list)
{
	SinglyLinkedList current = *this;

	Node* temp = list.head;

	while (temp != 0)
	{
		current.AddToTail(temp->data);
		temp = temp->next;
	}
	return current;
}

SinglyLinkedList::operator int* ()
{
	int* arr = new int[count];

	Node* temp = head;
	int i = 0;
	for (i = 0; i < count; i++)
	{
		arr[i] = temp->data;
		temp = temp->next;
	}
	return arr;
}