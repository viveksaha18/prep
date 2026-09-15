class Solution {
  public:
    int setBits(int n) {
        int cnt = 0;
        while(n > 0) {
            if((n&1) != 0) {
                cnt = cnt + 1;
            }
            n = n >> 1;
        }
        return cnt;
    }
};
