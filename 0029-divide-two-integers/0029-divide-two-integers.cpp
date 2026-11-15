class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Convert to long long because abs(INT_MIN)
        // cannot be stored in an int
        long long a = dividend;
        long long b = divisor;

        // Determine sign of answer
        bool negative = (a < 0) ^ (b < 0);

        a = abs(a);
        b = abs(b);

        long long quotient = 0;

        while (a >= b) {

            long long temp = b;
            long long multiple = 1;

            // Find the largest power-of-2 multiple of divisor
            while ((temp << 1) <= a) {
                temp <<= 1;
                multiple <<= 1;
            }

            // Subtract that multiple
            a -= temp;

            // Add its contribution to quotient
            quotient += multiple;
        }

        if (negative)
            quotient = -quotient;

        // 32-bit limits
        if (quotient > INT_MAX)
            return INT_MAX;

        if (quotient < INT_MIN)
            return INT_MIN;

        return (int)quotient;
    }
};