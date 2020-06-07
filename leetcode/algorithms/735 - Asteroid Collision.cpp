class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        bool destroyed;
        
        for (auto& ast: asteroids) {
            destroyed = false;
            
            while (!res.empty() && ast < 0 && res.back() > 0) {
                if (res.back() < -ast) {
                    res.pop_back();
                }
                else if (res.back() == -ast) {
                    destroyed = true;
                    res.pop_back();
                    break;
                }
                else {
                    destroyed = true;
                    break;
                }
            }
            
            if (!destroyed) {
                res.push_back(ast);
            }
        }
        
        return res;
    }
};