class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n,1);

        // step1. prefix products ko calculate karo
        int prefix = 1;
        for(int i=0; i<n; i++){
            answer[i] = prefix;
            prefix *= nums[i];
        }

        // step2. suffix products ko calculate karo aur multiply karo existing prefix products ke saath
        int suffix = 1;
        for(int i =n-1; i>=0; i--){
            answer[i] *= suffix;
            suffix *= nums[i];
        }
        return answer;
    }
};
