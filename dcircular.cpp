#include <iostream>
using namespace std;

template <class T>
struct Node
{
public:
    T data;    
    Node* next; 
    Node* prev; 
};

template <class T>
class doublylinkedlist
{
private:
    Node<T>* head;

public:
    
    doublylinkedlist();

   
    ~doublylinkedlist();

    void insertAtHead(T newitem);

    void insertAtTail(T newitem);

    void insertAt(T newitem, int index);

    void removeAtHead();

    void removeAtTail();

    void removeAt(int index);

    T retreiveAt(int index);

    void replaceAt(T newelement, int index);

    bool isExist(T item);

    bool isItemAtEqual(T item, int index);

    void swap(int firstitemindex, int seconditemindex);

    int linkedListSize();

    bool isEmpty();

    void print();

    void clear();
    

};

template <class T>
bool doublylinkedlist<T>::isEmpty()
{
    return (head->next == head);
}

template <class T>
bool doublylinkedlist<T>::isExist(T item)
{
    Node<T>* cur = head->next;

    while (cur != head)
    {

        if (cur->data == item)
            return true;

        if ((cur->data) < item)
            cur = cur->next;
        else
            break;
    }

    return false;
}

template <class T>
doublylinkedlist<T>::doublylinkedlist()
{
    head = new Node<T>;
    head->next = head;
    head->prev = head;
}

template <class T>
doublylinkedlist<T>::~doublylinkedlist()
{
   
    clear();
    delete head;
}

template <class T>
int doublylinkedlist<T>::linkedListSize()
{
    
    if (head == head->next)
        return 0;
    int x = 0;
    Node<T>* cur = head->next;
    do
    {
        x++;
        cur = cur->next;
    } while (head != cur);

    return x;
}

template <class T>
void doublylinkedlist<T>::insertAtHead(T item)
{
    Node<T>* newnode = new Node<T>;
    newnode->data = item;
    newnode->next = head->next;
    head->next->prev = newnode;
    newnode->prev = head;
    head->next = newnode;
}
template <class T>
void doublylinkedlist<T>::insertAtTail(T item)
{
    Node<T>* newnode = new Node<T>;
    newnode->data = item;
    newnode->prev = head->prev;
    head->prev->next = newnode;
    newnode->next = head;
    head->prev = newnode;
}

template <class T>
void doublylinkedlist<T>::insertAt(T item, int index)
{
    int size = linkedListSize();

    if (index < 0 || index>size)
    {
        cout << "out of range\n" << endl;
        return;
    }

    if (index == 0)
    {
        insertAtHead(item);
        return;
    }

    Node<T>* newnode = new Node<T>;
    Node<T>* cur = head->next;

    newnode->data = item;
    for (int i = 0; i < index - 1; ++i)
    {
        cur = cur->next;
    }

    newnode->next = cur->next;
    newnode->prev = cur;
    cur->next->prev = newnode;
    cur->next = newnode;
}

template <class T>
void doublylinkedlist<T>::removeAtHead()
{
    if (isEmpty())
    {
        cout << "the linked list in empty\n";
        return;
    }
    Node<T>* ptr = head->next;
    head->next = head->next->next;
    head->next->prev = head;
    delete ptr;
}

template <class T>
void doublylinkedlist<T>::removeAtTail()
{
    if (isEmpty())
    {
        cout << "the linked list in empty\n";
        return;
    }
    Node<T>* ptr = head->prev;
    head->prev = head->prev->prev;
    head->prev->next = head;
    delete ptr;
}

template <class T>
void doublylinkedlist<T>::removeAt(int index)
{
    if (isEmpty())
    {
        cout << "the linked list in empty\n";
        return;
    }
    int size = linkedListSize();
    if (index < 0 || index >= size)
    {
        cout << "out of range\n";
        return;
    }
    Node<T>* cur = head->next;
    int i = 0;
    while (i++ < index)cur = cur->next;

    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    delete cur;
}

template <class T>
T doublylinkedlist<T>::retreiveAt(int index)
{
    int size = linkedListSize();
    if (index < 0 || index >= size)
    {
        cout << "out of range\n";
        return -1;
    }

    int i = 0;
    Node<T>* current = head->next;
    while (i++ < index)
        current = current->next;

    return current->data;
}

template <class T>
void doublylinkedlist<T>::replaceAt(T newelement, int index)
{
    int size = linkedListSize();
    if (index < 0 || index >= size)
    {
        cout << "out of range\n";
        return;
    }

    int i = 0;
    Node<T>* current = head->next;
    while (i++ < index)
        current = current->next;

    current->data = newelement;
}

template <class T>
bool doublylinkedlist<T>::isItemAtEqual(T item, int index)
{
    int size = linkedListSize();
    if (index < 0 || index >= size)
    {
        cout << "out of range\n";
        return false;
    }

    int i = 0;
    Node<T>* current = head->next;
    while (i++ < index)
        current = current->next;

    return current->data == item;
}

template <class T>
void doublylinkedlist<T>::swap(int firstitemindex, int seconditemindex)
{
    Node<T>* current = head->next;
    Node<T>* prev = head;
    Node<T>* first = nullptr;
    Node<T>* second = nullptr;
    Node<T>* prevfirst = nullptr;
    Node<T>* prevsecond = nullptr;
    int size = linkedListSize();
    if (min(firstitemindex, seconditemindex) < 0 || max(firstitemindex, seconditemindex) >= size)
    {
        cout << "can't swap (out of range)\n";
        return;
    }
    int i = 0;
    for (int i = 0; i < size; i++)
    {
        if (i == firstitemindex)
            first = current, prevfirst = prev;
        if (i == seconditemindex)
            second = current, prevsecond = prev;
        prev = current;
        current = current->next;
        if (first != nullptr && second != nullptr)
            break;
    }

    Node<T>* temp = nullptr;
    prevsecond->next = first;
    prevfirst->next = second;
    first->next->prev = second;
    second->next->prev = first;
    temp = first->next;
    first->next = second->next;
    second->next = temp;
    temp = first->prev;
    first->prev = second->prev;
    second->prev = temp;
}

template <class T>
void doublylinkedlist<T>::print()
{
    Node<T>* cur = head->next;
    while (cur != head)
    {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

template <class T>
void doublylinkedlist<T>::clear()
{
    Node<T>* cur = head->next;
    Node<T>* Prev = nullptr;
    while (head != cur)
    {
        Prev = cur;
        cur = cur->next;
        delete Prev;
    }
}

int main()
{
    doublylinkedlist<int> myList;
    myList.insertAtHead(1);
    myList.insertAtHead(2);
    myList.insertAtHead(3);
    myList.insertAtHead(4);
    myList.insertAtTail(5);
    myList.insertAtTail(6);
    myList.insertAtTail(7);
    myList.insertAtTail(8);
    myList.print();
    myList.swap(0, 7);
    myList.print();
  cout<<  myList.retreiveAt(0)<<endl;
    //myList.print();
    myList.insertAt(50, 3);
    myList.print(); 
    myList.replaceAt(90, 5);
    myList.print();

    if (myList.isExist(90))
      cout << "element exist" << endl;
    else
      cout << "doesnot exist" << endl;
         

     if (myList.isItemAtEqual(900, 2))
       cout << "yes" << endl;
     else
       cout << "no" << endl;
     

      if (myList.isEmpty())
          cout << "Empty" << endl;
      else
          cout << "not empty" << endl;

       cout << myList.linkedListSize() << endl;

      
        myList.removeAtTail();
        myList.removeAtHead();
        myList.removeAt(1);
        myList.print(); 

       myList.clear();

}