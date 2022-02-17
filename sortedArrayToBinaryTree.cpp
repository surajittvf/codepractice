#include <iostream>
#include <vector>
using namespace std;

typedef struct Node
{
    int val;
    Node* left; 
    Node* right;
    
    Node(int f_val) : 
        val(f_val), 
        left(nullptr),
        right(nullptr)
    {}
}Node;

Node* createBST(std::vector<int>& arr, int start, int end)
{
    if(start > end)
    {
        return nullptr;
    }
    int mid = (start + end) >> 1;
    Node* root = new Node(arr[mid]);
    root->left = createBST(arr, start, mid-1);
    root->right = createBST(arr, mid+1, end);
    return root;
}

int main()
{
    std::vector<int> arr{1, 2, 3, 4, 5, 6, 7};
    Node* bst = createBST(arr, 0, arr.size()-1);
    return 0;
}