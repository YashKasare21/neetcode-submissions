class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n==0) return 0;

        stack<int> st;
        vector<int> left_smaller(n), right_smaller(n);

        for(int i = 0; i<n; i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            left_smaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n - 1; i>=0; i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            right_smaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        int max_area = 0;
        for(int i = 0; i < n; i++){
            int width = right_smaller[i] - left_smaller[i] - 1;
            int area = heights[i] * width;
            max_area = max(max_area, area);
        }
        return max_area;
    }
};
