/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int copiedChars = 0;
        int readChars = 4;
        
        while (copiedChars < n && readChars == 4) {
            readChars = read4(buf + copiedChars);
            copiedChars += readChars;
        }
        
        return min(n, copiedChars);
    }
};