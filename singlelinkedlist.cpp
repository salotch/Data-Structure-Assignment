#include<iostream>
using namespace std;
template<class T>
class linkedlist{
    struct Node{
        T item;
        Node *next;
    };
    Node *head;
    Node *tail;
    int length;
    public:
    linkedlist(){
        head=tail=NULL;
        length=0;
    }
    bool isEmpty(){
    return length==0;
    }
    void insertAtHead(T element)
    {
        Node*newnode=new Node;
        newnode->item=element;
        if(length==0)
        {
            head=tail=newnode;
            newnode->next=NULL;
        }
        else{
            newnode->next=head;
            head=newnode;
        }
        length++;
    }
    void insertAtTail(T element){
        Node*newnode=new Node;
        newnode->item=element;
        if(length==0)
        {
            head=tail=newnode;
            newnode->next=NULL;
        }
        else{
            tail->next=newnode;
            newnode->next=NULL;
            tail=newnode;
        }
        ++length;
    }
    void insertAt(T element,int index)
    {
        if(index<0||index>=length)
        {
            cout<<"out of range";
        }
        else{
            if(index==0)
            insertAtHead(element);
            else if(index==length-1)
            insertAtTail(element);
            else{
                Node*newnode=new Node;
                newnode->item=element;
                Node*curr=head;
                for(int i=1;i<index;i++)
                {
                    curr=curr->next;
                }
                newnode->next=curr->next;
                curr->next=newnode;
                ++length;
            }
        
        }
    }
    void removeAtHead(){
        if(isEmpty())
        cout<<"oops! empty list Can't remome:("<<endl;
        else if(length==1){
            delete head;
            head=tail=NULL;
            length--;
        }
        else{
            Node*curr=head;
            head=head->next;
            delete curr;
            length--;
        }
        
    }
    void removeAtTail(){
        if(isEmpty())
        cout<<"oops! empty list Can't remome:("<<endl;
        else if(length==1){
            delete head;
            head=tail=NULL;
            length--;
        }
        else{
            Node*curr=head->next;
            Node *prv=head;
            while(curr!=tail){
                prv=curr;
                curr=curr->next;
            }
            delete curr;
            prv->next=NULL;
            tail=prv;
            length--;
        }
    }
    void removeAt(int index){
        if(index<0||index>=length)
        {
            cout<<"out of range";
        }
        else{
            if(index==0)
            removeAtHead();
            else if(index==length-1)
            removeAtTail();
            else{
                Node*curr=head->next;
                Node*prv=head;
                for(int i=1;i<index;i++)
                {
                    prv=curr;
                    curr=curr->next;
                }
                prv->next=curr->next;
                --length;
            }
        
        }
    }
    int linkedlistSize()
    {
        return length;
    }
    bool isExist(T element)
    {
        Node*curr=head;
        while(curr!=NULL)
        {
            if(curr->item==element)
            return true;
            curr=curr->next;
        }
        if(curr==NULL){
        return false;}
    }
    bool isItemAtEqule(T element,int index)
    {
        if(index<0||index>=length)
        {
            return false;
        }
        Node*curr=head;
        for(int i=0;i<index;i++)
        {
        curr=curr->next;
        }
        return(curr->item==element);
    }
    void replaceAt(T element,int index)
    {
        if(index<0||index>=length)
        {
            cout<<"out of range";
        }
        Node*curr=head;
        for(int i=0;i<index;i++)
        {
        curr=curr->next;
        }
        (curr->item=element);
    }
    T retrieveAt(int index)
    {
        if(index<0||index>=length)
        {
            cout<<"out of range";
        }
        Node*curr=head;
        for(int i=0;i<index;i++)
        {
        curr=curr->next;
        }
        return (curr->item);
    }
    void print()
    {
        if(isEmpty())
        cout<<"no need to clear it is empty list";
        Node*curr=head;
        while(curr!=NULL)
        {
            cout<<curr->item<<" ";
            curr=curr->next;
        }
    }
    void swap(int firstItemIdx,int secondItemIdx )
    {
        if(firstItemIdx==secondItemIdx)
        return;
        if(firstItemIdx>=length||secondItemIdx>=length||firstItemIdx<0||secondItemIdx<0)
        return;
        if(firstItemIdx+1==secondItemIdx){
            return;
        }
        Node*prvf=nullptr;
        Node*currf=head;
        Node*prvs=nullptr;
        Node*currs=head;
        for(int i=0;i<firstItemIdx;i++){
            prvf=currf;
            currf=currf->next;
        }
        for(int i=0;i<secondItemIdx;i++){
            prvs=currs;
            currs=currs->next;
        }
        if(prvf){
            prvf->next=currs;
        }
        else
        {
            head=currs;
        }
        if(prvs){
            prvs->next=currf;
        }
        else
        {
            head=currf;
        }
        Node*temp=currs->next;
        currs->next=currf->next;
        currf->next=temp;

    }
    void clear()
    {
        if(isEmpty())
        cout<<"no need to clear it is empty list";
        else
        {
            Node*temp;
            while(head!=NULL){
                temp =head;
                head=head->next;
                delete temp;
            }
            tail=NULL;
            length=0;
        }
    }
};
int main()
{
    linkedlist<int> l;
    l.insertAtHead(30);
    l.insertAtHead(40);
    l.insertAtHead(50);
    l.insertAtHead(60);
    l.insertAtHead(70);
    l.replaceAt(60,3);
    l.insertAtTail(100);
    l.insertAt(20,2);
    l.removeAtHead();
    l.removeAtTail();
    l.removeAt(2);
    l.swap(0,3);
    l.print();
    cout<<endl<<l.retrieveAt(3); 
    cout<<endl<<l.linkedlistSize()<<endl<<l.isExist(100)<<endl<<l.isItemAtEqule(40,3);
    l.clear();
    cout<<endl;
    l.print();
}
