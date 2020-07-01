class Solution {
    
    bool validIpV4(string ip) {
        int dots = 0;
        int part = 0;
        bool foundLeadingZero = false;
        int cnt = 0;
        
        for (int i = 0; i < ip.size(); i++) {
            if (isdigit(ip[i])) {
                if (cnt == 0 && ip[i] == '0') {
                    foundLeadingZero = true;
                }
                else if (cnt > 0 && foundLeadingZero) {
                    return false;
                }
                
                part = part * 10 + ip[i] - '0';
                cnt++;
                
                if (part > 255) {
                    return false;
                }
            }
            else if (ip[i] == '.') {
                dots++;
                
                if (part < 0 || part > 255 || cnt == 0) {
                    return false;
                }
                
                part = 0;
                foundLeadingZero = false;
                cnt = 0;
            }
            else {
                return false;
            }
        }
        
        return dots == 3 && part >= 0 && part < 256 && cnt > 0;
    }
    
    bool validIpV6(string ip) {
        int colon = 0;
        string part = "";
        
        for (int i = 0; i < ip.size(); i++) {
            if (isdigit(ip[i])) {
                part.push_back(ip[i]);
            }
            else if (isalpha(ip[i])) {
                if (tolower(ip[i]) < 'a' || tolower(ip[i]) > 'f') {
                    return false;
                }
                
                part.push_back(ip[i]);
                
                if (part.size() > 4) {
                    return false;
                }
            }
            else if (ip[i] == ':') {
                colon++;
                
                if (part.empty() || part.size() > 4) {
                    return false;
                }
                
                part.clear();
            }
            else {
                return false;
            }
        }
        
        return colon == 7 && !part.empty() && part.size() < 5;
    }
    
public:
    string validIPAddress(string IP) {
        if (validIpV4(IP)) {
            return "IPv4";
        }
        else if (validIpV6(IP)) {
            return "IPv6";
        }
        
        return "Neither";
    }
};