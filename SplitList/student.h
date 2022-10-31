void splitList(list<T>& list1, list<T>& list2) {
    // Add your code here
    int s = mSize;
    int n = (mSize + 1)/2;
    iterator it = begin();
    for(int i = 0; i < n; i++){
        iterator itref = it.ptr -> next;
        iterator itlast = list1.mHeader -> prev;
        itlast.ptr -> next = it.ptr;
        it.ptr -> prev = itlast.ptr;
        list1.mHeader -> prev = it.ptr;
        it.ptr -> next = list1.mHeader;
        it = itref;
        list1.mSize += 1;
        mSize -= 1;
    }
    for(int i = n; i < s; i++){
        iterator itref = it.ptr -> next;
        iterator itlast = list2.mHeader -> prev;
        itlast.ptr -> next = it.ptr;
        it.ptr -> prev = itlast.ptr;
        list2.mHeader -> prev = it.ptr;
        it.ptr -> next = list2.mHeader;
        it = itref;
        list2.mSize += 1;
        mSize -= 1;
    }
    mHeader -> next = mHeader;
    mHeader -> prev = mHeader;
}
