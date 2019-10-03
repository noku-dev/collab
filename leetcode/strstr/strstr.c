int strStr(char * haystack, char * needle){
    int needLen = strlen(needle);
    int hayLen = strlen(haystack);
    
    if (needLen == 0)
        return 0;
    if (hayLen == 0)
        return -1;
    
    for (int i = 0; i < (hayLen - needLen) + 1; i++) {
        if (haystack[i] == needle[0]) {
            int j = 1;
            while (haystack[i + j] == needle[j] && j < needLen) {
                j++;
            }
            if (j == needLen)
                return i;
        }
    }
    return -1;
}
