def gaussSqr(n):
    return n*(n+1)*(2*n+1)//6

def gauss(n):
    return n*(n+1)//2

def main():
    mod = 2147483647
    t = int(input())
    for cs in range(t):
        n = int(input())
        ans = ((n+1)*gauss(n) - gaussSqr(n) + mod) % mod
        print(ans)

main()