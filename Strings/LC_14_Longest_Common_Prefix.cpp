// key Idea - Find the longest common prefix by comparing sorted boundary strings 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n = strs.size();
        int begin = 0;
        int end = 0;
        string s;
        while(strs[0][begin] != '\0' || strs[n-1][end] != '\0'){
            if(strs[0][begin] == strs[n-1][end]){
                s.push_back(strs[0][begin]);
                begin++;
                end++;
            }
            else return s;
        }
        return s;
    }
};