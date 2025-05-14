class Solution {
public:
    string removeDuplicateLetters(string s) {
        

        unordered_map<char,int> lastIndex;
        unordered_set<char> seen;
        stack<char> st;

        for(int i=0;i<s.size();i++)
        {
            lastIndex[s[i]]=i;
        }

        for(int i=0;i<s.size();i++)
        {
            char c=s[i];
           if(seen.count(c)) continue;
            while(!st.empty() && st.top()>c && i<lastIndex[st.top()])
            {
                seen.erase(st.top());
                st.pop();
            }

            st.push(c);
            seen.insert(c);
        }

        string result;
        while(!st.empty())
        {
            result+=st.top();
            st.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }

};