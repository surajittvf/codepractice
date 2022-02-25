#include<iostream>
#include<list>
#include<vector>
#include<unordered_map>

using namespace std;

struct Node
{
    int val;
    int minDistance;

    Node(int f_val)
    {
        val = f_val;
        minDistance = INT_MAX;
    }
};


template <typename NodeType>
class Graph 
{
public:
    typedef std::list<NodeType*> adjList;
    typedef std::unordered_map<int, NodeType*> Idx2NodePtrMap; 

private:
    int N;
    adjList* adj;
    Idx2NodePtrMap idxPtrMap; 
    
    void doDjikstraDFSTraversal(int nodeIdx=0, int minDistance=0)
    {
        minDistance++;
        typename adjList::iterator it = adj[nodeIdx].begin();
        typename adjList::iterator itEnd = adj[nodeIdx].end();
        for (;it!=itEnd; ++it)
        {
            (*it)->minDistance = min((*it)->minDistance, minDistance);
            doDjikstraDFSTraversal((*it)->val, minDistance);
        }
    }

    bool hasRouteToLastElem()
    {
        if (idxPtrMap.find(N-1) == idxPtrMap.end())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    
public:
    Graph(int numOfVertices): 
        N(numOfVertices),
        adj(new adjList[N])   
    {}

    ~Graph()
    {
        for(int i=0; i<N; ++i)
        {
            typename Idx2NodePtrMap::iterator it = idxPtrMap.begin();
            typename Idx2NodePtrMap::iterator itEnd = idxPtrMap.end();
            for(; it!=itEnd; ++it)
            {
                if(it->second)
                {
                    delete it->second;
                    it->second = nullptr;
                }
            }
            adj[i].clear();
        }
        delete[] adj;
    }
    
    void connect(int a, int b)
    {
        if (!idxPtrMap[a])
        {
            idxPtrMap[a] = new NodeType(a);
        }
        if (!idxPtrMap[b])
        {
            idxPtrMap[b] = new NodeType(b);
        }
        adj[a].push_back(idxPtrMap[b]);
    }

    int minJumpsRequired()
    { 
        if(hasRouteToLastElem())
        {
            doDjikstraDFSTraversal();
            return idxPtrMap[N-1]->minDistance;
        }
        else
        {
            return INT_MAX;
        }
    }

    
};

typedef Graph<Node> IndexGraph;


IndexGraph array2IndexGraph(std::vector<int>& arr)
{
    IndexGraph g(arr.size());
    for(int i=0; i<arr.size(); ++i)
    {
        for(int j=1; j<=arr[i] && (i+j)<arr.size(); ++j)
        {
            g.connect(i, i+j);
        }
    }
    return g;
}

int main()
{
    std::vector<int> arr = {1, 3, 1, 1, 7, 9};
    IndexGraph g = array2IndexGraph(arr);
    std::cout << "minimum jumps required: " << g.minJumpsRequired() << std::endl;

    return 0;
}