import sys

sys.stdin = open("very_big_sum/input.txt", "r")
sys.stdout = open("very_big_sum/output.txt", "w")


#
# Complete the 'aVeryBigSum' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts LONG_INTEGER_ARRAY ar as parameter.
#

def aVeryBigSum(ar):
    total=0
    for arrayElement in ar:
        total += arrayElement
    return total

if __name__ == '__main__':
    ar_count = int(input().strip())

    ar = list(map(int, input().rstrip().split()))

    result = aVeryBigSum(ar)

    print((str(result) + '\n'))
    print('\n')