for _ in range(int(input())):
    a,b=map(int,input().split())
    k=input()
    s=[]
    for ele in k:
        s.append(ele)
    flag=True
    p1=0
    p2=len(s)-1
    a-=s.count('0')
    b-=s.count('1')
    while(p1<=p2):
        if a<0 or b<0:
            flag=False
            break
        if p1 == p2:
            if s[p1] == '1' and  s[p2] == '1':
                pass
            if s[p1] == '0' and  s[p2] == '0':
                pass
            if s[p1] == '1' and  s[p2] == '0':
                flag=False
                break
            if s[p1] == '0' and  s[p2] == '1':
                flag=False
                break
            if s[p1] == '1' and  s[p2] == '?':
                if b<=0:
                    flag=False
                    break
                else:
                    s[p2]='1'
                    b-=2
            if s[p1] == '?' and  s[p2] == '1':
                if b<=0:
                    flag=False
                    break
                else:
                    s[p1]='1'
                    b-=2
            if s[p1] == '0' and  s[p2] == '?':
                if a<=0:
                    flag=False
                    break
                else:
                    s[p2]='0'
                    a-=2
            if s[p1] == '?' and  s[p2] == '0':
                if a<=0:
                    flag=False
                    break
                else:
                    s[p1]='0'
                    a-=2
            if s[p1] == '?' and  s[p2] == '?':
                if a<0 or b<0:
                    flag=False
                    break
                if a in [0] and b in [0]:
                    flag=False
                    break
                if a==max(a,b):
                    s[p1]='0'
                    s[p2]='0'
                    a-=1

                else:
                    s[p1]='1'
                    s[p2]='1'
                    b-=1
        else:
            if s[p1] == '1' and  s[p2] == '1':
                pass
            if s[p1] == '0' and  s[p2] == '0':
                pass
            if s[p1] == '1' and  s[p2] == '0':
                flag=False
                break
            if s[p1] == '0' and  s[p2] == '1':
                flag=False
                break
            if s[p1] == '1' and  s[p2] == '?':
                if b<=0:
                    flag=False
                    break
                else:
                    s[p2]='1'
                    b-=1
            if s[p1] == '?' and  s[p2] == '1':
                if b<=0:
                    flag=False
                    break
                else:
                    s[p1]='1'
                    b-=1
            if s[p1] == '0' and  s[p2] == '?':
                if a<=0:
                    flag=False
                    break
                else:
                    s[p2]='0'
                    a-=1
            if s[p1] == '?' and  s[p2] == '0':
                if a<=0:
                    flag=False
                    break
                else:
                    s[p1]='0'
                    a-=1
            if s[p1] == '?' and  s[p2] == '?':
                if a<0 or b<0:
                    flag=False
                    break
                if a in [0,1] and b in [0,1]:
                    flag=False
                    break
                if a==max(a,b):
                    s[p1]='0'
                    s[p2]='0'
                    a-=2

                else:
                    s[p1]='1'
                    s[p2]='1'
                    b-=2
            
        p1+=1
        p2-=1
    if flag:
        print("".join(s))
    else:
        print(-1)
        

            






    
















































