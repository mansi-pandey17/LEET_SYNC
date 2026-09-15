class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> result = new ArrayList<>();
        int n = nums.length;
        if (n < 4) return result;

        Arrays.sort(nums);

        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if ((long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if ((long) nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                if ((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if ((long) nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;

                int left = j + 1;
                int right = n - 1;
                long twoSumTarget = (long) target - nums[i] - nums[j];

                while (left < right) {
                    long sum = (long) nums[left] + nums[right];
                    if (sum < twoSumTarget) {
                        left++;
                    } else if (sum > twoSumTarget) {
                        right--;
                    } else {
                        result.add(Arrays.asList(nums[i], nums[j], nums[left], nums[right]));
                        int leftVal = nums[left];
                        int rightVal = nums[right];
                        while (left < right && nums[left] == leftVal) left++;
                        while (left < right && nums[right] == rightVal) right--;
                    }
                }
            }
        }

        return result;
    }
}