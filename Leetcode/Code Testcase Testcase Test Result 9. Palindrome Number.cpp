class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        bool res = true;
        int l =0; int r = s.size()-1;
        for(int i =0;i<s.size();i++){
            if(l>=r){
                break;
            }
            if(s[l]!=s[r]){
                res = false;
                break;
            }
            l++; r--;
        }
        return res;
    }
};
