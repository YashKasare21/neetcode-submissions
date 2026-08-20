class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //1. freq ko count karenge
        unordered_map<int, int> freqMap;
        for(int num : nums){
            freqMap[num]++;
        }



        //2. min heap use karenge taaki top k elements ka track rhe
        // pair format : {frequency, element}
        // greater<pair<int, int>> yeh first element pe min-heap based bana deta hai 

        priority_queue<pair<int, int>,vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        for(auto& pair : freqMap){
            minHeap.push({pair.second, pair.first});

            // agar heap size k se exceed krti hai, kam freq wale element ko remove krdo 
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }




        //3. elements ko heap se exract karenge 
        vector<int> result;
        while(!minHeap.empty()){
            result.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return result;
    }
};
