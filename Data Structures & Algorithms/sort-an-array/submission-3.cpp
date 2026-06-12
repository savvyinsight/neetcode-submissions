class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int left = 0,right = nums.size()-1;
        quickSort(nums,left,right);
        return nums;
    }

    void quickSort(vector<int>& nums,int left,int right){
        if(left>=right) return;
        int pivot = partition(nums,left,right);
        quickSort(nums,left,pivot-1);
        quickSort(nums,pivot+1,right);
    }

    int partition(vector<int>& nums,int left,int right){
        int random = left+rand()%(right-left+1);
        swap(nums[random],nums[right]);
        int pivot = nums[right];
        int i = left,j = right;
        while(i<=j){
            while(i<=j && nums[j]>=pivot) j--;
            while(i<=j && nums[i]<=pivot) i++;
            if(i<j){
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[right],nums[i]);
        return i;
    }
};