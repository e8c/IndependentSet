/**

   NOTE: it is undirected so each connection goes two ways

   create separate function to build graphs of varying sizes?
 */



#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Each individual AdjList, a vector of AdjList would be our graph
class Vertex {

public:

int vertex;//vertex number
vector<int> neighbors; //its neighbors
bool independent; //if it's independent

//Construction of a vertex
Vertex(int num);

};

//Constructor
//Each node has a vertex, a neigbor array, and a bool saying if it's independent
Vertex::Vertex(int num) : vertex(num),neighbors(0), independent(true){
}

//Min Heap's Comp
class pairComp {
public:
bool operator()(Vertex lhs, Vertex rhs) const {
        return lhs.neighbors.size() < rhs.neighbors.size();
}
};



vector<int> independentSet(vector<Vertex> inputGraph) {

        vector<int> indepSet;

        //dclaring priority queue
        priority_queue<Vertex, vector<Vertex>, pairComp> pq;

        //push every pair from inputGraph into pq
        for(int i = 0; i < inputGraph.size(); i++) {
                Vertex &v = inputGraph[i];
                pq.push(v);
        }

        //while pq is not empty, we keep popping
        while(pq.size() > 0) {
                //explore the node with lowest degree
                Vertex toExplore = pq.top();
                pq.pop();

                //if toExplore is true, set neighbors to false
                if (inputGraph[toExplore.vertex].independent == true) {
                        for(int index = 0; index < toExplore.neighbors.size(); index++) {

                                //cerr << "setting " << inputGraph[toExplore.neighbors[index]].vertex << endl;
                                inputGraph[toExplore.neighbors[index]].independent= false;

                                //  inputGraph[i].independent = false;
                        }
                        //add it to the return list
                        indepSet.push_back(toExplore.vertex);
                }
        }

        return indepSet;
}

// build graph with numNodes nodes
vector <Vertex> buildGraph (int numNodes) {
        vector <Vertex> graph;
        double count = 0;
        double max = numNodes * numNodes * .5;

        // fills "graph" with vertices
        for (int i = 0; i < numNodes; i++) {
                graph.push_back(Vertex(i));
        }

        // generate edges; loop indeices are offeset because want to ensure
        // actual fifty percent odds
        for (int j = 0; j < graph.size(); j++) {
                // seeds the random obj

                // performs that actual adds
                for (int k = (j + 1); k < graph.size(); k++) {
                        if (rand() % 2) {
                                count++;
                                // essentially perform a double add bc it's undirected
                                graph.at(j).neighbors.push_back(k);
                                graph.at(k).neighbors.push_back(j);

                        }

                }

        }

        double ratio = count / max;
        cerr << count << " nodes were added out of a possible " << max << " nodes. this is " << ratio << endl;

        return graph;
}

void printGraph (vector<Vertex> graph) {
        for (int i = 0; i < graph.size(); i++) {
                cerr << i << ": ";

                for (int j = 0; j < graph.at(i).neighbors.size(); j++) {
                        cerr << graph.at(i).neighbors.at(j) << " ";
                }

                cerr << endl;
        }

}

vector<int> independentSetBT(vector<Vertex> inputGraph){
}

if(inputGraph.size() == 0) return inputGraph;
vector<Vertex> copy1;
vector<Vertex> copy2;



for(int i = 0; i < inputGraph.size(); i++) {
        copy1[i] = inputGraph[i];
        copy2[i] = inputGraph[i];
}



vector<Vertex> S_1;
vector<Vertex> S_2;

Vertex v = inputGraph[0];

vector<int> neighb = v.neighbors;

S_1.insert(v);

copy1.remove(v);
 for(int i = 0; i < nieghb.size(); i++){
    for(int j = 0; j < copy1.size(); j++){
      if(copy[i].vertex == neib[i]){
        copy1.remove(neighb[i]);
        j = copy1.size();
      }
    }
  }

S_1.insert(independentSet(copy1));

if(neighb.size() == 0 || neighb.size() == 1) {
        return S_1;
}
copy2.remove(v);

S_2.insert(independentSet(copy2));

if(S_2.size() > S_1.size()) {
        return S_2;
} else {
        return S_1;
}
}

int main() {
        srand(time(NULL));
        long num = 128;
        for(int i = 0; i < 10; i++) {
                vector<Vertex> graph = buildGraph(num*1.5);
                cerr << "num is" << num*1.5 << endl;



                //printGraph(graph);
                //find the independentSet of this grpah
                vector<int> returned = independentSetBT(graph);

                cout << "{";
                for(int i = 0; i < returned.size(); i++) {
                        cout << returned[i] << " ";
                }
                cout << "}" << endl;

                cout << "The size of the independent set is " << returned.size() << "." <<endl;
                num = num * 2;
        }

}
