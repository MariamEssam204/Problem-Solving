class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum =0; int x =1;
        for(int i=0;i<apple.size();i++){
            sum+=apple[i];
        }
        for(int i =0;i<capacity.size();i++){
            if(capacity[i]>=sum){
                return 1;
            }
        }
        int size = capacity.size();
        sort(capacity.begin(), capacity.end());
        for(int i =size-2;i>=0;i--){
            capacity[i] += capacity[i+1];
            if(capacity[i]>= sum){
                return x+1;
            }
            else{
                x++;
            }

        }
        return x+1;
    }
};
