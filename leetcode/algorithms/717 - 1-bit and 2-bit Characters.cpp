class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int last = 1;
        for (int i = 0; i < bits.size(); i++) 
            if (bits[i] == 1) {
                last = 2;
                i++;
            }
            else
                last = 1;
        return last == 1;
    }
};