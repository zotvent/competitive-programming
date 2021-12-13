/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
    
    int findMaxDepth(vector<NestedInteger>& list) {
        int maxDepth = 1;
        
        for (NestedInteger i: list) {
            if (!i.isInteger()) {
                maxDepth = max(maxDepth, 1 + findMaxDepth(i.getList()));
            }
        }
        
        return maxDepth;
    }
    
    int weightedSum(vector<NestedInteger>& list, int depth, int maxDepth) {
        int sum = 0;
        
        for (NestedInteger i: list) {
            if (i.isInteger()) {
                sum += i.getInteger() * (maxDepth - depth + 1);
            }
            else {
                sum += weightedSum(i.getList(), depth + 1, maxDepth);
            }
        }
        
        return sum;
    }
    
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int maxDepth = findMaxDepth(nestedList);
        return weightedSum(nestedList, 1, maxDepth);
    }
};