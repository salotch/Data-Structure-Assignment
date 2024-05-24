#include "item.h"
class BST{
private:
    struct TreeNode{
        Item item;
        TreeNode* left,* right;
    };
    TreeNode* root;
    void inorderAscending(TreeNode* p){
        if(p!=NULL){//left root right
            inorderAscending(p->left);
            p->item.print();
            inorderAscending(p->right);
        }
    }
    void inorderDescending(TreeNode* p){//right root left
        if(p!=NULL){//right root left
            inorderDescending(p->right);
            p->item.print();
            inorderDescending(p->left);
        }
    }
    void preorder(TreeNode* p){//root left right
        if(p!=NULL){
            p->item.print();
            preorder(p->left);
            preorder(p->right);
        }
    }
    void postorder(TreeNode* p){//left right root
        if(p!=NULL){
            postorder(p->left);
            postorder(p->right);
            p->item.print();
        }
    }
    void Clear(TreeNode* p){
        if(p!=NULL){
            Clear(p->left);
            Clear(p->right);
            delete p;
            p=NULL;
        }
    }
    void deleteFromTree(TreeNode* &p)
    {
        TreeNode *current;
        TreeNode *trailCurrent;
        TreeNode *temp;

        if(p->left == NULL && p->right == NULL)
        {
            delete p;
            p = NULL;
        }
        else if(p->left == NULL)
        {
            temp = p;
            p = p->right;
            delete temp;
        }
        else if(p->right == NULL)
        {
            temp = p;
            p = p->left;
            delete temp;
        }
        else
        {
            current = p->left;
            trailCurrent = NULL;

            while(current->right != NULL)
            {
                trailCurrent = current;
                current = current->right;
            }

            p->item = current->item;

            if(trailCurrent == NULL)
                p->left = current->left;
            else
                trailCurrent->right = current->left;

            delete current;
        }
    }
public:
    BST(){
        root=NULL;
    }
    bool isEmpty(){
        return (root==NULL);
    }
    void inorderTraversalAscending(){
        inorderAscending(root);
    }
    void inorderTraversalDescending(){
        inorderDescending(root);
    }
    void preorderTraversal(){
        preorder(root);
    }
    void postorderTraversal(){
        postorder(root);
    }
    void ClearTree(){
        Clear(root);
    }
    ~BST(){
        Clear(root);
    }
    void AddItemPrice(Item item)
    {
        TreeNode *current;
        TreeNode *trailCurrent;
        TreeNode *newNode;
        newNode = new TreeNode;
        assert(newNode != NULL);
        newNode->item = item;
        newNode->left = NULL;
        newNode->right = NULL;

        if(root == NULL)
            root = newNode;
        else
        {
            current = root;

            while(current != NULL)
            {
                trailCurrent = current;
                if(current->item > item)
                    current = current->left;
                else
                    current = current->right;
            }

            if(trailCurrent->item > item)
                trailCurrent->left = newNode;
            else
                trailCurrent->right = newNode;
        }
    }
    bool searchPrice(Item &item){
        TreeNode *current = root;
        while (current !=  NULL) {
            //cout << "Comparing with item: " << current->item.getName() << ", " << current->item.getCategory() << ", " << current->item.getPrice() << endl;
            if (current->item==item){
                return true;
            }
            else if (current->item > item)
                current = current->left;
            else
                current = current->right;
        }
        return false;
    }

    void deleteItemPrice(Item &item) {
        TreeNode *current = root;
        TreeNode *trailCurrent =NULL;
        bool found = false;

        while (current != NULL && !found) {
            //cout << "Comparing with item: " << current->item.getName() << ", " << current->item.getCategory() << ", " << current->item.getPrice() << endl;
            if (current->item==item){
                found = true;break;
            }
            else {
                trailCurrent = current;
                if (current->item > item)
                    current = current->left;
                else
                    current = current->right;
            }
        }

        if (current == NULL) {
            cout << "The delete item is not in the tree.\n";
            return;
        }

        if (found) {
            if (current == root)
                deleteFromTree(root);
            else if (trailCurrent->item > item)
                deleteFromTree(trailCurrent->left);
            else
                deleteFromTree(trailCurrent->right);
        }
    }
    void AddItemName(Item item)
    {
        TreeNode *current;
        TreeNode *trailCurrent;
        TreeNode *newNode;
        newNode = new TreeNode;
        assert(newNode != NULL);
        newNode->item = item;
        newNode->left = NULL;
        newNode->right = NULL;

        if(root == NULL)
            root = newNode;
        else
        {
            current = root;

            while(current != NULL)
            {
                trailCurrent = current;
                if(current->item < item)
                    current = current->right;
                else
                    current = current->left;
            }

            if(trailCurrent->item < item)
                trailCurrent->right = newNode;
            else
                trailCurrent->left = newNode;
        }
    }
    bool searchName(Item &item){
        TreeNode *current = root;
        while (current !=  NULL) {
            //cout << "Comparing with item: " << current->item.getName() << ", " << current->item.getCategory() << ", " << current->item.getPrice() << endl;
            if (current->item==item){
                return true;
            }
            else if (current->item < item)
                current = current->right;
            else
                current = current->left;
        }
        return false;
    }

