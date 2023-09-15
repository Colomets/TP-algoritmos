#include<iostream>
#include<cstring>
#include<cctype>
#include<cstdio>

using namespace std;

bool esRepetido(char revisar[], char letra,int l);
int ahorcado();
bool descubrir(bool v[],int top);

int main(){
    int p=ahorcado();

    return 0;
}

int ahorcado(){
    int errores=0, puntos=100, k=0,tl;
    
    const int a=6,b=7;
    char muneco[a][b]{{' ','_','_','_',' ',' ',' '},{'|',' ',' ',' ',' ',' ',' '},{'|',' ',' ',' ',' ',' ',' '},{'|',' ',' ',' ',' ',' ',' '},{'|',' ',' ',' ',' ',' ',' '},{'-','-','-','-','-','-','-'}};
    
    bool descubierto=false,mostrar[20],r;
    char adivina='a';
    
    string palabra="palabra";//ingresar la palabra desde el archivo

    for(int q=0;q<b;q++){
        mostrar[q]=false;
    }
    
    tl=palabra.size();
    
    char escritas[tl];
    for(int q=0;q<tl;q++){
        escritas[q]=' ';
    }

    while(errores<6 && !descubierto){
        
        for(int i=0;i<a;i++)
        {//dibuja el munieco
            cout<<"             ";
            for(int q=0;q<b;q++){
                cout<<muneco[i][q];
            }
            cout<<endl;
        }

        cout<<"             ";
        
        for(int i=0;i<tl;i++)//muestra la palabra o espacios de letra segun si estan descubiertos o no
        {
            if(mostrar[i]){
                cout<<palabra[i]<<" ";
            }else{
                cout<<"_ ";
            }
        }
        cout<<endl;

        do{//permite ingresar unicamente una letra
            if (!isalpha(adivina))
            {
                cout<<"¡Ese caracter no es una letra!"<<endl;//mensaje de error
            }

            cout<<"Ingrese una letra a adivinar: "<<endl;
            cin>>adivina;
        }while(!isalpha(adivina) || esRepetido(escritas,adivina,k));
        
        adivina=tolower(adivina);//las letras siempre seran minusculas
        
        if (palabra.find(adivina)==-1)
        {
        //si la letra no está en la palabra, aumentan los errores y se dibuja el muñeco
            
            errores++;
            switch(errores)
            {
            case 1:
                muneco[1][3]='o';//cabeza
                puntos-=10;
                break;
            case 2:
                muneco[2][3]='H';//cuerpo
                puntos-=10;
                break;
            case 3:
                muneco[2][2]='/';//brazo izquierdo
                puntos-=10;
                break;
            case 4:
                muneco[2][4]='\\';//brazo derecho
                puntos-=10;
                break;
            case 5:
                muneco[3][2]='/';//pierna izquierda
                puntos-=10;
                break;
            case 6:
                muneco[3][4]='\\';//pierna derecha
                puntos=0;
                break;
            }
        }else
        {
            for(int i=0;i<tl;i++)//revela las letras adivinadas de la palabra
            {
                if(adivina==palabra[i])
                {
                    mostrar[i]=true;
                }
            }
        }
        escritas[k++]=adivina;//almacena las letras escritas
        descubierto=descubrir(mostrar,tl);
    }//fin del programa

        for(int i=0;i<a;i++)
        {//dibuja el munieco
            cout<<"             ";
            for(int q=0;q<b;q++){
                cout<<muneco[i][q];
            }
            cout<<endl;
        }
        
        cout<<"             ";
        
        for(int i=0;i<tl;i++)//muestra la palabra
        {
            cout<<palabra[i]<<" ";

        }
    if (errores==6)
    {
        cout<<endl<<"Perdiste!"<<endl;
    }else if(descubierto){
        cout<<endl<<"Ganaste!"<<endl;
    }
    
    return puntos;//devuelve los puntos para sumar al puntaje del jugador
}
bool esRepetido(char revisar[], char letra,int l){//devuelve si la letra ya fue escrita
    bool reply=false;

    for(int i=0;i<l;i++)
    {
        if (revisar[i]==letra)
        {
            reply=true;
        }
    }

    if(reply){
        cout<<"¡Ya ingresaste esa letra!"<<endl;
    }

    return reply;
}
bool descubrir(bool v[],int top){
    bool a=true;
    for(int i=0;i<top;i++){
        a=a&&v[i-1]&&v[i];
    }
    return a;
}