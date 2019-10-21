class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        # check rows
        for row in board:
            numset = set()
            for col in row:
                if col == '.':
                    continue
                elif col.isdigit():
                    if col in numset:
                        return False
                    else:
                        numset.add(col)
                else:
                    return False
        
        
        # check columns
        for col in range(0, 9):
            numset = set()
            for row in board:
                letter = row[col]
                if letter == '.':
                    continue
                elif letter.isdigit():
                    if letter in numset:
                        return False
                    else:
                        numset.add(letter)
                else:
                    return False
        
        # check boxes
        for rowidx in range(0, 9):
            row = board[rowidx]
            if rowidx % 3 == 0:
                boxset = dict()
                boxset[0] = set()
                boxset[1] = set()
                boxset[2] = set()
            for colidx in range(0, 9):
                box = int(colidx / 3)
                letter = row[colidx]
                if letter == '.':
                    continue
                elif letter.isdigit():
                    if letter in boxset[box]:
                        return False
                    else:
                        boxset[box].add(letter)
                        # print(rowidx, colidx, box, letter, boxset)
                else:
                    return False
                    
        return True
