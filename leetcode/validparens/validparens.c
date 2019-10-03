bool isValid(char * s){
    int i = 0;
    for (int j = 0; j < strlen(s); j++) {
        switch (s[j]) {
            case '(':
            case '{':
            case '[':
                if (i != j)
                    s[i] = s[j];
                i++;
                // printf ("open %d, %d, %c\n", i, j, s[i]);
            break;
        
            case ')':
                // printf ("close paren %d, %d, %c\n", i, j, s[i]);
                if (i == 0)
                  return false;
                if (s[i - 1] != '(')
                    return false;
                i--;
            break;

            case '}':
                // printf ("close braces %d, %d, %c\n", i, j, s[i]);
                if (i == 0)
                    return false;
                if (s[i - 1] != '{')
                    return false;
                i--;
            break;

            case ']':
                // printf ("close brackets %d, %d, %c\n", i, j, s[i]);
                if (i == 0)
                    return false;
                if (s[i - 1] != '[')
                    return false;
                i--;
            break;
                
            default:
                // printf("default\n");
                return false;
        }
    }
    // printf("end, i is %d\n", i);
    
    if (i != 0)
        return false;
    return true;
}
