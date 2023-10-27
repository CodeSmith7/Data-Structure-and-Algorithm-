#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
struct node{
  int data;
  struct node* link;
};


void insertatHead(struct node* &head,struct node* &tail,int data){
  if (head == NULL){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->link = NULL;
    p->data = data;
    head = p;
    tail = p;
    return ;
  }
  struct node* p = (struct node*)malloc(sizeof(struct node));
  p->link = head ;
  p->data = data;
  head = p;
}
void insertatTail(struct node* &head,struct node* &tail, int data){
  if (head == NULL){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->link = NULL;
    p->data = data;
    head = p;
    tail = p;
    return ;
  }
  struct node* p = (struct node*)malloc(sizeof(struct node));
  p->data = data;
  p->link =NULL;
  tail->link = p;
  tail = p;
}
int getLength(struct node* head){
  struct node* temp = head;
  int len = 0;

   while (temp != NULL ){
     temp = temp -> link;
     len++;
   }
   return len;
}


void insertatposition(int pos,struct node* &head,struct node* &tail,int data){
   if(head == NULL){
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->link = NULL;
    p->data = data;
    head = p;
    tail = p;
    return ;
   }
   if(pos <= 1){
     insertatHead(head,tail,data);
     return;
   }
   //calculating length of linked list
   int len =  getLength(head);
   if(pos >= len){
    insertatTail(head,tail,data);
    return;
   }

   struct node* prev = head;
   int i =1;

  while (i<pos){
    prev = prev -> link;
    i++;
  }
  struct node* curr = prev -> link;
  
  struct node* p = (struct node*)malloc(sizeof(struct node));
  p->data = data;
  prev -> link = p;
  p -> link = curr;
}
//isme problem hain


void deleteNode(int pos,struct node* &head,struct node* &tail){
  if (head == NULL){
     printf("LINKED list is empty");
     return;
     }
  //deleting first node
  if (pos == 1){
    struct node* temp = head ;
    head = temp -> link;
    temp -> link = NULL;//important step 
    //free (temp);
    delete temp;
    return;
  } 
  int len = getLength(head);
  //last element 
  if(pos >= len){
    //bounded position to last element 

        if(pos != len){
           pos = len;
         }
     struct node* temp = head ;
      int i =1;
     while (i < pos - 1 ){
        temp = temp ->link;
           i++;
       }
     temp ->link = NULL;
     struct node* del = tail;
     tail = temp;
     //free(del);
     delete del;
     return;
   }

//delete from the midddle 

  int i =1 ;
  struct node* prev = head;
  while(i < pos -1){
   prev = prev -> link; 
   i++;
  }
 struct node* curr = prev -> link;
 prev -> link = curr -> link;
 curr->link = NULL;
 delete curr;
}

void printLL (struct node* head){
  struct node* temp = head;
  while(temp != NULL ){
    printf("%d\t",temp -> data);
    temp = temp -> link;
  }
}




void  sortList(struct node* head){
  struct node* i = head;
  struct node* j = head;
  while (i->link  != NULL){
    j  = i->link;
    while(j != NULL){
      if(i->data > j-> data){
        int temp = i->data;
        i->data  = j->data;
        j->data  = temp;
      }
      j=j->link;
    }
    i=i->link;
   }
   
}

void removeDuplicate(struct node* &head){
  //no node
  if (head == NULL){
    cout<< "ll is empty";
    return ;
  }
  //only one node
  if (head->link == NULL){
    cout <<"only one node";
    return;
  }

  struct node* curr = head;
  while(curr!= NULL){
    if ((curr->link != NULL) && (curr-> data == curr ->link ->data)){
      struct node* temp = curr->link;
      curr-> link =curr->link->link;
      //delete the node 
      temp -> link = NULL;
      free(temp);

    }else{
      curr = curr->link;
    }
  }
}

int main() {
 
 struct node* head = NULL;
 struct node* tail = NULL;
 
 insertatHead(head,tail,4);
 insertatHead(head,tail,4);
 insertatHead(head,tail,3);
 insertatHead(head,tail,2);
 insertatHead(head,tail,2);
 insertatHead(head,tail,1);
 insertatTail(head,tail,8);
 insertatTail(head,tail,8);
 insertatTail(head,tail,8);
 insertatTail(head,tail,2008);
 insertatTail(head,tail,2008);
 cout<< endl;


 printLL(head);

 cout << endl;

 removeDuplicate(head);
 cout<<endl;
  printLL(head);

  return 0;
}