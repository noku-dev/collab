#!/bin/python

import math
import os
import random
import re
import sys

# Complete the countSwaps function below.
def countSwaps(a):
    swaps = 0
    alen = len(a)
    for i in range (0, alen):
        for j in range (0, alen - 1):
            # Swap adjacent elements if they are in decreasing order
            if a[j] > a[j + 1]:
                tmp = a[j]
                a[j] = a[j + 1]
                a[j + 1] = tmp
                swaps += 1
        
    print("Array is sorted in %d swaps." %(swaps))
    print("First Element: %d" %(a[0]))
    print("Last Element: %d" %(a[alen - 1]))


if __name__ == '__main__':
    n = int(raw_input())

    a = map(int, raw_input().rstrip().split())

    countSwaps(a)
