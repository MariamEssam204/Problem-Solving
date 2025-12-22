class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        //strs.size();
        int m=strs[0].size();
        // dp[j] = max columns we can keep ending at column j
        vector<int> dp(m, 1);
        for(int j =0;j<strs[0].size();j++){
            for(int i=0;i<j;i++){
                bool canextend = true;
                for(int row =0;row<strs.size();row++){
                    if(strs[row][j]<strs[row][i]){
                        canextend =false;
                        break;
                    }
                }
                if(canextend){
                    dp[j] = max(dp[j],dp[i]+1);
                }
            }
            
        }
        int maxtokeep = *max_element(dp.begin(),dp.end());
       return m - maxtokeep;
    }
};
