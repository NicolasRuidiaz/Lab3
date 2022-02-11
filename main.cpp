#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
string leer(string nombre);
int leer(string nombre,int guia);
void escribir(string nombre, string contenido);
void escribir(string nombre, int contenido);
void agregar(string nombre, int contenido);
void agregar(string nombre, string contenido);
string string2Bin(string nombre);


string codificacion1(string nombre, int n);
string codificacion(string nombre,int semilla, int metodo);
string codificacion2(string nombre, int n);
bool iniciaradmin(string nombre,int n);
string invertir(string binario,int n,int sep);
int indicador_cod(string aux, int n);//Retorna 1,2 o 3 segun codificacion.

string deco1(string nombre,int n);
string Bin2String(string nombre);
string deco2(string nombre,int n);
string decodificacion(string nombreentrada,string nombresalida,int semilla, int metodo);

int main()
{
    int n=0;  //Valor semilla
    string textoOriginal,contradmin,usuarioadmin;
    string textoBinario;
    string textoCodificado;
    short int indice=0;
    string indicador="";
    short int metodo=0;
    do{cout<<"Desea conservar la semilla y método de codificación anterior?"<<endl<<"1.Si"<<endl<<"2.No"<<endl;
    cin>>indice;
    }while(indice<=0|| indice>=3);
    if (indice==1){
        n=leer("seed1.txt",2);
        metodo=leer("seed1.txt",1);
        decodificacion("usr.txt","usr.txt",n,metodo);
        textoOriginal=Bin2String("usr.txt");
    }
    else{
        n=leer("seed1.txt",2);
        metodo=leer("seed1.txt",1);
        decodificacion("usr.txt","usr.txt",n,metodo);
        textoOriginal=Bin2String("usr.txt");
    cout<<"Ingrese el valor semilla para la codificacion:"; cin>>n ;
    cout<<"Desea usar el metodo de codificación 1 o 2:";cin>>metodo;

    escribir("seed1.txt",metodo);
    agregar("seed1.txt",n);
    }

    short int semilladmin=0;
    semilladmin=leer("seed.txt",1);//1 metodo 2 semilla
    bool inicio=iniciaradmin("sudo.txt",semilladmin);
    if (inicio==false){
    cout<<"NO HUBO INICIO";
    }
    else{
       cout<<"Bienvenido ADMIN";
       string datos=leer("usr.txt");
       int opt=0;
       do{
           cout<<"Menú"<<endl<<"1.Ingresar usuarios nuevos"<<endl<<"2.Empezar Cajero";cin>>opt;
           if (opt==1){
               cout<<"Escribir usuarios nuevos";
               string nuevo="";
               string cc="0";
               string contrasena="0000";
               string saldo="0";
               cout<<"Ingrese la cedula nueva:"<<endl;
               cin>>cc;
               cout<<"Ingrese la contrasena"<<endl;
               cin>>contrasena;
               cout<<"Ingrese el saldo del usuario "<<endl;
               cin>>saldo;
               string separador=";";
               nuevo+=cc+separador+contrasena+separador+saldo+".";
           textoOriginal+=nuevo;
           cout<<textoOriginal<<"TXTORIGINAL PAPA"<<endl;
           escribir("usr.txt",textoOriginal);
           nuevo=string2Bin("usr.txt");
           escribir("usr.txt",nuevo);
           nuevo=codificacion("usr.txt",n,metodo);
            escribir("usr.txt",nuevo);

            //nuevo=decodificacion("usr.txt","usr.txt",n,metodo);

           //nuevo=Bin2String("usr.txt");
            //cout<<nuevo<<" ;nuevo"<<endl;
            //ERRORRR SOLUCOINAR VOYO POR AQUIII

        }
           else if(opt==2){
               cout<<"Iniciar funcion de cajero";
               string nuevo="";
               nuevo=leer("usr.txt");

           }
           else{
               cout<<"Ingrese una opcion valida";
           }
       }
       while (opt>2 || opt<1);

   }

    return 0;
}//PREGUNTAR SI GUARDAR USUARIOADMIN O BORRAR Y PEDIR NUEVO EN UN REINGRESO
//Crear archivo con el numero de semilla para no olvidar cuando el programa se cierre


