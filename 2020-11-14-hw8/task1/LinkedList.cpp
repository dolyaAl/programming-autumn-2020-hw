#include "LinkedList.h"

LinkedList::LinkedList(const LinkedList& list)
{
    tail = head = nullptr;
    count = 0;

    Node* temp = list.head;
    while (temp != nullptr)
    {
        addToTail(temp->data);
        temp = temp->next;
    }
}

LinkedList::~LinkedList()
{
    Node* temp = head;
    while (temp != nullptr)
    {
        Node* node = temp;
        temp = temp->next;
        delete node;
    }
}

bool LinkedList::indexValid(int index)
{
    return (index >= 0 && index < count);
}

int LinkedList::length()
{
    return count;
}

bool LinkedList::addToHead(int element)
{
    if (head == nullptr) 
    {
        head = tail = new Node(element);
    }
    else 
    {
        head = new Node(element, head);
    }
    ++count;
    return true;
}

bool LinkedList::addToTail(int element)
{
    if (tail == nullptr) 
    {
        head = tail = new Node(element);
    }
    else 
    {
        tail->next = new Node(element);
        tail = tail->next;
    }
    ++count;
    return true;
}

bool LinkedList::add(int index, int element)
{
    if (index == 0)
    {
        return addToHead(element);
    }
    if (index == count)
    {
        return addToTail(element);
    }
    if (!indexValid(index))
    {
        return false;
    }

    Node* temp = head;
    for (int i = 0; i < index - 1; ++i)
    {
        temp = temp->next;
    }
    temp->next = new Node(element, temp->next);
    ++count;

    return true;
}

int LinkedList::get(int index)
{
    if (!indexValid(index))
    {
        return -1;
    }
    if (index == 0)
    {
        return head->data;
    }
    if (index == count - 1)
    {
        return tail->data;
    }

    Node* temp = head;
    for (int i = 0; i < index; ++i)
    {
        temp = temp->next;
    }
    return temp->data;

}

bool LinkedList::set(int index, int element)
{
    if (!indexValid(index))
    {
        return false;
    }
    if (index == 0)
    {
        head->data = element;
    }
    else if (index == count - 1)
    {
        tail->data = element;
    }
    else
    {
        Node* temp = head;
        for (int i = 0; i < index; ++i)
        {
            temp = temp->next;
        }
        temp->data = element;
    }
    return true;
}

LinkedList& LinkedList::operator=(const LinkedList list)
{
    if (head != nullptr)
    {
        while (head != nullptr)
        {
            extractHead();
        }
    }
    Node* temp = list.head;
    for (int i = 0; i < list.count - 1; ++i)
    {
        addToTail(temp->data);
        temp = temp->next;
    }
    return *this;
}

void LinkedList::operator+=(int element)
{
    addToHead(element);
}

int& LinkedList::operator[](int index)
{
    if (head == nullptr)
    {
        addToHead(0);
        return head->data;
    }
    if (index <= 0)
    {
        return head->data;
    }
    if (index >= count)
    {
        addToTail(0);
        return tail->data;
    }
    if (index == count - 1)
    {
        return tail->data;
    }
    Node* temp = head;
    for (int i = 0; i < index; ++i)
    {
        temp = temp->next;
    }
    return temp->data;
}

std::ostream& operator<<(std::ostream& stream, const LinkedList list)
{
    stream << "[" << list.count << "]{";
    if (list.head == nullptr)
    {
        stream << "EMPTY";
    }
    else
    {
        Node* temp = list.head;
        while (temp != nullptr)
        {
            stream << temp->data;
            if (temp->next != nullptr)
            {
                stream << ", ";
            }
            temp = temp->next;
        }
    }
    stream << "}";

    return stream;
}

int LinkedList::extractHead()
{
    int element = head->data;
    head = head->next;
    count--;
    return element;
}

int LinkedList::extractTail()
{
    if (tail == nullptr)
    {
        return -1;
    }
    if (count == 1)
    {
        int element = tail->data;
        head = tail = nullptr;
        count--;
        return element;
    }
    else
    {
        int element = tail->data;
        Node* temp = head;
        for (int i = 0; i < count - 2; ++i)
        {
            temp = temp->next;
        }
        temp->next = nullptr;
        tail = temp;
        count--;
        return element;
    }
}

int LinkedList::extract(int index)
{
    if (head == nullptr)
    {
        return 0;
    }
    if (index <= 0)
    {
        return extractHead();
    }
    if (index >= count - 1)
    {
        return extractTail();
    }
    else if (indexValid(index))
    {
        int element = 0;
        Node* temp = head;
        for (int i = 0; i < index; ++i)
        {
            temp = temp->next;
        }
        element = temp->data;
        Node* node = head;
        for (int i = 0; i < index - 1; ++i)
        {
            node = node->next;
        }
        Node* del = node->next;
        node->next = node->next->next;
        delete del;
        --count;
        return element;
    }
    return 0;
}

void LinkedList::operator-=(int index)
{
    if (index <= 0)
    {
        extractHead();
    }
    if (index >= count - 1)
    {
        extractTail();
    }
    else if (indexValid(index))
    {
        Node* node = head;
        for (int i = 0; i < index - 1; ++i)
        {
            node = node->next;
        }
        Node* del = node->next;
        node->next = node->next->next;
        delete del;
        --count;
    }
}

int LinkedList::indexOf(int element)
{
    if (head == tail && head == nullptr)
    {
        return -1;
    }
    Node* temp = head;
    for (int i = 0; i < count - 1; ++i)
    {
        if (temp->data == element)
        {
            return i;
        }
        temp = temp->next;
    }
    return -1;
}

bool LinkedList::contains(int element)
{
    Node* temp = head;
    for (int i = 0; i < count - 1; ++i)
    {
        if (temp->data == element)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

bool LinkedList::swap(int index1, int index2)
{
    Node* temp1 = head;
    for (int i = 0; i < index1 - 2; ++i)
    {
        temp1 = temp1->next;
    }
    Node* temp2 = head;
    for (int i = 0; i < index1 - 2; ++i)
    {
        temp2 = temp2->next;
    }
    Node* node1 = temp2->next->next;
    temp2->next->next = temp1->next->next;
    temp1->next->next = node1;
    delete node1;
    Node* node2 = temp1->next;
    temp1->next = temp2->next;
    temp2->next = node2;
    delete node2;
    return (indexValid(index1) && indexValid(index2));
}