    void deleteItemName(Item &item) {
        TreeNode *current = root;
        TreeNode *trailCurrent =NULL;
        bool found = false;

        while (current != NULL && !found) {
            //cout << "Comparing with item: " << current->item.getName() << ", " << current->item.getCategory() << ", " << current->item.getPrice() << endl;
            if (current->item==item){
                found = true;break;
            }
            else {
                trailCurrent = current;
                if (current->item < item)
                    current = current->right;
                else
                    current = current->left;
            }
        }

        if (current == NULL) {
            cout << "The delete item is not in the tree.\n";
            return;
        }

        if (found) {
            if (current == root)
                deleteFromTree(root);
            else if (trailCurrent->item < item)
                deleteFromTree(trailCurrent->right);
            else
                deleteFromTree(trailCurrent->left);
        }
    }
};
void BSTmenu(){
    BST treeByPrice, treeByName;
    cout << "Welcome to the Item Management System using BST\n";
    while (true) {
        cout << "Which operation do you want to perform:\n";
        cout << "1. Insert element\n";
        cout << "2. Delete element\n";
        cout << "3. Retrieve all elements in the tree normally (by insertion order)\n";
        cout << "4. Retrieve all elements in the tree ascending by item's name\n";
        cout << "5. Retrieve all elements in the tree descending by item's name\n";
        cout << "6. Retrieve all elements in the tree ascending by item's price\n";
        cout << "7. Retrieve all elements in the tree descending by item's price\n";
        cout << "8. Exit\n";

        char choose;
        cin >> choose;
        if (choose == '1') {//insert
            int option=0;
            do
             {
                cout << "1. Do you want to insert data from file\n";
                cout << "2. Insert values manually\n";
                cin >> option;
            }while(option != 1 && option != 2);
            if (option == 1) {//from file
                vector<Item> it = ReadItem();
                for (auto &item : it) {
                    treeByPrice.AddItemPrice(item);
                    treeByName.AddItemName(item);
                }
            } else {//manually
                int num;
                cout << "Enter number of items you want to insert: ";
                cin >> num;
                while (num--) {
                    string name, category;
                    int price;
                    cout << "\nEnter item name: ";
                    cin >> ws; // clear whitespace
                    getline(cin,name);
                    cout << "Enter item category: ";
                    getline(cin,category);
                    cout << "Enter item price: ";
                    cin >> price;

                    Item item(name, category, price);
                    treeByPrice.AddItemPrice(item);
                    treeByName.AddItemName(item);
                }
            }
        } else if (choose == '2') {//delete
            string name, category;
            int price;
            cout << "\nEnter item name: ";
            cin >> ws; // clear whitespace
            getline(cin,name);
            cout << "Enter item category: ";
            getline(cin,category);
            cout << "Enter item price: ";
            cin >> price;
            Item item(name,category, price);
            if(treeByPrice.searchPrice(item)){
                cout<<"Item is Found\n";
                treeByPrice.deleteItemPrice(item);
            }
            else cout<<"Item is Not Found\n";
            if(treeByName.searchName(item)){
                  cout<<"Item is Found\n";
                  treeByName.deleteItemName(item);
            }
            else cout<<"Item is Not Found\n";
        } else if (choose == '3') {
            cout << "\n** Retrieve all elements (preorder by insertion) **\n";
            treeByName.preorderTraversal();
        } else if (choose == '4') {
            cout << "\n** Retrieve all elements ascending by item's name **\n";
            treeByName.inorderTraversalAscending();
        } else if (choose == '5') {
            cout << "\n** Retrieve all elements descending by item's name **\n";
            treeByName.inorderTraversalDescending();
        } else if (choose == '6') {
            cout << "\n** Retrieve all elements ascending by item's price **\n";
            treeByPrice.inorderTraversalAscending();
        } else if (choose == '7') {
            cout << "\n** Retrieve all elements descending by item's price **\n";
            treeByPrice.inorderTraversalDescending();
        } else if (choose == '8') {
            break;
        } else {
            cout << "Invalid option, please try again.\n";
        }
    }
    return;
}
