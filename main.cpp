#include "Heaps.h"
#include "AVL.h"
#include "BST.h"
int main()
{
    cout<<"welcome\n choose which data structure you want\n";
    cout<<"1. AVL Trees\n2. Binary Search Trees (BST)\n3. Heaps\n";
    int c;
    cin>>c;
    if(c==1)
    {
        avlmenue();
        return 0;
    }
    if(c==2)
    {
        bstmenue();
        return 0;
    }
    if(c==3)
    {
        heapsmenue();
        return 0;
    }

}