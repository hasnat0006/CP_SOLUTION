import math

def solve():
    n = int(input())
    ans = math.ceil(math.log2(n))
    print(ans + 1)

if __name__ == "__main__":
    t = 1
    # t = int(input())
    for _ in range(t):
        solve()
