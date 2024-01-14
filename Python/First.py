A =6
B = "Barry"
A = str(A)
print(B+A)
d = 8
e = 16
g = d**e
print(g)
M = [1,5,2,8,6,3]
E = []
O = []
for i in M:
    if(i%2 == 0):
        E.append(i)
    else:
        O.append(i)

print(E,'\n',O)
C= 1+3j
print(type(C))