#include<bits/stdc++.h>
# include<fstream>
#define ll long long
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
vector<Item> ReadItem(){
fstream ifile("item.txt",ios::in|ios::out|ios::app);
ll no_item;
ifile>>no_item;
 vector<Item> it;
 for(int i=0;i<no_item;i++){
  string name,category;
  int price;
        ifile.ignore();
        getline(ifile,name);
        getline(ifile,category);
        ifile>>price;
        it.push_back(Item(name,category,price));
 }
 return it;
}
class BST{
  private:
    struct TreeNode{
    Item item;
    TreeNode* left,* right;
};
   TreeNode* root;
   void inorder(TreeNode* p){
       if(p!=NULL){//left root right
        inorder(p->left);
        p->item.print();
        inorder(p->right);
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
    void inorderTraversal(){
        inorder(root);
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
void printPrice(){
    vector<Item>it=ReadItem();
    BST b;
    //for(auto& i:it){
      //   cout<<i.getName()<<i.getCategory()<<i.getPrice() << endl;
    //}
    for (auto &item : it) {
        b.AddItemPrice(item);
    }
    //Tuna
      //meat
      //90

 cout<<" * Print tree Inorder *\n";
    b.inorderTraversal();
    cout<<"***********************\n";
 Item itemDelete(" apples"," fruit",66);
    if(b.searchPrice(itemDelete))cout<<"Yes,the Item is Found\n";
    else cout<<"No,The Item is not Found\n";
    cout << "Deleting item:\n";
    itemDelete.print();
    b.deleteItemPrice(itemDelete);
    if(b.isEmpty())cout<<"YES, Tree IS Empty.\n";
    else cout<<"NO, Tree Have Item. \n";
    cout<<"***********************\n";
    cout<<" * Print tree Inorder *\n";
    b.inorderTraversal();
    cout<<"***********************\n";
    cout<<"\n * Print tree Preorder *\n";
    b.preorderTraversal();
    cout<<"***********************\n";
    cout<<"\n * Print tree Postorder *\n";
    b.postorderTraversal();
}
void printName(){
    vector<Item>it=ReadItem();
    BST b;
    //for(auto& i:it){
      //   cout<<i.getName()<<i.getCategory()<<i.getPrice() << endl;
    //}
    for (auto &item : it) {
        b.AddItemName(item);
    }
    //Tuna
      //meat
      //90

 cout<<" * Print tree Inorder *\n";
    b.inorderTraversal();
    cout<<"***********************\n";
 Item itemDelete(" Tuna"," meat",90);
    if(b.searchName(itemDelete))cout<<"Yes,the Item is Found\n";
    else cout<<"No,The Item is not Found\n";
    cout << "Deleting item:\n";
    itemDelete.print();
    b.deleteItemName(itemDelete);
    if(b.isEmpty())cout<<"YES, Tree IS Empty.\n";
    else cout<<"NO, Tree Have Item. \n";
    cout<<"***********************\n";
    cout<<" * Print tree Inorder *\n";
    b.inorderTraversal();
    cout<<"***********************\n";
    cout<<"\n * Print tree Preorder *\n";
    b.preorderTraversal();
    cout<<"***********************\n";
    cout<<"\n * Print tree Postorder *\n";
    b.postorderTraversal();
}
int main(){
    cout<<"\n*********Price*********\n";
    printPrice();
    cout<<"\n*********Name*********\n";
    printName();
    return 0;
}



