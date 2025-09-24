class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0;
        int total = 0;

        for (int x : nums) total += x;

        for (int i = 0; i < nums.size(); i++) {
            if (left == total - left - nums[i]) {
                return i;
            }
            left += nums[i];
        }

        return -1; 
    }
};
