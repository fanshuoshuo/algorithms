class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        int max=-1;
        for(int i=0;i<s.size();i++){
            int len=0;
            for(int j=i;j<s.size();j++){
                //s[j] not in range [i,j-1]
                char c=s[j];
                bool notSame=true;
                for(int k=i;k<j-1;k++){
                    if(c==s[k]) notSame=false;
                }
                if(notSame) {len++;max=len>max?len:max;}
                else break;
            }  
        }
        //bbbbbbb
        return max;
    }
    
};