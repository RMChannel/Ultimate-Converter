#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int system(const char *command);

int intpow(int a, int b) {
    int result=1;
    if (b!=0) {
        for (int i=0;i<b;i++) {
            result=result*a;
        }
    }
    else {
        a=1;
    }
    return result;
}


void binadd(char *numchar, int n) {
    while ((strlen(numchar)%n)>0) {
        for (int i=strlen(numchar); i>=0; i--) {
            numchar[(i+1)]=numchar[i];
        }
        numchar[0]='0';
    }
}


int bintooctal(char *numchar) {
    int result=0, i2=0, i3=0;
    for (int i=strlen(numchar)-1; i>=0; i--) {
        if (i2==3) {
            i2=0;
            i3++;
        }
        if (numchar[i]=='1') {
            result=(result+(intpow(2,i2))*(intpow(10,i3)));
        }
        i2++;
    }
    return result;
}


void octaltobin(int numint, char *numchar) {
    const char octalconvert[9][4] = {"000","001","010","011","100","101","110","111"};
    long int temp=0;
    while (numint>0) {
        temp=numint%10;
        for (int i=0;i<3;i++) {
            numchar[i]=octalconvert[temp][i];
        }
        numint=numint/10;
        printf("%d %d\n", temp, numint);
        if (numint>0) {
            for (int i=strlen(numchar); i>=0; i--) {
                numchar[(i+3)]=numchar[i];
            }
        }
    }
}


void inttobin(int numint, char *numchar) {
    while (numint>0) {
        int temp=numint%2;
        for (int i=strlen(numchar); i>=0; i--) {
            numchar[(i+1)]=numchar[i];
        }
        if (temp==1) {
            numchar[0]='1';
        }
        else {
            numchar[0]='0';
        }
        numint/=2;
    }
}


int bintoint(char *numchar) {
    int result=0;
    int i2=strlen(numchar)-1;
    for (int i=0;i<strlen(numchar);i++) {
        if (numchar[i]=='1') {
            result=result+(intpow(2,i2));
        }
        i2--;
    }
    return result;
}


int inttooct(int numint) {
    int result=0;
    int i=0;
    while (numint>0) {
        int temp=(numint%8)*(intpow(10,i));
        result=result+temp;
        numint=numint/8;
        i++;
    }
    return result;
}

int octtoint(int numint) {
    int i=0,result=0;
    while (numint>0) {
        int temp=(numint%10)*(intpow(8,i));
        result=result+temp;
        numint=numint/10;
        i++;
    }
    return result;
}


void inttoesa(int numint, char *numchar) {
    const char esaover[2][16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    while (numint>0) {
       int temp=numint%16;
       for (int i=strlen(numchar); i>=0; i--) {
           numchar[(i+1)]=numchar[i];
       }
       numchar[0]=esaover[0][temp];
       numint=numint/16;
    }   
}


void bintoesa(char *numchar) {
    const char esaover[2][16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    char temp[1000];
    temp[0]='\0';
    for (int i=0;i<strlen(numchar);i++) printf("%c",numchar[i]);
    int result=0, i2=0, i3=0, i4=0;
    for (int i=strlen(numchar)-1; i>=0; i--) {
        if (numchar[i]=='1') result=result+(intpow(2,i2));
        if (i2==3) {
            temp[i4]=esaover[0][result];
            result=0;
            i2=-1;
            i4++;
        }
        i2++;
    }
    memset(numchar,0,1000);
    i2=0;
    for (int i=strlen(temp)-1; i>=0; i--) {
        numchar[i2]=temp[i];
        i2++;
    }
}


int main(void) {
    system("cls");
    char numchar[1000];
    numchar[0]='\0';
    int firstbase, secondbase, result;
    long int numint;
    const char listofconvert[4][12] = {"Ottale","Binario","Decimale","Esadecimale"};
    printf("Benvenuto in Ultimate Converter V1.3\nScegli la base del numero iniziale:\n[1]Ottale\n[2]Binario\n[3]Decimale\n[4]Esadecimale\n");
    scanf("%d",&firstbase);
    printf("Scegli la base in cui covertire il numero:\n");
    for (int i=1; i<5; i++) {if (i!=firstbase) {printf("[%d]%s\n", i, listofconvert[(i-1)]);}}
    scanf("%d",&secondbase);
    switch(firstbase) {
        case 1:
            printf("Insersci il numero in ottale: ");
            scanf("%ld",&numint);
            break;
        case 2:
            printf("Insersci il numero in binario (massimo 999 cifre): ");
            scanf("%s",&numchar);
            break;
        case 3:
            printf("Inserisci un numero intero: ");
            scanf("%ld",&numint);
            break;
        case 4:
            printf("Inserisci il numero in esadecimale: ");
            scanf("%s",&numchar);
            break;
    }
    if (firstbase==1) {
        switch(secondbase) {
            case 2:
                octaltobin(numint,numchar);
                printf("Result= ");
                for (int i=0;i<strlen(numchar);i++) {
                    printf("%c",numchar[i]);
                }
                break;
            case 3:
                result=octtoint(numint);
                printf("Result= %d",result);
                break;
            case 4:
                break;    
        }
    }
    else if (firstbase==2) {
        switch(secondbase) {
            case 1:
                binadd(numchar,3);
                result=bintooctal(numchar);
                printf("Result= %d", result);
                break;
            case 3:
                result=bintoint(numchar);
                printf("Result= %d",result);
                break;
            case 4:
                binadd(numchar,4);
                bintoesa(numchar);
                printf("Result= ");
                for (int i=0;i<strlen(numchar);i++) {
                    printf("%c",numchar[i]);
                }
                break;    
        }
    }
    else if (firstbase==3) {
        switch(secondbase) {
            case 1:
                result=inttooct(numint);
                printf("Result= %d",result);
                break;
            case 2:
                inttobin(numint,numchar);
                printf("Result= ");
                for (int i=0;i<strlen(numchar);i++) {
                    printf("%c",numchar[i]);
                }
                break;
            case 4:
                inttoesa(numint,numchar);
                printf("Result= ");
                for (int i=0;i<strlen(numchar);i++) {
                    printf("%c",numchar[i]);
                }
                break;    
        }
    }
    else if (firstbase==4) {
        switch(secondbase) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;        
        }
    }
}