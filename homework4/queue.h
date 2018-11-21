#include<iostream>
#include<ostream>
using namespace std;
// Creating template Node class
template<class T>
class Node{
public:
T data;
Node<T> *next;
Node<T>(T data){
this->data = data;
next = NULL;
}
};
//Declaration of Queue class
template <typename> class Queue;
// Declaration of << overloading function
template <typename T> std::ostream& operator<<(std::ostream&,Queue<T>);
// Implementation of Queue class
template <typename T>
class Queue
{
int size;
Node<T> *head, *tail;
public:
Queue(){
size=0;
head=NULL;
tail=NULL;
}
int get_size(){
return size;
}
void enqueue(T data){
Node<T> *node = new Node<T>(data);
if(size == 0){
head=node;
tail=node;
} else{
tail->next = node;
tail = tail->next;
}
size++;
}
T dequeue(){
if(size==0){
throw std::underflow_error("underflow_error");
}
else{
T data = head->data;
if(head == tail){
head = tail = NULL;
} else{
head=head->next;
}
size--;
return data;
}
}
// making operator overloading function as friend of Queue class
friend std::ostream& operator<< <>(std::ostream& out,Queue<T> obj);
};
// Implementation of << overloading function
template <typename T> std::ostream& operator<<(std::ostream& out,Queue<T> obj){
Node<T> *tmp = obj.head;
while(tmp != NULL){
out<<tmp->data<<" ";
tmp = tmp->next;
}
return out;
};
