def main():
    t = int(input())
    for i in range(t):
        k = int(input()) - 1
        x = 0
        while k > 0:
            r = k % 2
            x += r
            k = k // 2
        print(pow(2,x))
main()