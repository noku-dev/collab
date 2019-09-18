# brute force
words = ["GEEKS", "FOR", "QUIZ", "GO"]
boggle = [['G', 'I', 'Z'], ['U', 'E', 'K'], ['Q', 'S', 'E']]

def nextLetter(letter, curRow, curCol):
    prevRow = max(0, curRow - 1)
    nextRow = min (2, curRow + 1)
    prevCol = max(0, curCol - 1)
    nextCol = min(2, curCol + 1)
    for row in range(prevRow, nextRow + 1):
        for col in range(prevCol, nextCol + 1):
            if row == curRow and col == curCol:
                pass
            elif letter == boggle[row][col]:
                return True, row, col
    return False, curRow, curCol

for row in range(len(boggle)):
    for i in range(len(boggle[row])):
        matches = [x for x in words if x[0] == boggle[row][i]]
        for checkWord in matches:
            curRow = row
            curCol = i
            j = 1
            while j < len(checkWord):
                found, curRow, curCol = nextLetter(checkWord[j], curRow, curCol)
                if not found:
                    break
                j += 1
            if j == len(checkWord):
                print (checkWord)
print ("done")
