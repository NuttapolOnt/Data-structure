// Your code here



KeyT getValueOfMostImbalanceNode() {
    std::pair<int,std::pair<KeyT,int>> ans = getHeight(mRoot);
    return ans.second.first;
}
std::pair<int,std::pair<KeyT,int>> getHeight(node* n){
    std::pair<int,std::pair<KeyT,int>> tmp;
    if((n -> left != NULL) && (n -> right != NULL)){
        std::pair<int,std::pair<KeyT,int>> lhs = getHeight(n -> left);
        std::pair<int,std::pair<KeyT,int>> rhs = getHeight(n -> right);
        int diff = (lhs.first > rhs.first) ? lhs.first - rhs.first : rhs.first - lhs.first; 
        if(rhs.second.second > lhs.second.second){
            if(rhs.second.second > diff){
                int m = (lhs.first > rhs.first) ? lhs.first+1 : rhs.first+1;
                tmp.first = m;
                tmp.second = rhs.second;
            }
            else{
                int m = (lhs.first > rhs.first) ? lhs.first+1 : rhs.first+1;
                tmp.first = m;
                tmp.second.first = (n -> data).first; 
                tmp.second.second = diff;
            }
        }
        else{
            if(diff > lhs.second.second){
                int m = (lhs.first > rhs.first) ? lhs.first+1 : rhs.first+1;
                tmp.first = m;
                tmp.second.first = (n -> data).first;
                tmp.second.second = diff;
            }
            else{
                int m = (lhs.first > rhs.first) ? lhs.first+1 : rhs.first+1;
                tmp.first = m;
                tmp.second = lhs.second;
            }
        }
    }
    else if ((n -> left != NULL) && (n -> right == NULL)){
        std::pair<int,std::pair<KeyT,int>> lhs = getHeight(n -> left);
        int diff = lhs.first + 1;
        if(diff > lhs.second.second){
            tmp.first = lhs.first +1;
            tmp.second.first = (n -> data).first;
            tmp.second.second = diff;
        }
        else{
            lhs.first += 1;
            tmp = lhs;
        }
    }
    else if ((n -> left == NULL) && (n -> right != NULL)){
        std::pair<int,std::pair<KeyT,int>> rhs = getHeight(n -> right);
        int diff = rhs.first + 1;
        if(rhs.second.second > diff){
            rhs.first += 1;
            tmp = rhs;
        }
        else{
            tmp.first = rhs.first + 1;
            tmp.second.first = (n -> data).first;
            tmp.second.second = diff;
        }
    }
    else if ((n -> left == NULL) && (n -> right == NULL)){
        tmp.first = 0;
        tmp.second.first = (n -> data).first;
        tmp.second.second = 0;
    }
    return tmp;
}
