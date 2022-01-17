#include<bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;    
    int minDistaceToLastNode;

    Node(int d, int m) : data(d), minDistaceToLastNode(m){}

    static Node* create(int d, int m=INT_MAX)
    {
        return new Node(d, m);
    }
};

template<typename DataType>
class Graph
{
public:
    typedef DataType ValueType ;
    typedef std::pair<DataType*, int> AdjType; 
    typedef std::list<AdjType> AllAdjType; 
    typedef std::vector<int> RestrictedPathType;
    typedef std::vector<RestrictedPathType> AllRestrictedPathType;

private:
    int N;
    AllAdjType* adj;
    bool* visited;

    void initMinDistFromNode(int idx, int parentsMinDistToLastNode=0)
    {
        AllAdjType::iterator it = adj[idx].begin();
        AllAdjType::const_iterator itEnd = adj[idx].end();
        for(; it!=itEnd; ++it)
        {
            int currMinDist = it->second + parentsMinDistToLastNode;
            if(currMinDist < it->first->minDistaceToLastNode )
            {
                it->first->minDistaceToLastNode = currMinDist;
                initMinDistFromNode(it->first->data-1, it->first->minDistaceToLastNode);
            }            
        }
    }

    void printRestrictedPathsUtils(int idx, int minDist, int end, int* restrictedPath, int restrictedPathIdx)
    {

        // Mark the current node and store it in path[]
        visited[idx-1] = true;
        restrictedPath[restrictedPathIdx] = idx;
        restrictedPathIdx++;

        if (idx == end)
        {
            std::cout << restrictedPath[0];
            for (int i = 1; i < restrictedPathIdx; i++)
            {                
                std::cout << "-->" << restrictedPath[i];
            }
            cout << endl;
        }
        else
        {
            AllAdjType::iterator it = adj[idx-1].begin();
            AllAdjType::const_iterator itEnd = adj[idx-1].end();
            for(; it!=itEnd; ++it)
            {
                if (!visited[it->first->data-1] && it->first->minDistaceToLastNode < minDist)
                    printRestrictedPathsUtils(it->first->data, it->first->minDistaceToLastNode, end, restrictedPath, restrictedPathIdx);
            }
        }
        restrictedPathIdx--;
        visited[idx-1] = false;        
    }

public:
    Graph(int NodeCount)
    {
        N = NodeCount;   
        adj = new AllAdjType[N];
        
    }

    inline AllAdjType& operator[](int idx)
    {
        return adj[idx];
    }

    inline size_t size() const
    {
        return static_cast<std::size_t>(N);
    } 

    inline void addEdge(DataType* u, DataType* v, int weight)
    {
        adj[u->data-1].push_back(std::make_pair(v, weight));
        adj[v->data-1].push_back(std::make_pair(u, weight));
    }

    inline void initMinDistFromLastNode()
    {
        initMinDistFromNode(N-1);
    }

    void printRestrictedPaths(DataType* n1, DataType* n2)
    {                
        int start = n1->data;
        int end = n2->data;
        int startMinDist = n1->minDistaceToLastNode;
        visited = new bool[N];
        for(int i=0; i<N; ++i)
        {
            visited[i] = false;        
        }
        int* restrictedPath = new int[N];                
        int restrictedPathIdx = 0;
        restrictedPath[restrictedPathIdx] = start;
        visited[start-1] = true;
        printRestrictedPathsUtils(start, startMinDist, end, restrictedPath, restrictedPathIdx);
    }
};

typedef Graph<Node> Network;


int main()
{
    int N = 5;  
    Node* n1 = Node::create(1);
    Node* n2 = Node::create(2);
    Node* n3 = Node::create(3);
    Node* n4 = Node::create(4);
    Node* n5 = Node::create(5, 0);

    Network g(N);    
    g.addEdge(n1, n2, 3);
    g.addEdge(n1, n3, 3);
    g.addEdge(n1, n4, 2);
    g.addEdge(n2, n3, 1);
    g.addEdge(n2, n5, 2);
    g.addEdge(n4, n5, 10);
    g.addEdge(n3, n5, 1);

    int* visited = new int[N];
    int* presentInStack = new int[N];

    g.initMinDistFromLastNode();

    int start = n1->data;
    int startMinDist = n1->minDistaceToLastNode;
    int end = n5->data;
    
    g.printRestrictedPaths(n1, n5);

    delete n1;
    delete n2;
    delete n3;
    delete n4;
    delete n5;

    return 0;
}