class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int> map;
        int l=0,maxlen=0;
        for(int r=0;r<n;r++)
        { 
            map[fruits[r]]++;
            while(map.size()>2)
            {
                map[fruits[l]]--;
                if(map[fruits[l]]==0)
                {
                    map.erase(fruits[l]);
                }
                l++;
            }
            maxlen=max(maxlen,r-l+1);
        
        }
        return maxlen;
    }
};