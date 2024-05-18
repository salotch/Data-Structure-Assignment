#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#define ll long long
using namespace std;

class Item
{
private:
    string itemName;
    string category;
    int price;

public:
    Item(string x, string y, int z) : itemName(x), category(y), price(z) {}
    Item() : itemName(""), category(""), price(0) {}

    string getName() { return itemName; }
    string getCategory() { return category; }
    int getPrice() { return price; }

    void setName(string x) { itemName = x; }
    void setCategory(string y) { category = y; }
    void setPrice(int z) { price = z; }

    void print()
    {
        cout << "Item name is: " << itemName << "\n"
             << "Category is: " << category << "\n"
             << "Price is: " << price << "\n";
    }

   /* bool operator<(Item &other)
    {
        return this->price < other.price;
    }

    bool operator>(Item &other)
    {
        return this->itemName > other.itemName;
    }*/
};

vector<Item> ReadItem()
{
    fstream ifile("item.txt", ios::in | ios::out | ios::app);
    ll no_item;
    ifile >> no_item;
    vector<Item> it;
    for (int i = 0; i < no_item; i++)
    {
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

class Price
{
private:
    vector<Item> heap;
  
  public:

    void heapifyUp(int index)
    {
        if (index == 0)
            return;
        int parent = (index - 1) / 2;
        if (heap[index].getPrice() < heap[parent].getPrice())
        {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int min = index;

        if (left < heap.size() && heap[left].getPrice() < heap[min].getPrice())
        {
            min = left;
        }
        if (right < heap.size() && heap[right].getPrice() < heap[min].getPrice())
        {
            min = right;
        }
        if (min != index)
        {
            swap(heap[index], heap[min]);
            heapifyDown(min);
        }
    }


    void insert(Item item)
    {
        heap.push_back(item);
        heapifyUp(heap.size() - 1);
    }

    Item extractMin()
    {
        if (heap.empty())
            cout << "Heap already empty" << endl;
        Item minItem = heap.front();
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
            heapifyDown(0);
        return minItem;
    }

    bool isEmpty()
    {
        return heap.empty();
    }
};

class Name
{
private:
    vector<Item> heap;
 
 public:
    void heapifyUp(int index)
    {
        if (index == 0)
            return;
        int parent = (index - 1) / 2;
        if (heap[index].getName() < heap[parent].getName())
        {
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }
   
    void heapifyDown(int index)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int min = index;

        if (left < heap.size() && heap[left].getName() < heap[min].getName())
        {
            min = left;
        }
        if (right < heap.size() && heap[right].getName() < heap[min].getName())
        {
            min = right;
        }
        if (min != index)
        {
            swap(heap[index], heap[min]);
            heapifyDown(min);
        }
    }


    void insert(Item item)
    {
        heap.push_back(item);
        heapifyUp(heap.size() - 1);
    }

    Item extractMin()
    {
        if (heap.empty())
            cout << "Heap already empty" << endl;
        Item minItem = heap.front();
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
            heapifyDown(0);
        return minItem;
    }

    bool isEmpty()
    {
        return heap.empty();
    }
};

void Normally_displaying(vector<Item> &items)
{
    for (auto &item : items)
    {
        item.print();
    }
}

void display_Ascending_ByPrice(vector<Item> &items)
{
    Price minH;
    for (auto &item : items)
    {
        minH.insert(item);
    }
    while (!minH.isEmpty())
    {
        Item minItem = minH.extractMin();
        minItem.print();
    }
}

void display_Ascending_ByName(vector<Item> &items)
{
    Name minH;
    for (auto &item : items)
    {
        minH.insert(item);
    }
    while (!minH.isEmpty())
    {
        Item minItem = minH.extractMin();
        minItem.print();
    }
}

void ItemdeletionFromList(vector<Item>& items,  Item& item)
{
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        if (it->getName() == item.getName() && it->getCategory() == item.getCategory() && it->getPrice() == item.getPrice())
        {
            items.erase(it);
            break;
        }
    }
}


void ItemAdditionToList(vector<Item>& items,  Item& newItem)
{
    items.push_back(newItem);
}

int main()
{
    vector<Item> items = ReadItem();

    cout << "---------------------------------------" << endl;
    cout << "Normally displaying:\n";
    Normally_displaying(items);

    cout << "----------------------------------------" << endl;

    cout << "Ascending order by price:\n";
    display_Ascending_ByPrice(items);

    cout << "-----------------------------------------" << endl;

    cout << "Ascending order by name:\n";
    display_Ascending_ByName(items);

    cout << "------------------------------------------\n"
         << "------------------------------------------" << endl;

    Item newItem("icecoffe", "drink", 35);
    Name heapName;
    for (const auto &item : items)
    {
        heapName.insert(item);
    }
    heapName.insert(newItem);
    cout << "new item sorting by name :"
         << " icecoffe, drink, 35" << endl;
    while (!heapName.isEmpty())
    {
        Item minItem = heapName.extractMin();
        minItem.print();
    }

    cout << "---------------------------------------------\n"
         << "---------------------------------------------" << endl;

    Price heapPrice;
    for (auto &item : items)
    {
        heapPrice.insert(item);
    }
    heapPrice.insert(newItem);
    cout << "new item sorting by price : "
         << "icecoffe, drink, 35" << endl;
    while (!heapPrice.isEmpty())
    {
        Item minItem = heapPrice.extractMin();
        minItem.print();
    }


cout << "---------------------------------------------\n"
         << "---------------------------------------------" << endl;

   Item DeletedItem;
cout << "Enter the details of the item for deletion:" << endl;
string name, category;
int price;
cout << "Name: ";;
cin >> name;
cout<<endl;
cout << "Category: ";
cin >> category;
cout<<endl;
cout << "Price: ";
cin >> price;
cout<<endl;
DeletedItem = Item(name, category, price);
ItemdeletionFromList(items, DeletedItem);
cout << "After deleting the specified item from the list:" << endl;
Normally_displaying(items);

cout << "---------------------------------------------\n"
         << "---------------------------------------------" << endl;


Item AddedItem;
cout << "Enter the details of the new item:" << endl;
string nameIt, categoryIt;
int priceIt;
cout << "Name: ";
cin >> nameIt;
cout << "Category: ";
cin >> categoryIt;
cout << "Price: ";
cin >> priceIt;
AddedItem = Item(nameIt, categoryIt, priceIt);
items.push_back(AddedItem);
cout << "New item added to the list:" << endl;
Normally_displaying(items);



    return 0;
}
