class Solution {
public:
    int bestClosingTime(string customers) {
        int size = customers.size();
        int y =0;
        vector<int>res(size+1,0);
        for(int i=0;i<size;i++){
            if(customers[i]=='Y'){
                y++;
            }
        }
        res[0] = y;
        for(int i=1;i<=size;i++){
            if(customers[i-1]=='Y'){
                res[i] = res[i-1]-1;
            }
            else{
                res[i] = res[i-1]+1;
            }
        }
        auto minindex = min_element(res.begin(),res.end());
        int k = distance(res.begin(), minindex);

        return k;
    }
};
