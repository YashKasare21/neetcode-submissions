class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;
        
        while (left <= right) {
            int i = left + (right - left) / 2; // Partition point in nums1
            int j = (m + n + 1) / 2 - i;       // Partition point in nums2
            
            // Handle edge cases
            int nums1_left_max = (i == 0) ? INT_MIN : nums1[i - 1];
            int nums1_right_min = (i == m) ? INT_MAX : nums1[i];
            int nums2_left_max = (j == 0) ? INT_MIN : nums2[j - 1];
            int nums2_right_min = (j == n) ? INT_MAX : nums2[j];
            
            // Check if partition is valid
            if (nums1_left_max <= nums2_right_min && nums2_left_max <= nums1_right_min) {
                // Found the correct partition
                if ((m + n) % 2 == 1) {
                    // Odd total length
                    return max(nums1_left_max, nums2_left_max);
                } else {
                    // Even total length
                    return (max(nums1_left_max, nums2_left_max) + min(nums1_right_min, nums2_right_min)) / 2.0;
                }
            } else if (nums1_left_max > nums2_right_min) {
                // i is too large, need to decrease it
                right = i - 1;
            } else {
                // i is too small, need to increase it
                left = i + 1;
            }
        }
        
        return 0.0; // Should never reach here
    }
};