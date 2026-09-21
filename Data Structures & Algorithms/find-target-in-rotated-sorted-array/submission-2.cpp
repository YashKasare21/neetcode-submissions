class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            // Determine which half mid is in
            if (nums[mid] > nums[right]) {
                // Mid is in the left sorted portion
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1; // Target is in left half
                } else {
                    left = mid + 1; // Target is in right half
                }
            } else {
                // Mid is in the right sorted portion
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1; // Target is in right half
                } else {
                    right = mid - 1; // Target is in left half
                }
            }
        }
        
        return -1;
    }
};
