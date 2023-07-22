summ = 0
sum2 = 0
for i in range(1, 5):
    for j in range(1, 5):
        print(i,' ', end='')
        print(j,' ', end='')
        print(i^j)
        summ += i^j
print("sum = ", summ)
def gcd(a ,b):
    if(b == 0):
        return a
    else:
        return gcd(b, a % b)
for i in range(1, 5):
    for j in range(1, 5):
        t1 = i ^ j
        gc = gcd(t1, summ)
        print(i, j, end = ' ')
        print(t1 // gc, end = ' ')
        print('/', end = ' ')
        print(summ // gc)
        sum2 += (i + j) * t1 / summ
print("sum2 = ", sum2)
