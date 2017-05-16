class Solution {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    // sort the array and compare indices
    if (nums.size() == 0) return 0;
    vector<int> s(nums);
    sort(s.begin(), s.end());
    int start = s.size(), end = 0;
    for (int u = 0; u < s.size(); u++) {
      if (s[u] != nums[u]) {
        start = min(start, u);
        end = max(end, u);
      }
    }
    if (end < start) return 0;
    return (end - start + 1);
  }
};
