class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0,r = nums.size()-1;
        quickSort(nums,l,r);
    }

    void quickSort(vector<int>& nums,int left,int right){
        if(left>=right) return;
        int pivot = partition(nums,left,right);
        quickSort(nums,left,pivot-1);
        quickSort(nums,pivot+1,right);
    }

    int partition(vector<int>& nums,int l,int r){
        int pivot = nums[l];
        int i = l+1,j = r;
        while(i<=j){
            while(i<=j && nums[j]>=pivot){
                --j;
            }
            while(i<=j && nums[i]<=pivot){
                ++i;
            }
            if(i<j){
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[l],nums[j]);
        return j;
    }
};