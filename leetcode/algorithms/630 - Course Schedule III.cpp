class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int>& left, vector<int>& right) {
            return left[1] < right[1];
        });
        priority_queue<int> q;
        int time = 0;
        
        for (auto& c: courses) {
            if (time + c[0] <= c[1]) {
                q.push(c[0]);
                time += c[0];
            }
            else if (!q.empty() && q.top() > c[0]) {
                time += c[0] - q.top();
                q.pop();
                q.push(c[0]);
            }
        }
        
        return q.size();
    }
};