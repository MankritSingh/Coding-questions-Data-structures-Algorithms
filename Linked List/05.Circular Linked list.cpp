//NULL check should be added to all functions ie if head 
//and tail is null
//In Circular linkedlist we use tail instead of head as we can
//easily access head from tail by just going to next element
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node(){}
	Node(int d){
		data=d;
		next=NULL;
	}
};
void insertAtVal(Node* &tail,int val,int d){
  //if list empty
	if(tail==NULL){
		Node* n1=new Node(d);
		tail=n1;
		n1->next=n1;
	}
	else{
		Node* temp=tail;
		while(temp->data!=val){
			temp=temp->next;
		} 
		Node* n1=new Node(d);
		n1->next=temp->next;
		temp->next=n1;
		if(temp==tail)	tail=n1;	
	}
}
void deleteNode(Node* &tail,int val){
	//when list is empty
	if(tail==NULL){
		cout<<"List is empty"<<endl;
		return;
	}
	Node* prev=tail;
	Node* curr=tail->next;
	//when there is only 1 node
	if(prev==curr){
		tail=NULL;
		delete prev;
	}
	while(curr->data!=val){
		prev=curr;
		curr=curr->next;
	}
	prev->next=curr->next;
	if(curr==tail)	tail=prev;
	delete(curr);
}
void print(Node* tail){
	Node* temp=tail->next;
	while(temp!=tail){
		cout<<temp->data<<" ";
		temp=temp->next;
	} 
	cout<<temp->data;
	cout<<endl;
}
int main(){
  //testing the code
	Node* tail=NULL;
	deleteNode(tail,10);
	insertAtVal(tail,10,10);
	print(tail);
	insertAtVal(tail,10,20);
	print(tail);
	insertAtVal(tail,10,30);
	print(tail);
	deleteNode(tail,30);
	print(tail);
	cout<<tail->data;

}
