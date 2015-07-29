class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        // write your code here
         
        int result = -1;
        int i = 0;
        int j = -1;
        if (source == nullptr || target == nullptr) {
            return result;
        }
        if ( *target == '\0')
            return i;
        while (*source !='\0') {
            ++j;
            if(*source == *target) {
                i = j;
                const char *p = source;
                const char *q = target;
            while (*p == *q) {
                if (*(q+1) =='\0') {
                    return i;
                }
                p++;
                q++;
                }
            }
            ++source;
                ++i;
        }
        return result;
    }
};
