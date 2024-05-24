#include "item.h"
vector<Item> ReadItem( string filename){
    fstream ifile(filename, ios::in | ios::out | ios::app);
    long long no_item;
    ifile >> no_item;
    vector<Item> it;

    for (int i = 0; i < no_item; i++){
        string name, category;
        int price;
        ifile.ignore();
        getline(ifile, name);
        getline(ifile, category);
        ifile >> price;
        it.push_back(Item(name, category, price));
    }
    return it;
}
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
    Node<t>* insertHelpername(Node<t>* node,t key) {

        if (node == nullptr) {
            auto newNode = new Node<t>;
            newNode->data = key;
            return newNode;
        }
        if (key < node->data)
        {
            node->left= insertHelpername(node->left,key);
        }
        else if(!(key<node->data))
        {
            node->right = insertHelpername(node->right,key);
        }
        else
            return node;//to prevent multiplication in AVL

        node->height=1+max(height(node->right), height(node->left));

        int balance= getBalance(node);
//rotations
        if(balance>1 && key < node->left->data)
            return rightRotate(node);

        if(balance<-1 && !(key < node->right->data))
            return leftRotate(node);

        if (balance>1 && !(key < node->left->data))
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
    Node<t>* insertHelper(Node<t>* node,t key) {

        if (node == nullptr) {
            auto newNode = new Node<t>;
            newNode->data = key;
            return newNode;
        }
        if (!(key > node->data))
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
        if(balance>1 && !(key > node->left->data))
            return rightRotate(node);

        if(balance<-1 && key > node->right->data)
            return leftRotate(node);

        if (balance>1 && key > node->left->data)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && !(key > node->right->data))
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }
    Node<t>* deleteHelper(Node<t>* root,t data){
        if(root==nullptr)
            return root;
        if(data < root->data)
            root->left = deleteHelper(root->left,data);
        else if(!(data <= root->data))
            root->right =deleteHelper(root->right,data)  ;
        else{
            if((root->left == nullptr)||(root->right == nullptr)){
                Node<t> *temp=root->left? root->left : root->right;
                if (temp==nullptr)
                {
                    temp=root;
                    root=nullptr;
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
        if(root==nullptr)
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
    Node<t>* deleteHelperp(Node<t>* root,t data){
        if(root==nullptr)
            return root;
        if(data > root->data)
            root->right =deleteHelperp(root->right,data)  ;
        else if(!(data >= root->data))
            root->left = deleteHelperp(root->left,data);
        else{
            if((root->left == nullptr)||(root->right == nullptr)){
                Node<t> *temp=root->left? root->left : root->right;
                if (temp==nullptr)
                {
                    temp=root;
                    root=nullptr;
                }
                else
                    *root = *temp;
                free(temp);
            }
            else{
                Node<t> *temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteHelperp(root->right,temp->data);
            }
        }
        if(root==nullptr)
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
            n->data.print();
            inorder(n->right);
        }
    }
    void des(Node<t>* n)
    {
        if(n != nullptr) {

            des(n->right);
            n->data.print();
            des(n->left);
        }
    }
    void printH(Node<t>* n)
    {
        if(n != nullptr) {

            n->data.print();
            printH(n->left);
            printH(n->right);

        }
    }
    Node<t>* minValueNode(Node<t>*node)
    {
        Node<t>* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;

    }
public:
    AVL(){
        root= nullptr;
    }
    void insert(t val)
    {
        root = insertHelper(root,val);
    }
    void insertn(t val)
    {
        root = insertHelpername(root,val);
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
    void printNormally()
    {
        printH(root);
        cout<<endl;
    }
    void Delete(t val)
    {
        root = deleteHelper(root,val);
    }
    void Deletep(t val)
    {
        root = deleteHelperp(root,val);
    }
};

void avlmenue() {
    AVL<Item> tree;
    AVL<Item> tree2;
    cout<<"Welcome to AVL trees\n";
    while (true)
    { cout<<"which opperation you want to preform :\n";
        cout<<"1.insert element \n2.delete element\n3.Retrieve all elements in the tree normally."
              "\n4.Retrieve all elements in the tree ascending  by item's name."
              "\n5.Retrieve all elements in the tree descending by the item's name."
              "\n6.Retrieve all elements in the tree ascending by the item's price."
              "\n7.Retrieve all elements in the tree descending by the item's price."
              "\n8.Exit\n";
        char choose;
        cin>>choose;
        if(choose == '1') {
            int x=0;
            string filename="";
            do {
                cout<<"1.do you want to insert data from file\n2.insert values manually";
                cin>>x;
            } while(x!=1&&x!=2);
            if(x==1)
            {
                cout<<"enter file name:";
                cin>>filename;
                filename+=".txt";
                vector<Item> v=ReadItem(filename);
                for(int i=0;v.size()>i;i++)
                {
                    tree.insert(v[i]);
                    tree2.insertn(v[i]);
                }

            }
            else {
                int num;
                cout << "enter number of items you want to insert:";
                cin >> num;
                while (num--) {
                    Item i;
                    int price;
                    string name, cate;
                    cout << "\nenter item name: ";
                    cin >> name;
                    cout << "\nenter item category: ";
                    cin >> cate;
                    cout << "\nenter item price: ";
                    cin >> price;
                    i.setName(name);
                    i.setCategory(cate);
                    i.setPrice(price);
                    tree.insert(i);
                    tree2.insertn(i);
                }
            }
        }
        else if(choose=='2')
        {
            cout<<"enter the item data you want to delete:\n";
            Item i;
            int price;
            string name, cate;
            cout << "\nenter item name: ";
            cin >> name;
            cout << "\nenter item category: ";
            cin >> cate;
            cout << "\nenter item price: ";
            cin >> price;
            i.setName(name);
            i.setCategory(cate);
            i.setPrice(price);
            tree.Deletep(i);
            tree2.Delete(i);
        }
        else if(choose=='3')
        {
            tree.printNormally();
        }
        else if(choose=='4' )
        {
            tree2.printAsc();
        }
        else if(choose=='5')
        {
            tree2.printDes();
        }
        else if(choose=='6')
        {
            tree.printAsc();
        }
        else if(choose=='7' )
        {
            tree.printDes();
        }
        else
            break;
    }
}