#ifndef DATA_STRUCTURE_ASSIGNMENTFINAL_ITEM_H
#define DATA_STRUCTURE_ASSIGNMENTFINAL_ITEM_H
#include <algorithm>
#include <iostream>
#include<vector>
#include<fstream>
#include <stdexcept>
#include <string>
#include<bits/stdc++.h>
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
    bool operator<=(Item &other){
        return(this->itemName<=other.itemName);
    }
    bool operator>(Item &other) {
        return (this->price > other.price);
    }
    bool operator>=(Item &other) {
        return (this->price >= other.price);
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
#endif //DATA_STRUCTURE_ASSIGNMENTFINAL_ITEM_H
