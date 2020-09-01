
def check(n):
    return (3*n*n + n) // 2

def main():
    h = int(input())
    while check(h) % 4 != 0:
        h += 1
    print(h)

main()