import sys
input = sys.stdin.readline
import math
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    gcd = 0
    lcm = 1
    for i in range(n-1,-1,-1):
        print(i, a[i])
        gcd = math.gcd(gcd, a[i])
        lcm = math.lcm(lcm, a[i] // gcd)
    print(lcm)