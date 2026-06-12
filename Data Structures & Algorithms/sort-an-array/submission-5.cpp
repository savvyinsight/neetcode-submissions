class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int l = 0,r = nums.size()-1;
        mergeSort(nums,l,r);
        return nums;
    }

    void mergeSort(vector<int>& nums,int left,int right){
        if(left>=right) return;
        int m = left+(right-left)/2;
        mergeSort(nums,left,m);
        mergeSort(nums,m+1,right);
        merge(nums,left,m,right);
    }

    void merge(vector<int>& nums,int l,int m,int r){
        vector<int> temp;
        int i = l, j = m+1;
        while(i<=m && j<=r){
            if(nums[i]<=nums[j]){
                temp.push_back(nums[i++]);
            }else{
                temp.push_back(nums[j++]);
            }
        }

        while(i<=m){
            temp.push_back(nums[i++]);
        }

        while(j<=r){
            temp.push_back(nums[j++]);
        }

        for(int i = l;i<=r;++i){
            nums[i] = temp[i-l];
        }
    }
};