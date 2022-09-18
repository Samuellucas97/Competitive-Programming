#!/bin/python3

import sys

sys.stdin = open("plus_minus/input.txt", "r")
sys.stdout = open("plus_minus/output.txt", "w")

#
# Complete the 'plusMinus' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def plusMinus(arr):
    ratio_positive=ratio_negative=ratio_zero=0
    number_positive=number_negative=number_zero=0
    
    for element in arr:
        if element == 0:
            number_zero += 1
        elif (element > 0):
            number_positive += 1
        else:
            number_negative += 1
    
    arr_length = len(arr)
    print('%.6f' % (number_positive / float(arr_length )) )
    print('%.6f' % ( number_negative / float(arr_length )) )
    print('%.6f' % ( number_zero / float(arr_length )) )
    
if __name__ == '__main__':
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    plusMinus(arr)
