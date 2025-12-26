class Solution {
public:
    int mirrorDistance(int n) {
        string s = to_string(n);
        string str ="";
        for(int i=s.size()-1;i>=0;i--){
            str+=s[i];
        }
        int res = stoi(str);
        //cout<<res;
        res = abs(n - res);
        return res;
    }
};
