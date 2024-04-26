#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include<iomanip>
#include<iterator>
#include<algorithm>
#include<utility>
#include <chrono>
#define ll long long
using namespace std;
class Student{
private:
    string name,id;
    double gpa;
public:
     Student() : name(""), id(""), gpa(0.0) {} // Default constructor implementation
;
    Student(string& x,string& y,double& z){
        name=x;
        id=y;
        gpa=z;
    }
    string get_name(){
        return name;
    }
    string get_id(){
        return id;
    }
    double get_gpa(){
        return gpa;
    }
    bool operator<(Student sn){
        return (name < sn.name);
    }
    bool operator<=(const Student& sn){
        return (name <= sn.name);
    }
    bool operator>(Student sg){
        return (gpa > sg.gpa);//
    }
    bool operator>=(const Student& sg){
        return (gpa >= sg.gpa);
    }
    void operator=(Student sg){
        (gpa = sg.gpa);
        (id = sg.id);
        (name= sg.name);
    }
};
vector<Student> read_student_data(){
    fstream sfile("student.txt",ios::in|ios::out|ios::app);
        ll no_student;
        sfile>>no_student;
        vector<Student>st;
        for(int i=0;i<no_student;i++){
            string name,id;
            double gpa;
            sfile.ignore();
            getline(sfile, name);
            getline(sfile, id);
            sfile>>gpa;
            st.push_back(Student(name,id,gpa));
        }
        return st;
    }
template<typename Func, class T>
double measure_time(Func func, vector<T>& arr) {
    auto start = chrono::high_resolution_clock::now(); // Get the current time before executing the function
    func(arr); // Execute the provided function
    auto end = chrono::high_resolution_clock::now(); // Get the current time after executing the function
    chrono::duration<double> duration = end - start; // Calculate the time difference in milliseconds
    return duration.count();
}

