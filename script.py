import os
import functions
numbers="1234567890"
listofconvert={
    1:"Ottale",
    2:"Binario",
    3:"Decimale"
}
while True:
    go=True
    #Funzione del menu e controllo del dato inserito
    while go:
        firstbase=input("Benvenuto in Ultimate Converter V1.1\nScegli la base del numero iniziale:\n[1]Ottale\n[2]Binario\n[3]Decimale\n")
        if (firstbase in numbers):
            if not(int(firstbase) in listofconvert):
                print("Carattere non riconosciuto, rirpovare")
                os.system("pause")
                os.system("cls")
            else:
                go=False
                firstbase=int(firstbase)
        else:
            print("Carattere non riconosciuto, rirpovare")
            os.system("pause")
            os.system("cls")

    #Scelta della base in cui covertire il numero con contro9llo      
    message="Scegli la base in cui covertire il numero:"
    i=1
    while i<4:
        if i!=firstbase: message=message+"\n["+str(i)+"]"+listofconvert[i]
        i+=1
    go=True
    while go:
        secondbase=input(message+"\n")
        if (secondbase in numbers):
            if (not(int(secondbase) in listofconvert) or (int(secondbase)==firstbase)):
                print("Carattere non riconosciuto, rirpovare")
                os.system("pause")
                os.system("cls")
            else:
                go=False
                secondbase=int(secondbase)
        else:
            print("Carattere non riconosciuto, rirpovare")
            os.system("pause")
            os.system("cls")

    #Inserimento 1°valore
    if firstbase==1:
        print("Inserisci il numero in ottale")
        num=functions.insertoctal()
    elif firstbase==2:
        print("Inserisci il numero in binario")
        num=functions.insertbin()
    elif firstbase==3:
        print("Inserisci un numero decimale")
        num=functions.insertnum()
    #Switch della funzione
    #OTTALE A BINARIO E VICEVERSA
    if (firstbase==1 and secondbase==2): result=functions.octaltobin(num)
    elif (firstbase==2 and secondbase==1): result=functions.bintooctal(num)
    #DECIMALE A BINARIO E VICEVERSA
    elif (firstbase==3 and secondbase==2): result=functions.dectobin(num)
    elif (firstbase==2 and secondbase==3): result=functions.bintodec(num)
    #Stampa del risultato
    choice=input("Il risultato è: "+result+"\nVuoi ricominciare?\n[1]Sì\n[Altro]No\n")
    if choice!="1": exit()
    else: os.system("cls")