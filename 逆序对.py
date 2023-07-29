n = int(input())
mlist = list(map(int,input().split()))
li = [0]*100
res = 0
for i in range(n):
    li[mlist[i]] += 1
    res += sum(li[mlist[i]+1:])
print(res)