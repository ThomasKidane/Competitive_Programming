def mul(a,b,m):
    res=[[0,0],[0,0]]
    for i in range(2):
        for j in range(2):
            for k in range(2):
                res[i][k]+=(a[i][j]*b[j][k])%m
                res[i][k]=res[i][k]%m

    return res


def expo_power(a,n,m):
    res=[[1,0],[0,1]]
    while n>0:
        if n%2==1:
            res=mul(res,a,m)
        n/=2
        a=mul(a,a,m)

    return res
            



n=int(input())
k=int(input())
m=int(input())

# print(m)
v=[[0,1],
   [k-1,k-1]]
if n!=1:

    res=expo_power(v,n-2,m)
    
    # print(res)
    print(((k-1)*((res[0][0]+res[1][0])+((res[0][1]+res[1][1])*(k-1))%m)%m)%m)
else :
    print(k-1)