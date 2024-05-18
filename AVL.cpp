#include <algorithm>
#include <iostream>
using namespace std;

class Item{
private:
    string itemName;
    string category;
    int price;
public:
    Item(string x,string y,int z){
        itemName=x;
        category=y;
        price=z;
    }
    Item(){}
    string getName(){return itemName;}
    string getCategory(){return category;}
    int getPrice(){return price;}
    void setName(string x){itemName=x;}
    void setCategory(string y){category=y;}
    void setPrice(int z){price=z;}
    bool operator==(Item &other){
        return ((this->itemName == other.itemName )&& (this->category == other.category) &&( this->price == other.price));
    }
    bool operator<(Item &other){
        return(this->itemName<other.itemName);
    }
    bool operator>(Item &other){
        return (this->price > other.price);
    }
    void print(){
        cout<<"Item name is: "<<itemName<<"\n"<<"Category is: "<<category<<"\n"<<"Price is: "<<price<<"\n";
    }
};

template<class t>
class Node {
public:
    t data;
    Node *left;
    Node *right;
    int height;
    Node(){
        right=left= nullptr;
        height=1;
    }

};
template<class t>
class AVL{
Node<t> *root;

int height(Node<t>* n){
    if(n == nullptr)
        return 0;
    return  n->height;
}
int getBalance(Node<t>*n)
{
    if(n==nullptr)
        return 0;
    return height(n->left)- height(n->right);
}
Node<t>* rightRotate(Node<t>* y)
{
    Node<t> *x=y->left;
    Node<t> *temp=x->right;

    x->right=y;
    y->left=temp;

    y->height= 1+max(height(y->left), height(y->right));
    x->height= 1+max(height(x->left), height(x->right));

    return x;
}

Node<t>* leftRotate(Node<t>* y){


    Node<t> *x=y->right;
    Node<t> *temp=x->left;

    x->left=y;
    y->right=temp;

    y->height= 1+max(height(y->left), height(y->right));
    x->height= 1+max(height(x->left), height(x->right));

    return x;

}
Node<t>* insertHelper(Node<t>* node,int key) {

    if (node == nullptr) {
        auto newNode = new Node<t>;
        newNode->data = key;
        return newNode;
    }
    if (key < node->data)
    {
        node->left= insertHelper(node->left,key);
    }
    else if(key>node->data)
    {
     node->right = insertHelper(node->right,key);
    }
    else
        return node;//to prevent multiplication in AVL

    node->height=1+max(height(node->right), height(node->left));

    int balance= getBalance(node);
//rotations
    if(balance>1 && key<node->left->data)
        return rightRotate(node);

    if(balance<-1 && key >node->right->data)
        return leftRotate(node);

    if (balance>1 && key >node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
void inorder(Node<t>* n)
{
    if(n != nullptr) {

        inorder(n->left);
        cout << n->data << " ";
        inorder(n->right);
    }
}
    void des(Node<t>* n)
    {
        if(n != nullptr) {

            des(n->right);
            cout << n->data << " ";
            des(n->left);
        }
    }
public:
    AVL(){
        root= nullptr;
    }
    void insert(t val)
    {
        root = insertHelper(root,val);
    }
    void printAsc()
    {
        inorder(root);
        cout<<endl;
    }
    void printDes()
    {
    des(root);
        cout<<endl;
    }
};
int main()
{
    AVL<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.printAsc();
    tree.printDes();
}
