class Solution {
public:
    int minPairSum(vector<int>& nums) {
        vector<pair<int, int>> arr;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i =0; i<n/2;i++){
            pair<int , int > temp;
            temp.first = nums[i];
            temp.second = nums[n-i-1];
            arr.push_back(temp);
        }
        int maxi = 0;
        for(int i=0;i<arr.size();i++){
            int sum = arr[i].first + arr[i].second;
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};
