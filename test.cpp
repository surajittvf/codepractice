#include <iostream>
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

  Node* set_parent(Node* f_node)
  {
     f_node->next = this;
     return f_node;
  }
  Node* set_child(Node* f_node)
  {
     this->next = f_node;
     return f_node;
  }
};


void rotate_left(Node*& f_node, int k)
{
   Node* old_head = f_node;   
   Node* new_head;
   
   Node* curr = old_head;   
   int cnt=0;
   while(curr->next)
   {
      curr = curr->next;
      cnt++;
      if (cnt==k)
      { 
         new_head = curr;
      }      
   }
   curr->next = old_head;   
   
   cnt = k;
   while(cnt)
   {
      curr = curr->next;
      cnt--;
   }
   curr->next = nullptr;   
   f_node = new_head;
}


void rotate_right(Node* f_node, int k)
{
   Node* old_head = f_node;   
   Node* new_head;
   
   Node* curr = old_head;   
   int cnt=0;
   while(curr->next)
   {
      curr = curr->next;
      cnt++;
      if (cnt==k)
      { 
         new_head = curr;
      }      
   }
   curr->next = old_head;   
   
   cnt = k;
   while(cnt)
   {
      curr = curr->next;
      cnt--;
   }
   curr->next = nullptr;   
   f_node = new_head;
}


void print(Node* f_node)
{
   Node* tmp = f_node;
   std::string conn = "->";   
   while(tmp)
   {
      if (nullptr == tmp->next)
      {
         conn = "";
      }
      std::cout << tmp->data << conn; 
      tmp = tmp->next;
   }
   std::cout << std::endl;
}


int main()
{
   Node* tmp = new Node(60);
   int k;
   std::cin >> k;
   for(int i=50; i>=10; i=i-10)
   {
      tmp = tmp->set_parent(new Node(i));
   }
   print(tmp);
   rotate_left(tmp, k);
   print(tmp);
   return 0;
}