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
        cout<< "Item name is: " << itemName << "\n"
            << "Category is: " << category << "\n"
            << "Price is: " << price << "\n";
    }

    bool operator<(Item &other)
    {
        return this->price < other.price;
    }

    bool operator>(Item &other)
    {
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

class Price{

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

class Name{

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

void Normally_displaying(vector<Item> &items){
    for (auto &item : items)
        item.print();
}

void display_descending_ByPrice(vector<Item> &items){
    Price maxH;
    for (auto &item : items)
        maxH.insert(item);

    while (!maxH.isEmpty()){
        Item maxItem = maxH.extractmaxx();
        maxItem.print();
    }
}

void display_descending_ByName(vector<Item> &items)
{
    Name maxH;
    for (auto &item : items)
        maxH.insert(item);

    while (!maxH.isEmpty()){
        Item maxItem = maxH.extractmaxx();
        maxItem.print();
    }
}

int main()
{
    vector<Item> items = ReadItem();

    cout << "---------------------------------------" << endl;
    cout << "Normally displaying:\n";
    Normally_displaying(items);

    cout << "----------------------------------------" << endl;

    cout << "Descending order by price:\n";
    display_descending_ByPrice(items);

    cout << "-----------------------------------------" << endl;

    cout << "Descending order by name:\n";
    display_descending_ByName(items);

    cout << "------------------------------------------\n"
        << "------------------------------------------" << endl;

    Item newItem("ice coffe", "drink", 35);
    Name heapName;
    for (const auto &item : items)
        heapName.insert(item);

    heapName.insert(newItem);

    cout << "new item sorting by name :"
        << " ice coffe, drink, 35" << endl;
    while (!heapName.isEmpty()){
        Item maxItem = heapName.extractmaxx();
        maxItem.print();
    }

    cout << "---------------------------------------------\n"
        << "---------------------------------------------" << endl;

    Price heapPrice;
    for (auto &item : items)
        heapPrice.insert(item);

    heapPrice.insert(newItem);
    cout << "new item sorting by price : "
        << "ice coffe, drink, 35" << endl;

    while (!heapPrice.isEmpty()){
        Item maxItem = heapPrice.extractmaxx();
        maxItem.print();
    }

    return 0;
}
