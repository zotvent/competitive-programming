class Solution {
public:
    bool judgeCircle(string moves) {
        int move[4] = {0};
        for (int i = 0; i < moves.length(); i++) 
            move[indexOf(moves[i])]++;
        
        if (move[0] == move[1] && move[2] == move[3])
            return true;
        else 
            return false;
    }
    
    int indexOf(char c) {
        if (c == 'R')
            return 0;
        else if (c == 'L') 
            return 1;
        else if (c == 'U')
            return 2;
        else 
            return 3;
    }
};