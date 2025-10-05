class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector<bool> prime(n+1, true);   
        if (n <= 1) return 0;            
        prime[0] = prime[1] = false;

        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                cnt++;
                for (long long j = 1LL * 2 * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }
        return cnt;
    }
};
