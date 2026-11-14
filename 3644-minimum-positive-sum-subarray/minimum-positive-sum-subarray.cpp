class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;
        for (int size = l; size <= r; ++size) {
            int windowSum = 0;
            for (int i = 0; i < size; ++i) {
                windowSum += nums[i];
            }
            if (windowSum > 0) {
                ans = min(ans, windowSum);
            }
            for (int i = size; i < n; ++i) {
                windowSum += nums[i] - nums[i - size];

                if (windowSum > 0) {
                    ans = min(ans, windowSum);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};