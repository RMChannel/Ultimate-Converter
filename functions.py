numbers="1234567890"
octalbin={
    "0":"000",
    "1":"001",
    "2":"010",
    "3":"011",
    "4":"100",
    "5":"101",
    "6":"110",
    "7":"111"
}
def insertoctal():
    octalnum=["8","9"]
    go=True
    while go:
        n=input()
        if (octalnum[0] in n) or (octalnum[1] in n): print("Numero ottale non corretto, riprovare")
        else:
            try:
                int(n)
                go=False
            except ValueError:
                print("Caratteri non riconosciuti, riprovare")
                go=True
    return n

def insertbin():
    binnum=["2","3","4","5","6","7","8","9"]
    go=True
    while go:
        n=input()
        for i in binnum:
            if i in n:
                print("Numero non corretto, riprovare")
                go=True
                break
            elif (i=="9"): return n

def insertnum():
    go=True
    while go:
        n=input()
        try:
            int(n)
            go=False
        except ValueError:
            print("Caratteri non riconosciuti, riprovare")
            go=True
    return n

def binseparator(n, bin):
    result=[]
    temp=""
    i=0
    for c in bin:
        if i!=n:
            temp=temp+c
            i+=1
        else:
            result.append(temp)
            temp=c
            i=0
    result.append(temp)
    return result


def octaltobin(num):
    result=""
    for i in num: result=result+octalbin[i]
    return result

def bintooctal(num):
    result=""
    while (len(num)%3)!=0:
        num="0"+num
    num=binseparator(3,num)
    for i in num:
        i2=0
        while True:
            if i==octalbin[str(i2)]:
                result=result+str(i2)
                break
            else: i2+=1
    return result

def bintodec(num):
    result=0
    num2=""
    for i in num: num2=i+num2
    i2=0
    for i in num2:
        if i=="1": result=result+pow(2,i2)
        i2+=1
    return str(result)

def dectobin(num):
    result=""
    num=int(num)
    while num!=1:
        result=str(num%2)+result
        num=int(num/2)
    return "1"+result