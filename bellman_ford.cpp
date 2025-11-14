#include <iostream>
#include <map>
using namespace std;

const int INF = 1e9;

template <typename T>
class bellmanFord{
    map<T,map<T,int>> adjgraph;
    public:
    void addEdge(T src, T dest, int wt){
        adjgraph[src][dest]=wt;
    }
    void smallestPathWeight(T src){
        map<T, int> leastDist;
        for (auto &i : adjgraph) {
            leastDist[i.first] = INF;
            for(auto &j : i.second){
                leastDist[j.first] =INF;
            }
        }
        int V = adjgraph.size();
        leastDist[src] = 0;
        for(int i = 0; i<=V;i++){
            bool pathUpdated = false;
            for(auto &paths : adjgraph){
                for(auto &edge: paths.second){
                    T from = paths.first;
                    T to = edge.first;
                    int wt = edge.second;
                    if(leastDist[from]!=INF && leastDist[from]+wt<leastDist[to]){
                        if(i==V){
                            cout<<"Negative Cycle is present"<<endl;
                            return;
                        }
                        leastDist[to] = leastDist[from]+wt;
                        pathUpdated = true;
                    }
                }
            }
            if(!pathUpdated){
                break;
            }
        }
        for(auto &weights : leastDist){
            cout<<"Shortest path to "<<weights.first<<" is "<<weights.second<<endl;
        }
    }
};

int main() {
    bellmanFord<string> g;

    // Simple paths
    g.addEdge("A", "B", 5);
    g.addEdge("A", "C", 10);
    g.addEdge("B", "C", 3);

    // Extra nodes
    g.addEdge("C", "D", -2);
    g.addEdge("D", "E", 1);
    g.addEdge("X", "Y", 7);  // separate component
    g.addEdge("E", "F", 2);

    cout << "===== Test 1: Normal graph =====" << endl;
    g.smallestPathWeight("A");

    // Negative edges but no cycle
    bellmanFord<string> g2;
    g2.addEdge("A", "B", 4);
    g2.addEdge("B", "C", -10);
    g2.addEdge("C", "D", 3);

    cout << "\n===== Test 2: Includes negative edges but no cycle =====" << endl;
    g2.smallestPathWeight("A");

    // Negative cycle
    bellmanFord<string> g3;
    g3.addEdge("A", "B", 1);
    g3.addEdge("B", "C", -2);
    g3.addEdge("C", "A", -1);  // cycle sum = -2

    cout << "\n===== Test 3: Negative cycle detection =====" << endl;
    g3.smallestPathWeight("A");

    return 0;
}