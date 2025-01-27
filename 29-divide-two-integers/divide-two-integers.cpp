class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle edge cases for overflow
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; // Overflow case
        }
        if (dividend == INT_MIN && divisor == 1) {
            return INT_MIN; // No overflow case
        }

        // Determine the sign of the result
        bool isNegative = (dividend < 0) ^ (divisor < 0);

        // Work with positive values
        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);

        int result = 0;

        // Subtract the divisor multiplied by powers of 2 from the dividend
        while (absDividend >= absDivisor) {
            long long temp = absDivisor;
            long long multiple = 1;

            // Find the largest multiple of the divisor that fits into the dividend
            while (absDividend >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            absDividend -= temp;
            result += multiple;
        }

        // Apply the sign
        return isNegative ? -result : result;
    }
};
