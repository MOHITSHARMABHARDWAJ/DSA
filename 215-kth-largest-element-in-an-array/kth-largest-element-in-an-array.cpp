class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quick_select(nums,k);
    }

    int quick_select(vector<int>& nums, int k)
    {
        vector<int> left;
        vector<int> middle;
        vector<int> right;

        int pivot = nums[rand()% nums.size()];
        for(int& num: nums)
        {
            if (num > pivot)
                left.push_back(num);
            else if (num < pivot)
                right.push_back(num);
            else
                middle.push_back(num);
        }
        if (k<=left.size())
            return quick_select(left, k);
        else if (k > left.size() + middle.size())
            return quick_select(right, k - left.size() - middle.size());
        return pivot;
    }
};