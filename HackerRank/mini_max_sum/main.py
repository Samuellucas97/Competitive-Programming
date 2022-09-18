#!/bin/python3

import sys

sys.stdin = open("mini_max_sum/input.txt", "r")
sys.stdout = open("mini_max_sum/output.txt", "w")

#
# Complete the 'miniMaxSum' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def miniMaxSum(arr):
    arr.sort()
    max_value = arr[0] + arr[1] + arr[2] + arr[3]
    
    arr.sort(reverse=True)
    min_value = arr[0] + arr[1] + arr[2] + arr[3]
    print(f'{max_value} {min_value}') 


if __name__ == '__main__':

    arr = list(map(int, input().rstrip().split()))

    miniMaxSum(arr)
