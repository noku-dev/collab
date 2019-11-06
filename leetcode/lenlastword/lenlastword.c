int lengthOfLastWord(char * s){
    int prev_count = 0, count = 0;
    while (*s != '\0') {
        if (*s == ' ') {
            if (count)
                prev_count = count;
            count = 0;
        } else {
            count++;
        }
        s++;
    }
    return (count == 0 ? prev_count : count);
}
