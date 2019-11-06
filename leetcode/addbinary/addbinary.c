char * addBinary(char * a, char * b){
    int lena = strlen(a);
    int lenb = strlen(b);
    char *aptr = a + lena - 1;
    char *bptr = b + lenb - 1;
    char *result = NULL;
    int maxresult = (lena > lenb ? lena : lenb) + 2;
    int carry = 0;
    result = malloc(sizeof(char)*maxresult);
    
    result[maxresult - 1] = '\0';
    maxresult--;
    while (aptr >= a || bptr >= b) {
        char s[2] = {'\0'};
        int val = 0;
        if (aptr >= a) {
            s[0] = *aptr;
            val += atoi(s);
            aptr--;
        }
        if (bptr >= b) {
            s[0] = *bptr;
            val += atoi(s);
            bptr--;
        }
        if (carry) {
            val++;
            carry = 0;
        }
        if (val > 1) {
            carry = 1;
            val -= 2;
        }
        result[maxresult - 1] = val == 0 ? '0' : '1';
        maxresult--;
    }
    if (carry) {
        result[maxresult - 1] = '1';
    } else
        result++;
    
    return result;
    
}
