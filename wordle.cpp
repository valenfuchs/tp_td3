#include "funciones.h"
#include "funciones.cpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <ctime>


using namespace std;

//debe utilizar las funciones declaradas en funciones.h para implementar el juego interactivo.

int main(){
    
    vector<string> listado = cargar_listado("listado.txt");
    
    srand(time(nullptr)); // use current time as seed for random generator
    int numero_random = rand() % listado.size(); // numero random del 0 al 4709
    string palabra_secreta = listado[numero_random];

    
    string intento;
    cout << "bienvenido a Wordle!" << endl;
    cout << "el juego consta de adivinar una palabra secreta de 5 letras." << endl;
    cout << "usted tiene 5 intentos." << endl;
    
    int cant_intentos = 5;

    while ((intento != palabra_secreta) && (cant_intentos != 0)) {
        
        cout << "por favor introduzca debajo su intento:" << endl;
        getline(cin, intento);
        
        while (intento_valido(intento, palabra_secreta, listado) == 0){ 
            cout << "intento no valido, vuelva a intentar" << endl;
            cout << "por favor introduzca debajo su intento:" << endl;
            getline(cin, intento);
        }

        cant_intentos = cant_intentos - 1;
        vector<EstadoLetra> respuesta = evaluar_intento(intento, palabra_secreta);
        string respuesta_final = respuesta_en_string(respuesta);
        cout << respuesta_final << endl;
        cout << "(restan " << cant_intentos << " intentos)" << endl;
        cout << endl; 
        
    }
    
    if (cant_intentos == 0) {
        cout << endl << "se han agotado los intentos." << endl;
        cout << "game over :(" << endl;
        cout << endl;
        cout << "pd: la palabra era... " << palabra_secreta << endl;
        cout << endl; 
        
        }

    if (intento == palabra_secreta) {
        cout << endl << "felicitaciones! usted ha ganado :)";
    }

}