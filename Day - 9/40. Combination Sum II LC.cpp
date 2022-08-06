class Solution {
public:
    vector<vector<int>> ans;
    vector<int> nums;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        nums = candidates;
        int index=0;
        sort(nums.begin(), nums.end());
        vector<int> set;
        backtrack(set,index,target);
        return ans;
    }
    void backtrack( vector<int> &set, int index, int target){
        if(target<0) return;
        if(target==0){
            ans.push_back(set);
            return;
        }
        for(int i=index;i<nums.size();i++){
            set.push_back(nums[i]);
            backtrack(set,i+1,target-nums[i]);
            while((i+1)<nums.size() && nums[i+1]==nums[i])
                i++;
            set.pop_back();
        }
    }
};
