class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> numSet;

        

        for (int i=0; i< nums.size(); i++){
            int n = target - nums[i];
            if (numSet.find(n)!=numSet.end()){
                return {i, numSet[n]};
            }else{
            numSet[nums[i]]=i;
            }
        }
        return {-1, -1};
    }
};