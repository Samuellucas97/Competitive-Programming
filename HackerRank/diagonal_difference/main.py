#!/bin/python3


import sys

sys.stdin = open("diagonal_difference/input.txt", "r")
sys.stdout = open("diagonal_difference/output.txt", "w")

#
# Complete the 'diagonalDifference' function below.
#
# The function is expected to return an INTEGER.
# The function accepts 2D_INTEGER_ARRAY arr as parameter.
#

def diagonalDifference(arr):
    total_left=total_right=0
    counter_left=0
    counter_right=len(arr)-1

    for row in arr:
        total_left += row[counter_left]
        counter_left+=1

        total_right += row[counter_right]
        counter_right-=1

    return abs(total_left - total_right)

if __name__ == '__main__':
    n = int(input().strip())

    arr = []

    for _ in range(n):
        arr.append(list(map(int, input().rstrip().split())))

    result = diagonalDifference(arr)

    print(str(result) + '\n')

