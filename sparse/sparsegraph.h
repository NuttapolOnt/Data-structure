#ifndef __SPARSE_GRAPH_H__
#define __SPARSE_GRAPH_H__

// Your code here
#include<unordered_set>
#include<vector>

using namespace std;


class SparseGraph{
public:
    SparseGraph() {
        // Your code here
        mSize = 3;
        mData = std::vector<std::unordered_set<int>>(3);
    }

    SparseGraph(int n_in) {
        // Your code here
        mSize = n_in;
        mData = std::vector<std::unordered_set<int>>(n_in);
    }

    SparseGraph(const SparseGraph& G) {
        // Your code here
        mSize = G.mSize;
        std::vector<std::unordered_set<int>> nData(G.mData);
        mData = nData;
    }

    void AddEdge(int a, int b) {
        mData[a].insert(b);
    }

    void RemoveEdge(int a, int b) {
        // Your code here
        mData[a].erase(b);
    }

    bool DoesEdgeExist(int a, int b) const {
        // Your code here
        if(a == b){
            return true;
        }
        if(mSize == 0){
            return false;
        }
        auto it = mData[a].find(b);
        return (it != mData[a].end());
    }

    SparseGraph Transpose() const {
        // Your code here
        SparseGraph ans(mSize);
        for(int i = 0; i < mSize; i++){
            for(int x : mData[i]){
                ans.mData[x].insert(i);
            }
        }
        return ans;
    }

protected:
    // Your code here
    int mSize;
    std::vector<std::unordered_set<int>> mData;
};
#endif // __SPARSE_GRAPH_H__


