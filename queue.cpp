#include <iostream>

using namespace std;
template<class t>
class array_queue{
    int index;
    int size;
    int qsize;
    t* front;
    t* rare;
    t* arr;
public:
    array_queue():size(100), index(0), qsize(0)
    {
        arr = new t[size];
        front = nullptr;
        rare = nullptr;
    }
    array_queue(int s) : size(s), index(0), qsize(0) {
        arr = new t[size];
        front = nullptr;
        rare = nullptr;
    }
    ~array_queue() {
        delete[] arr;
    }

    void enqueue(t ele) {
        if (qsize < size) {
            arr[index] = ele;
            if (qsize == 0)
                front = &arr[index];
            rare = &arr[index];
            index++;
            qsize++;

        } else {
            cout << "Error: The Queue is Full.\n" <<endl;
        }
    }
    t dequeue()
    {
        if(isempty())
        {
            cout<<"Error: The Queue is Empty.\n";
            return t();
        }
        else if(front==rare)
        {  t *i=front;
            clear();
            return *i;
        }
        else{
            qsize--;
            t *i=front;
            front++;
            return *i;
        }
    }
    t first()
    {
        if(isempty())
        {
            cout<<"Error: The Queue is Empty.\n";
            return t();
        }
        else{
            t *i=front;
            return *i;
        }
    }
    bool isempty()
    {
        return (qsize==0);
    }
    void clear()
    {
        qsize=0;
        index=0;
        front=nullptr;
        rare=nullptr;
        delete[] arr;
        arr = new t[size];

    }
    int queuesize(){
        return qsize;
    }
    void print()
    {
        if(isempty())
            cout<<"Error: The Queue is Empty.\n";
        else{
            t *i=front;
            while (i!=rare+1) {
                cout<<*i<<" ";
                i++;
            }cout<<"\n";
        }
    }

};

template<class t>
class node {
public:
    t data;
    node* next;
};

template<class t>
class linked_queue {
    int queuesize;
    node<t> *front, *rear;
public:
    linked_queue() {
        front =NULL;
        rear = NULL;
        queuesize=0;

    }
    void enqueue(t ele) {

        node<t> *newnode = new node<t>;
        newnode->data=ele;
        newnode->next=NULL;
        if (isempty()) {
            front = newnode;
            rear = newnode;
        } else {
            node<t>*temp=front;
            while(temp!=rear)
            {
                temp=temp->next;
            }
            temp->next=newnode;
            rear=newnode;
        }
        queuesize++;
    }
    t dequeue()
    {
        if(isempty()) {
            cout << "Error: The Queue is Empty.\n";
            return t();
        }
        node<t> *temp=front;
        front=front->next;
        queuesize--;
        return temp->data;
    }
    void print()
    {
        if(isempty())
            cout<<"Error: The Queue is Empty.\n";
        else
        {
            node<t>*temp=front;
            while(temp!=rear)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<rear->data<<endl;
//            another way to display elements
//            while(temp->next!=NULL)
//            {
//                cout<<temp->data<<" ";
//                temp=temp->next;
//            }
//            cout<<temp->data<<endl;

        }

    }
    bool isempty()
    {
        return front==NULL;
    }
    t first()
    {
        if(isempty())
        {cout<<"Error: The Queue is Empty.\n";
            return t();
        }
        return front->data;
    }
    int get_queuesize()
    {return queuesize;
    }
    void clear()
    {
        front=NULL;
        rear=NULL;
        queuesize=0;
    }
};
void functions_of_array_queue()
{

    array_queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout<<"the current values in the array based queue: \n";
    q.print();
    auto  deleted=q.dequeue();
    cout<<"\nthe first element -->"<<deleted<<"<-- in the queue is deleted\n";
    cout<<"\nthe current values in the queue array based: \n";
    q.print();
    auto first_ele=q.first();
    cout<<"\n-->"<<first_ele<<"<-- is the first element in queue\n";
    cout<<"\nis the queue empty? "<<q.isempty()<<"\n";
    cout<<"\nthe queue size: "<<q.queuesize()<<"\n";
    q.clear();
    cout<<"\nthe current values in the queue : \n";
    q.print();
    cout<<"\nis the queue empty? "<<q.isempty()<<"\n";

}
void functions_of_linked_queue()
{
    linked_queue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout<<"\nthe current values in the linked list based queue: \n";
    q.print();
    auto  deleted=q.dequeue();
    cout<<"\nthe first element -->"<<deleted<<"<-- in the queue is deleted\n";
    cout<<"\nthe current values in the queue array based: \n";
    q.print();
    auto first_ele=q.first();
    cout<<"\n-->"<<first_ele<<"<-- is the first element in queue\n";
    cout<<"\nis the queue empty? "<<q.isempty()<<"\n";
    cout<<"\nthe queue size: "<<q.get_queuesize()<<"\n";
    q.clear();
    cout<<"\nthe current values in the queue : \n";
    q.print();
    cout<<"\nis the queue empty? "<<q.isempty()<<"\n";
}
int main() {

    functions_of_array_queue();
    functions_of_linked_queue();
}

