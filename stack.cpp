#include<bits/stdc++.h>
using namespace std;
const int MAX_SIZE=200;
class ArrayStack{
 private:
     int Top;
     int arr[MAX_SIZE];
 public:
    ArrayStack():Top(-1){}
    void push(int value){
    if(Top==MAX_SIZE-1){//stack full
       cout<<"stack full on push\n";
    }
    else{
         Top++;
         arr[Top]=value;
    }
}
bool is_Empty(){
 return (Top<0);
}
int pop(){
 if(is_Empty())cout<<"stack is Empty\n";
 else{// remove last element
  return arr[Top--];
 }
}
int get_top(){

    if(is_Empty())cout<<"stack is Empty\n";
    else{
        return arr[Top];
 }
}
int StackSize(){
  if(is_Empty())return (0);
  else{
    return (Top+1);
  }
}
void Clear(){
  while(!is_Empty())pop();
}
void print(){
 if(is_Empty())cout<<"stack is Empty\n";
 else{
        cout<<'[';
    for(int i=Top;i>=0;i--)cout<<arr[i]<<" ";
        cout<<']';
    cout<<"\n";
 }
}
};
void Stack_List(){
    cout<<"Array Based Implementation of The Stack\n";
    ArrayStack obj;
    obj.push(5);
    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.push(35);
    obj.print();
    cout<<"size: "<<obj.StackSize()<<"\n";
    obj.pop();
    obj.print();
    cout<<"Top: "<<obj.get_top()<<"\n";
    obj.Clear();
    obj.print();
}
struct Stack{
 int data;
 Stack* next;
};
Stack* top=NULL;
bool is_Empty_Slinked(){
   if(top==NULL)
      return true;
   else return false;
}
void push_stack_linked(int value){
  Stack* new_element=new Stack;
  new_element->data=value;
  new_element->next=top;
  top=new_element;
}
int pop_stack_linked(){
    Stack* first;
    int value;
    first=top;
    if(is_Empty_Slinked()){
          cout<<"stack is Empty\n";
          return -1;
      }
    else{
          top=first->next;
          value=first->data;
          delete(first);
           return value;
    }
}
void print_stack_linked() {
    Stack* current_node;
    if (is_Empty_Slinked()) {
         cout<<"stack is Empty\n";
    } else {
        current_node = top;
        cout<<'[';
        while (current_node != NULL) {
            cout << current_node->data << " ";
            current_node = current_node->next;
        }
        cout<<']';
    }
    cout<<"\n";
}
int Top_stack_linked(){
 return top->data;
}
void Clear_stack_linked(){
  while(!is_Empty_Slinked())pop_stack_linked();
}
int StackSize_linked(){
  int ctr=0;
  Stack* element;
  element=top;
  if(is_Empty_Slinked())return ctr;
  else{
    while(element->next!=NULL){
            ctr++;
            element= element->next;
    }
    return ctr+1;
  }
}
void stack_linked_list(){
    cout<<"Linked List Based Implementation of The Stack\n";
    push_stack_linked(5);
    push_stack_linked(10);
    push_stack_linked(20);
    push_stack_linked(30);
    push_stack_linked(35);
    print_stack_linked();
    cout<<"size: "<<StackSize_linked()<<"\n";
    pop_stack_linked();
    print_stack_linked();
    cout<<"TOP: "<<Top_stack_linked()<<"\n";
    Clear_stack_linked();
    print_stack_linked();
}
int main()
{
    Stack_List();
    cout<<"\n";
    stack_linked_list();
    return 0;
}
