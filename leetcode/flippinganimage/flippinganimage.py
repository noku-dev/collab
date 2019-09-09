
result = list()
for rows in B:
    flip = rows[::-1]
    invert = list(map(lambda x : int(not x), flip))
    result.append(invert)
    
print (result)