string codificacion1(string nombre,int n){
    string resultado1="";
    string textoBinario = leer(nombre);//Leer el archivo binario.
    textoBinario.append("\n");//Agregar salto de linea para funcionanmiento de tamanio.//IMPORTANTE
    string aux="";
    int aux2=0;
    int tam=0;
    int indicador_codificacion;
    int tamanio=textoBinario.length()-2;//PRUEBA %%SI HAY ERROR ES POR ESTO$$ IMPORTYAANTTTTTEE
    cout<<tamanio<<"indicadortamanio"<<endl;
    int veces=0;
    if (tamanio%n==0){//prestar atencion a esto

        veces=tamanio/n;
    }
    else{// si N no es multiplo del tamanio de datos para tomar ultimos datos sin problema.
       aux2=tamanio%n;

       cout<<tamanio<<": DEBERIA SER 40"<<endl;
       //cout<<aux2<<"ESTE ES AUX 2 DEBERIA SER EL RESTO A ANADIR"<<endl;
       veces=tamanio/n+1;

    }

    cout<<veces<<":veces"<<endl;

    for(int i=0;i<veces;i++){
        aux="";

        for(int j=0;j<n;j++){//For: para trabajar por grupos de n bits
           aux+=(textoBinario[j]);
            //cout<<aux<<" :AUX ";
        }
        textoBinario=textoBinario.substr(n,tamanio);//SOLUCOINAR 5 O MAS
        cout<<textoBinario.length()<<":Largo de textobinario luego de extraer N"<<endl;
        tam=textoBinario.length();
        cout<<tam<<":tam"<<endl;
        cout<<aux<<":AUX"<<endl;
        if (i==0){
            resultado1+=invertir(aux,n,1);
            indicador_codificacion=indicador_cod(aux,n);
        }
        //PREGUNTAR INDICADOR CODIFICACION

        else if ((tam==0) && (aux2!=0)){

            aux=aux.substr(0,aux2);
            cout<<aux<<":Aqui SE ESTA IMPRIMIENDO el ultimo aux"<<endl;
            resultado1+=aux;
            resultado1+="\n";
           return resultado1;
        }

        else if (indicador_codificacion==1){//decision:0 == 1... invertir(string,n,1)
            resultado1+=invertir(aux,n,1);
            indicador_codificacion=indicador_cod(aux,n);
        }
        else if(indicador_codificacion==2){//                  0 > 1 ... invertir(string,n,2)
           resultado1+=invertir(aux,n,2);
           indicador_codificacion=indicador_cod(aux,n);
        }
        else if(indicador_codificacion==3){//0 < 1 ... invertir(string,n,3)
          resultado1+=invertir(aux,n,3);
          indicador_codificacion=indicador_cod(aux,n);
        }

    }

     resultado1.append("\n");


   return resultado1;    //retornar el resultado
}
string deco1(string nombre,int n){
    string resultado1="";
    string textoBinario = leer(nombre);//Leer el archivo binario.
    string aux="";
    int veces=0;
    int tam=0;
    int aux2=0;
    int indicador_codificacion=0;
    int tamanio=textoBinario.length()-2;//
    cout<<"esto es tamanio:"<<tamanio<<endl;
    if (tamanio%n==0){
        veces=tamanio/n;
    }
    else{
        aux2=tamanio%n;
        cout<<aux2<<"este es aux2 de DECO1"<<endl;
        veces=tamanio/n+1;
    }

     cout<<veces<<":veces"<<endl;
    for(int i=0;i<veces;i++){
        cout<<i<<"ESTO ES VECES, por aqui VA"<<endl;
        aux="";
        for(int j=0;j<n;j++){//For: para trabajar por grupos de n bits
           aux+=(textoBinario[j]);

        }
        textoBinario=textoBinario.substr(n,tamanio);

       cout<<textoBinario.length()<<"DEBERIA SER IGUAL A AUX 2 deco"<<endl;
       tam=textoBinario.length();
       cout<<tam<<":tam deco"<<endl;
       cout<<aux<<":AUX deco"<<endl;
        cout<<aux<<":AUX"<<endl;
        if (i==0){

            resultado1+=invertir(aux,n,1);
            aux=invertir(aux,n,1);

            indicador_codificacion=indicador_cod(aux,n);
        }
        else if ((tam<n) && (aux2!=0)){

            cout<<aux<<":Aqui SE ESTA IMPRIMIENDO el ultimo aux DE DECO1"<<endl;
            aux=aux.substr(0,aux2);
            resultado1+=aux;
           return resultado1;



        }
        //PREGUNTAR INDICADOR CODIFICACION


        else if (indicador_codificacion==1){//decision:0 == 1... invertir(string,n,1)

            resultado1+=invertir(aux,n,1);
            aux=invertir(aux,n,1);
            indicador_codificacion=indicador_cod(aux,n);
        }
        else if(indicador_codificacion==2){//                  0 > 1 ... invertir(string,n,2)
           resultado1+=invertir(aux,n,2);
           aux=invertir(aux,n,2);
           indicador_codificacion=indicador_cod(aux,n);
        }
        else if(indicador_codificacion==3){//0 < 1 ... invertir(string,n,3)
          resultado1+=invertir(aux,n,3);
          aux=invertir(aux,n,3);
          indicador_codificacion=indicador_cod(aux,n);
        }

    }
    resultado1=resultado1.substr(0,tamanio);//Prestar atencion a esto, debe igualar resulatado1=
   return resultado1;    //retornar el resultado
}
string codificacion2(string nombre, int n){
    string resultado2="";
    string textoBinario = leer(nombre);//Leer el archivo binario.
    textoBinario.append("\n");
    string aux="";
    string indicador_anterior="";
    string indicador_anterior2="";
    int veces =0;
    int tam=0;
    int aux2=0;

    int tamanio=textoBinario.length()-2;
    if (tamanio%n==0){
        veces=tamanio/n;
    }
    else{
        aux2=tamanio%n;
        veces=tamanio/n+1;
    }
    for(int i=0;i<veces;i++){
        aux="";
        for(int j=0;j<n;j++){//For: para trabajar por grupos de n bits
           aux+=(textoBinario[j]);
            //cout<<aux<<" :AUX ";
        }
        cout<<textoBinario<<"el error"<<endl;
        tam=textoBinario.length();
        cout<<tam<<";tam"<<endl;


        cout<<aux<<":AUX"<<endl;


        if (i==0){
            indicador_anterior=textoBinario[tamanio-1];//ultimodato
            cout<<indicador_anterior<<":Indicador anterior vez #1"<<endl;
            resultado2+=indicador_anterior;
            indicador_anterior2=aux[n-1];
            if (indicador_anterior2=="1"){
                escribir("indicadorcod.txt","1");
            }
            else{
                escribir("indicadorcod.txt","0");
            }
            aux=aux.substr(0,n-1);

            resultado2+=aux;
            cout<<aux<<"Aux deberia tener n-1 primeros bits"<<endl;

        }
        //aqui
        else if(i==veces-1 && aux2!=0){
            resultado2+=indicador_anterior;
            aux=aux.substr(0,aux2-1);
            cout<<aux<<":Aux caso especial"<<endl;
            resultado2+=aux;
            }
        else if (i!=veces-1||aux2==0){

            indicador_anterior=aux[n-1];//TOMAR ULTIMO DE AUX PARA EL SIGUIENTE
            resultado2+=indicador_anterior;

            aux=aux.substr(0,n-1);
            //resultado2+=indicador_anterior2;
            resultado2+=aux;//TOMAR ULTIMO DE AUX PARA EL SIGUIENTE

            cout<<aux<<": Aux deberia tener n-1 "<<endl;
            cout<<indicador_anterior<<": Deberia ser el ultimo digito de los grupos"<<endl;
        }

        if (tam>=n){
        textoBinario=textoBinario.substr(n,tamanio);
        }

        //Otros condicionales

    }
    resultado2.append("\n");

    return resultado2;
}
string deco2(string nombre, int n){
    string resultado2="";
    string textoBinario = leer(nombre);//Leer el archivo binario.
    string aux="";
    string indicador_anterior="";
    string indicador_ultimo="";

    int veces =0;
    int tam=0;

    int aux2=0;

    int tamanio=textoBinario.length()-2;

    if (tamanio%n==0){
        veces=tamanio/n;
    }
    else{
        aux2=tamanio%n;
        veces=tamanio/n+1;

    }
    for(int i=0;i<veces;i++){
        aux="";
        for(int j=0;j<n;j++){//For: para trabajar por grupos de n bits
           aux+=(textoBinario[j]);
            //cout<<aux<<" :AUX ";
        }

        tam=textoBinario.length();
        cout<<aux<<":AUX"<<endl;


        if (i==0){
        indicador_ultimo=aux[0];
        indicador_anterior=leer("indicadorcod.txt");
        indicador_anterior=indicador_anterior[0];
        //aux[n-1];//ultimo (error)
        //cout<<indicador_anterior<<":indicador anterior"<<endl;
        //cout<<indicador_ultimo<<":primer dato del codificado"<<endl;
        aux=aux.substr(1,n-1);
        //cout<<aux<<":aux, dos ultimos"<<endl;
        resultado2+=aux;
        resultado2+=indicador_anterior;
        }
        else if((i==veces-1) && (aux2!=0)){//caso especial final; Aux dice:si n es multiplo de tamanio es 0

            aux=aux.substr(1,aux2-1);
            //cout<<aux<<":Aux caso especial"<<endl;
            resultado2+=aux;
            //resultado2+=indicador_anterior;// aqui tala vaina

            }

        else if (i!=veces-1||aux2==0){
            indicador_anterior=aux[0];//primer dato,cout<<indicador_anterior<<":indicador anterior"<<endl;
            aux=aux.substr(1,n-1);//ultimos datos,cout<<aux<<": aux 2 ultimos de n"<<endl;
            resultado2+=aux;
            if(i!=veces-1){// en la ultima iteración se guarda uno mas, por el lógico Or
            resultado2+=indicador_anterior;
            }


        }




        if (tam>=n){
        textoBinario=textoBinario.substr(n,tamanio);
        }

    }
   resultado2+=indicador_ultimo;
    return resultado2;
}
string codificacion(string nombre,int semilla, int metodo){
    string res="";
    if (metodo==1){
        res=codificacion1(nombre,semilla);
    }
    else if (metodo==2){
        res=codificacion2(nombre,semilla);
    }
    return res;
}
string decodificacion(string nombreentrada,string nombresalida,int semilla, int metodo){
    string res="";
    if (metodo==1){
        res=deco1(nombreentrada,semilla);
    }
    else if (metodo==2){
        res=deco2(nombreentrada,semilla);
    }
    escribir(nombresalida,res);
    return res;
}
string string2Bin(string nombre){
    string textoOrig, letraBin, textoBin;
    textoOrig = leer(nombre);
    int num;

    for (unsigned int i=0; i<textoOrig.length()-1; i++){
        num = textoOrig[i];
        cout << textoOrig[i]<<" - "<< num <<endl;
        letraBin = "00000000";
        for (int j=7; j>=0; j--){
            letraBin[j]=num%2 + 48;
            num = num/2;
        }
        cout<<letraBin <<endl;

        textoBin+=letraBin;
    }
    return textoBin;
}
string Bin2String(string nombre){
    string textoOrig, textoBin;
    textoOrig = leer(nombre);
    int tamanio=textoOrig.length()-1;
    cout<<tamanio<<"TAmanNIO bin2string"<<endl;
    textoOrig=textoOrig.substr(0,tamanio);
    char letra;
    int indicador=0;
    int indicador_exp=0;
    for(int i=0;i<tamanio/8;i++){
        int aux=0;
        for(int j=7,k=0;j>=0;j--,k++){
            cout<<textoOrig[j]<<":";
            indicador_exp=pow(2,k);
            cout<<indicador_exp<<"<-Indicador expo"<<endl;
                indicador=(((textoOrig[j])-48)*indicador_exp);
            aux+=indicador;
       cout<<"Este es indicador:"<<indicador<<endl;

    }



    cout<<"este es numero:"<<aux<<endl;
    letra=aux;
    textoBin+=letra;
    textoOrig=textoOrig.substr(8,tamanio);

    cout <<textoOrig<<"orig - num: "<< aux <<":IMPORTANTE PAPA"<<endl;

}


    return textoBin;
}
void escribir(string nombre, string contenido){
    ofstream archivo;
    archivo.open(nombre);
    //cout<<archivo.tellp()<<endl;

    if(!archivo.is_open()){
        cout<<"Error abriendo el archivo"<<endl;
        exit(1);
    }
    //archivo.seekp(20);
    archivo << contenido;
    archivo.close();
}
void agregar(string nombre, int contenido){
    ofstream archivo;
    archivo.open(nombre,ios::app);
    //cout<<archivo.tellp()<<endl;

    if(!archivo.is_open()){
        cout<<"Error abriendo el archivo"<<endl;
        exit(1);
    }
    //archivo.seekp(20);
    archivo << contenido;
    archivo.close();
}
void agregar(string nombre, string contenido){
    ofstream archivo;
    archivo.open(nombre,ios::app);
    //cout<<archivo.tellp()<<endl;

    if(!archivo.is_open()){
        cout<<"Error abriendo el archivo"<<endl;
        exit(1);
    }
    //archivo.seekp(20);
    archivo << contenido;
    archivo.close();
}

