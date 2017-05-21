class Solution {
 public:
  int findLHS(vector<int>& nums) {
    map<int, int> M;
    for (auto n : nums) {
      if (M.find(n) == M.end()) {
        M[n] = 0;
      }
      M[n]++;
    }
    if (M.size() < 2) return 0;
    auto it = M.begin(), itn = next(it, 1);
    int ret = 0;
    // Remember that the subsuquence will have consecutive min/max elements
    while (itn != M.end()) {
      if (itn->first - it->first == 1) ret = max(ret, it->second + itn->second);
      it++;
      itn++;
    }
    return ret;
  }
};
