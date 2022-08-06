class Solution {
public:
    set<vector<int>> st;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> vec;
        sort(nums.begin(), nums.end());
        backtrack(nums,0,vec);
        vector<vector<int>> ans(st.begin(), st.end());
        
        return ans;
    }
    
    void backtrack(vector<int> &nums, int index, vector<int> &vec){
        if(index==nums.size()){
            st.insert(vec);
            return;
        }
        vec.push_back(nums[index]);
        backtrack(nums,index+1,vec);
        vec.pop_back();
        backtrack(nums,index+1,vec);
    }
};

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> Subsets={{}};
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n; ){
            int sameCount=0;
            
            while((i+sameCount)<n && nums[i+sameCount]==nums[i])
                sameCount++;
            
            int prevSubsetCount=Subsets.size();
            
            for(int k=0;k<prevSubsetCount;k++){
                vector<int> prevSubset=Subsets[k];
            
                for(int j=0;j<sameCount;j++){
                    prevSubset.push_back(nums[i+j]);
                    Subsets.push_back(prevSubset);
                }
            
            }
            i+=sameCount;
        }
        
        return Subsets;
    }

};
