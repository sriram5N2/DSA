class Solution {
public:
struct Query {
        int l, r, threshold, idx;
    };
    vector<int> subarrayMajority(vector<int>& nums, vector<vector<int>>& queries) {

        int n = nums.size();
        int qn = queries.size();
        
        // 1. Prepare Queries
        std::vector<Query> queriesVect(qn);
        for(int i = 0; i < qn; i++) {
            queriesVect[i] = {queries[i][0], queries[i][1], queries[i][2], i};
        }

        // 2. Normal Mo's Sorting Approach
        int block_size = std::max(1, n / (int)std::sqrt(qn));
        std::sort(queriesVect.begin(), queriesVect.end(), [&](const Query& a, const Query& b) {
            int block_a = a.l / block_size;
            int block_b = b.l / block_size;
            if (block_a != block_b) {
                return block_a < block_b;
            }
            // Normal approach: Always sort R in ascending order within a block
            return a.r < b.r;
        });

        // 3. Data Structures for Frequency Tracking
        std::vector<int> res(qn);
        std::unordered_map<int, int> freqMap; // Value -> Current Count
        std::vector<std::set<int>> freqs(n + 1); // Count -> Sorted Set of Values
        int maxFreq = 0;

        // 4. Helper Functions
        auto add = [&](int idx) {
            int num = nums[idx];
            int old_f = freqMap[num];
            
            // Remove from old frequency set
            if (old_f > 0) freqs[old_f].erase(num);
            
            // Update frequency and move to new set
            int new_f = ++freqMap[num];
            freqs[new_f].insert(num);
            
            // Update global maximum frequency
            if (new_f > maxFreq) maxFreq = new_f;
        };

        auto remove = [&](int idx) {
            int num = nums[idx];
            int old_f = freqMap[num];
            
            // Remove from current frequency set
            freqs[old_f].erase(num);
            
            // Update frequency and move back to lower set
            int new_f = --freqMap[num];
            if (new_f > 0) freqs[new_f].insert(num);
            
            // If the maxFreq set is now empty, decrement maxFreq
            if (maxFreq > 0 && freqs[maxFreq].empty()) {
                maxFreq--;
            }
        };

        // 5. Processing Queries
        int cur_l = 0;
        int cur_r = -1;

        for (const auto& q : queriesVect) {
            // Expand Right
            while (cur_r < q.r) add(++cur_r);
            // Expand Left
            while (cur_l > q.l) add(--cur_l);
            // Shrink Right
            while (cur_r > q.r) remove(cur_r--);
            // Shrink Left
            while (cur_l < q.l) remove(cur_l++);

            // Answer logic: Must hit threshold and pick smallest from the maxFreq set
            if (maxFreq >= q.threshold) {
                res[q.idx] = *freqs[maxFreq].begin();
            } else {
                res[q.idx] = -1;
            }
        }

        return res;
        
    }
};