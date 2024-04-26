#include <iostream>

using namespace std;
template<class T>
struct node {
    T data;
    node* next;
    node* prev;
};

template<class T>
class doubleLinkedList{
    node<T>*head;
    node<T>*tail;
    int Size;
public:
    doubleLinkedList():head(nullptr), tail(nullptr),Size(0){}

    void insertAtHead(T element){
        node<T>* newnode = new node<T>;
        newnode->data = element;
        newnode->next = head;
        newnode->prev = nullptr;

        if(head != nullptr)
            head->prev = newnode;

        head = newnode;
        if(tail == nullptr)
            tail = newnode;

        Size++;

        //return;
    }

    void insertAtTail(T element){
        if(head == nullptr)
            insertAtHead(element);
        else{
            node<T>* newnode = new node<T>;
            newnode->data = element;
            newnode->next = nullptr;
            newnode->prev = tail;
            tail->next = newnode;
            tail = newnode;
            Size++;
        }
        //return;
    }

    void insertAt(T element, int index){
        if(index < 0){
            cout << "Invalid index\n";
            return;
        }
        if(index > Size){
            cout << "Out of range\n";
            return;
        }
        if(index == 0)
            insertAtHead(element);
        else if(index == Size)
            insertAtTail(element);
        else{
            node<T>* newnode = new node<T>;
            node<T>* curr = head;
            newnode->data = element;
            for(int i = 0; i < index; i++)
                curr = curr->next;
            newnode->next = curr->next;
            newnode->prev = curr;
            curr->next = newnode;
            curr->next->prev = newnode;

            Size++;
        }
        //return;
    }

    void removeAtHead(){
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        node<T>* temp = head;
        head = head->next;
        if(head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;

        delete temp;
        Size--;

        //return;
    }
    void removeATTail(){
        if (tail == nullptr) {
            cout << "List is empty\n";
            return;
        }
        node<T>* temp = tail;
        tail = tail->prev;
        if(tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr;

        delete temp;
        Size--;

        //return;
    }

    void removeAt(int index){
        if(index < 0){
            cout << "Invalid index\n";
            return;
        }
        if(index > Size){
            cout << "Out of range\n";
            return;
        }
        if(index == 0)
            removeAtHead();
        else if(index == Size)
            removeATTail();
        else{
            node<T>* curr = head;
            for(int i = 0; i < index; i++)
                curr = curr->next;

            curr->prev ->next = curr->next;
            curr->next -> prev = curr->prev;
            Size--;
        }
    }

    T retrieveAt(int index){
        if(index < 0){
            cout << "Invalid index\n";
            return -1;
        }
        if(index > Size){
            cout << "Out of range\n";
            return -1;
        }
        node<T>* curr = head;
        for(int i = 0; i < index; i++)
            curr = curr->next;

        return curr->data;
    }

    void raplaceAt(T newElement, int index){
        if(index < 0){
            cout << "Invalid index\n";
            return ;
        }
        if(index > Size){
            cout << "Out of range\n";
            return ;
        }

        node<T>* curr = head;
        for(int i = 0; i < index; i++)
            curr = curr->next;

        curr->data = newElement;
    }

    bool isExist(T element){
        node<T>* curr = head;
        while(curr != nullptr){
            if(curr->data == element)
                return true;
        }
        return false;
    }

    bool isItemAtEqual(T element, int index){
        if(index < 0){
            cout << "Invalid index\n";
            return -1;
        }
        if(index > Size){
            cout << "Out of range\n";
            return -1;
        }
        node<T>* curr = head;

        for(int i = 0; i < index; i++)
            curr = curr->next;

        return curr->data == element;
    }

    void Swap(int firstItemIdx, int secondItemIdx){
        if (firstItemIdx < 0 || secondItemIdx < 0) {
            cout << "Invalid indices\n";
            return;
        }
        if ( firstItemIdx >= Size || secondItemIdx >= Size) {
            cout << "Out of range\n";
            return;
        }
        if(firstItemIdx == secondItemIdx)
            return;
        node<T>* firstNode = head;
        node<T>* secondNode = head;

        for(int i = 0; i < firstItemIdx; i++)
            firstNode = firstNode->next;

        for(int i = 0; i < secondItemIdx; i++)
            secondNode = secondNode->next;

        T temp = firstNode->data;
        firstNode->data = secondNode->data;
        secondNode->data = temp;
    }

    bool isEmpty(){
        return Size == 0;
    }

    int DLL_is_size(){
        return Size;
    }

    void Clear(){
        while(head != nullptr){
            node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        Size = 0;
    }

    void print(){
        node<T>* curr = head;
        while(curr != nullptr){
            cout<< curr->data <<" ";
            curr = curr->next;
        }
        cout<<endl;
    }

};

int main()
{
    doubleLinkedList<int> dll;
    dll.insertAtHead(1);
    dll.insertAtTail(3);
    dll.insertAt(2, 1);
    dll.print(); // Output: 1 2 3
    cout << "Size: " << dll.DLL_is_size() << endl; // Output: 3
    dll.removeAt(1);
    dll.print(); // Output: 1 3
    cout << "Size: " << dll.DLL_is_size() << endl; // Output: 2
    cout << "Element at index 1: " << dll.retrieveAt(1) << endl; // Output: 3
    cout << "Is 3 in the list: " << dll.isExist(3) << endl; // Output: 1 (true)
    cout << "Is element at index 1 equal to 3: " << dll.isItemAtEqual(3, 1) << endl; // Output: 1 (true)
    dll.Swap(0, 1);
    dll.print(); // Output: 3 1
    dll.Clear();
    cout << "Is the list empty: " << dll.isEmpty() << endl; // Output: 1 (true)
    return 0;
}
