// Trabajo Final C++ 2022
// Quiniela Instantanea con apuestas : 4 CIFRAS , A LA CABEZA Y CORRIDA DE 20 PUESTOS, 3 CIFRAS Y 2 CIFRAS , SOLO A LA CABEZA
//Autores:Caba Emilce y Mariano Ramos 
// Mails de contactos: caba_emi@live.com.ar ; ramosjm@gmail.com


#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <ctype.h>



using namespace std;
//Variables Globales
double premio = 0;
double premio2 = 0;
double premio3 = 0;
double premio4 = 0;
double premio5 = 0;
double premio6 = 0;
double premio7 = 0;
double premio8 = 0;
double premio9 = 0;
//Prototipos de funciones
void grillo();
void saludo();
void reglas();
void Ingreso_de_apuestas(int& numero_ingresado_1, double& apuesta, int& numero_ingresado_2, double& apuesta2, int& numero_ingresado_3, double& apuesta3);
void a_la_cabeza(int arr[20], int numero_ingresado_1, int numero_ingresado_2, int numero_ingresado_3, int apuesta, int apuesta2, int apuesta3);
void corrida_en_10_cuatro_cifras(int arr[20], int numero_ingresado_1, double apuesta);
void corrida_en_20_cuatro_cifras(int arr[20], int numero_ingresado_2, double apuesta);
void corrida_en_10_tres_cifras(int arr[20], int numero_ingresado_2, double apuesta2);
void corrida_en_20_tres_cifras(int arr[20], int numero_ingresado_2, double apuesta2);
void corrida_en_10_dos_cifras(int arr[20], int numero_ingresado_3, double apuesta3);
void corrida_en_20_dos_cifras(int arr[20], int numero_ingresado_3, double apuesta3);
void imprimirResultados(double apuesta, int arr[20], int x, double premio);
void imprimirResultados_dos_cifras(double apuesta, int arr[20], int x, double premio);
void imprimirResultados_tres_cifras(double apuesta, int arr[20], int x, double premio);
struct apostador
{
    string apellido;
    string nombre;
    string direccion;
    string dni;
    string cuit;
    double premioMayor;
};

