class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int cnt =0;
        for(int i=0;i<digits.size();i++){
            if(digits[digits.size()-i-1]==9){
                digits[digits.size()-1]=0;
                cnt++;
            }
            else{
                digits[digits.size()-i-1]++;
                break;
            }
        }
        if(cnt== digits.size()){
           for(int i=0;i< digits.size();i++){
             digits[i] =0;
           }
           digits[0] =1;
            digits.push_back(0);
        }
        
        else if(cnt!=0){
            for(int i=digits.size() - cnt;i< digits.size();i++){
             digits[i] =0;
           }
        }

       return digits; 
    }
};
