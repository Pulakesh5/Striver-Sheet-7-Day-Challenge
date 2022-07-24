/*
Initial observation : >(n/3) + >(n/3) = <(n/3)
So there can be at-most 2 numbers with n/3 majority condition
now use this to check for two major numbers just like in majoriyt element question 
*/


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n=nums.size();
        int major1=-1,major2=-1,c1=0,c2=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]==major1) c1++;
            else if(nums[i]==major2) c2++;
            else if(c1==0){
                major1=nums[i];c1=1;
            }
            else if(c2==0){
                major2=nums[i];c2=1;
            }
            else{
                c1--;c2--;
            }
        }
        int majorCount1=0,majorCount2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==major1)
                majorCount1++;
            else if(nums[i]==major2)
                majorCount2++;
        }
        vector<int> majors;
        if(majorCount1>(n/3)) majors.push_back(major1);
        
        if(majorCount2>(n/3)) majors.push_back(major2);
        
        return majors; 
        
    }
};
