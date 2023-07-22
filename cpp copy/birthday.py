n = 365
for i in range(1, 366):
    ans = 1
    for j in range(0, i):
        ans *= (n - j) / n
    print("when i = ", i, ", ans = " , ans)
