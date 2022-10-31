#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include<vector>

class Tree{
    class Node{
        public:
            friend class Tree;
            Node() {data = -1; left = NULL; right = NULL;}
            Node(const int x, Node* left, Node* right) : data(x), left(left), right(right) {}

        protected:
            int data;
            Node* left;
            Node* right;
    };
public:

    Tree() {
        mRoot = NULL;
        mSize = 0;
    }

    ~Tree() {
        clear(mRoot);
    }

    void clear(Node*& r) {
        if (!r) return;
        clear(r->left);
        clear(r->right);
        delete r;
    }

    void insert(int x) {
        insertAt(mRoot, x);
    }
    bool isSameBinaryTree(Tree& t) {
        // Insert your code here
        if(mSize != t.mSize){
            return false;
        }
        std::vector<int> member1;
        std::vector<int> member2;
        get_next(*mRoot,member1);
        get_next(*(t.mRoot),member2);
        for(int i = 0; i < member1.size();i++){
            if(member1[i] != member2[i]){
                return false;
            }
        }
        return true;
    }
    // You can also put your code here
    bool get_next(Node ref,std::vector<int> &member){
        if((ref.left == NULL) && (ref.right == NULL)){
            member.push_back(ref.data);
            return true;
        }
        else if(ref.left == NULL){
            get_next(*ref.right,member);
            member.push_back(ref.data);
            return true;
        }
        else if(ref.right == NULL){
            get_next(*ref.left,member);
            member.push_back(ref.data);
            return true;
        }
        else if(get_next(*(ref.left),member) && get_next(*(ref.right),member)){
            member.push_back(ref.data);
            return true;
        }
        return false;
    }

protected:
    void insertAt(Node*& r, int x) {
        if (!r) {
           r = new Node(x, NULL, NULL);
           mSize++;
           return;
        }
        if (r->data == x) return; // Do nothing
        if (x < r->data) insertAt(r->left, x); else
        insertAt(r->right, x);
    }
    Node* mRoot;
    int mSize;

};

#endif // TREE_H_INCLUDED
