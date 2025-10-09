#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        int target = nums.size() - k;  

        while (true) {
            int pivotIndex = partition(nums, left, right);
            if (pivotIndex == target)
                return nums[pivotIndex];
            else if (pivotIndex < target)
                left = pivotIndex + 1;   
            else
                right = pivotIndex - 1;  
        }
    }

private:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[right];
        int i = left;
        for (int j = left; j < right; j++) {
            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
        swap(nums[i], nums[right]);
        return i; 
    }
};