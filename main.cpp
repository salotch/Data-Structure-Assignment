#include "Heaps.h"
#include "BST.h"
#include "AVL.h"
int main()
{
    cout<<"welcome\n choose which data structure you want\n";
    cout<<"1. AVL Trees\n2. Binary Search Trees (BST)\n3. Heaps\n";
    int c;
    cin>>c;
    if(c==1)
    {
        avlmenue();
    }
    if(c==2)
    {
        bstmenue();
    }
    if(c==3)
    {
        heapsmenue();
    }
}