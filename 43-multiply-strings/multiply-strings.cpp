class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0"; // Handle edge case
        
        int n = num1.size(), m = num2.size();
        vector<int> result(n + m, 0); // Initialize a result array
        
        // Multiply each digit of num1 with each digit of num2
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0'); // Multiply digits
                int sum = mul + result[i + j + 1]; // Add to current position
                
                result[i + j + 1] = sum % 10; // Set the current position
                result[i + j] += sum / 10;   // Carry to the next position
            }
        }
        
        // Convert result vector to a string, skipping leading zeros
        string product = "";
        for (int num : result) {
            if (!(product.empty() && num == 0)) { // Skip leading zeros
                product += to_string(num);
            }
        }
        
        return product.empty() ? "0" : product; // Return the final product
    }
};
