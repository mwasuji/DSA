class Solution {
public:
     int majorityElement(vector<int>& nums) {
    //     unordered_map<int, int> hash;
    //     int res = 0;
    //     int majority = 0;

    //     for (int n : nums) {
    //         hash[n] = 1 + hash[n];
    //         if (hash[n] > majority) {
    //             res = n;
    //             majority = hash[n];
    //         }
    //     }

    //     return res;        
    // }

   unordered_map<int,int> m;

   for (auto i :nums){
    m[i]++;
   }

   for (auto i:m){
    if (i.second >(nums.size()/2)  ){
        return i.first;
    } 

   } return 0;
   }

};