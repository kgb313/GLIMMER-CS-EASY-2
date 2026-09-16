#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node *next;
} Node;

//添加元素部分
Node* CreateNewNode(int n){
    Node *NewNode=(Node*)malloc(sizeof(Node));
    NewNode->data=n;
    NewNode->next=NULL;
    return NewNode;
}

void HeadInsert (Node* head,int n){
    Node* NewNode=CreateNewNode(n);
    NewNode->next=head->next;
    head->next=NewNode;
}//呃呃虽然ai提示我应该写头插但是看了网课已经养成了固定头节点的习惯...
 //而且我问ai它说头节点插入更常用所以我写个头节点插入可以吗QAQ

void TailInsert(Node* head,int n){
    Node* p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    Node* NewNode=CreateNewNode(n);
    p->next=NewNode;
}


//查找元素部分
void PrintList(Node* head){
    Node* p=head->next;
    while(p!=NULL){
        printf("%d",p->data);
        p=p->next;
    }
}

int FindNode(Node *head,int n){
    Node *p=head->next;
    for(int i=1;p!=NULL;i++){
        if(p->data==n){return i;}
        p=p->next;
        }
        return 0;
    }


//删除和更改部分
bool deleteNthNode(Node* head,int n){
    if(n<2){return false;}
    Node *p=head->next;
    Node *q=head;
    for(int i=0;i!=(n-2);i++){
        if(p!=NULL){
        q=q->next;
        p=p->next;
        }
        else{return false;}    
    }
    q->next=p->next;
    free(p);
    p=NULL;
    return true;
}


//反转函数部分(花了好久才想出来的)
void ReverseList(Node* head){
    Node* p=head->next;if(p==NULL){return;}
    Node* q=p->next;
    p->next=NULL;
    while(q!=NULL){
        Node* m=q;
        q=q->next;
        m->next=p;
        p=m;
    }
    head->next=p;
}


int main(){
	Node* head=CreateNewNode(-1);
	return 0;
}
    



    
