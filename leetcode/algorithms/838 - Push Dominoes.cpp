class Solution {
public:
    string pushDominoes(string dominoes) {
        const int n = dominoes.size();
        vector<int> forces(n, 0);
        int force;
        
        for (int i = 0; i < n; i++) {
            if (dominoes[i] == 'R') force = n;
            else if (dominoes[i] == 'L') force = 0;
            else force = max(force - 1, 0);
            forces[i] += force;
        }
        
        for (int i = n - 1; i >= 0; i--) {
            if (dominoes[i] == 'L') force = n;
            else if (dominoes[i] == 'R') force = 0;
            else force = max(force - 1, 0);
            forces[i] -= force;
        }
        
        for (int i = 0; i < n; i++) {
            dominoes[i] = (forces[i] > 0 ? 'R' : forces[i] < 0 ? 'L' : '.');
        }
        
        return dominoes;
    }
};