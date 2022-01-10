#include <bits/stdc++.h>
using namespace std;

struct Node 
{
   int data;
   Node* next;

   Node (int f_data) : 
   data(f_data), 
   next(nullptr)
   {}
};

template<typename node_t>
class List
{
private:
   node_t* head;

   inline void rotate(node_t*& h, node_t*& t, int l, int r)
   {
      node_t* curr = h;      
      node_t* blockHead1 = curr;
      node_t* blockTail1 = nullptr;
      node_t* blockHead2 = nullptr;
      node_t* blockTail2 = nullptr;
      int i = ((r+l)%l+l)%l;
      while(curr && i>0)
      {
         curr = curr->next;
         if(--i == 1)
         {
            blockTail1 = curr;
         };
      }
      blockHead2 = curr;
      while(curr != t)
      {         
         curr = curr->next;
         blockTail2 = curr;
      }

      blockTail2->next = blockHead1;      
      h = blockHead2;
      t = blockTail1;
   }

public:
   List(): head(nullptr){}
   
   inline void push_front(int data)
   {
      node_t* tmp = new node_t(data);
       if(!head)
      {
         head = tmp;
         return;
      }
      tmp->next = head; 
      head = tmp;
   }

   inline void blockRotation(int m, int n, int d)
   {
      node_t* curr = head;
      node_t* blockParent = nullptr;
      node_t* blockChild = nullptr;
      while(curr && curr->data != m)
      {         
         blockParent = curr;
         curr = curr->next; 
      }
      node_t* blockHead = curr;
      if (!blockHead)
      {
         return;
      }
      int blockSize=1;
      while(curr && curr->data != n)
      {         
         curr = curr->next; 
         ++blockSize;
      }
      node_t* blockTail = curr;
      blockChild = blockTail->next;
      
      if(!blockTail)
      {
         return;
      }      
      
      rotate(blockHead, blockTail, blockSize, d);
      blockParent->next = blockHead;
      blockTail->next = blockChild;
   }

   friend ostream& operator<<(ostream& os, const List<node_t>& ll)
   {
      node_t* curr = ll.head; 
      std::string connSym = "->";
      while(curr)
      {
         if(!curr->next)
         {
            connSym = "\n";
         }
         os << curr->data << connSym; 
         curr = curr->next; 
      }
      return os; 
   }
};

typedef List<Node> LinkedList;


int main()
{
   LinkedList ll;
   int i=10;
   while(i>0)
   {
      ll.push_front(i--);
   }
   std::cout << "linked list: "<< ll;
   ll.blockRotation(3, 8, -4);
   std::cout << "reversed linked list: "<< ll;
   return 0;
}