class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        heapSort(nums);
        return nums;
    }

    void heapSort(vector<int>& nums){
        int n = nums.size();
        //build max heap
        for(int i = n/2-1;i>=0;--i){
            heapify(nums,n,i);
        }

        //sort phase
        for(int i = n-1;i>0;--i){
            swap(nums[0],nums[i]);
            heapify(nums,i,0);
        }
    }

    void heapify(vector<int>& nums,int n,int i){
        int l = (i<<1)+1;
        int r = (i<<1)+2;
        int largestNode = i;

        if(l<n && nums[l] > nums[largestNode]){
            largestNode = l;
        }
        if(r<n && nums[r] > nums[largestNode]){
            largestNode = r;
        }

        if(largestNode != i){
            swap(nums[i],nums[largestNode]);
            heapify(nums,n,largestNode);
        }
    }


};