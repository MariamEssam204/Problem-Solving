class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum =0;
        sort(happiness.begin(),happiness.end(),greater<>());
        for(long long i=0;i<k;i++){
            sum+=happiness[i];
            if(i<happiness.size()-1){
                if(happiness[i+1]>=i+1){
                    happiness[i+1]-=i+1;
                }
                else{
                    happiness[i+1]=0;
                }
            }
            
        }
    
        return sum;
    }
};
