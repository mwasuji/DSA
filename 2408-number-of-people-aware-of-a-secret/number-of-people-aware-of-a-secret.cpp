class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int M = 1e9 +7;
      int curr=0;
      int ans =1;
      queue<pair<int,int>>delayq,forgetq;
      delayq.push({1,1});
      forgetq.push({1,1});
      for (int i=1;i<=n;++i){

        if(!forgetq.empty() && forgetq.front().first + forget<= i){
            auto front = forgetq.front();
            forgetq.pop();
            auto no = front.second;
            ans= (ans -no + M)% M;
            curr = (curr -no + M)% M;
        }

        if(!delayq.empty() && delayq.front().first + delay <= i ){
            auto front = delayq.front();
            delayq.pop();
            curr = (curr + front.second) % M;

        }

        if (curr>0){
            ans= (ans +curr) % M;
            delayq.push({i,curr});
            forgetq.push({i,curr});
        }
      }
      return ans;
    }
};