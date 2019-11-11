#!/bin/python

import math
import os
import random
import re
import sys

# Complete the makeAnagram function below.
def makeAnagram(a, b):
    count = 0
    for i in a:
        if i in b:
            b = b.replace(i, '', 1)
        else:
            count += 1
    count += len(b)
    return count

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    a = raw_input()

    b = raw_input()

    res = makeAnagram(a, b)

    fptr.write(str(res) + '\n')

    fptr.close()
