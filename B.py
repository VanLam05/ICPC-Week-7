MOD = 10**9 + 7

def solve():
    n = int(input())
    res = [[0] * (n + 1) for _ in range(n + 1)]

    res[1][1] = 1
    for i in range(2, n + 1):
        for j in range(1, i + 1):
            res[i][j] = res[i - 1][j] * j + res[i - 1][j - 1]

    ans = sum(res[n][1:n+1])
    print(ans)

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
