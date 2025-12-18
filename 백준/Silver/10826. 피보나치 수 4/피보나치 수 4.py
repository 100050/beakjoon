a, b, c = 0, 1, 1

n = int(input())

if n == 0:
    print(0)
elif n == 1:
    print(1)
else:
    for i in range(1, n):
        c = a + b
        a = b
        b = c
        
    print(c)