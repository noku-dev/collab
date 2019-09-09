A = [[1,1,0],[1,0,1],[0,0,0]]
B = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]

result = list()
for rows in B:
    flip = rows[::-1]
    invert = list(map(lambda x : int(not x), flip))
    result.append(invert)
    
print (result)
