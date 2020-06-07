class SnakeGame {
private:
    int width;
    int height;
    vector<vector<int>> food;
    pair<int, int> head;
    int score;
    deque<pair<int, int>> snake;
    set<pair<int, int>> body;
    
    bool validMove() {
        if (head.first < 0 || head.second < 0 || head.first >= height || head.second >= width) {
            return false;
        }
        
        if (body.count(head) > 0 && head != snake.back()) {
            return false;
        }
        
        return true;
    }
    
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        this->width = width;
        this->height = height;
        this->food = food;
        head = {0, 0};
        score = 0;
        snake.push_back(head);
        body.insert(head);
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        if (direction == "U") head.first--;
        else if (direction == "L") head.second--;
        else if (direction == "R") head.second++;
        else head.first++;
        
        if (!validMove()) {
            return -1;
        }
        
        if (score < food.size() && food[score][0] == head.first && food[score][1] == head.second) {
            body.insert(head);
            snake.push_front(head);
            score++;
        }
        else {
            body.erase(snake.back());
            snake.pop_back();
            body.insert(head);
            snake.push_front(head);
        }
        
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */