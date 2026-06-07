#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
    // Safe negative infinity (Fits in JSON bounds, lower than lowest possible sum)
    const long long MIN_INF = -1e14;

public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        int n = nums.size();
        
        // 1-based Prefix sums for O(1) subarray sum lookups
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }
        
        long long ans = MIN_INF;
        
        // prev_dp represents the max sum using EXACTLY j-1 subarrays
        // Initialized to 0 for 0 subarrays.
        vector<long long> prev_dp(n + 1, 0); 
        
        for (int j = 1; j <= m; j++) {
            // curr_dp represents the max sum using EXACTLY j subarrays
            vector<long long> curr_dp(n + 1, MIN_INF);
            
            // Stores valid 'k' indices, sorted to keep the maximum valid calculation at the front
            deque<int> dq; 
            
            for (int i = 1; i <= n; i++) {
                // Option 1: Skip current element (inherit max from previous index for same subarray count)
                curr_dp[i] = curr_dp[i - 1];
                
                // The new 'k' index that just became valid for minimum length 'l'
                int k_in = i - l; 
                // The 'k' index that just became invalid due to maximum length 'r'
                int k_out = i - r; 
                
                // 1. Add the new valid k_in to our Monotonic Queue
                if (k_in >= 0 && prev_dp[k_in] != MIN_INF) {
                    long long val = prev_dp[k_in] - pref[k_in];
                    // Maintain decreasing order: pop elements worse than our new candidate
                    while (!dq.empty() && (prev_dp[dq.back()] - pref[dq.back()]) <= val) {
                        dq.pop_back();
                    }
                    dq.push_back(k_in);
                }
                
                // 2. Remove 'k' indices from the front if they exceed max length 'r'
                while (!dq.empty() && dq.front() < k_out) {
                    dq.pop_front();
                }
                
                // 3. Option 2: Form a valid subarray ending at i using the best 'k'
                if (!dq.empty()) {
                    int best_k = dq.front();
                    long long current_val = prev_dp[best_k] - pref[best_k] + pref[i];
                    curr_dp[i] = max(curr_dp[i], current_val);
                }
                
                // Update global answer if we have formed a valid configuration
                if (curr_dp[i] != MIN_INF) {
                    ans = max(ans, curr_dp[i]);
                }
            }
            // Move our current state to previous for the next subarray count
            prev_dp = curr_dp; 
        }
        
        return ans;
    }
};