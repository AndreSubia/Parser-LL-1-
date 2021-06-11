#include <iostream>
#include <vector>
using namespace std;

class Produccion{
    public:
        string izquierda;
        string derecha;
    public:
        Produccion(){};
};

/* struct test{
    string izquierda;
    string derecha;
}; */

class Gramatica{
    public:
        //vector<string> terminales;
        //vector<string> noTerminales;
        vector<Produccion> producciones;
    public:
        Gramatica(){};
        /* bool esTerminal(char c){
            if((c>=65 && c<=90)||(c>=97 && c<=122)){
                return false;
            }
            return true;
        } */
        vector<Produccion> getProducciones(string nt);
};

int main(){
    return 0;
}