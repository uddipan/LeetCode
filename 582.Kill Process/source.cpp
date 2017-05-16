class Solution {
 public:
  vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
    unordered_map<int, vector<int>> children;
    for (unsigned u = 0; u < pid.size(); u++) {
      if (children.find(ppid[u]) == children.end()) {
        children[ppid[u]] = vector<int>();
      }
      children[ppid[u]].push_back(pid[u]);
    }
    // BFS on parent process
    vector<int> ret;
    queue<int> Q;
    Q.push(kill);
    while (!Q.empty()) {
      int fr = Q.front();
      Q.pop();
      ret.push_back(fr);
      if (children.find(fr) != children.end()) {
        auto ch = children[fr];
        for (auto i : ch) Q.push(i);
      }
    }
    return ret;
  }
};
