class Solution {
  public:
    int setKthBit(int n, int k) {
        // Code here
        if(n & (1 << k) == 1) return n;
        n = n | (1 << k);
        return n;
    }
};