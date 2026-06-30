class Solution {
  public:
    int minInsAndDel(vector<int> &a, vector<int> &b) {
    unordered_map<int,int>mp;
    for(int num:b) mp[num]++;
    vector<int>temp;
    int n = a.size();
    for(int i=0;i<n;i++){
        if(mp.find(a[i])==mp.end()) continue;
        if((temp.size()==0||temp[temp.size()-1]<a[i])){
            temp.push_back(a[i]);
        }
        else{
            int idx = lower_bound(temp.begin(),temp.end(),a[i])-temp.begin();
            temp[idx] = a[i];
        }
    }
    int k = temp.size();
    return b.size()+a.size()-2*k;
    }
};
