#!/bin/python3

import math
import os
import random
import re
import sys

sys.stdin = open("find_median/input.txt", "r")
sys.stdout = open("find_median/output.txt", "w")

#
# Complete the 'findMedian' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def findMedian(arr):
    arr.sort()
    media_position = 0
    div_part_media_position=math.floor(len(arr)/2)
    mod_part_media_position=(len(arr) % 2) 
    media_position = div_part_media_position + mod_part_media_position 
    return arr[media_position-1] 

if __name__ == '__main__':
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    result = findMedian(arr)

    print(str(result) + '\n')
