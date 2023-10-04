#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int system(const char *command);

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
            result=(result+(pow(2,i2))*(pow(10,i3)));
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

int main(void) {
    system("cls");
    char numchar[1000];
    int firstbase, secondbase;
    long int numint;
    const char listofconvert[3][7] = {"Ottale","Binario"};
    printf("Benvenuto in Ultimate Converter V1.0\nScegli la base del numero iniziale:\n[1]Ottale\n[2]Binario\n");
    scanf("%d",&firstbase);
    printf("Scegli la base in cui covertire il numero:\n");
    for (int i=1; i<3; i++) {if (i!=firstbase) {printf("[%d]%s\n", i, listofconvert[(i-1)]);}}
    scanf("%d",&secondbase);
    switch(firstbase) {
        case 1: {
            printf("Insersci il numero in ottale: ");
            scanf("%ld",&numint);
            break;
        }
        case 2: {
            printf("Insersci il numero in binario (massimo 999 cifre): ");
            scanf("%s",&numchar);
            break;
        }
    }
    if (firstbase==1) {
        switch(secondbase) {
            case 2:
                octaltobin(numint,numchar);
                printf("Result=");
                for (int i=0;i<strlen(numchar);i++) {
                    printf("%c",numchar[i]);
                }
            break;
        }
    }
    else if (firstbase==2) {
        switch(secondbase) {
            case 1:
                binadd(numchar,3);
                int result=bintooctal(numchar);
                printf("Result=%d", result);
            break;
        }
    }
}