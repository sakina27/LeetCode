int Solution::solve(vector<int> &A, int B) {
    unordered_map<int, int> mp;
    int count = 0;
    int xr = 0;
    mp[xr]++;
    for (int i=0; i<A.size(); i++){
        xr = xr ^ A[i];
        if (mp.find(xr^B)!=mp.end()){
            count += mp[xr^B];
        }
        mp[xr]++;
    }
    return count;
}
