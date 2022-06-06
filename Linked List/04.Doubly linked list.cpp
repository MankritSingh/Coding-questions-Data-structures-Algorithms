//NULL check should be added to all functions ie if head 
//and tail is null
#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data=5;
  Node* next;
  Node* prev;
  Node(int dt){
      data=dt;
      next=NULL;
      prev=NULL;
  }
};

void insertAtHead(Node* &head,int dt){
	Node* n1=new Node(dt);
	head->prev=n1;
	n1->next=head;
	head=n1;	
}
void insertAtTail(Node* &tail,int dt){
	Node* n1=new Node(dt);
	tail->next=n1;
	n1->prev=tail;
	tail=n1;
}
void insertAtPosition(Node* &head,Node* &tail,int pos,int dt){
	//in this we also have to take care of insertion at start as it doesnt
	//work and insertion at end,as the tail is not updated
	if(pos==1)
	{				
		insertAtHead(head,dt);
		return;
	}
	Node* temp=head;
	while(pos--!=2){
		temp=temp->next;
	}
	//insert at end,Make sure you are taking tail and head by reference if you want to update them
	if(temp->next==NULL){
		insertAtTail(tail,dt);
		return;
	}
	Node* n1=new Node(dt);
	Node* tempnext=temp->next;
	temp->next=n1;
	n1->prev=temp;
	n1->next=tempnext;
	tempnext->prev=n1;
}
void deleteNode(Node* &head,int pos/*Node* &tail*/){
	if(pos==1){
		Node* temp=head;
		head=head->next;
		head->prev=NULL;
		delete(temp);//used to free memory occupied by the node
	}	
	else{
		Node* temp=head;
		Node* tempprev=temp;
		while(pos--!=1){
			tempprev=temp;
			temp=temp->next;
		}
		//code to change tail too
		tempprev->next=temp->next;
		if(temp->next!=NULL)	temp->next->prev=tempprev; 
		delete(temp);
	}

}
void print(Node* &head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data<<" ";
		temp=temp->next;	
	}
	cout<<endl;
}

int main(){
	Node* n1=new Node(10);
	Node* head=n1;
	Node* tail=n1;
	print(head);
	insertAtHead(head,20);
	print(head);
	insertAtTail(tail,50);
	print(head);
	insertAtHead(head,90);
	print(head);
	insertAtTail(tail,70);
	print(head);
	insertAtPosition(head,tail,2,100);
	print(head);
	insertAtPosition(head,tail,7,110);
	print(head);
	insertAtTail(tail,55);
	print(head);
	deleteNode(head,1);
	print(head);

}
