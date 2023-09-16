#include<iostream>
using namespace std;

int main(){
    int idioma,aumento=1,numero;
    string idioma="Inglés";

    do
    {
    cout<<"Ingrese el número: "<<endl;
    cin>>numero;
    } while (numero>9||numero<0);

    do
    {
    cout<<"Ingrese el aumento con el que mostrar el número: "<<endl;
    cin>>aumento;
    } while (numero>9||numero<0);

    imprimirNum(numero,aumento);


    

    return 0;
}

void imprimirNum(int num, int aum){
    char disp[5][4]; //alto=5, ancho=4
    for(int i=0;i<5;i++){
        for(int a=0;a<4;a++){//lleno la matriz de espacios vacíos
            disp[i][a]=' ';
        }
    }

    if(num!=6&&num!=5){//0,1,2,3,4,7,8,9
        disp[1][3]='|';
    }
    if(num!=2){//0,1,3,4,5,6,7,8,9
        disp[3][3]='|';
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
        disp[1][1]='-';
        disp[1][2]='-';
    }
    if (num!=0&&num!=1&&num!=7)//2,3,4,5,6,8,9
    {
        disp[1][1]='-';
        disp[1][2]='-';
    }
    if (num!=1&&num!=4&&num!=7)//0,2,3,5,6,8,9
    {
        disp[1][1]='-';
        disp[1][2]='-';
    }

    //impresion del numero
    barrasHorizontales(disp[0],aum);
    barrasVerticales(disp[1],aum);
    barrasHorizontales(disp[2],aum);
    barrasVerticales(disp[3],aum);
    barrasHorizontales(disp[4],aum);

    for(int i=0;i<aum;i++){
        cout<<disp[1][0];
    }
}

void barrasVerticales(char v[],int aumento){
    for (int i = 0; i < aumento; i++)//barras verticales
    {
        cout<<v[0];

        for(int p=0;p<aumento;p++)
        cout<<v[1]<<v[2];

        cout<<v[3]<<endl;
    }
    
    return;
}

void barrasHorizontales(char v[],int aumento){
    cout<<v[0];

    for (int i = 0; i < aumento; i++)
    {
        cout<<v[1]<<v[2];
    }
    
    cout<<v[3]<<endl;

    return;
}

void imprimirPalabra(int num){

}