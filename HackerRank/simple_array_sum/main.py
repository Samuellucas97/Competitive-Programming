#!/bin/python3

from functools import total_ordering
import math
import os
import random
import re
import sys


sys.stdin = open("simple_array_sum/input.txt", "r")
sys.stdout = open("simple_array_sum/output.txt", "w")


#
# Complete the 'simpleArraySum' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY ar as parameter.
#

def simpleArraySum(ar):
    total_sum_array = 0
    for element_value in ar:
        total_sum_array += element_value 
    return total_sum_array


if __name__ == '__main__':
    ar_count = int(input().strip())

    ar = list(map(int, input().rstrip().split()))

    result = simpleArraySum(ar)

    print(str(result))
   
   