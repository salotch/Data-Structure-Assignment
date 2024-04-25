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
     std::string name,id;
     double gpa;
 public:
 Student();
 Student(std::string& x,std::string& y,double& z){
 name=x;
 id=y;
 gpa=z;
 }
 std::string get_name(){
  return name;
 }
 std::string get_id(){
  return id;
 }
  double get_gpa(){
    return gpa;
 }
  bool operator<(Student sn){
        return (name < sn.name);
    }

    bool operator>(Student sg){
        return (gpa > sg.gpa);
    }
};
std::vector<Student> read_student_data(){
std::fstream sfile("student.txt",ios::in|ios::out|ios::app);
 ll no_student;
 sfile>>no_student;
 std::vector<Student>st;
 for(int i=0;i<no_student;i++){
  std::string name,id;
  double gpa;
        sfile.ignore();
        std::getline(sfile, name);
        std::getline(sfile, id);
        sfile>>gpa;
        st.push_back(Student(name,id,gpa));
 }
 return st;
}
template<typename Func, class T>
double measure_time(Func func, std::vector<T>& arr) {
    auto start = std::chrono::high_resolution_clock::now(); // Get the current time before executing the function
    func(arr); // Execute the provided function
    auto end = std::chrono::high_resolution_clock::now(); // Get the current time after executing the function
    std::chrono::duration<double> duration = end - start; // Calculate the time difference in milliseconds
    return duration.count();
}
template<class T>
void insertion_sort_gpa(std::vector<T>& arr) {
    int n = arr.size();
    if (n <= 1) return; // No need to sort if there is only one element or less
    int j;
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        j = i - 1;
        while (j >= 0 && key > arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
template<class T>
void insertion_sort_name(std::vector<T>& arr) {
    int n = arr.size();
    int j;
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void print_insertion_sort(){
  std::fstream sfile("student.txt",ios::in|ios::out|ios::app);
  if(sfile){
  std::vector<Student>st= read_student_data();
    ofstream writer_name("SortedByName.txt",ios::out|ios::app);
    insertion_sort_name(st);
    if(writer_name){
        double time_taking_name = measure_time(insertion_sort_name<Student>, st);
        std::cout<<"Algorithm: Insertion Sort\n"<<"Running Time: "<<time_taking_name<<" seconds\n";
        writer_name<<"Algorithm: Insertion Sort\n";
        writer_name<<"Running Time: "<<time_taking_name<<" seconds\n";
    for (auto& it : st) {
        std::cout << it.get_name() << " " << it.get_id() << " " << it.get_gpa() << std::endl;
        writer_name<< it.get_name() << endl;
        writer_name<< it.get_id() << endl;
        writer_name<< it.get_gpa() << endl;
    }
    }
    else cout<<"Error: SortedByName file\n";
    std::cout<<"|||\n";
    ofstream writer_gpa("SortedByGPA.txt",ios::out|ios::app);
   insertion_sort_gpa(st);
    if(writer_gpa){
        double time_taking_gpa = measure_time(insertion_sort_gpa<Student>, st);
        std::cout<<"Algorithm: Insertion Sort\n"<<"Running Time: "<<time_taking_gpa<<" seconds\n";
        writer_gpa<<"Algorithm: Insertion Sort\n";
        writer_gpa<<"Running Time: "<<time_taking_gpa<<" seconds\n";
    for (auto& it : st) {
       std::cout << it.get_name() << " " << it.get_id() << " " << it.get_gpa() << std::endl;
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
void selection_sort_ascending(vector<T>& arr){// from lower to higher ^-^
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
void selection_sort_descending(vector<T>& arr){//from higher to lower
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
template<class T>
void Bubble_sort_gpa(std::vector<T>& arr) {
    int n = arr.size(), j;
    bool flag = true;

    for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++)
    {
        if (arr[j+1] > arr[j])
        {
            swap(arr[j], arr[j + 1]);
            flag = false;
        }
    }
    if (flag == true)
        break;
}
}
template<class T>
void Bubble_sort_name(std::vector<T>& arr) {
    int n = arr.size(), j;
    bool flag = true;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j+1] < arr[j])
            {
                swap(arr[j], arr[j + 1]);
                flag = false;
            }
        }
         if (flag == true)
            break;
    }
}
template<class T>
void shell_sort_gpa(std::vector<T>& arr){
   int n = arr.size(),j;
   for(int gap=n/2;gap>0;gap/=2){
    for(int i=gap;i<n;i++){
        T temp=arr[i];
        j=i;
        while(j>=gap&&temp>arr[j-gap]){
            arr[j]=arr[j-gap];
            j-=gap;
        }
        arr[j]=temp;
    }
   }
}
template<class T>
void shell_sort_name(std::vector<T>& arr){
   int n = arr.size(),j;
   for(int gap=n/2;gap>0;gap/=2){
    for(int i=gap;i<n;i++){
        T temp=arr[i];
        j=i;
        while(j>=gap&&temp<arr[j-gap]){
            arr[j]=arr[j-gap];
            j-=gap;
        }
        arr[j]=temp;
    }
   }
}
void print_shell_sort(){
std::fstream sfile("student.txt",ios::in|ios::out|ios::app);
  if(sfile){
  std::vector<Student>st=read_student_data();
    ofstream writer_name("SortedByName.txt",ios::out|ios::app);
    shell_sort_name(st);
    if(writer_name){
        double time_taking_name = measure_time(shell_sort_name<Student>, st);
        std::cout<<"Algorithm: Shell Sort\n"<<"Running Time: "<<time_taking_name<<" seconds\n";
        writer_name<<"Algorithm: Shell Sort\n";
        writer_name<<"Running Time: "<<time_taking_name<<" seconds\n";
    for (auto& it : st) {
        std::cout << it.get_name() << " " << it.get_id() << " " << it.get_gpa() << std::endl;
        writer_name<< it.get_name() << endl;
        writer_name<< it.get_id() << endl;
        writer_name<< it.get_gpa() << endl;
    }
    }
    else cout<<"Error: SortedByName file\n";
    std::cout<<"|||\n";
    ofstream writer_gpa("SortedByGPA.txt",ios::out|ios::app);
   shell_sort_gpa(st);
    if(writer_gpa){
        double time_taking_gpa = measure_time(shell_sort_gpa<Student>, st);
        std::cout<<"Algorithm: shell Sort\n"<<"Running Time: "<<time_taking_gpa<<" seconds\n";
        writer_gpa<<"Algorithm: shell Sort\n";
        writer_gpa<<"Running Time: "<<time_taking_gpa<<" seconds\n";
    for (auto& it : st) {
       std::cout << it.get_name() << " " << it.get_id() << " " << it.get_gpa() << std::endl;
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
    std::fstream sfile("student.txt", ios::in | ios::out | ios::app);
    if (sfile) {
        std::vector<Student>st = read_student_data();
        ofstream writer_name("SortedByName.txt", ios::out | ios::app);
       Bubble_sort_name(st);
        if (writer_name) {
            double time_taking_name = measure_time(Bubble_sort_name<Student>, st);
            std::cout << "Algorithm: Bubble Sort\n" << "Running Time: " << time_taking_name << " seconds\n";
            writer_name << "Algorithm: Bubble Sort\n";
            writer_name << "Running Time: " << time_taking_name << " seconds\n";
            for (auto& it : st) {
                std::cout << it.get_name() << " " << it.get_id() << " " << it.get_gpa() << std::endl;
                writer_name << it.get_name() << endl;
                writer_name << it.get_id() << endl;
                writer_name << it.get_gpa() << endl;
            }
        }
        else cout << "Error: SortedByName file\n";
        std::cout << "|||\n";
        ofstream writer_gpa("SortedByGPA.txt", ios::out | ios::app);
        Bubble_sort_gpa(st);
        if (writer_gpa) {
            double time_taking_gpa = measure_time(Bubble_sort_gpa<Student>, st);
            std::cout << "Algorithm: Bubble Sort\n" << "Running Time: " << time_taking_gpa << " seconds\n";
            writer_gpa << "Algorithm: Bubble Sort\n";
            writer_gpa << "Running Time: " << time_taking_gpa << " seconds\n";
            for (auto& it : st) {
                std::cout << it.get_name() << " " << it.get_id() << " " << it.get_gpa() << std::endl;
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
fstream sfile("student.txt",ios::in|ios::out|ios::app);
  if(sfile){
    vector<Student> st = read_student_data();
    ofstream writer_gpa("SortedByGPA.txt",ios::out|ios::app);
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

    ofstream writer_name("SortedByName.txt",ios::out|ios::app);
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
int main()
{
   print_insertion_sort();
   print_selection_sort();
   print_Bubble_sort();
   print_shell_sort();
    return 0;
}
