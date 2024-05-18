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
Node<t>* insertHelper(Node<t>* node,int data) {

    if (node == nullptr) {
        auto newNode = new Node<t>;
        newNode->data = data;
        return newNode;
    }
    if (data < node->data)
    {
        node->left= insertHelper(node->left,data);
    }
    else if(data>node->data)
    {
        node->right = insertHelper(node->right,data);
    }
    else
        return node;//to prevent multiplication in AVL

    node->height=1+max(height(node->right), height(node->left));

    int balance= getBalance(node);
//rotations
    if(balance>1 && data<node->left->data)
        return rightRotate(node);

    if(balance<-1 && data >node->right->data)
        return leftRotate(node);

    if (balance>1 && data >node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
Node<t>* minValueNode(Node<t>*node)
{
    Node<t>* current = node;
    while (current->left != NULL)
        current = current->left;
    return current;

}
Node<t>* deleteHelper(Node<t>* root,t data){
    if(root==NULL)
        return root;
    if(data<root->data)
        root->left = deleteHelper(root->left,data);
    else if(data>root->data)
        root->right =deleteHelper(root->right,data)  ;
    else{
        if((root->left == NULL)||(root->right == NULL)){
            Node<t> *temp=root->left? root->left : root->right;
            if (temp==NULL)
            {
                temp=root;
                root=NULL;
            }
            else
            *root = *temp;
            free(temp);
        }
        else{
            Node<t> *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteHelper(root->right,temp->data);
        }
        }
        if(root==NULL)
        return root;
        root->height =1 + max(height(root->left),height(root->right));
        int balance = getBalance(root);
        if(balance>1 && getBalance(root->left)>=0)
        return rightRotate(root);
        if(balance>1 && getBalance(root->left)<0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if(balance<-1 && getBalance(root->right)<=0)
        return leftRotate(root);
        if(balance<-1 && getBalance(root->left)>0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
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
    void Delete(t val)
    {
        root = deleteHelper(root,val);
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
    tree.Delete(40);
    tree.printAsc();
    tree.printDes();
}
