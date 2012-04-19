#ifndef NODE_
#define NODE_

using namespace std;

#include <iostream>
#include <list>

class node
{
    public:

        bool connected(int Vertex)
        {

            for (std::list<node>::const_iterator iterator = Neighbours.begin(),
                    end = Neighbours.end(); iterator != end; ++iterator)
            {
                if (*iterator==Vertex)
                {
                    return true;
                }
            }

            return false;
        }

        void printNeighbours()
        {
            for (std::list<int>::const_iterator iterator = Neighbours.begin(),
                    end = Neighbours.end(); iterator != end; ++iterator)
            {
                cout << *iterator;
            }
            return;
        }

        int getStubs()
        {
            return Stubs;
        }

        void addEdge(node edge)
        {
            Neighbours.push_front(edge);
            return;
        }
        void decStubs()
        {
            Stubs = Stubs - 1;
            return;
        }

        void setStubs(int num)
        {
            Stubs = num;
            return;
        }

    private:
        int Stubs;
        list<node> Neighbours;
};
#endif
