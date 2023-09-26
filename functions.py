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
esabin={
    "0":"0000",
    "1":"0001",
    "2":"0010",
    "3":"0011",
    "4":"0100",
    "5":"0101",
    "6":"0110",
    "7":"0111",
    "8":"1000",
    "9":"1001",
    "A":"1010",
    "B":"1011",
    "C":"1100",
    "D":"1101",
    "E":"1110",
    "F":"1111",
}
esachar=["0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"]
def insertoctal():
    octalnum=["8","9"]
    go=True
    while go:
        n=input()
        if (octalnum[0] in n) or (octalnum[1] in n) or (n==""): print("Numero ottale non corretto, riprovare")
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
            if (i in n) or (n==""):
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

def insertesa():
    lowchar=["a","b","c","d","e","f"]
    go=True
    while go:
        n=input()
        for i in n:
            if i in lowchar: n=n.replace(i,esachar[(lowchar.index(i))+10])
            if not(i in esachar) or (n==""):
                print("Numero non corretto, riprovare")
                go=True
                break
            else:
                go=False
    return n

def binseparator(n, bin):
    result=[]
    temp=""
    i=0
    while (len(bin)%n)!=0:
        bin="0"+bin
    for c in bin:
        if i!=n:
            temp=temp+c
            i+=1
        else:
            result.append(temp)
            temp=c
            i=1
    result.append(temp)
    return result


def octaltobin(num):
    result=""
    for i in num: result=result+octalbin[i]
    return result

def bintooctal(num):
    num=binseparator(3,num)
    result=""
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

def octaltodec(num):
    l=len(num)-1
    result=0
    for i in num:
        if l>0:
            result=result+(pow(8,l)*int(i))
            l-=1
        else: result=result+int(i)
    return str(result)

def dectooctal(num):
    num=int(num)
    result=""
    while num>0:
        result=str(num%8)+result
        num=int(num/8)
    return result

def bintoexa(num):
    result=""
    num=binseparator(4,num)
    for i in num:
        i2=0
        while True:
            if i2>9: i3=esachar[i2]
            else: i3=i2
            if i==esabin[str(i3)]:
                result=result+str(i3)
                break
            else: i2+=1
    return result

def exatobin(num):
    result=""
    for i in num: result=result+esabin[i]
    return result

def dectoexa(num):
    num=int(num)
    result=""
    while True:
        result=esachar[int(num%16)]+result
        if ((int(num/16))==0): break
        num=num/16
    return result

def exatodec(num):
    result=0
    for i in num: result=(result*16)+esachar.index(i)
    return str(result)

def octtoexa(num):
    num=octaltobin(num)
    num=bintoexa(num)
    return num

def exatooct(num):
    num=exatobin(num)
    num=bintooctal(num)
    return num