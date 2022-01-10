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

   inline void reverse()
   {
      if(!head || !head->next)
      {
         return;
      }
      
      node_t* prev = nullptr; 
      node_t* next = nullptr;
      node_t* curr = head;

      while(curr)
      {
         next = curr->next;
         curr->next = prev; 
         prev = curr;
         curr = next; 
      }
      head = prev;
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
   ll.reverse();
   std::cout << "reversed linked list: "<< ll;
   return 0;
}