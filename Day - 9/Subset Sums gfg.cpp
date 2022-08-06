class Solution
{
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans;
        for(int i=0;i<(1<<N);i++){
            bitset<16> bits(i);
            long long sum=0ll;
            for(int j=0;j<N;j++){
                if(bits[j]) sum+=arr[j];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};

class Solution
{
public:
    vector<int> ans;
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        long long sum=0;
        backtrack(arr,0,sum);
        return ans;
    }
     void backtrack(vector<int> arr, int i, long long sum){
         if(i==arr.size()){
             ans.push_back(sum);
             return;
         }
         backtrack(arr,i+1,sum);
         backtrack(arr,i+1,sum+arr[i]);
     }
};
