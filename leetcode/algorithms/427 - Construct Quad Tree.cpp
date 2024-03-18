/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {

    Node* calc(vector<vector<int>>& grid, int topRow, int rightCol, int bottomRow, int leftCol) {
        int val = grid[topRow][leftCol];
        bool isLeaf = true;
        for (int r = topRow; r <= bottomRow; r++) {
            for (int c = leftCol; c <= rightCol; c++) {
                if (grid[r][c] != val) {
                    isLeaf = false;
                    break;
                }
            }
            if (!isLeaf) break;
        }
        if (isLeaf) {
            Node* node = new Node(val, true);
            return node;
        }
        Node* node = new Node(val, false);
        int midRow = topRow + (bottomRow - topRow) / 2;
        int midCol = leftCol + (rightCol - leftCol) / 2;
        node->topLeft = calc(grid, topRow, midCol, midRow, leftCol);
        node->topRight = calc(grid, topRow, rightCol, midRow, midCol + 1);
        node->bottomLeft = calc(grid, midRow + 1, midCol, bottomRow, leftCol);
        node->bottomRight = calc(grid, midRow + 1, rightCol, bottomRow, midCol + 1);
        return node;
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        const int rows = grid.size();
        const int cols = grid[0].size();
        return calc(grid, 0, cols - 1, rows - 1, 0);
    }
};
