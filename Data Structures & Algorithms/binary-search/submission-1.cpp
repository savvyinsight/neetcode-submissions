class Solution {
public:
    int binarySearch(vector<int>& nums, int target,int l,int r){
        if(l>r) return -1;
        int m = l+(r-l)/2;
        if(nums[m] == target){
            return m;
        }
        if(nums[m] < target){
            return binarySearch(nums,target,m+1,r);
        }else{
            return binarySearch(nums,target,l,m-1);
        }
    }

    int search(vector<int>& nums, int target) {
        int l  = 0,r = nums.size();
        return binarySearch(nums,target,l,r);
    }


};
