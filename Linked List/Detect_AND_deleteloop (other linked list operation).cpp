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

Node*  findMiddleNode(Node* &head){
   
    if (head == NULL){
      cout << "linked List is empty" << endl;
      return head ;
    }
    if( head -> next == NULL){
      //ll have one node only 
      return head ;
    }
  

 Node* fast = head ;
 Node* slow = head;
 while(fast != NULL && slow != NULL){
   fast = fast->next;
   if (fast != NULL){
     fast = fast->next;
     slow = slow-> next;
   }
 }
 return slow;

}

int getLength(Node* &head){
  Node* temp = head;
  int len = 0;
  while (temp !=NULL){
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


 bool checkForLoop(Node* & head){
   if (head == NULL){
     cout<< "ll is empty";
     return false;
   }
   Node* slow = head;
   Node* fast = head;

   while (fast != NULL){
     fast = fast -> next;
     if (fast != NULL){
       fast = fast -> next;
       slow = slow -> next;
     }
     if (fast == slow){
       //loop is present 
       return true;
     }
   
   }
     // fast become NULL
     return false;
 }

 Node*  removeloop(Node* & head){
   if (head == NULL){
     cout<< "ll is empty";
     return head;
   }
   Node* slow = head;
   Node* fast = head;

   while (fast != NULL){
     fast = fast -> next;
     if (fast != NULL){
       fast = fast -> next;
       slow = slow -> next;
     }
     if (fast == slow){
       slow = head ;
       break;
     }
    }
    Node* prev = fast;
     while( fast != slow){
       prev = fast;
       slow = slow -> next;
       fast = fast -> next;
     }
     prev -> next = NULL;
     return slow;
  }
 Node*  startOfLoop(Node* & head){
   if (head == NULL){
     cout<< "ll is empty";
     return head;
   }
   Node* slow = head;
   Node* fast = head;

   while (fast != NULL){
     fast = fast -> next;
     if (fast != NULL){
       fast = fast -> next;
       slow = slow -> next;
     }
     if (fast == slow){
       slow = head ;
       break;
     }
    }
   
     while( fast != slow){
       slow = slow -> next;
       fast = fast -> next;
     }

     return slow;
  }

int main() {
  Node* head =new Node(10);
  
  Node* s =new Node(20);
  Node* t =new Node(30);
  Node* f =new Node(40);
  Node* fi =new Node(50);
  Node* si =new Node(60);
  Node* se =new Node(70);
  Node* ei =new Node(80);
  Node* ni =new Node(90);
  head -> next = s;
  s-> next =t;
  t-> next = f;
  f->next = fi;
  fi -> next = si;
  si -> next = se;
  se->next = ei;
  ei-> next = ni;
  ni->next = f;

  
  
  cout << " whether loop is present " << checkForLoop(head) << endl;
 cout << " starting point of loopis  " << startOfLoop(head)-> data << endl;

  //removeloop(head);
   //cout << " whether loop is present " << checkForLoop(head) << endl;
  //print(head);  
  
    return 0;
}
