import cmath as cm
while 1:
    up = float(input("up:"))
    down = float(input("down:"))
    # n = float(input("num:"))
    n = up / down
    # print(3 ** n + (n - 2) / (n + 1))
    # print(n - 2 * cm.log10(1 / cm.sqrt(n)))
    # print(cm.log(n) + 2 * n - 6)
    # a = float(8 / 33)
    print(cm.log(n, 0.5) + 1 / (2 * n) - 17 / 2)
    # print(a * (n ** 3) - 2 * a * n + a - 1 / 8)