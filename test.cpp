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
};

template <typename node_t>
class List
{
private:
    node_t* head;
public:
    List(): 
        head(nullptr)
    {}
   
    inline void push_back(int data)
    {
        node_t* tmp = new node_t(data);
        if(!head)
        {
            head = tmp;
            return;
        }
        node_t* curr = head;
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = tmp;
    }

    inline void push_front(int data)
    {
        node_t* tmp = new node_t(data);
        tmp->next = head;
        head = tmp;
    }

    friend ostream& operator<<(ostream& os, const List<node_t>& list)
    {
        node_t* curr = list.head;
        std::string conn = "->";
        while(curr)
        {
            if(!curr->next)
            {
                conn = "\n";
            }
            os << curr->data << conn;
            curr = curr->next;
        }
        return os;
    }
};

typedef List<Node> linkedList;



int main()
{
    linkedList ll;
    for(int i=1; i<=10; ++i)
    {
       ll.push_back(i);
    }
    std::cout << ll; 
    return 0;
}