class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int numberOfBytesToProcess = 0;
        
        int mask1 = (1 << 7);
        int mask2 = (1 << 6);
        int mask;
        
        for (int i = 0; i < data.size(); i++) {
            if (numberOfBytesToProcess == 0) {
                mask = mask1;
                
                while ((mask & data[i]) != 0) {
                    numberOfBytesToProcess++;
                    mask >>= 1;
                }
                
                if (numberOfBytesToProcess == 0) {
                    continue;
                }
                
                if (numberOfBytesToProcess > 4 || numberOfBytesToProcess == 1) {
                    return false;
                }
            }
            else {
                if (!((data[i] & mask1) != 0 && (data[i] & mask2) == 0)) {
                    return false;
                }
            }
            
            numberOfBytesToProcess--;
        }
        
        return numberOfBytesToProcess == 0;
    }
};