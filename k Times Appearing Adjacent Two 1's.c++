class Solution {
    const int mod = 1e9+7;
    int solve(int i,int n,int k,int prev,vector<vector<vector<int>>>& dp){
        if(k < 0) return 0;
        if(i==n){
            if(k==0) return 1;
            return 0;
        }
        if(dp[i][k][prev]!=-1) return dp[i][k][prev];
        long long skip = solve(i+1,n,k,0,dp);
        long long take1 = 0;
        long long take2 = 0;
        if(prev==0){
            take1 = solve(i+1,n,k,1,dp);
        }
        else{
            take2 = solve(i+1,n,k-1,1,dp);
        }
        return dp[i][k][prev]=(skip+take1+take2)%mod;
    }
  public:
    int countStrings(int n, int k) {
    if(k>n) return 0;
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return solve(0,n,k,0,dp);
    }
};
