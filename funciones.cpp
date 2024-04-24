#include "funciones.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> cargar_listado(const string & nombre_archivo){

    ifstream infile (nombre_archivo);
    vector<string> palabras;
/*
    if (infile.good()==false) {
        cout <<"no se pudo abrir el archivo" << endl;
        exit(1);
    }
*/
    string line;
    while(!infile.eof()){
        getline(infile, line);
        // if (line.empty()){ } 
        if (line.size() != 0) { palabras.push_back(line); }
    }
    infile.close();
    return palabras;
}

bool intento_valido(const string & intento, const string & palabra_secreta, const vector<string> &listado){


    if (intento.size() != palabra_secreta.size()) {
        return false;
    }

    int i;
    for (i=0 ; i < listado.size() ; ++i){
        if (intento == listado[i]){
            return true;
        }
    }
   
    return false;
}

vector <EstadoLetra> evaluar_intento(const string & intento, const string & palabra_secreta){
    
    vector<EstadoLetra> respuesta;
    int i;
    int j;
    for (i=0 ; i<intento.size() ; ++i){

        if (intento[i] == palabra_secreta[i]) { respuesta.push_back(EstadoLetra::LugarCorrecto); } 

        else{
            for (j=0 ; j<palabra_secreta.size() ; ++j){
                if (intento[i]==palabra_secreta[j]) { 
                    respuesta.push_back(EstadoLetra::LugarIncorrecto);
                    break; 
                }
                else {
                    if (j == (palabra_secreta.size()-1)) {
                        respuesta.push_back(EstadoLetra::NoPresente);
                    }
                }
            }
        }
    }

    return respuesta;
}

string respuesta_en_string(const vector<EstadoLetra> & respuesta){

    string respuesta_final;
    int i;
    for (i=0 ; i< respuesta.size() ; ++i){
        switch (respuesta[i])
        {
            case EstadoLetra::LugarCorrecto: respuesta_final.append("+"); 
            break; 

            case EstadoLetra::LugarIncorrecto: respuesta_final.append("-"); 
            break;

            case EstadoLetra::NoPresente: respuesta_final.append("X"); 
            break;
        }
    }

    return respuesta_final;
}