int main()
{
    //Declaracion de  Variables:  

    int aciertos, numeroaleatorio, numero_ingresado_1, numero_ingresado_2, numero_ingresado_3, i, cont, cont1, x, num1;
    int numerosingresados, contadorarr;
    char j, k;
    string deseo, deseo1, deseo2;
    aciertos = 0;
    int arr[20];
    double apuesta = 0;
    double apuesta2 = 0;
    double  apuesta3 = 0;
    numeroaleatorio = 0;
    x = 0;
    bool continuar;
    double arr_premios[5];
    int p = 0;
    int cont2 = 0;
    int baseImponible = 300000;
    int cont_repeticion_jugadas = 0;
    apostador apostadores[5];

    //Definicion de  semilla 0 rand 1 y numero aleatorio hasta 9999
    srand(time(0));

    do
    {   //Variables Locales
        premio = 0;
        premio2 = 0;
        premio3 = 0;
        premio4 = 0;
        premio5 = 0;
        premio6 = 0;
        premio7 = 0;
        premio8 = 0;
        premio9 = 0;


        // Ciclo numero random, maximo 20 , a medida que ingresan cuentan la cantidad que hay.
         // Carga la lista random de numeros del extracto
        contadorarr = 0;
        while (contadorarr < 20)
        {

            numeroaleatorio = rand() % 9999;
            arr[contadorarr] = numeroaleatorio;
            contadorarr++;
        }
        // Condicion que permite ver la lista si desea para probar el juego o dejarlo que sea azar puro
        cout << "Para probar el programa desea imprimir la lista?  'si', si quiere, sino 'no' y Mucha suerte,va solo con el  Azar " << endl;
        cin >> deseo;
        cout << endl;

        if (deseo == "si")
        {
            // Impresion de lista de numeros premiados
            for (int i = 0; i < contadorarr; i++)
            {
                cout << "Numero " << i << " = " << setw(4) << setfill('0') << arr[i] << endl;

            }
            cout << endl;
            cout << endl;
        }
        else
        {
            cout << (" Suerte solo elegiste el AZAR") << endl;
        }
        // LOGO OIFICIAL DE LOTERIA DE LA PROVINCIA//
        grillo();
        // ENCABEZADO Y BIENVENIDA//
        saludo();

        // Condicion que permite ver el reglamento del juego o o pasar sin verlo
        cout << "Conoce el reglamento del juego?  no , si quiere que se los expliquen , si , si desea seguir sin leerlos" << endl;
        cin >> deseo1;
        cout << endl;

        if (deseo1 == "no")

            reglas();

        else

            cout << ("Que comience el Juego") << endl;

        /*INGRESO DE DATOS POR EL APOSTADOR */
        Ingreso_de_apuestas(numero_ingresado_1, apuesta, numero_ingresado_2, apuesta2, numero_ingresado_3, apuesta3);


        double premioTotal = 0;

        //FUNCIONES QUE COMPARAN LAS APUESTAS Y MUESTRAN LOS RESULTADOS

        a_la_cabeza(arr, numero_ingresado_1, numero_ingresado_2, numero_ingresado_3, apuesta, apuesta2, apuesta3);
        corrida_en_10_cuatro_cifras(arr, numero_ingresado_1, apuesta);
        corrida_en_20_cuatro_cifras(arr, numero_ingresado_1, apuesta);
        corrida_en_10_tres_cifras(arr, numero_ingresado_2, apuesta2);
        corrida_en_20_tres_cifras(arr, numero_ingresado_2, apuesta2);
        corrida_en_10_dos_cifras(arr, numero_ingresado_3, apuesta3);
        corrida_en_20_dos_cifras(arr, numero_ingresado_3, apuesta3);
        cout << endl;
        //Suma total de premios
        premioTotal = premio + premio2 + premio3 + premio4 + premio5 + premio6 + premio7 + premio8 + premio9;

        // TICKET PAGO 

        cout << "**TICKET PAGO **" << endl;
        cout << "****" << endl;
        cout << " Premio total: " << " $ " << setprecision(9) << premioTotal << endl;
        cout << "****" << endl;
        cout << "****" << endl << endl << endl;
        // Arreglo que guarda todos los premios ganados
        arr_premios[p] = premioTotal;
        p = p + 1;

        // Condicional para elegir seguir jugando o dejar de hacerlo 
        cout << ("Desea seguir jugando?  Maximo 5 veces por la Ley N 15.131 de Juego Responsable  ") << endl;
        cin >> deseo2;
        if (deseo2 == "si")
        {
            continuar = true;
            cont_repeticion_jugadas++;
        }
        else
        {
            continuar = false;
            cout << ("Gracias por participar!!!") << endl << endl;
        }
    } while (continuar == true && cont_repeticion_jugadas < 5);
    // Carga datos a la estructura de apostadores
    cout << "            Debe completar los datos porque supero el minimo no imponible  " << endl << endl << endl;
    cont = 0;
    for (p = 0; p < 5; p++)
    {
        if (arr_premios[p] >= baseImponible)
        {

            cout << "Ingrese el nombre del apostador : " << endl;
            cin >> apostadores[cont].apellido, '/ n';
            cout << "Ingrese el apellido del apostador: " << endl;
            cin >> apostadores[cont].nombre, '/n';
            cout << "Ingrese el dni del apostador: " << endl;
            cin >> apostadores[cont].dni, '/n';
            cout << "Ingrese el cuil/cuit del apostador: " << endl;
            cin >> apostadores[cont].cuit, '/n';
            apostadores[cont].premioMayor = arr_premios[p];
            cont = cont + 1;
        }   cout << endl << endl;
        cont2 = cont;
    }

    //Imprime la Lista para la UIF (Unidad de Informacion Financiera)
    /* Cuando el premio supera la base no imponible" ;*/

    cout << "            LISTA PARA PRESENTAR EN LA UIF" << endl << endl ;
    for (int i = 0; i < cont2; i++)
    {

        cout << "        Apellido :" << apostadores[i].apellido << endl;
        cout << "        Nombre : " << apostadores[i].nombre << endl;
        cout << "        DNI :" << apostadores[i].dni << endl;
        cout << "        CUIT/CUIL :" << apostadores[i].cuit << endl;
        cout << "        Premio Mayor :  $  " << apostadores[i].premioMayor << endl;

    }
    return 0;
}
void saludo()
{
    cout << "----------------------------" << endl;
    cout << "|        Bienvenido        |" << endl;
    cout << "|           a la           |" << endl;
    cout << "|    Quiniela Instantanea  |" << endl;
    cout << "|            de            |" << endl;
    cout << "|       EMI Y MARIAN       |" << endl;
    cout << "----------------------------" << endl;
    cout << endl;

    return;

}
void grillo()
{
    cout << ("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW@@#########@@WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW") << endl;
    cout << ("WWWWWWWWWWWWWWWWWWWWWWWWW@=**********************=#@WWWWWWWWWWWWWWWW@##@WWWWWWW") << endl;
    cout << ("WWWWWWWWWWWWWWWWWWWW@#*********************************#WWWWWWWWWWW=***=@WWWWWw") << endl;
    cout << ("WWWWWWWWWWWWWWWWW@=***************************************=@WWWWWWW=*****@WWWWW") << endl;
    cout << ("WWWWWWWWWWWWWW@=*********************************************=WWWWWW#===@WWWWWW") << endl;
    cout << ("WWWWWWWWWWWW#*************************************************=@WWWWWWWWWWWWWWw") << endl;
    cout << ("WWWWWWWWWW@*****************************************************=@WWWWWWWWWWWWW") << endl;
    cout << ("WWWWWWW#**********#@=*********=W@=*********************========@====@WWWWW@***w") << endl;
    cout << ("WWWWWW=********==*@WWW@========@WW============================@@======#WWWWWW#@") << endl;
    cout << ("WWWW@==============@WWWW#=======WWW#=========================#W=======#WWWWWWWW") << endl;
    cout << ("WWWW================#WWWWW@=====@WWW#========================W#=====#W@==WWWWWW") << endl;
    cout << ("WWW===================WWWWWW@====W@#WW======================@@====#W#====#WWWWW") << endl;
    cout << ("WW#====================@WWWWWW@==WW=#WW@===================#W====W@=======@WWWW") << endl;
    cout << ("W@======================@WW@WWWWW@===#WWW@=================@@==@@==========WWWW") << endl;
    cout << ("W#=======================@WW#@WWWWWW#==@WWW@==============@W@#W#===========#WWW") << endl;
    cout << ("W=========================@WW##WWWWWWWW@#@WWW@==========@WWWWWW#============WWW") << endl;
    cout << ("@==========================@WW#=#WWWWWWWWWW@WWWW#======#WW@#=@WW@===========WWW") << endl;
    cout << ("#===========================WWW===#WWWWWWWWWWWWWWWW@#==@WWW@WWWWW@==========@WW") << endl;
    cout << ("#===========================#WW@=====@WWWWWWWWWWWWWWWWWWWWWWWWWW@===========@WW") << endl;
    cout << ("#============================@WW###@WWWWWWWWWWWWWWWWWWWWWWWWWW#=============@WW") << endl;
    cout << ("@==========================##=WWWWWWWWWWWWWWWWWWWWWWWWWWWWW#================WWW") << endl;
    cout << ("W=====================#@WWWWW=#WWWWWWWWWWWWWWWWWWWWWWWWWWW#=================WWW") << endl;
    cout << ("W#================@WWWWWWWWWW#=WWWWWWWWWWWWWWWWWWWWWWWWWWWW@===============@WWW") << endl;
    cout << ("W@===============#@@@@####=====@WW#==#####WWW@####=====#WW#================WWWW") << endl;
    cout << ("WW#============================#WW#========WWW=======#WW#=================@WWWW") << endl;
    cout << ("WWW#===========================#WW@=====##WWWW@#####WWWWWW@##============#WWWWW") << endl;
    cout << ("WWWW==========================##WWW@WWWWWWWWW@@@@#########@@@@@WWWWW@@@##WWWWWW") << endl;
    cout << ("WWWW@#=================#@@#@WWWWWW@@#================================#@WWWWWWWw") << endl;
    cout << ("WWWWWW#==========##@WWWW==@WWW@========================================WWWWWWWW") << endl;
    cout << ("WWWWWWW####=#@WWWWWWWW@==@WWWW=======================================#WWWWWWWWW") << endl;
    cout << ("WWWWWWWW@@WWWWWWWW@#======#@#======================================@WWWWWWWWWWw") << endl;
    cout << ("WWWWWWWWWWWWWW@===================================================@WWWWWWWWWWWW") << endl;
    cout << ("WWWWWWWWWWWW#===================================================@WWWWWWWWWWWWWW") << endl;
    cout << ("WWWWWWWWWWWWWW#===============================================@WWWWWWWWWWWWWWWW") << endl;
    cout << ("WWWWWWWWWWWWWWWWW#=========================================#WWWWWWWWWWWWWWWWWWW") << endl;
    cout << ("WWWWWWWWWWWWWWWWWWWW@===================================@WWWWWWWWWWWWWWWWWWWWWW") << endl;
    cout << ("WWWWWWWWWWWWWWWWWWWWWWWW@#=========================#@WWWWWWWWWWWWWWWWWWWWWWWWWW") << endl;
    cout << ("WWWWWWWWWWWWWWWWWWWWWWWWWWWWWW@@@##=======##@@WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW") << endl;
    cout << ("           ############################################################        ") << endl;


}
void reglas()
{
    cout << " El juego consiste en acertar 4 cifras , 3 cifras  y 2 cifras  a la cabeza( en la  primer posicion )  " << endl;
    cout << " Y tambien podes jugar a acertar las 4 cifras, 3 cifras  y 2 cifras en las 10 y 20 posiciones de la lista " << endl;
    cout << " De acuerdo a la posicion en que salga tu numero es el importe que ganas" << endl;
    cout << " 4 cifras a la cabeza paga 3500 veces lo apostado " << endl;
    cout << " 3 cifras a la cabeza paga 600 veces lo apostado  " << endl;
    cout << " 2 cifras a la cabeza paga 70 veces lo apostado " << endl;
    cout << " 4 cifras a los 10 paga 350  veces lo apostado " << endl;
    cout << " 4 cifras a los 20 paga 175 veces lo apostado " << endl;
    cout << " 3 cifras a los 10 paga 60  veces lo apostado " << endl;
    cout << " 3 cifras a los 20 paga 30 veces lo apostado " << endl;
    cout << " 2 cifras a los 10 paga 7  veces lo apostado " << endl;
    cout << " 2 cifras a los 20 paga 3.5 veces lo apostado " << endl;
    cout << endl;
    cout << endl;
}
void Ingreso_de_apuestas(int& numero_ingresado_1, double& apuesta, int& numero_ingresado_2, double& apuesta2, int& numero_ingresado_3, double& apuesta3)
{
    /*INGRESO DE DATOS POR EL APOSTADOR */
    cout << "  Debes elegir un numero de 4 cifras, otro de 3 cifras y por ultimo el de 2 cifras:  " << endl;
    cout << endl;
    cout << "Ingresa el primer numero de 4 cifras que queres jugar : " << endl;;
    cin >> numero_ingresado_1;
    cout << "Ingresa el monto de  dinero  que queres apostar al 1er numero: " << endl;;
    cin >> apuesta;
    cout << "Ingresa el segundo  numero  de 3 cifras que queres jugar: " << endl;;
    cin >> numero_ingresado_2;
    cout << "Ingresa el monto de dinero  que queres apostar al 2 do numero : " << endl;;
    cin >> apuesta2;
    cout << "Ingresa el tercer numero de 2 cifras  que queres jugar: " << endl;;
    cin >> numero_ingresado_3;
    cout << "Ingresa  el monto de dinero  que queres apostar  al 3 er numero : " << endl;;
    cin >> apuesta3;
    cout << endl;
}
void a_la_cabeza(int arr[20], int numero_ingresado_1, int numero_ingresado_2, int numero_ingresado_3, int apuesta, int apuesta2, int apuesta3)
{/* COMPARACION A LA CABEZA */
    if (numero_ingresado_1 == arr[0]) {
        cout << " Ganaste 4 cifras a la cabeza " << endl;
        premio = apuesta * 3500;
        cout << " Tu numero : " << setw(4) << setfill('0') << arr[0] << "    |    " << setw(1) << " $ " << setprecision(9) << premio << endl << endl;
    }
    else cout << " No Ganaste las 4 cifras a la cabeza" << endl << endl;

    if (numero_ingresado_2 == arr[0] % 1000) {
        cout << " Ganaste 3 cifras a la cabeza" << endl;
        premio2 = apuesta2 * 600;
        cout << " Tu numero : " << setw(3) << setfill('0') << arr[0] % 1000 << "    |    " << setw(1) << " $ " << premio2 << endl << endl;
    }
    else cout << " No Ganaste las 3 cifras a la cabeza" << endl << endl;

    if (numero_ingresado_3 == arr[0] % 100)
    {
        cout << " Ganaste 2 cifras a la cabeza" << endl;
        premio3 = apuesta3 * 70;
        cout << " Tu numero : " << setw(2) << setfill('0') << arr[0] % 100 << "    |    " << setw(1) << " $ " << premio3 << endl << endl;

    }
    else cout << " No Ganaste las 2 cifras a la cabeza" << endl << endl;
}
void corrida_en_10_cuatro_cifras(int arr[20], int numero_ingresado_1, double apuesta)
{   /* COMPARACION CON LOS 10 PRIMEROS NUMEROS ALEATORIOS, SIN CONTAR LA CABEZA , SOLO 4 CIFRAS */

    int x = 1;
    int contador = 0;

    for (x = 1; x < 11; x++)
    {

        if (arr[x] == numero_ingresado_1)
        {
            contador++;
            break;
        }
    }
    if (contador > 0)
    {
        premio4 = (apuesta * 350);
        imprimirResultados(apuesta, arr, x, premio4);
    }
    else
    {
        cout << "No ganaste  las 4 cifras a los 10" << endl << endl;
    }


}
void corrida_en_10_tres_cifras(int arr[20], int numero_ingresado_2, double apuesta2)
{   /* COMPARACION CON LOS 10 PRIMEROS NUMEROS ALEATORIOS, SIN CONTAR LA CABEZA , SOLO 4 CIFRAS */

    int x = 1;
    int contador = 0;

    for (x = 1; x < 11; x++)
    {

        if (arr[x] % 1000 == numero_ingresado_2)
        {
            contador++;
            break;
        }
    }
    if (contador > 0)
    {
        premio6 = (apuesta2 * 60);
        imprimirResultados_tres_cifras(apuesta2, arr, x, premio6);
    }
    else
    {
        cout << "No ganaste las tres cifras  a los 10" << endl << endl;
    }


}
void corrida_en_10_dos_cifras(int arr[20], int numero_ingresado_3, double apuesta3)
{   /* COMPARACION CON LOS 10 PRIMEROS NUMEROS ALEATORIOS, SIN CONTAR LA CABEZA , SOLO 4 CIFRAS */

    int x = 1;
    int contador = 0;

    for (x = 1; x < 11; x++)
    {

        if (arr[x] % 100 == numero_ingresado_3)
        {
            contador++;
            break;
        }
    }
    if (contador > 0)
    {
        premio7 = (apuesta3 * 7);
        imprimirResultados_dos_cifras(apuesta3, arr, x, premio7);
    }
    else
    {
        cout << "No ganaste las dos cifras  a los 10" << endl << endl;
    }


}
void corrida_en_20_cuatro_cifras(int arr[20], int numero_ingresado_1, double apuesta)
{
    /* COMPARACION CON LOS NUMEROS DE LA POSICION 11 A LA 20 ALEATORIOS, SIN CONTAR LA CABEZA, SOLO 4 CIFRAS*/
    int x;
    int contador = 0;
    for (x = 11; x < 20; x++)
    {

        if (arr[x] == numero_ingresado_1)
        {
            contador++;
            break;
        }
    }
    if (contador > 0)
    {
        premio5 = apuesta * 175;
        imprimirResultados(apuesta, arr, x, premio5);
    }
    else
    {
        cout << "No ganaste las 4 cifras  a los 20 " << endl << endl;
    }



}
void corrida_en_20_tres_cifras(int arr[20], int numero_ingresado_2, double apuesta2)
{
    /* COMPARACION CON LOS NUMEROS DE LA POSICION 11 A LA 20 ALEATORIOS, SIN CONTAR LA CABEZA, SOLO 4 CIFRAS*/
    int x;
    int contador = 0;
    for (x = 11; x < 20; x++)
    {

        if (arr[x] % 1000 == numero_ingresado_2)
        {
            contador++;
            break;
        }
    }
    if (contador > 0)
    {
        premio8 = apuesta2 * 30;
        imprimirResultados_tres_cifras(apuesta2, arr, x, premio8);
    }
    else
    {
        cout << "No ganaste 3 cifras  a los 20 " << endl << endl;
    }



}
void corrida_en_20_dos_cifras(int arr[20], int numero_ingresado_3, double apuesta3)
{
    /* COMPARACION CON LOS NUMEROS DE LA POSICION 11 A LA 20 ALEATORIOS, SIN CONTAR LA CABEZA, SOLO 4 CIFRAS*/
    int x;
    int contador = 0;
    for (x = 11; x < 20; x++)
    {

        if (arr[x] % 100 == numero_ingresado_3)
        {
            contador++;
            break;
        }
    }
    if (contador > 0)
    {
        premio9 = apuesta3 * 3.5;
        imprimirResultados_dos_cifras(apuesta3, arr, x, premio9);
    }
    else
    {
        cout << "No ganaste 2 cifras  a los 20 " << endl << endl;
    }



}
void imprimirResultados(double apuesta, int arr[20], int x, double premio)
{
    //IMPRESION de Resultados:SI GANASTE ENTRE LOS 10 PRIMEROS
    if (x > 0 && x <= 10)
    {
        cout << " Ganaste 4 cifras  a los 10 " << endl << endl;
        cout << " Tu numero : " << setw(4) << setfill('0') << arr[x] << "    |    " << setw(1) << " $ " << premio << endl << endl;
    }
    else if (x > 10)
    {//IMPRESION de Resultados:SI GANASTE ENTRE EL 1 1 Y 20 LUGARES
        cout << " Ganaste 4 cifras  a los 20" << endl << endl;
        cout << " Tu numero : " << setw(4) << setfill('0') << arr[x] << "    |    " << setw(1) << " $ " << premio << endl << endl;
    }
    else if (x == 0)
    {

    }


}
void imprimirResultados_dos_cifras(double apuesta, int arr[20], int x, double premio)
{
    //IMPRESION de Resultados:SI GANASTE ENTRE LOS 10 PRIMEROS
    if (x > 0 && x <= 10)
    {
        cout << " Ganaste 2 cifras  a los 10 " << endl << endl;
        cout << " Tu numero : " << setw(2) << setfill('0') << arr[x] % 100 << "    |    " << setw(1) << " $ " << premio << endl << endl;
    }
    else if (x > 10)
    {//IMPRESION de Resultados:SI GANASTE ENTRE EL 1 1 Y 20 LUGARES
        cout << " Ganaste 2 cifras  a los 20" << endl << endl;
        cout << " Tu numero : " << setw(0) << setfill('0') << arr[x] % 100 << "    |    " << setw(1) << " $ " << premio << endl << endl;
    }
    else if (x == 0)
    {

    }


}
void imprimirResultados_tres_cifras(double apuesta, int arr[20], int x, double premio)
{
    //IMPRESION de Resultados:SI GANASTE ENTRE LOS 10 PRIMEROS
    if (x > 0 && x <= 10)
    {
        cout << " Ganaste 3 cifras  a los 10 " << endl << endl;
        cout << " Tu numero : " << setw(3) << setfill('0') << arr[x] % 1000 << "    |    " << setw(1) << " $ " << premio << endl << endl;
    }
    else if (x > 10)
    {//IMPRESION de Resultados:SI GANASTE ENTRE EL 1 1 Y 20 LUGARES
        cout << " Ganaste 3 cifras  a los 20" << endl << endl;
        cout << " Tu numero : " << setw(3) << setfill('0') << arr[x] % 1000 << "    |    " << setw(1) << " $ " << premio << endl << endl;
    }
    else if (x == 0)
    {

    }
}