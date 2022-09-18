#!/bin/python3

import sys


sys.stdin = open("time_conversion/input.txt", "r")
sys.stdout = open("time_conversion/output.txt", "w")


#
# Complete the 'timeConversion' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def timeConversion(s):
    periodic_time=s[8:10]
    hour=s[0:2]

    if int(hour) == 12:
        if periodic_time == "AM":
            hour="00"
        else:
            hour="12"
    else:
        if periodic_time != "AM":
          hour = str(int(hour) + 12)

    return hour + s[2:8]


if __name__ == '__main__':

    s = input()

    result = timeConversion(s)

    print(result + '\n')
