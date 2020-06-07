class MyHashSet {
private:
    struct Node {
        int val;
        Node* next;

        Node(int val) {
            this->val = val;
            next = NULL;
        }
    };

    vector<Node*> bucket;
    int keyRange;

    int hash(int key) {
        return key % keyRange;
    }

public:
    /** Initialize your data structure here. */
    MyHashSet() {
        keyRange = 769;
        bucket.resize(keyRange);
        for (int i = 0; i < keyRange; i++) {
            bucket[i] = new Node(-1);
        }
    }

    void add(int key) {
        Node* prev = bucket[hash(key)];
        Node* root = prev->next;

        while (root) {
            if (root->val == key) {
                return;
            }
            prev = root;
            root = root->next;
        }

        prev->next = new Node(key);
    }

    void remove(int key) {
        Node* prev = bucket[hash(key)];
        Node* root = prev->next;

        while (root) {
            if (root->val == key) {
                prev->next = root->next;
                root->next = NULL;
                root = NULL;
                return;
            }

            prev = root;
            root = root->next;
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        Node* root = bucket[hash(key)];

        while (root) {
            if (root->val == key) {
                return true;
            }
            root = root->next;
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */