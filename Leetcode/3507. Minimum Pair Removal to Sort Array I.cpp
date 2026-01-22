class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        while(true){
            bool x = 1;
            for(int i = 0; i < n - 1; i++){
                if(nums[i] > nums[i + 1]){
                    x = 0; //unorderd
                    break;
                }
            }
            if (x) break;
            if (!x) {
                int pos = 0;
                int temp = INT_MAX;
                for (int i = 0; i < n - 1; i++) {
                    if (nums[i] + nums[i + 1] < temp) {
                        temp = nums[i] + nums[i + 1];
                        pos = i;
                    }
                }
                nums[pos] = temp;
                nums.erase(nums.begin() + pos + 1);
                n--;  // Update the size
                res++;
                
            }
        }
        return res;
    }
};
