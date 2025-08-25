class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int i=-1,j=-1;
        int count=0;
        for(int n=0;n<s1.size();n++)
        {
            if(s1[n]!=s2[n])
            {
                count++;
                if(i==-1){
                    i=n;
                }
                else if(j==-1){
                    j=n;
                }
            }
        }

        if(count==0) return true;
        else if(count==2 && s1[i]==s2[j] && s1[j]==s2[i]) return true;

        return false;
    }
};