template<typename Func, class T>
double measure_time(Func func, vector<T>& arr,int l,int r) {
    auto start = chrono::high_resolution_clock::now(); // Get the current time before executing the function
    func(arr,l,r); // Execute the provided function
    auto end = chrono::high_resolution_clock::now(); // Get the current time after executing the function
    chrono::duration<double> duration = end - start; // Calculate the time difference in milliseconds
    return duration.count();
}
int comparison_insertion_gpa=0;
int comparison_insertion_name=0;
template<class T>
void insertion_sort_gpa(vector<T>& arr) {
    int n = arr.size();
    int j;
    for (int i = 1; i < n; i++) {
        comparison_insertion_gpa++;
        T key = arr[i];
        j = i - 1;
        while (j >= 0 && key > arr[j]) {
            comparison_insertion_gpa+=2;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
template<class T>
void insertion_sort_name(vector<T>& arr) {
    int n = arr.size();
    int j;
    for (int i = 1; i < n; i++) {
            comparison_insertion_name++;
        T key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j]) {
            comparison_insertion_name+=2;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void print_insertion_sort(){
    fstream sfile("student.txt",ios::in|ios::out);
    if(sfile){
        vector<Student>st= read_student_data();
        ofstream writer_name("SortedByName.txt",ios::app);
        insertion_sort_name(st);
        if(writer_name){
            double time_taking_name = measure_time(insertion_sort_name<Student>, st);
            cout<<"Algorithm: Insertion Sort\n"<<"Running Time: "<<time_taking_name<<" seconds\n";
            writer_name<<"Algorithm: Insertion Sort\n";
            writer_name<<"Running Time: "<<time_taking_name<<" seconds\n";
            std::cout << "Number of comparisons in insertion sort by name: " << comparison_insertion_name << std::endl;
            writer_name<<"Number of comparisons in insertion sort by name: " << comparison_insertion_name << std::endl;
            for (auto& it : st) {
                cout << it.get_name() << " " << it.get_id() << " " << it.get_gpa() << endl;
                writer_name<< it.get_name() << endl;
                writer_name<< it.get_id() << endl;
                writer_name<< it.get_gpa() << endl;
            }
        }
        else 
        cout<<"Error: SortedByName file\n";
        
        cout<<"|||\n";
        
        ofstream writer_gpa("SortedByGPA.txt",ios::app);
        insertion_sort_gpa(st);
        if(writer_gpa){
            double time_taking_gpa = measure_time(insertion_sort_gpa<Student>, st);
            cout<<"Algorithm: Insertion Sort\n"<<"Running Time: "<<time_taking_gpa<<" seconds\n";
            writer_gpa<<"Algorithm: Insertion Sort\n";
            writer_gpa<<"Running Time: "<<time_taking_gpa<<" seconds\n";
            std::cout << "Number of comparisons in insertion sort by GPA: " << comparison_insertion_gpa << std::endl;
            writer_gpa<<"Number of comparisons in insertion sort by GPA: " << comparison_insertion_gpa << std::endl;
            for (auto& it : st) {
            cout << it.get_name() << " " << it.get_id() << " " << it.get_gpa() << endl;
                writer_gpa<< it.get_name() << endl;
                writer_gpa<< it.get_id() << endl;
                writer_gpa<< it.get_gpa() << endl;
            }
        }
        else cout<<"Error: SortedByGPA file\n";
    }
    else cout<<"Error: student file\n";
    sfile.close();
}
template<class T>
void selection_sort_ascending(vector<T>& arr){
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int mini = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[mini]) {
            mini = j;
            }
        }
    swap(arr[i], arr[mini]);
    }
}
template<class T>
void selection_sort_descending(vector<T>& arr){
    int n = arr.size(), j;
    for (int i = 0; i < n - 1; i++) {
        int mini = i;
        for ( j = i + 1; j < n; j++) {
            if (arr[j] > arr[mini]) {
            mini = j;
            }
        }
    swap(arr[i], arr[mini]);
    }
}

int Bubble_GPA_comparisons=0;
int Bubble_Name_comparisons=0;
template<class T>
void Bubble_sort_gpa(vector<T>& arr) {
    int n = arr.size();
    bool flag = true;

    for (int i = 0; i < n - 1; i++) {
        Bubble_GPA_comparisons++;
    for (int j = 0; j < n - i - 1; j++)
    {    Bubble_GPA_comparisons++;
        if (arr[j+1] > arr[j])
        {   Bubble_GPA_comparisons++;
            swap(arr[j], arr[j + 1]);
            flag = false;
        }
    }
    if (flag == true){
        Bubble_GPA_comparisons++;
        break;}
}
}
template<class T>
void Bubble_sort_name(vector<T>& arr) {
    int n = arr.size();
    bool flag = true;

    for (int i = 0; i < n - 1; i++) {
        Bubble_Name_comparisons++;
        for (int j = 0; j < n - i - 1; j++)
        {  Bubble_Name_comparisons++;
            if (arr[j+1] < arr[j])
            { Bubble_Name_comparisons++;
                swap(arr[j], arr[j + 1]);
                flag = false;
            }
        }
        if (flag == true){
            Bubble_Name_comparisons++;
            break;}
    }
}
int comparison_shell_name=0;
int comparison_shell_gpa=0;
template<class T>
void shell_sort_gpa(vector<T>& arr){
    int n = arr.size(),j;
    for(int gap=n/2;gap>0;gap/=2){
        comparison_shell_gpa++;
        for(int i=gap;i<n;i++){
            comparison_shell_gpa++;
            T temp=arr[i];
            j=i;
            while(j>=gap&&temp>arr[j-gap]){
                comparison_shell_gpa+=2;
                arr[j]=arr[j-gap];
                j-=gap;
            }
            arr[j]=temp;
        }
    }
}
template<class T>
void shell_sort_name(vector<T>& arr){
    int n = arr.size(),j;
    for(int gap=n/2;gap>0;gap/=2){
        comparison_shell_name++;
        for(int i=gap;i<n;i++){
            comparison_shell_name++;
            T temp=arr[i];
            j=i;
            while(j>=gap&&temp<arr[j-gap]){
                comparison_shell_name+=2;
                arr[j]=arr[j-gap];
                j-=gap;
            }
            arr[j]=temp;
        }
    }
}
template<class T>
void merge_name(vector<T>& arr,int left,int middle,int right) {
    int n1=middle-left+1;//+1 to avoid if two array not equle each other
    int n2=right-middle;
    vector<T>l(n1);
    vector<T>r(n2);
    for(int i=0;i<n1;i++)
    {
        l[i]=arr[left+i];
    }
    for(int j=0;j<n2;j++)
    {
        r[j]=arr[middle+1+j];
    }
    int i=0,j=0;
    int k=left;
    while(i<n1&&j<n2)
    {
        if(l[i]<=r[j]){
            arr[k]=l[i];
            ++i;
        }
        else{
            arr[k]=r[j];
            j++;
        }
        ++k;
    }
    while(i<n1)
    {
        arr[k]=l[i];
        ++k;
        ++i;
    }
    while(j<n2)
    {
        arr[k]=r[j];
        ++k;
        ++j;
    }

}
template<class T>
void merge_Gpa(vector<T>& arr,int left,int middle,int right) {
    int n1=middle-left+1;//+1 to avoid if two array not equle each other
    int n2=right-middle;
    vector<T>l(n1);
    vector<T>r(n2);
    for(int i=0;i<n1;i++)
    {
        l[i]=arr[left+i];
    }
    for(int j=0;j<n2;j++)
    {
        r[j]=arr[middle+1+j];
    }
    int i=0,j=0;
    int k=left;
    while(i<n1&&j<n2)
    {
        if(l[i]>=r[j]){
            arr[k]=l[i];
            ++i;
        }
        else{
            arr[k]=r[j];
            j++;
        }
        ++k;
    }
    while(i<n1)
    {
        arr[k]=l[i];
        ++k;
        ++i;
    }
    while(j<n2)
    {
        arr[k]=r[j];
        ++k;
        ++j;
    }

}

template<class T>
void merge_Sort_name(vector<T>& arr,int left,int right) {
    if(left<right){
        int m;
        m=left+(right-left)/2;//-1 to reach to base case
        merge_Sort_name(arr,left,m);
        merge_Sort_name(arr,m+1,right);
        merge_name(arr,left,m,right);

    }

}
template<class T>
void merge_Sort_Gpa(vector<T>& arr,int left,int right) {
    if(left<right){
        int m;
        m=left+(right-left)/2;//+left to know idex after we know middle
        merge_Sort_Gpa(arr,left,m);
        merge_Sort_Gpa(arr,m+1,right);
        merge_Gpa(arr,left,m,right);

    }

}

void print_merge_sort(){
fstream sfile("student.txt",ios::in|ios::out);
    if(sfile){
        vector<Student>st=read_student_data();
        int r=st.size();
        ofstream writer_name("SortedByName.txt",ios::app);
        merge_Sort_name(st,0,r-1);
        if(writer_name){
            double time_taking_name = measure_time(merge_Sort_name<Student>, st,0,r-1);
            cout<<"Algorithm: Merge Sort\n"<<"Running Time: "<<time_taking_name<<" seconds\n";
            writer_name<<"Algorithm: Merge Sort\n";
            writer_name<<"Running Time: "<<time_taking_name<<" seconds\n";
            for (auto& it : st) {
                cout << it.get_name() << " " << it.get_id() << " " << it.get_gpa() << endl;
                writer_name<< it.get_name() << endl;
                writer_name<< it.get_id() << endl;
                writer_name<< it.get_gpa() << endl;
            }
        }
        else cout<<"Error: SortedByName file\n";
        cout<<"|||\n";
        ofstream writer_gpa("SortedByGPA.txt",ios::app);
        merge_Sort_Gpa(st,0,r-1);
        if(writer_gpa){
            double time_taking_gpa = measure_time(merge_Sort_Gpa<Student>, st,0,r-1);
            cout<<"Algorithm: Merge Sort\n"<<"Running Time: "<<time_taking_gpa<<" seconds\n";
            writer_gpa<<"Algorithm: Merge Sort\n";
            writer_gpa<<"Running Time: "<<time_taking_gpa<<" seconds\n";
            for (auto& it : st) {
            cout << it.get_name() << " " << it.get_id() << " " << it.get_gpa() << endl;
                writer_gpa<< it.get_name() << endl;
                writer_gpa<< it.get_id() << endl;
                writer_gpa<< it.get_gpa() << endl;
            }
        }
        else cout<<"Error: SortedByGPA file\n";
    }
    else cout<<"Error: student file\n";
    sfile.close();
}
void print_shell_sort(){
fstream sfile("student.txt",ios::in|ios::out);
    if(sfile){
        vector<Student>st=read_student_data();
        ofstream writer_name("SortedByName.txt",ios::app);
        shell_sort_name(st);
        if(writer_name){
            double time_taking_name = measure_time(shell_sort_name<Student>, st);
            cout<<"Algorithm: Shell Sort\n"<<"Running Time: "<<time_taking_name<<" seconds\n";
            writer_name<<"Algorithm: Shell Sort\n";
            writer_name<<"Running Time: "<<time_taking_name<<" seconds\n";
            std::cout << "Number of comparisons in shell sort by name: " << comparison_shell_name << std::endl;
            writer_name<<"Number of comparisons in shell sort by name: " << comparison_shell_name << std::endl;
            for (auto& it : st) {
            cout << it.get_name() << " " << it.get_id() << " " << it.get_gpa() << endl;
            writer_name<< it.get_name() << endl;
            writer_name<< it.get_id() << endl;
            writer_name<< it.get_gpa() << endl;
            }
        }
        else cout<<"Error: SortedByName file\n";
        cout<<"|||\n";
        ofstream writer_gpa("SortedByGPA.txt",ios::app);
        shell_sort_gpa(st);
        if(writer_gpa){
            double time_taking_gpa = measure_time(shell_sort_gpa<Student>, st);
            cout<<"Algorithm: shell Sort\n"<<"Running Time: "<<time_taking_gpa<<" seconds\n";
            writer_gpa<<"Algorithm: shell Sort\n";
            writer_gpa<<"Running Time: "<<time_taking_gpa<<" seconds\n";
            std::cout << "Number of comparisons in shell sort by GPA: " << comparison_shell_gpa << std::endl;
            writer_gpa<<"Number of comparisons in shell sort by GPA: " << comparison_shell_gpa << std::endl;
            for (auto& it : st) {
            cout << it.get_name() << " " << it.get_id() << " " << it.get_gpa() << endl;
                writer_gpa<< it.get_name() << endl;
                writer_gpa<< it.get_id() << endl;
                writer_gpa<< it.get_gpa() << endl;
            }
        }
        else cout<<"Error: SortedByGPA file\n";
    }
    else cout<<"Error: student file\n";
    sfile.close();
}
void print_Bubble_sort() {
    fstream sfile("student.txt", ios::in | ios::out);
    if (sfile) {
        vector<Student>st = read_student_data();
        ofstream writer_name("SortedByName.txt", ios::app);
        Bubble_sort_name(st);
        if (writer_name) {
            double time_taking_name = measure_time(Bubble_sort_name<Student>, st);
            cout << "Algorithm: Bubble Sort\n" << "Running Time: " << time_taking_name << " seconds\n";
            writer_name << "Algorithm: Bubble Sort\n";
            writer_name << "Running Time: " << time_taking_name << " seconds\n";
            std::cout << "Number of comparisons in Bubble sort by name: " << Bubble_Name_comparisons << std::endl;
            writer_name<<"Number of comparisons in Bubble sort by name: " << Bubble_Name_comparisons << std::endl;
            for (auto& it : st) {
                cout << it.get_name() << " " << it.get_id() << " " << it.get_gpa() << endl;
                writer_name << it.get_name() << endl;
                writer_name << it.get_id() << endl;
                writer_name << it.get_gpa() << endl;
            }
        }
        else cout << "Error: SortedByName file\n";
        cout << "|||\n";
        ofstream writer_gpa("SortedByGPA.txt", ios::app);
        Bubble_sort_gpa(st);
        if (writer_gpa) {
            double time_taking_gpa = measure_time(Bubble_sort_gpa<Student>, st);
            cout << "Algorithm: Bubble Sort\n" << "Running Time: " << time_taking_gpa << " seconds\n";
            writer_gpa << "Algorithm: Bubble Sort\n";
            writer_gpa << "Running Time: " << time_taking_gpa << " seconds\n";
            std::cout << "Number of comparisons in Bubble sort by GPA: " << Bubble_GPA_comparisons << std::endl;
            writer_name<<"Number of comparisons in Bubble sort by GPA: " << Bubble_GPA_comparisons << std::endl;
            for (auto& it : st) {
                cout << it.get_name() << " " << it.get_id() << " " << it.get_gpa() << endl;
                writer_gpa << it.get_name() << endl;
                writer_gpa << it.get_id() << endl;
                writer_gpa << it.get_gpa() << endl;
            }
        }
        else cout << "Error: SortedByGPA file\n";
    }
    else cout << "Error: student file\n";
    sfile.close();
}
void print_selection_sort(){
fstream sfile("student.txt",ios::in|ios::out);
    if(sfile){
    vector<Student> st = read_student_data();
    ofstream writer_gpa("SortedByGPA.txt",ios::app);
    selection_sort_descending(st);
    if(writer_gpa){
        double time_taking_gpa = measure_time(selection_sort_descending<Student>, st);

        cout << "Algorithm: selection Sort by GPA \n" << "Running Time: " << time_taking_gpa << " seconds\n";

        writer_gpa << "Algorithm: selection Sort by GPA \n";
        writer_gpa << "Running Time: " << time_taking_gpa << " seconds\n";

        for (auto& it : st) {
            cout << it.get_name() << endl << it.get_id() << endl << it.get_gpa() << endl<<endl;
            writer_gpa  << it.get_name() << endl;
            writer_gpa << it.get_id() << endl;
            writer_gpa << it.get_gpa() << endl;
        }
    }
    else cout<<"Error: SortedDescending file\n ||| \n";

    ofstream writer_name("SortedByName.txt",ios::app);
    selection_sort_ascending(st);
    if(writer_name){
        double time_taking_name = measure_time(selection_sort_ascending<Student>, st);
        cout << "Algorithm: selection Sort by name\n" << "Running Time: " << time_taking_name << " seconds\n";

        writer_name << "Algorithm: selection Sort by name\n";
        writer_name << "Running Time: "<<time_taking_name<<" seconds\n";
        for (auto& it : st) {
            cout << it.get_name() << endl << it.get_id() << endl << it.get_gpa() << endl<<endl;
            writer_name << it.get_name() << endl;
            writer_name << it.get_id() << endl;
            writer_name << it.get_gpa() << endl;
            }
    }
    else cout<<"Error: SortedAscending file\n";
}
    else cout<<"Error: student file\n";
    sfile.close();
}

template<class t>
void quick_gpa_des(vector<t>& arr,ll l, ll h){
    if(l<h){
        ll p=partitioning_quick_gpa_des(arr,l,h);
        quick_gpa_des(arr,l,p-1);
        quick_gpa_des(arr,p+1,h);
    }
}
template<class t>
void quick_name(vector<t>& arr,ll l, ll h){
    if(l<h){
        ll p=partitioning_quick_name(arr,l,h);
        quick_name(arr,l,p-1);
        quick_name(arr,p+1,h);
    }
}

template<class t>
ll partitioning_quick_gpa_des(vector<t>& arr,ll start, ll end){
    ll i=start ;
    ll j=end;
    ll pivot =i;
    while(true)
    {
        if(i>=j)
        {swap(arr[pivot],arr[j]);
            break;
        }
        while(arr[i]>arr[pivot])
            i++;
        while(arr[pivot]>arr[j])
            j--;
        swap(arr[i],arr[j]);
    }
    return pivot;
}
template<class t>
ll partitioning_quick_name(vector<t>& arr,ll start, ll end){
    ll i=start ;
    ll j=end;
    ll pivot =i;
    while(true)
    {
        if(i>=j)
        {
            swap(arr[pivot],arr[j]);
            break;
        }
        while(arr[i]<arr[pivot])
            i++;
        while(arr[pivot]<arr[j])
            j--;
        swap(arr[i],arr[j]);
    }
    return pivot;
}
//quick

void print_quick_sort(){
    int abdo=1;
    fstream sfile("student.txt",ios::in|ios::out);
    if(sfile){
        vector<Student> st = read_student_data();
        ofstream writer_gpa("SortedByGPA.txt",ios::app);
        ll k=st.size();

        quick_gpa_des(st,0,k-1);
        if(writer_gpa){
            double time_taking_gpa = measure_time(quick_gpa_des<Student>, st,0,k-1);

            cout << "Algorithm: quick Sort by GPA \n" << "Running Time: " << time_taking_gpa << " seconds\n";

            writer_gpa << "Algorithm: quick Sort by GPA \n";
            writer_gpa << "Running Time: " << time_taking_gpa << " seconds\n";

            for (auto& it : st) {

                cout << it.get_name() << endl << it.get_id() << endl << it.get_gpa() << endl<<endl;
                writer_gpa  << it.get_name() << endl;
                writer_gpa << it.get_id() << endl;
                writer_gpa << it.get_gpa() << endl;

            } writer_gpa.close();
        }
        else cout<<"Error: SortedDescending file\n ||| \n";

        fstream writer_name("SortedByName.txt",ios::app);
        quick_name(st,0,k-1);
        if(writer_name){
            double time_taking_name = measure_time(quick_name<Student>, st,0,k-1);
            cout << "Algorithm: quick Sort by name\n"<< "Running Time: " << time_taking_name << " seconds\n";

            writer_name << "Algorithm: quick Sort by name\n";
            writer_name << "Running Time: "<<time_taking_name<<" seconds\n";
            for (auto& it : st) {

                cout << it.get_name() << endl << it.get_id() << endl << it.get_gpa() << endl<<endl;
                writer_name << it.get_name() << endl;
                writer_name << it.get_id() << endl;
                writer_name << it.get_gpa() << endl;
            }
            writer_name.close();
        }
        else cout<<"Error: SortedAscending file\n";
    }
    else cout<<"Error: student file\n";
    sfile.close();

}
int main()
{
    print_insertion_sort();
    print_selection_sort();
    print_Bubble_sort();
    print_shell_sort();
    print_merge_sort();
    print_quick_sort();

}
