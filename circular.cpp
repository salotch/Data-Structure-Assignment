#include <iostream>
using namespace std;

template <class T>
struct node
{
    T info;
    node<T>* next;
};

template <class T>
class circularlinkedlist
{

private:
    node<T>* last;

public:
    void insertAtHead(T newitem);
    void insertAtTail(T newitem);
    void insertAt(T newitem, int index);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    // template <class T>
    T retreiveAt(int index);
    void replaceAt(T newelement, int index);
    bool isExist(T searchitem);
    bool isItemAtEqual(T item, int index);
    void swap(int firstitemindex, int seconditemindex);
    bool isEmpty();
    int linkedListSize();
    void clear();
    // void print();

    circularlinkedlist()
    {
        last = nullptr;
    }

    void print()
    {
        node<T>* current = nullptr;
        if (last != nullptr)
        {
            current = last->next;
            do
            {
                cout << current->info << " ";
                current = current->next;
            } while (current != last->next);
            cout << endl;
        }
    }
};

template <class T>
void circularlinkedlist<T>::insertAtHead(T newitem)
{
    node<T>* newNode = new node<T>;
    newNode->info = newitem;
    if (isEmpty())
    {
        last = newNode;
        last->next = newNode;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
    }
}

template <class T>
void circularlinkedlist<T>::insertAtTail(T newitem)
{
    node<T>* newNode = new node<T>;
    newNode->info = newitem;
    if (isEmpty())
    {
        last = newNode;
        last->next = newNode;
        return;
    }
    else
    {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
}

template <class T>
void circularlinkedlist<T>::insertAt(T newitem, int index)
{
    if (index < 0)
    {
        cout << "index unavailable" << endl;
        ;
    }

    if (index == 0)
    {
        insertAtHead(newitem);
        return;
    }

    node<T>* newNode = new node<T>;
    newNode->info = newitem;
    newNode->next = nullptr;

    if (isEmpty())
    {
        last = newNode;
        last->next = newNode;
        return;
    }

    int size = linkedListSize();
    if (index > size)
    {
        cout << "out of range" << endl;
        ;
    }

    node<T>* current = last->next;
    for (int i = 0; i < index - 1; ++i)
    {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    if (current == last)
    {
        last = newNode;
    }
}
template <class T>
void circularlinkedlist<T>::removeAtHead()
{
    if (isEmpty())
        return;
    if (last->next == last)
    {
        delete last;
        return;
    }
    node<T>* current = last->next;
    last->next = current->next;
    delete current;
}

template <class T>
void circularlinkedlist<T>::removeAtTail()
{
    if (isEmpty())
        return;
    if (last->next == last)
    {
        delete last;
        // last = nullptr;
        return;
    }

    node<T>* current = last->next;
    while (current->next != last)
    {
        current = current->next;
    }
    current->next = last->next;
    delete last;
    last = current;
}

template <class T>
void circularlinkedlist<T>::removeAt(int index)
{
    if (isEmpty())
    {
        cout << " no  index like that" << endl;
        ;
        return;
    }

    int size = linkedListSize();
    if (index < 0 || index >= size)
    {
        cout << "out of range" << endl;
    }

    if (last->next == last)
    {
        delete last;

        return;
    }
    int i = 0;
    node<T>* current = last->next;
    node<T>* prev = last;
    while (i++ < index)
    {
        prev = current;
        current = current->next;

        if (current == last->next)
        {
            cout << " no index like that" << endl;
            ;
            return;
        }
    }

    prev->next = current->next;
    if (current == last)
        last = prev;
    delete current;
}

template <class T>
T circularlinkedlist<T>::retreiveAt(int index)
{
    if (isEmpty())
        return -1;

    int size = linkedListSize();
    if (index < 0 || index >= size)
    {
        cout << "out of range" << endl;
    }

    int i = 0;
    node<T>* current = last->next;
    while (i++ < index)
    {
        current = current->next;

        if (current == last->next)
        {
            cout << "Error no such index";
            return -1;
        }
    }

    return current->info;
}

template <class T>
void circularlinkedlist<T>::replaceAt(T newelement, int index)
{
    if (isEmpty())
        return;

    int size = linkedListSize();
    if (index < 0 || index >= size)
    {
        cout << "out of range" << endl;
    }

    int i = 0;
    node<T>* current = last->next;
    while (i++ < index)
    {
        current = current->next;

        if (current == last->next)
        {
            cout << "Error no such index";
            return;
        }
    }

    current->info = newelement;
}

template <class T>
bool circularlinkedlist<T>::isExist(T searchitem)
{
    if (isEmpty())
        return -1;
    node<T>* current = last->next;
    do
    {
        if (current->info == searchitem)
            return 1;
        current = current->next;
    } while (current != last->next);

    return false;
}

template <class T>
bool circularlinkedlist<T>::isItemAtEqual(T item, int index)
{
    if (isEmpty())
        return -1;
    int i = 0;
    node<T>* current = last->next;
    while (i <= index)
    {

        if (i == index)
            return current->info == item;

        i++;
        if (current->next == last->next)
        {
            cout << "Error no such index";
            return false;
        }
        current = current->next;
    }
}

template <class T>
void circularlinkedlist<T>::swap(int firstitemindex, int seconditemindex)
{
    node<T>* current = last->next;
    node<T>* prev = last;
    node<T>* first = nullptr;
    node<T>* second = nullptr;
    node<T>* prevfirst = nullptr;
    node<T>* prevsecond = nullptr;
    int i = 0;
    do
    {
        if (i == firstitemindex)
            first = current, prevfirst = prev;
        if (i == seconditemindex)
            second = current, prevsecond = prev;
        i++;
        prev = current;
        current = current->next;
        if (first != nullptr && second != nullptr)
            break;
    } while (last->next != current);

    if (first == nullptr || second == nullptr)
    {
        cout << "you cannot swap";
        return;
    }
    node<T>* temp = nullptr;
    if (first == last)last = second;
    else if (second == last)last = first;
    prevsecond->next = first;
    prevfirst->next = second;
    temp = first->next;
    first->next = second->next;
    second->next = temp;
}

template <class T>
bool circularlinkedlist<T>::isEmpty()
{
    return last == nullptr;
}

template <class T>
int circularlinkedlist<T>::linkedListSize()
{
    int size = 0;
    if (isEmpty())
        return size;
    node<T>* current = last->next;
    do
    {
        size++;
        current = current->next;
    } while (current != last->next);
    return size;
}

template <class T>
void circularlinkedlist<T>::clear()
{
    if (isEmpty())
        return;
    node<T>* current = last->next;
    node<T>* prev = nullptr;
    while (last != current)
    {
        prev = current;
        current = current->next;
        delete prev;
    }
    delete last;
}

int main()
{
    
    circularlinkedlist<int> myList;
    int newitem = 5;
    myList.insertAtHead(newitem);
    int item = 9;
    myList.insertAtHead(item);
    int n = 20;
    myList.insertAtTail(n);
    int k = 90;
    int index = 2;
    myList.insertAt(60, 2);

    myList.print();
    myList.swap(2, 1);
    myList.print();
    // cout << myList.retreiveAt(2) << endl;
    // ;
    // int r = 900;
    // myList.replaceAt(900, 2);
    // // myList.isExist(90);

    // if (myList.isExist(90))
    // {
    //     cout << "element exist" << endl;
    //     ;
    // }
    // else
    //     cout << "doesnot exist" << endl;
    // ;

    // if (myList.isItemAtEqual(900, 2))
    // {
    //     cout << "yes" << endl;
    // }
    // else
    //     cout << "no" << endl;
    // ;

    // if (myList.isEmpty())
    //     cout << "Empty" << endl;
    // else
    //     cout << "not empty" << endl;

    // cout << myList.linkedListSize() << endl;

    // myList.swap(0, 3);
    // myList.print();

    // myList.clear();
    // myList.removeAtTail();
    // myList.removeAtHead();
    // myList.removeAt(1);
    // myList.print();
    return 0;

}