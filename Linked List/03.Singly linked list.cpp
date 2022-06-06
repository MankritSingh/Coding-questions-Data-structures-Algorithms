#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data=5;
  Node* next;
  Node(){  }
  Node(int dt){
      data=dt;
      next=NULL;
  }
};

void insertAtHead(Node* &head,int dt){
	Node* n1=new Node(dt);
	n1->next=head;
	head=n1;	
}
void insertAtTail(Node* &tail,int dt){
	Node* n1=new Node(dt);
	tail->next=n1;
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
	Node* n1=new Node(dt);
	Node* temp=head;
	pos-=2;
	while(pos--){
		temp=temp->next;
	}
	//insert at end,Make sure you are taking tail and head by reference if you want to update them
	if(temp->next==NULL){
		insertAtTail(tail,dt);
		return;
	}
	n1->next=temp->next;
	temp->next=n1;

}
void deleteNode(Node* &head,int pos/*Node* &tail*/){
	if(pos==1){
		Node* temp=head;
		head=head->next;
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
		//if(temp->next==NULL)	tail=tempprev;
		tempprev->next=temp->next;
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
	insertAtPosition(head,tail,1,100);
	print(head);
	insertAtPosition(head,tail,7,110);
	print(head);
	insertAtTail(tail,55);
	print(head);
	deleteNode(head,8);
	print(head);

}
