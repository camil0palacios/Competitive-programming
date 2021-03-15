def main():
    n, k = map(int, input().split())
    if k == 0:
        print(1)
        return 
    dp = [[0] * 2 for i in range(n + 1)]
    ps = [0 for i in range(n + 1)]
    dp[0][0] = dp[0][1] = 1
    ps[0] = 1
    ps[1] = ps[0] + 1
    for i in range(1, n):
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1]
        ps[i + 1] = ps[i] + dp[i][0]
        s = i - k
        if s >= 0:
            dp[i][1] = ps[i] - ps[s]
        else:
            dp[i][1] = ps[i]
    print(dp[n - 1][0] + dp[n - 1][1])

main()