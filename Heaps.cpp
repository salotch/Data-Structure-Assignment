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

    void print(){
        cout << "Item name is: " << itemName << "\n"
             << "Category is: " << category << "\n"
             << "Price is: " << price << "\n";
    }

    bool operator<(Item &other){
        return this->price < other.price;
    }

    bool operator>(Item &other){
        return this->itemName > other.itemName;
    }
};

vector<Item> ReadItem(){
    fstream ifile("item.txt", ios::in | ios::out | ios::app);
    ll no_item;
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
//-----------MaxHeap in Descending order by price-----------------------
class heap_for_Price{

    vector<Item> heap;

  public:

    void heapifyUp(int index){
        if (index == 0)
            return;

        int parent = (index - 1) / 2;

        if (heap[index].getPrice() > heap[parent].getPrice()){
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index){
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int maxx = index;

        if (left < heap.size() && heap[left].getPrice() > heap[maxx].getPrice())
            maxx = left;

        if (right < heap.size() && heap[right].getPrice() > heap[maxx].getPrice())
            maxx = right;

        if (maxx != index){
            swap(heap[index], heap[maxx]);
            heapifyDown(maxx);
        }
    }


    void insert(Item item){
        heap.push_back(item);
        heapifyUp(heap.size() - 1);
    }

    Item extractmaxx(){

        if (heap.empty())
            cout << "Heap already empty\n";

        Item maxItem = heap.front();
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            heapifyDown(0);

        return maxItem;
    }

    bool isEmpty(){
        return heap.empty();
    }
};
//-----------MaxHeap in Descending order  by name-----------------------

class heap_for_name{

    vector<Item> heap;

 public:
    void heapifyUp(int index){
        if (index == 0)
            return;

        int parent = (index - 1) / 2;

        if (heap[index].getName() > heap[parent].getName()){
            swap(heap[index], heap[parent]);
            heapifyUp(parent);
        }
    }

    void heapifyDown(int index){
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int maxx = index;

        if (left < heap.size() && heap[left].getName() > heap[maxx].getName())
            maxx = left;

        if (right < heap.size() && heap[right].getName() > heap[maxx].getName())
            maxx = right;

        if (maxx != index){
            swap(heap[index], heap[maxx]);
            heapifyDown(maxx);
        }
    }


    void insert(Item item){
        heap.push_back(item);
        heapifyUp(heap.size() - 1);
    }

    Item extractmaxx(){
        if (heap.empty())
            cout << "Heap already empty\n";

        Item maxItem = heap.front();
        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty())
            heapifyDown(0);

        return maxItem;
    }

    bool isEmpty(){
        return heap.empty();
    }
};

void display_descending_ByPrice(vector<Item> &items){
    heap_for_Price maxH;
    for (auto &item : items)
        maxH.insert(item);

    while (!maxH.isEmpty()){
        Item maxItem = maxH.extractmaxx();
        maxItem.print();
        cout << endl;
    }
}

void display_descending_ByName(vector<Item> &items)
{
    heap_for_name maxH;
    for (auto &item : items)
        maxH.insert(item);

    while (!maxH.isEmpty()){
        Item maxItem = maxH.extractmaxx();
        maxItem.print();
        cout << endl;
    }
}


//-----------MinHeap in Ascending order by price-----------------------
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
//-----------MinHeap in Ascending order by name-----------------------
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

//----------------------Display items normally------------------------
void Normally_displaying(vector<Item> &items){
    for (auto &item : items){
        item.print();
        cout <<  endl;
    }
}
int main(){

    vector<Item> items = ReadItem();

    int choice;
    do {
        cout << "\nMini-menu for Heaps:\n";
        cout << "1. Add item data\n";
        cout << "2. Delete item data\n";
        cout << "3. Display the item data normally\n";
        cout << "4. Display items sorted by their name (ascending)\n";
        cout << "5. Display items sorted by their name (descending)\n";
        cout << "6. Display items sorted by their prices (ascending)\n";
        cout << "7. Display items sorted by their prices (descending)\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, category;
                int price;
                cout << "Enter item name, category, and price: ";
                cin >> name >> category >> price;
                Item newItem(name, category, price);
                items.push_back(newItem);
                cout << "\n New item added to the list: \n" << endl;
                Normally_displaying(items);
                break;
            }
            case 2: {
                string name, category;
                int price;
                cout << "Enter item name, category, and price: ";
                cin >> name >> category >> price;
                Item DeletedItem(name, category, price);
                ItemdeletionFromList(items, DeletedItem);
                cout << "\n item deleted from the list:\n" << endl;
                Normally_displaying(items);
                break;
            }
            case 3: {
                Normally_displaying(items);
                break;
            }
            case 4: {
                cout << "\n sorted by name in ascending order:\n";
                display_Ascending_ByName(items);
                break;
            }
            case 5: {
                std::cout << "\n sorted by name in descending order:\n";
                display_descending_ByName(items);
                break;
            }
            case 6: {
                std::cout << "\n sorted by price in ascending order:\n";
                display_Ascending_ByPrice(items);
                break;
            }
            case 7: {
                std::cout << "\n sorted by price in descending order:\n";
                display_descending_ByPrice(items);
                break;
            }
            case 8:
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 8);


//================================================================================


    return 0;
}
