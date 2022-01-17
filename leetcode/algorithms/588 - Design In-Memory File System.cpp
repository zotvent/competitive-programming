class FileSystem {
    
    struct Node {        
        bool isFile;
        string content;
        unordered_map<string, Node*> children;
        
        Node(bool isFile) {
            this->isFile = isFile;
        }
    };
    
    Node* root;
    
    vector<string> split(string path) {
        vector<string> res;
        string cur = "";
        
        for (auto& i: path) {
            if (i == '/') {
                if (!cur.empty()) {
                    res.push_back(cur);
                }
                cur.clear();
            }
            else cur.push_back(i);
        }
        
        if (!cur.empty()) {
            res.push_back(cur);
        }
        
        return res;
    }
    
    Node* traverse(string path) {
        vector<string> folders = split(path);
        Node* cur = root;
        
        for (auto& i: folders) {
            if (!cur->children.count(i)) {
                cur->children[i] = new Node(false);
            }
            cur = cur->children[i];
        }
        
        return cur;
    }
    
public:
    FileSystem() {
        root = new Node(false);
    }
    
    vector<string> ls(string path) {
        vector<string> folders = split(path);
        Node* cur = traverse(path);
        vector<string> res;
        
        if (cur->isFile) {
            res.push_back(folders.back());
        }
        else {
            for (auto& i: cur->children) {
                res.push_back(i.first);
            }
            sort(res.begin(), res.end());
        }
        
        return res;
    }
    
    void mkdir(string path) {
        Node* cur = traverse(path);
    }
    
    void addContentToFile(string filePath, string content) {
        Node* cur = traverse(filePath);
        cur->isFile = true;
        cur->content += content;
    }
    
    string readContentFromFile(string filePath) {
        Node* cur = traverse(filePath);
        return cur->content;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */