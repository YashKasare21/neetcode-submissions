class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;

        int rows = matrix.size();
        int cols = matrix[0].size();
        int left = 0;
        int right = rows * cols - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            int r = mid / cols;
            int c = mid % cols;
            int val = matrix[r][c];

            if(val == target){
                return true;
            } else if(val < target){
                left = mid + 1;
            } else{
                right = mid - 1;
            }
        }

        return false;
    }
};
