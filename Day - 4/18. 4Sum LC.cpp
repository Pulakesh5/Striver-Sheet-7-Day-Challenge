#define all(x) x.begin(), x.end()
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // 4 sum is just like 2 sum just somehow fix one part of target
        // & use two pointer to find the  
        int n= nums.size();
        vector<vector<int>> ans;
        if(n<4) return ans;
        sort(all(nums));
        
        for(int i=0;i<(n-3);i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            if(0ll+nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) break;
            if(0ll+nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
            
            for(int j=i+1; j<(n-2); j++){
               A if(j>(i+1) && nums[j]==nums[j-1]) continue;
                if(0ll+nums[i]+nums[j]+nums[j+1]+nums[j+2] > target) break;
                if(0ll+nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
                
                int l=j+1,r=n-1,prevSum=nums[i]+nums[j],currSum;
                while(l<r){
                    currSum = nums[l]+nums[r];
                    if(prevSum+currSum==target)
                    {
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        do{l++;}while(l<r && nums[l]==nums[l-1]);
                        do{r--;}while(l<r && nums[r]==nums[r+1]);
                    }
                    else if(prevSum+currSum<target) l++;
                    else r--;
                }
            
            }
            
        }
        
        return ans;
    }
};
