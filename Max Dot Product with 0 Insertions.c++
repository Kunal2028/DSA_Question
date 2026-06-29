class Solution {
  public:
    int solve(int i,int j,vector<int>& a, vector<int>& b,vector<vector<int>>& dp){
        if(j==b.size()) return 0;
        if(i==a.size()) return -1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int skip = solve(i+1,j,a,b,dp);
        int taken = a[i]*b[j]+solve(i+1,j+1,a,b,dp);
        int ans = max(skip,taken);
        return dp[i][j]=ans;
    }
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        int m = a.size();
        int n = b.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,a,b,dp);
    }
};
