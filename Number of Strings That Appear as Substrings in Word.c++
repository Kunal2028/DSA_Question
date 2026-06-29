class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int cnt = 0;
        for(string z:patterns){
            if(word.find(z)!=-1) cnt++;
        }
        return cnt;
    }
};