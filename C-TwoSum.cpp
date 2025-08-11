class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>sum;
        for(int i=0; i<nums.size(); i++){
            if(sum.find(target-nums[i])!=sum.end()){
                return {sum[target-nums[i]],i};
            }
            sum[nums[i]] = i;
        }
        return { };
    }
};