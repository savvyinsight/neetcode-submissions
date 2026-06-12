class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int l = 0,r = nums.size()-1;
        quickSort(nums,l,r);
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
        swap(nums[random],nums[left]);
        int pivot = nums[right];
        int i = left - 1;
        
        for(int j = left; j < right; j++) {
            if(nums[j] <= pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[right]);
        return i+1;
    }
};