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


int main() {

}

