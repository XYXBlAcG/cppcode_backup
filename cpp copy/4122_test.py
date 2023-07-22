def factorize(n):
    if n == 1:
        return 1
    elif n == 2:
        return 1
    else:
        count = 1
        for i in range(2, n):
            if n % i == 0:
                count += factorize(n // i)
        return count
while(1):
    a = int(input("num:"))
    print(factorize(a))