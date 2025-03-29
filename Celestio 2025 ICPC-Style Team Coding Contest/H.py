a,b=map(int,input().split())
if a==0 and b==0:
    print(0)
else:
    if a%2 != b%2:
        print(-1)
    else:
        if a>b:
            print(-1)
        elif a==b:
            print(1)
            print(a)
        else:
            x=(b-a)//2
            y=x
            z=b-2*x
            if (z+x)^y == a:
                print(2)
                print(x,z+x)
            else:
                print(3)
                print(x,y,z)
