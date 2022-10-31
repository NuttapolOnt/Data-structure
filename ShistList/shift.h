void shift(int k) {
	// TODO: Add your code here
	if(k > 0){
		int n = k % mSize;
		iterator itref = begin();
		for(int i = 0; i < n; i++){
			++itref;  
		}
		iterator itbeg = mHeader -> next;
		iterator itend = mHeader -> prev;
		itbeg.ptr -> prev = itend.ptr;
		itend.ptr -> next = itbeg.ptr;

		mHeader -> prev = itref.ptr -> prev;
		itref.ptr -> prev -> next = mHeader;
		mHeader -> next = itref.ptr;
		itref.ptr -> prev = mHeader;
		
	}
	else if(k < 0){
		k = k*(-1);
		int n = k % mSize;
		iterator itref = mHeader -> prev;
		for(int i = 0; i < n; i++){
			--itref;  
		}
		iterator itbeg = mHeader -> next;
		iterator itend = mHeader -> prev;
		itbeg.ptr -> prev = itend.ptr;
		itend.ptr -> next = itbeg.ptr;
		
		mHeader -> next = itref.ptr -> next;
		itref.ptr -> next -> prev = mHeader;
		mHeader -> prev = itref.ptr;
		itref.ptr -> next = mHeader;
		
		
	}
}
