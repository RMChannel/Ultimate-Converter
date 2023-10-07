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
    int result=0, i2=0, i3=0, a=0;
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


int main(void) {
    system("cls");
    char numchar[1000];
    numchar[0]='\0';
    int firstbase, secondbase, result;
    long int numint;
    const char listofconvert[4][10] = {"Ottale","Binario","Decimale"};
    printf("Benvenuto in Ultimate Converter V1.2\nScegli la base del numero iniziale:\n[1]Ottale\n[2]Binario\n[3]Decimale\n");
    scanf("%d",&firstbase);
    printf("Scegli la base in cui covertire il numero:\n");
    for (int i=1; i<4; i++) {if (i!=firstbase) {printf("[%d]%s\n", i, listofconvert[(i-1)]);}}
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
            scanf("%ld", &numint);
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
        }
    }
}