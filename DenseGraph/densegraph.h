#ifndef __DENSE_GRAPH_H__
#define __DENSE_GRAPH_H__

// Your code here
#include <vector>
using namespace std;
class DenseGraph{
public:
    DenseGraph() {
        // Your code here
        n = 3;
        vector<bool> tmp(3);
        for(int i = 0; i < n; i++){
            edge.push_back(tmp);
        }
    }

    DenseGraph(int n_in) {
        // Your code here
        n = n_in;
        vector<bool> tmp(n_in);
        for(int i = 0; i < n; i++){
            edge.push_back(tmp);
        }
    }

    DenseGraph(const DenseGraph& G) {
        // Your code here
        vector<vector<bool>> tmp(G.edge);
        edge = tmp;
        n = G.n;
    }

    void AddEdge(int a, int b) {
        // Your code here
        edge[a][b] = true;
    }

    void RemoveEdge(int a, int b) {
        // Your code here
        edge[a][b] = false;
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here
        return edge[a][b];
    }

    DenseGraph Transpose() const {
        // Your code here
        DenseGraph tmp(*this);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                tmp.edge[j][i] = edge[i][j];
            }
        }
        return tmp;
    }

protected:
    int n;
    // Your code here
    vector<vector<bool>> edge;
};
#endif // __DENSE_GRAPH_H__
