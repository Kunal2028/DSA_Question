class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0;
        int right;
        int n = s.length();
        unordered_map<char,int>mp;
        int ans = 0;
        for(right=0;right<n;right++){
          mp[s[right]]++;
          while(mp['a']>0&&mp['b']>0&&mp['c']>0){
          ans += (n-right);
          mp[s[left]]--;
          left++;
          }
        }
        return ans;
    }
};
