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
        return ((itemName == other.itemName )&& (category == other.category) &&( price == other.price));
    }
    bool operator>(Item &other){
        return (price > other.price);
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
      if(p!=nullptr){
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
     void AddItem(Item item)
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
    bool search(Item &item){
        TreeNode *current = root;
        while (current !=  NULL) {
            if (current->item == item)
                return true;
            else if (current->item > item)
                current = current->left;
            else
                current = current->right;
        }
        return false;
    }

    void deleteItem(Item &item) {
        TreeNode *current = root;
        TreeNode *trailCurrent =NULL;
        bool found = false;

        while (current != NULL && !found) {
            if (current->item == item)
                found = true;
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
};

int main(){
    vector<Item>it=ReadItem();
    BST b;
    for (auto &item : it) {
        b.AddItem(item);
    }
    /*Tuna
      meat
      90
 */
 Item itemDelete("apples","fruit",66);
    cout << "Deleting item:\n";
    itemDelete.print();
    b.deleteItem(itemDelete);
    if(b.isEmpty())cout<<"YES, Tree IS Empty.\n";
    else cout<<"NO, Tree Have Item. \n";
    /*if(b.search(itemDelete))cout<<"yes\n";
    else cout<<"no\n";*/
    cout<<" * Print tree Inorder *\n";
    b.inorderTraversal();
    cout<<"\n * Print tree Preorder *\n";
    b.preorderTraversal();
    cout<<"\n * Print tree Postorder *\n";
    b.postorderTraversal();
    return 0;
}
