class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
      //get sum for sliding window
        int sum =0;
        for (int i=0;i<k;i++){
            sum+=nums[i];
        }

        int maxsum=sum;

        //start sliding window

        int startindex=0;
        int endindex=k;
        int n =nums.size();
        while(endindex < n){
            sum-=nums[startindex]; //remove previous element 
            startindex++;

            sum+=nums[endindex];  // add next elemnet
            endindex++;

            maxsum=max(maxsum,sum); // update the maxsum
        }

        return (double) maxsum/k;
    }
};