class Solution {
public:
    string addStrings(string num1, string num2) {
        string sum = "";
        int i = num1.size()-1, j = num2.size()-1, remainder = 0;
        while(remainder != 0 || i >= 0 || j >= 0) {
            int temp = remainder;
            if (i >= 0)
                temp += charToInt(num1[i--]);
            if (j >= 0)
                temp += charToInt(num2[j--]);
            sum += intToChar(temp%10);
            remainder = temp/10;
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
    
    int charToInt(char c) {
        return c-'0';
    }
    
    char intToChar(int x) {
        return (char) x + '0';
    }
};