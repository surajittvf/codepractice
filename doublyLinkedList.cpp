#include <bits/stdc++.h>
using namespace std;

struct DoubleEndedNode 
{
   int data;
   DoubleEndedNode* prev; 
   DoubleEndedNode* next;

   DoubleEndedNode (int f_data) : 
      data(f_data), 
      prev(nullptr),
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
         head->next = head; 
         head->prev = head;
         return;
      }
      node_t* last = head->prev; 
      tmp->next = head;
      head->prev = tmp;
      tmp->prev = last; 
      last->next = tmp;
      head = tmp;
   }

   inline void reverse()
   {
      if(!head || (head == head->next))
      {
         return;
      }
      
      node_t* prev = nullptr;
      node_t* next = nullptr;
      node_t* curr = head;
      const node_t* const begin = head;


      do
      {
         next = curr->next; 
         prev = curr->prev;
         curr->next = prev;
         curr->prev = next;
         curr = next;         
      }while(curr != begin);
      head = curr->next;
   }

   friend ostream& operator<<(ostream& os, const List<node_t>& ll)
   {
      const node_t* const head = ll.head;
      node_t* curr = ll.head; 
      std::string conn = "->";
      do
      {
         os << curr->data; 
         if (curr->next == head)
         {
            conn = "\n";
         }
         os << conn; 
         curr = curr->next; 
      }while(curr != head);
      return os; 
   }
};

typedef List<DoubleEndedNode> DoublyLinkedList;


int main()
{
   DoublyLinkedList dll;
   int i=10;
   while(i>0)
   {
      dll.push_front(i--);
   }
   std::cout << "doubly linked list: "<< dll;
   dll.reverse();
   std::cout << "reversed doubly linked list: "<< dll;
   return 0;
}