class MinStack {
	private:
	int *arr,capacity,size;
	int *minArr,minCapacity,minSize;

	void resize(int* &ptr,int &cap,int &currsize){
		int newCap = cap*2;
		int *newArr = new int[newCap];
		for(int i=0;i<currsize;i++){
			newArr[i] = ptr[i];
		}
		delete[] ptr;
		ptr = newArr;
		cap = newCap;
	}
public:

    MinStack():capacity(10),size(0),minCapacity(10),minSize(0) {
        arr = new int[capacity];
		minArr = new int[minCapacity];
    }

	~MinStack(){
		delete[] arr;
		delete[] minArr;
	}
    
    void push(int val) {
        if(size >= capacity) resize(arr,capacity,size);

		if(minSize == 0 || minArr[minSize-1]>= val){
			if(minSize >= minCapacity) resize(minArr,minCapacity,minSize);
			minArr[minSize++] = val;
		}

		arr[size++] = val;
    }
    
    void pop() {
        if(size == 0) return;

		if(arr[size-1] == minArr[minSize-1]){
			minSize--;
		}
		size--;
    }
    
    int top() {
        return arr[size-1];
    }
    
    int getMin() {
        return minArr[minSize-1];
    }
};
