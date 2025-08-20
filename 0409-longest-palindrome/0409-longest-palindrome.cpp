class Solution {
public:
    int longestPalindrome(string s) {
        int l=0;
        unordered_map<char, int> pal;
        for(char c:s) pal[c]++;
       
        bool is_odd=false;
        for(auto &p:pal)
        {
           if(p.second%2==0)
           {
            l+=p.second;
           }
           else{
            is_odd=true;
              l+=p.second -1;
           }
        }

        return is_odd?l+1:l;
;    }
};