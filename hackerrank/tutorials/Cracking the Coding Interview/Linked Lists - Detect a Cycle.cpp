/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    int cnt = 0;
    while (head && cnt < 101) {
        head = head->next;
        cnt++;
    }
    return cnt > 100;
}
