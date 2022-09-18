import sys

sys.stdin = open("compare_the_triplets/input.txt", "r")
sys.stdout = open("compare_the_triplets/output.txt", "w")


#
# Complete the 'compareTriplets' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER_ARRAY a
#  2. INTEGER_ARRAY b
#

def compareTriplets(a, b):
    scores = [0,0]
    
    for (element_a, element_b) in zip(a, b):
        if element_a > element_b:
            scores[0] += 1
        elif element_b > element_a:
            scores[1] += 1

    return scores


if __name__ == '__main__':
    a = list(map(int, input().rstrip().split()))

    b = list(map(int, input().rstrip().split()))

    result = compareTriplets(a, b)

    print(' '.join(map(str, result)))
    print('\n')