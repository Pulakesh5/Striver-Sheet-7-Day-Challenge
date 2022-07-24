/*
This is a great use of divide and conquer paradigm
Recursively sort the array and before merging two sub-arrays
check for any given condition and find the count
https://leetcode.com/problems/reverse-pairs/discuss/97268/General-principles-behind-problems-similar-to-%22Reverse-Pairs%22


*/



#define itr vector<int>::iterator 
class Solution {
public:
    int CountPair(itr begin, itr end){
        if(end-begin <= 1) return 0;
        itr mid = begin + (end-begin)/2;
        int count = 0;
        if(mid>begin) count += CountPair(begin,mid);
        if(mid<end) count += CountPair(mid,end);
        
        for(itr i=begin,j=mid;i<mid;i++){
            while(j<end && (*i) > 2ll*(*j)) j++;
            count += (j-mid);
        }
        inplace_merge(begin, mid, end);
        return count;   
    }
    
    int reversePairs(vector<int>& nums) {
        return CountPair(nums.begin(),nums.end());
    }
};