void escribir(string nombre, int contenido){
    ofstream archivo;
    archivo.open(nombre);
    //cout<<archivo.tellp()<<endl;

    if(!archivo.is_open()){
        cout<<"Error abriendo el archivo"<<endl;
        exit(1);
    }
    //archivo.seekp(20);
    archivo << contenido;
    archivo.close();
}

string leer(string nombre){
    string contenido;
    string linea;
    ifstream archivo;

    archivo.open(nombre);
    if(!archivo.is_open()){
        cout<<"Error abriendo el archivo"<<endl;
        exit(1);
    }
    //archivo.seekg(48);
    while (!archivo.eof()) {
        //cout<<archivo.tellg()<<endl;
        getline(archivo,linea);
        contenido.append(linea+"\n");

    }
    archivo.close();
    return contenido;
}
int leer(string nombre,int guia){//1. Primerdigito 2. segundo digito
    int contenido;
    string linea;
    ifstream archivo;

    archivo.open(nombre);
    if(!archivo.is_open()){
        cout<<"Error abriendo el archivo"<<endl;
        exit(1);
    }
    //archivo.seekg(48);
   // while (!archivo.eof()) {
        //cout<<archivo.tellg()<<endl;
        getline(archivo,linea);
        int tam=linea.length();
        if (guia==1){
            linea=linea[0];
        }
        else if(guia==2){
            linea=linea.substr(1,tam-1);
        }
        else if(guia==3){
            contenido=stoi(linea);
            archivo.close();
            return contenido;
        }
        contenido=stoi(linea);
    archivo.close();
    return contenido;
}
string invertir(string binario,int n,int sep){
    string resultado="";
    for(int j=0;j<n;j++){//For: para trabajar por grupos de n bits
        if (sep==1){
            if (binario[j]=='0'){
                 resultado+='1';
            }
            else if (binario[j]=='1'){
            resultado+='0';
            }
        }
        else if(sep==2){
            if ((j%2)==0){
               resultado+=binario[j];
            }
            else{
                if (binario[j]=='0'){
                    resultado+='1';
                 }
                 else if (binario[j]=='1'){
                     resultado+='0';
                 }
            }
         }
        else if (sep==3){
           if (j==2){
               if (binario[j]=='0'){
                  resultado+='1';
               }
               else if (binario[j]=='1'){
                   resultado+='0';
               }
           }
           else{
              resultado+=binario[j];
           }
         }
     }
    return resultado;
}
bool iniciaradmin(string nombre,int n){//sudo

    string textoOriginal,contradmin,usuarioadmin,aux,contradmin1,usuarioadmin1,txtbn;
    textoOriginal = leer(nombre);
    int tamanio=0;//Eliminar salto de linea final, solo e tamanio
   cout<<tamanio<<"tamaniopqajaaaaa"<<endl;
    string deco;
    int semilla_anterior=0;
    int tamanioguia=textoOriginal.length();
    semilla_anterior=leer("seed.txt",3);
    cout<<tamanioguia<<endl;
    //textoOriginal=textoOriginal.substr(0,tamanio);
    if (tamanioguia<=1){//Si no hay datos en el archivo
        cout<<"Buen dia, Ingrese su nuevo usuario administrador sin espacios"<<endl;cin>>usuarioadmin;
        cout<<usuarioadmin<<":usuarioadmin"<<endl;
        //
        cout<<"Ingrese su contraseña de 6 digitos"<<endl;cin>>contradmin;
        aux.append(usuarioadmin+';'+contradmin);
        escribir(nombre,aux);
        txtbn=string2Bin(nombre);
        cout<<txtbn<<"BINARIO"<<endl;
        escribir(nombre,txtbn);
        aux=codificacion2(nombre,n);
        escribir(nombre,aux);
        cout<<aux<<"BINARIO codi"<<endl;
        //hasta aqui todo bn
        cout<<"AQUI ESTa PASANDO"<<endl;
        deco=deco2(nombre,n);
        cout<<deco<<": Deco"<<endl;

        //VERIFICACION
        escribir("binario1cod.txt",deco);
        deco=Bin2String("binario1cod.txt");
        escribir("seed.txt",n);
        cout<<deco.length()<<" usr ;123456"<<endl;
        cout<<deco<<endl;
        return true;//registro completo.


    }
    else{
        deco=deco2(nombre,semilla_anterior);
        escribir("binariodeco.txt",deco);
        deco=Bin2String("binariodeco.txt");
        tamanio=deco.length();
        cout<<deco<<": Decodificado"<<endl;
        usuarioadmin=deco.substr(0,tamanio-7);
        cout<<usuarioadmin<<": usrer"<<endl;
        contradmin=deco.substr(tamanio-6,tamanio);
        cout<<contradmin<<"; contraadmin"<<endl;

        cout<<"Ingrese el usuario Administrador: ";cin>>usuarioadmin1;
        if(usuarioadmin==usuarioadmin1){
              cout<<"Ingrese su contraseña: ";cin>>contradmin1;
              if(contradmin==contradmin1){//contraseña de admin 6 digitos, se debe separar con cualquier caracter la contraseña de el adminnistrador
              return true;
              }
        }
    }
    /*deco=deco1(nombre,semilla_anterior);

    cout<<deco.length()<<";Largo"<<endl;//agregar para no tener problemas con tamanio de los datos
    escribir("deco.txt",deco);
    deco=Bin2String("deco.txt");
    cout<<deco<<": deco"<<endl;

    tamanio=deco.length();
    usuarioadmin1=deco.substr(0,tamanio-7);
    cout<<usuarioadmin1<<" usuarioadmin1"<<endl;
     contradmin1=deco.substr(tamanio-6,tamanio);
    cout<<contradmin1<<" contraadmin1"<<endl;
    cout<<"Ingrese el usuario Administrador: ";cin>>usuarioadmin;
    if(usuarioadmin==usuarioadmin1){
          cout<<"Ingrese su contraseña: ";cin>>contradmin;
          if(contradmin==contradmin1){//contraseña de admin 6 digitos, se debe separar con cualquier caracter la contraseña de el adminnistrador
          return true;
          }
    }*/
    return false;
}
int indicador_cod(string aux,int n){
    int c=0;//Contador del ciclo while
    int conta0=0;
    int conta1=0;
    while (c<n){
        if(aux[c]=='0'){
            conta0+=1;
        }
        else if(aux[c]=='1'){
            conta1+=1;
        }
        ++c;
    }//      contar 0 y 1.
    int indicador_codificacion=0;
    if(conta0==conta1){
        indicador_codificacion=1;
    }
    else if(conta0>conta1){//                  0 > 1 ... invertir(string,n,2)
       indicador_codificacion=2;
    }
    else if(conta0<conta1){//0 < 1 ... invertir(string,n,3)
     indicador_codificacion=3;
    }
    return indicador_codificacion;
}
