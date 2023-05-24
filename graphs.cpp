#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{

public:
    int label;
    vector<int> neighbours;
    // A node will 2 entities
    // 1. data type int called label
    // 2. a int type list called neighbours
};

struct Graph
{
    int n = 8;
    Node *nodes = new Node[n];

    void intializenodes()
    {
        // iterate through the nodes and assign labels
        for (int i = 0; i < n; i++)
        {
            nodes[i].label = i + 1;
        }
    }

    Node *getNode(int label)
    {
        for (int i = 0; i < n; i++)
        {
            if (nodes[i].label == label)
                return &nodes[i];
        }

        return nullptr;
    }

    void addedge(int u, int v)
    {
        // select node u and push v into u's neighbour
        
        getNode(u)->neighbours.push_back(v);

        // select node v and push u into v's neighbour
        getNode(v)->neighbours.push_back(u);
    }

    void print()
    {
        // lets iterate through each node and print its neighbours
        for (int i = 0; i < n; i++)
        {
            cout << "Node : " << nodes[i].label << ", Neighbours => ";
            auto neighbours = nodes[i].neighbours;

            for (auto i = neighbours.begin();i != neighbours.end(); i++)
            {
                cout << *i;

                if(i != neighbours.end() - 1) cout << ",";
            }

            cout << endl;
        }
    }
};

int main()
{
    

    Graph *g = new Graph;
    g->intializenodes();

    // add edges for the graphs here.
    g->addedge(1,2);
    g->addedge(1,3);
    g->addedge(1,5);
    g->addedge(1,4);
    g->addedge(2,3);
    g->addedge(2,6);
    g->addedge(4,6);
    g->addedge(4,8);
    g->addedge(4,7);
    g->addedge(5,6);
    g->addedge(5,8);
    g->addedge(5,7);
    
    // print the graph adjaceny list
    g->print();
}