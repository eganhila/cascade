#include <iostream>
#include <queue>
#include <vector>
#include "cascade.node.h"
using namespace std;

void setDistribution(node* arrayNodes, int* distribution);
void matchEdges(node* arrayNodes, vector<int> & allEdges);
void makeDistribution(int* distribution);
void makeEdges(int* distribution, vector<int> & allEdges);

const int TotalN= 20;

int main ()
{
    node nodes [TotalN];
    int distrib [TotalN];
    vector<int> edges;

    makeDistribution(distrib);
    setDistribution(nodes,distrib);
    
    makeEdges(distrib,edges);
    matchEdges(nodes,edges);


    for (int i=0; i<TotalN; i++)
    {
        cout << i << ": " << nodes[i].getStubs() << endl;
    }
}

void matchEdges(node* arrayNodes, vector<int> & allEdges)
{
    srand(time(NULL));
    node nA,nB;
    int vA, vB, A, B;
    int size = allEdges.size();

    for (int i=0; i <= size*5; i++)
    {
        A = rand() % size;
        B = rand() % size;

        vA = allEdges[A];
        vB = allEdges[B];

        if(vA==TotalN+1){ continue;}
        if(vB==TotalN+1){ continue;}
        
        nA = arrayNodes[vA];
        nB = arrayNodes[vB];

        nA.addEdge(nB);
        nB.addEdge(nB);

        allEdges[A] = TotalN+1;
        allEdges[B] = TotalN+1;
    }
    
}

void makeEdges(int * distribution, vector<int> & allEdges)
{
    int sum = 0;
    int k = 0;

    for(int i=0; i<TotalN; i++)
    {
        sum += distribution[i];
    }
    allEdges.resize(sum);

    for(int i=0; i<TotalN; i++)
    {
        for(int j=0; j<distribution[i]; j++)
        {
            allEdges[k] = i;
            k++;
        }
    }
}

void setDistribution(node* arrayNodes, int* distribution)
{
    for (int i=0; i<TotalN;i++)
    {
        arrayNodes[i].setStubs(distribution[i]);
    }
    return;
}

void makeDistribution(int* distribution)
{
    for (int i=0; i<TotalN;i++)
    {
        distribution[i] = 2;
    }
    return; 
}
