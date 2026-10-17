class Solution {
    int getDigitSum(int val) {
        int sum = 0;
        while (val > 0) {
            sum += val % 10;
            val /= 10;
        }
        return sum;
    }

public:
    int minSwaps(std::vector<int>& nums) {
        int n = nums.size();
        
        // 1. Build target array using vector sorting instead of map<int, set<int>>
        std::vector<std::pair<int, int>> pairs(n);
        for (int i = 0; i < n; i++) {
            pairs[i] = {getDigitSum(nums[i]), nums[i]};
        }
        
        std::sort(pairs.begin(), pairs.end());
        
        std::vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = pairs[i].second;
        }

        // 2. Fast O(1) hash map for position lookups
        std::unordered_map<int, int> ap;
        ap.reserve(n);
        for (int i = 0; i < n; i++) {
            ap[nums[i]] = i;
        }

        int sw = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] != nums[i]) {
                int targetIdx = ap[arr[i]];
                int currentVal = nums[i];

                // Swap in nums
                std::swap(nums[i], nums[targetIdx]);

                // O(1) updates in unordered_map
                ap[currentVal] = targetIdx;
                ap[arr[i]] = i;

                sw++;
            }
        }

        return sw;
    }
};