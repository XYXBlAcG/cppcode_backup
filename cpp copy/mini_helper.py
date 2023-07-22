def printf(x):
    ans = []
    res = []
    cnt = 0
    i = 0
    p = 0
    while x > 0:
        ans.append(x % 2)
        x >>= 1
        cnt += 1
        i += 1
    cnt -= 1
    while cnt >= 0:
        #print(ans[cnt], end='')
        res.append(ans[cnt])
        cnt -= 1
    res = [i *10**index for index,i in enumerate(res[::-1])]
    return sum(res)
def write(x, t):
    if t == 1:
        print(x)
    elif t == 2:
        printf(x)
    else:
        print("no match function to call : write(", end='')
        print(x, end='')
        print(", ", end='')
        print(t, end='')
        print(")")
def _h(arg):
    if arg == "write":
        print("write(x, t), x = 'the things you want to print' ")
        print("t = 1, directly print out")
        print("t = 2, 10 base to 2 base")
    else:
        print("no match function to call : ", end = '')
        print(arg)
def s(string):
    return ""+str(string)+""