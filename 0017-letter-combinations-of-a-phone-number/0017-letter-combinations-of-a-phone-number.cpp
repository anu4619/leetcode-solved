class Solution {
    public:
    void backtrack(vector<string>& ans,string mapping[],int index,string output, string digits){
        if(index>=digits.length())
        {
            ans.push_back(output);
            return;
        }

        int number=digits[index]-'0';
        string value=mapping[number];
        for(int i=0;i<value.length();i++)
        {
            output.push_back(value[i]);
            backtrack(ans,mapping,index+1,output,digits);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0){
            return ans;
        }
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int index=0;
        string output="";
        backtrack(ans,mapping,index,output,digits);
        return ans;
    }
};