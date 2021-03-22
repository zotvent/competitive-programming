class Solution {
    const string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const string url = "http://tinyurl.com/";
    const int base = (int) alphabet.size();
    long long count = 1;
    unordered_map<string, string> m;
    
    string next() {
        string res = "";
        long long c = count;
        
        while (c > 0) {
            res.push_back(c % base);
            c /= base;
        }
        
        return res;
    }
    
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string key = next();
        m[key] = longUrl;
        count++;
        return url + key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl.substr((int) url.size())];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));