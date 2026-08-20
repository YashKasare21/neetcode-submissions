class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> numMap;

        for(int i= 0; i<nums.size(); i++){
            int complement = target - nums[i];

            //check karo if complement exist krta hai kya map mei
            if(numMap.find(complement) != numMap.end()){
                return {numMap[complement], i};
            }

            // nhi toh current no. and uska index map pe add karo
            numMap[nums[i]]  = i;
        }

        return {}; //yeh return hum daalte hai kyuki hume gurantee kuch solution aye 
    }
};
