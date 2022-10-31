#include<iostream>

class node{
    public:
    node *prev;
    int data;
    node *next;
    node(){
        prev = this;
        data = 0;
        next = this;
    }
};

std::pair<bool, node*> check(node* it){
    node *it1 = it;
    node *it2 = it;
    int ref = it -> data;
    int count = 1;
    std::pair<bool, node*> ans;
    ans.first = false;
    ans.second = it;
    while(it1 -> next -> data == ref){
        it1 = it1 -> next;
        count += 1;
    }
    while(it2 -> prev -> data == ref){
        it2 = it2 -> prev;
        count += 1;
    }
    if(count >= 3){
        it1 -> prev = it2;
        it2 -> next = it1;
        ans.second = it2;
        ans.first = true;
    }
    return ans;
}

int main(){
    int n,k,v;
    std::cin >> n >> k >> v;
    node header;
    header.next = &header;
    header.prev = &header;
    node *ref = &header;
    for(int i = 0; i < n; i++){
        int a;
        std::cin >> a;
        node x ;
        x.data = a;
        x.prev = ref;
        ref -> next = &x;
        x.next = &header;
        header.prev = &x;
        ref = &x;
    }
    // node *pos = header.next;
    // for(int i = 0; i < k; i++){
    //     pos = pos -> next;
    // }
    // node tmp;
    // tmp.prev = pos -> prev;
    // pos -> prev -> next = &tmp;
    // tmp.next = pos;
    // while(true){
    //     std::pair<bool, node*> ans = check(pos);
    //     if(ans.first == false){
    //         break;
    //     } 
    //     pos = ans.second;
    // }
    node* beg = header.next;
    while(beg != &header){
        std::cout << beg -> data << " ";
        beg = beg -> next;
    }
    std::cout << std::endl;
    return 0;
}