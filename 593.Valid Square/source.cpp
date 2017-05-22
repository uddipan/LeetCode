class Solution {
 public:
  int Length(vector<int>& p1, vector<int>& p2) {
    int x = p1[0] - p2[0], y = p1[1] - p2[1];
    return (x * x + y * y);
  }

  int Angle(vector<int>& p1, vector<int>& p2, vector<int>& p3) {
    int x = (p3[0] - p2[0]) * (p1[0] - p2[0]);
    int y = (p3[1] - p2[1]) * (p1[1] - p2[1]);
    return x + y;
  }

  bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3,
                   vector<int>& p4) {
    int L2 = Length(p1, p2), L3 = Length(p1, p3), L4 = Length(p1, p4);
    if (L2 == L3 && L2 == L4 && L3 == L4) return false;
    // 1-4 diagonal
    if (L2 == L3) {
      if (Angle(p2, p1, p3) != 0) return false;
      if (Length(p2, p4) != L2 || Length(p3, p4) != L2) return false;
    }
    // 1-3 diagonal
    else if (L2 == L4) {
      if (Angle(p2, p1, p4) != 0) return false;
      if (Length(p2, p3) != L2 || Length(p3, p4) != L2) return false;
    }
    // 1-2 diagonal
    else if (L3 == L4) {
      if (Angle(p3, p1, p4) != 0) return false;
      if (Length(p2, p4) != L3 || Length(p3, p2) != L3) return false;
    } else {
      return false;
    }
    return true;
  }
};
