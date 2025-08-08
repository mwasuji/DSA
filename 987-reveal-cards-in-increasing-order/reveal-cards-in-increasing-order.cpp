class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        queue<int> q;
        vector<int> ans(n); 

        // Fill queue with indices 0 to n-1
        for (int i = 0; i < n; i++) {
            q.push(i);
        }

        // Sort the deck in increasing order
        sort(deck.begin(), deck.end());

        for (int i = 0; i < n; i++) {
            int idx = q.front(); q.pop();         // Place the current smallest card
            ans[idx] = deck[i];

            if (!q.empty()) {
                q.push(q.front()); q.pop();       // Move the next top index to bottom
            }
        }

        return ans;
    }
};
