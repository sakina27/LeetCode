class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0, count2 = 0;
        int element1 = INT_MIN, element2 = INT_MIN;
        vector<int> res;
        int n = nums.size()/3;

        // First pass: Find potential candidates
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == element1) {
                count1++;
            } else if (nums[i] == element2) {
                count2++;
            } else if (count1 == 0) {
                element1 = nums[i];
                count1 = 1;
            } else if (count2 == 0) {
                element2 = nums[i];
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // Reset counts for validation
        count1 = 0;
        count2 = 0;

        // Second pass: Validate the candidates
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == element1) {
                count1++;
            } else if (nums[i] == element2) {
                count2++;
            }
        }

        if (count1 > n) res.push_back(element1);
        if (count2 > n && element2 != element1) res.push_back(element2);

        return res;
    
    }
};