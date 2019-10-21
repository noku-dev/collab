bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    bool *numchk = (bool *)malloc(boardSize*sizeof(bool));
    bool *boxchk[3];
    
    // check rows
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < *boardColSize; j++) {
            numchk[j] = false;
        }
        for (int j = 0; j < *boardColSize; j++) {
            char let = board[i][j];
            if (let == '.')
                continue;
            else if (isdigit(let)) {
                int num = (int)(let - '0') - 1;
                if (numchk[num]) {
                    return false;
                } else {
                    numchk[num] = true;
                }
            } else {
                return false;
            }
        }
    }
    
    
    // check cols
    for (int j = 0; j < *boardColSize; j++) {
        for (int i = 0; i < boardSize; i++) {
            numchk[i] = false;
        }
        for (int i = 0; i < boardSize; i++) {
            char let = board[i][j];
            if (let == '.')
                continue;
            else if (isdigit(let)) {
                int num = (int)(let - '0') - 1;
                if (numchk[num]) {
                    return false;
                } else {
                    numchk[num] = true;
                }
            } else {
                return false;
            }
        }
    }
    

    // check boxes
    for (int box = 0; box < 3; box++)
        boxchk[box] = (bool *)malloc(boardSize*sizeof(bool));
    for (int i = 0; i < boardSize; i++) {
        if (i % 3 == 0) {
            for (int j = 0; j < *boardColSize; j++) {
                boxchk[0][j] = false;
                boxchk[1][j] = false;
                boxchk[2][j] = false;
            }
        }
        for (int j = 0; j < *boardColSize; j++) {
            int box = j/3;
            char let = board[i][j];
            if (let == '.')
                continue;
            else if (isdigit(let)) {
                int num = (int)(let - '0') - 1;
                if (boxchk[box][num]) {
                    return false;
                } else {
                    boxchk[box][num] = true;
                }
            } else {
                return false;
            }
        }
    }
    
    return true;
}

