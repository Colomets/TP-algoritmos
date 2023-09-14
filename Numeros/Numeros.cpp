#include<iostream>
using namespace std;

int main(){
    int idioma,aumento,numero;
    

    return 0;
}

void imprimirNum(int num, int aum){
    char disp[5][6]; //alto=5, ancho=6
    for(int i=0;i<5;i++){
        for(int a=0;a<6;a++){//lleno la matriz de espacios vacíos
            disp[i][a]=' ';
        }
    }
    if(num!=6&&num!=5){//0,1,2,3,4,7,8,9
        disp[1][5]='|';
    }
    if(num!=2){//0,1,3,4,5,6,7,8,9
        disp[3][5]='|';
    }
    if (num!=1&&num!=2&&num!=3&&num!=7)//0,4,5,6,8,9
    {
        disp[1][0]='|';
    }
    if (num==0||num==2||num==6||num==8)//0,2,6,8
    {
        disp[3][0]='|';
    }
    if (num!=4&&num!=1)//0,2,3,5,6,7,8,9
    {
        /* code */
    }
    
    
    


    for(int i=0;i<aum;i++){
        cout<<disp[1][0];
    }
}