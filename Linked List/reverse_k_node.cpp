#include <iostream>
using namespace std;
class Node{
 public:
     int data;
     Node* next;
     Node(int data){
       this -> data = data;
       this -> next = NULL;
     }


};
  
  void print(Node* &head){
    Node* temp  = head ;
    while(temp != NULL){
      cout<< temp -> data <<" ";
      temp = temp -> next;
    }
  }



int getLength(Node* &head){
  Node* temp = head;
  int len = 0;
  while (temp){
    len++;
    temp = temp -> next;

  }
  return len;

}
Node* reverseKnodes(Node* &head ,int k){
  if (head == NULL){
    cout<< "Linked list is empty" <<endl;
    return head;
  }
  if (k > getLength(head) ){
    //k claue become greater than length of linked list 
        return head;
  }

   //step 1: reverse first k nodes 
    
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr-> next;
    int count = 0;
    while (count < k){
      forward = curr->next;
      curr-> next = prev;
      prev = curr;
      curr = forward;
      count++;
    }

    //step 2: recursive calls
      if (forward != NULL){
        head -> next = reverseKnodes(forward,k);
      }
    // step 3: return head of modified linked list 
      
      return prev;

}
int main() {
  Node* head =new Node(10);
  
  Node* s =new Node(3);
  Node* t =new Node(2);
  Node* f =new Node(1);
  Node* fi =new Node(5);
  Node* si =new Node(4);
  Node* se =new Node(70);
  Node* ei =new Node(80);
   Node* ni =new Node(90);
  head -> next = s;
   s-> next =t;
  t-> next = f;
  f->next = fi;
  fi -> next = si;
  si -> next = NULL;
   se->next = ei;
  ei-> next = ni;

  
  print (head);

  cout<<" reversing nodes in group as k nodes " << endl;

  Node* newHead = reverseKnodes(head ,3);

  print(head );


  


    return 0;
}