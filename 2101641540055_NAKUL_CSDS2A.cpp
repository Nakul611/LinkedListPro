#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
	Node(int data){
	this->data=data;
	this->next=NULL;
	}
};
Node* insertAtHead(Node* &head){
	int data;
	cout<<"Enter the data: ";
	cin>>data;
	Node* temp = new Node(data);
	temp->next = head;
	head = temp;
	return head;
}

Node* insertAtTail(Node* head){
	int data;
	cout<<"Enter the data: ";
	cin>>data;
	Node* temp = new Node(data);
	head -> next = temp;
	return temp;
}

void insertAtMid(Node* head){
	int data;
	cout<<"Enter the data: ";
	cin>>data;
	Node* temp = new Node(data);
	int pos;
	cout<<"At which poition you want to insert new node? : ";
	cin>>pos;
	int curr = 1;
	Node* s = head;
	Node* prev;
	while(curr != pos){
		prev = s;
		s = s->next;
		curr++;
	}
	prev->next = temp;
	temp->next = s;	
}

Node* deleteAtHead(Node* &head){
	Node* temp = head;
	head = head->next;
	free(temp);
	return head; 
}

void deleteAtTail(Node* head){
	Node* temp = head;
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	temp ->next = NULL;
}

Node* deleteAtMid(Node* &head){
	Node* s = head;
	Node* prev;
	int pos;
	cout<<"At which poition you want to delete";
	cin>>pos;
	if(pos == 1){
		head = deleteAtHead(head);
		return head;
	}
	int curr = 1;
	while(curr != pos){
		prev = s;
		s=s->next;
		curr++;
	}
	prev->next = s->next;
	return head;	
}

void display(Node* head){
	Node* temp = head;
	while(temp != NULL){
		cout<< temp->data<<" ";
		temp = temp->next;
	}
}

Node* reverse(Node* head){
	if(head==NULL || head->next==NULL)
		return head;
	Node* first = head->next;
	Node* new_head = reverse(head->next);
	first->next = head;
	head->next= NULL;
	return new_head;
}

void MidNode(Node* head){
	Node* slow = head;
	Node* fast = head;
	while(fast != NULL && fast->next != NULL && ){
		slow = slow->next;
		fast = fast->next->next;
	}
	cout<<"The mid node is : "<<prev->data<<endl;
}

void nthNode(Node* head){
	int n;
	cout<<"Which node to print from the end: ";
	cin>>n;
	Node* temp = head;
	Node* s = head;
	int c=n;
	while(c>0){
		temp = temp->next;
		c--;
	}
	while(temp!=NULL){
		s=s->next;
		temp=temp->next;
	}
	cout<<"The nth node from the end is: "<<s->data<<endl;
}

Node* merge(Node* head, Node* head1){
    Node* ans = NULL;
    if (head == NULL)
        return head1;
    else if (head1 == NULL)
        return head;
    if (head->data <= head1->data){
        ans = head;
        ans->next = merge(head->next, head1);
    }
    else{
        ans = head1;
        ans->next = merge(head,head1->next);
    }
    return ans;
}

void checkPallindrome(Node* head){
    Node* slow = head;
    stack<int> s;
    while (slow != NULL) {
        s.push(slow->data);
        slow = slow->ptr;
    }
    while (head != NULL) {
        int i = s.top();
        s.pop();
        if (head->data != i) {
            cout<<"No";
        }
        head = head->ptr;
    }
    cout<<"Yes";
}

Node* rotate(Node* head, int k){
    Node* last = head;
    Node* temp = head;
    if (head == NULL || k == 0) {
        return head;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    while (k) {
        head = head->next;
        temp->next = NULL;
        last->next = temp;
        last = temp;
        temp = head;
        k--;
    }
    return head;
}

int main(){
	int c=10;
	int data;
	cout<<"Enter the data: ";
	cin>>data;			
	Node* node1 = new Node(data);
	Node* head = node1;
	while(c!=0){
		head = insertAtHead(head);
		c--;
	}
	display(head);
}
