//IMPORTANT: we will understand the working of linked list when made using a class

#include<bits/stdc++.h>
using namespace std;

class Node{//using class instead of structure
  public:
  int data=5;
  Node* next;
  Node(){  }
  Node(int dt){
      data=dt;
      next=NULL;
  }
  /*Now we want to store the address of/or we want to link to the next node.So what should be the data type of pointer?
  if we use int,then we can only point to int,so we make a pointer of data type Node as we want to point to the next node.*/
};

int main(){
  Node* n1=new Node(12);
  cout<<(*n1).data;
  cout<<n1->data;
  //Here we are again using pointer,why? Here we are dynamically decalaring an object.we can make an object
  //without a pointer too
   Node newNode;
   cout<<newNode.data;
}
