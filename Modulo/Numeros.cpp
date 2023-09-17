#include<iostream>
#include<stdlib.h>
#include<cctype>
#include<windows.h>
using namespace std;

void imprimirNum(int num, int aum);
void barrasVerticales(char v[],int aumento);
void barrasHorizontales(char v[],int aumento);
void imprimirPalabra(int num,int lang);

int main(){
    int idioma,aumento=1,numero=1;
    bool repetir;
    char guardia;
	//1=español,2=inglés,3=italiano,4=portugués,5=francés
	do{
		
		do
		{
			cout<<"Ingrese un numero de 0 a 9: "<<endl;
			
			cin>>guardia;
            if(!isdigit(guardia)){
                cout<<"Ese no es un numero..."<<endl;   
            }else
            {
                numero=guardia-'0';
            }
		
			if(numero>9||numero<0)
			{
				cout<<"El numero ingresado no esta en el rango!"<<endl;
			}
		
		} while (numero>9 || numero<0 && !isdigit(guardia));

		do
		{
			cout<<"Ingrese un aumento de 1 a 4 con el que mostrar el numero: "<<endl;
			cin>>guardia;

            if(!isdigit(guardia)){
                cout<<"Ese no es un numero..."<<endl;   
            }else
            {
                aumento=guardia-'0';
            }

            if(aumento>4 || aumento<1)
                cout<<"¡Ese numero no esta entre"<<endl;
		
		} while (aumento>4 || aumento<1 && !isdigit(guardia));

		do
		{
			cout<<"En que idioma desea mostrarlo? \n[1]-Espanol\n[2]-Ingles\n[3]-Italiano\n[4]-Portugues\n[5]-Frances\n\n"<<endl;
			cin>>guardia;

            if(!isdigit(guardia)){
                cout<<"Ese no es un numero..."<<endl;   
            }else
            {
                idioma=guardia-'0';
            }

			if(idioma>5||idioma<1)
				cout<<"¡Esa no es una de las opciones!";

		} while (idioma>5 || aumento<1 && !isdigit(guardia));

		imprimirPalabra(numero,idioma);
		imprimirNum(numero,aumento);
		
		do{
			cout<<"     Desea ver otro numero?\n     [1]-Si\n     [2]-No\n"<<endl;
			cin>>guardia;

            if(!isdigit(guardia)){
                cout<<"Ese no es ni siquiera un numero..."<<endl;
                idioma=guardia;
            }else
            {
                idioma=guardia-'0';
            }

            if(idioma!=1 && idioma!=2){
                cout<<"Esa no es una de las opciones"<<endl;
            }


		}while(idioma!=1 && idioma!=2 && !isdigit(guardia));
		
		if(idioma==2)
		{
			repetir=false;
		}
		else
		{
			repetir=true;
		}
		system("cls");
	}while(repetir);
	
    return 0;
}

void imprimirNum(int num, int aum){
    char disp[5][4]; //alto=5, ancho=4
    
    for(int i=0;i<5;i++)
    {
        for(int a=0;a<4;a++)//lleno la matriz de espacios vacíos
        {
            disp[i][a]=' ';
        }
    }

    if(num!=6&&num!=5)//en adelante define el dibujo del numero
    {
        disp[1][3]='|';
    }
    if(num!=2)
    {
        disp[3][3]='|';
    }
    if (num!=1&&num!=2&&num!=3&&num!=7)
    {
        disp[1][0]='|';
    }
    if (num==0||num==2||num==6||num==8)
    {
        disp[3][0]='|';
    }
    if (num!=4&&num!=1)
    {
        disp[0][1]='-';
        disp[0][2]='-';
    }
    if (num!=0&&num!=1&&num!=7)
    {
        disp[2][1]='-';
        disp[2][2]='-';
    }
    if (num!=1&&num!=4&&num!=7)
    {
        disp[4][1]='-';
        disp[4][2]='-';
    }

    //impresion del numero
    barrasHorizontales(disp[0],aum);
    barrasVerticales(disp[1],aum);
    barrasHorizontales(disp[2],aum);
    barrasVerticales(disp[3],aum);
    barrasHorizontales(disp[4],aum);

}

void barrasVerticales(char v[],int aumento){
    
    for (int i = 0; i < aumento; i++)
    {
        cout<<"    "<<v[0];

        for(int p=0;p<aumento;p++)
        {
            cout<<v[1]<<v[2];
        }

        cout<<v[3]<<endl;
    }
    
    return;
}

void barrasHorizontales(char v[],int aumento){
	cout<<"    "<<v[0];

    for (int i = 0; i < aumento; i++)
    {
        cout<<v[1]<<v[2];
    }
    
    cout<<v[3]<<endl;

    return;
}

void imprimirPalabra(int num,int lang){//

    string espanol[]={"Cero", "Uno", "Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete", "Ocho", "Nueve"};
    string ingles[]={"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    string italiano[]={"Zero", "Uno", "Due", "Tre", "Quattro", "Cinque", "Sei", "Sette", "Otto", "Nove"};
    string portugues[]={"Zero", "Um", "Dois", "Tres", "Quatro", "Cinco", "Seis", "Sete", "Oito", "Nove"};
    string frances[]={"Zero", "Un", "Deux", "Trois", "Quatre", "Cinq", "Six", "Sept", "Huit", "Neuf"};
    
    cout<<"Forma escrita en ";
    switch (lang)
    {
    case 1:
        cout<<"espanol: "<<espanol[num]<<endl;
        break;
    
    case 2:
        cout<<"ingles: "<<ingles[num]<<endl;
        break;
    
    case 3:
        cout<<"italiano: "<<italiano[num]<<endl;
        break;
    
    case 4:
        cout<<"portugues: "<<portugues[num]<<endl;
        break;
    
    case 5:
        cout<<"frances: "<<frances[num]<<endl;
        break;
    }
    return;
}