#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int system(const char *command);
const char esaover[2][16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

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
    char temp[1000];
    memset(temp,0,1000);
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


void esatobin(char *numchar) {
    const char esabin[16][5]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111"};
    char temp[1000];
    memset(temp,0,1000);
    int i5=0;
    for (int i2=0;i2<strlen(numchar);i2++) {
        int i3=0;
        while (numchar[i2]!=esaover[0][i3]) i3++;
        for (int i4=0;i4<4;i4++) {
            temp[i5]=esabin[i3][i4];
            i5++;
        }
    }
    memset(numchar,0,1000);
    for (int i=0;i<strlen(temp);i++) numchar[i]=temp[i];
}


int esatoint(char *numchar) {
    int result=0;
    for (int i=0;i<strlen(numchar);i++) {
        int i2=0;
        while (numchar[i]!=esaover[0][i2]) i2++;
        result=(result*16)+i2;
    }
    return result;
}


int main(void) {
    int firstbase, secondbase, result, go=1, comandcorrect;
    long int numint;
    while (go) {
        char numchar[1000];
        memset(numchar,0,1000);
        system("cls");
        printf("Benvenuto in Ultimate Converter V2.0\nScegli la base del numero iniziale:\n[1]Ottale\n[2]Binario\n[3]Decimale\n[4]Esadecimale\n");
        scanf("%d",&firstbase);
        switch(firstbase) {
            case 1:
                printf("Insersci il numero in ottale: ");
                scanf("%ld",&numint);
                octaltobin(numint,numchar);
                printf("Binario= ");
                for (int i=0;i<strlen(numchar);i++) printf("%c",numchar[i]);
                printf("\nDecimale= %d\n",octtoint(numint));
                binadd(numchar,4);
                bintoesa(numchar);
                printf("Esadecimale= ");
                for (int i=0;i<strlen(numchar);i++) printf("%c",numchar[i]);
                break;
            case 2:
                printf("Insersci il numero in binario (massimo 999 cifre): ");
                scanf("%s",&numchar);
                binadd(numchar,3);
                printf("Ottale= %d\n",bintooctal(numchar));
                printf("Decimale= %d\n",bintoint(numchar));
                binadd(numchar,4);
                bintoesa(numchar);
                printf("Esadecimale= ");
                for (int i=0;i<strlen(numchar);i++) printf("%c",numchar[i]);
                break;
            case 3:
                printf("Inserisci un numero intero: ");
                scanf("%ld",&numint);
                printf("Ottale= %d\n",inttooct(numint));
                inttobin(numint,numchar);
                printf("Binario= ");
                for (int i=0;i<strlen(numchar);i++) printf("%c",numchar[i]);
                memset(numchar,0,1000);
                inttoesa(numint,numchar);
                printf("\nEsadecimale= ");
                for (int i=0;i<strlen(numchar);i++) printf("%c",numchar[i]);
                break;
            case 4:
                printf("Inserisci il numero in esadecimale: ");
                scanf("%s",&numchar);
                esatobin(numchar);
                printf("Ottale= %d\n",bintooctal(numchar));
                printf("Binario= ");
                for (int i=0;i<strlen(numchar);i++) printf("%c",numchar[i]);
                printf("\nDecimale= %d",bintoint(numchar));
                break;
            default:
                printf("Comando non corretto, riprovare.\n");
                system("pause");
                break;
        }
        printf("\nVuoi ripetere il programma?\n[1]Si'\n[2]No\n");
        scanf("%d",&comandcorrect);
        if (comandcorrect!=1) go=0;
    }
}