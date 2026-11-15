class Solution {
public:
    const long long MOD = 1000000007;

    long long modPow(long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) result = (result * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return result;
    }

    int countGoodNumbers(long long n){
        long long evenPositions = (n + 1) / 2; // ceil(n/2)
        long long oddPositions  = n / 2;       // floor(n/2)
        long long ans = (modPow(5, evenPositions) * modPow(4, oddPositions)) % MOD;
        return (int)ans;

    }
};