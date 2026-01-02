class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int size = nums.size()/2;
        int target =0;
        for(int i=0;i<size*2 ;i++){
            int cnt =0;
            for(int j=0;j<size*2 ;j++){
                if(nums[i]==nums[j]){
                    cnt++;
                }
            }
            if(cnt == size){
                target = i; 
                break;
            }
        }
        return nums[target];
    }
};
