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
        int pivot = nums[left];
        int i = left+1,j = right;
        while(i<=j){
            if(nums[i]<pivot){
                ++i;
            }else if(nums[j]>pivot){
                --j;
            }else{
                swap(nums[i++],nums[j--]);
            }
        }
        swap(nums[left],nums[j]);
        return j;
    }
};