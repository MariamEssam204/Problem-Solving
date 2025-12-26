class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int n = nums1.size();
        int m = nums2.size();
        for(int i = 0;i<n;i++){
            res.push_back(nums1[i]);
        }
        for(int i = 0;i<m;i++){
            res.push_back(nums2[i]);
        }
        sort(res.begin(),res.end());
        double ans =0;
        if(res.size()%2!=0){
            ans = res [(res.size()/2)];
        }
        else{int num = 42;

            ans =static_cast<double>(( res [(res.size()/2)]+ res [(res.size()/2)-1]))/2;
        }
        return ans;
    }
};
