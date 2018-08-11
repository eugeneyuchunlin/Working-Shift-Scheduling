import os
def boring(name):
    result=[]
    print(name)
    lenth=len(name)-1
    if lenth!=0:
        for i in range(len(name)-1):
            a=name[i+1]-name[i]
            if a<0:
                a=(-1)*a
            result.append(a)
        ans = boring(result)
    else:
        return name[0]
    return ans
        
os.system("pause")
name=[9,7,12,8,20,8]
num=boring(name)
print(num)

'''
a=float(input("First Number = "))
b=float(input("Second Number = "))
print("{} + {} = {}".format(a,b,round(a+b,3)))
'''
