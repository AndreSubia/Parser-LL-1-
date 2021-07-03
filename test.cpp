#include <iostream>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

char FIN = '$';

template<typename K, typename V>
std::ostream &operator<<(ostream &out, const map<K, V> &m) {
    for (const std::pair<K, V> &p: m) {
        out << p.first << " -> ";
        for(int i=0; i<p.second.size();i++){
            out << p.second[i] << " ";
        }
        out<<"\n";
    }
    return out;
}

class Produccion{
    public:
        string izquierda;
        vector<char> produccion;
    public:
        Produccion(){};
        friend ostream& operator <<(ostream &out, Produccion const& p){
            for(int i = 0; i < p.produccion.size(); i++){
                if(i=1){out<<" ->";}
                else{
                    out<<" "<<p.produccion[i];
                }
            }
            return out;
        }
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
        Gramatica(string gramatica_txt){
            ifstream archivo;
            char letra;
            Produccion p;
            archivo.open(gramatica_txt);
            if(archivo.fail()){return;}
            while(!archivo.eof()){
                archivo.get(letra);
                if(letra != ' '){
                    cout<<letra<<endl;
                    p.produccion.push_back(letra);
                    if(letra == '\n'){
                        producciones.push_back(p);
                        Produccion p;
                    }
                }
            }
            for(int i=0;i<producciones.size();i++){
                cout<<producciones[i]<<endl;
            }

        };
        /* bool esTerminal(char c){
            if((c>=65 && c<=90)||(c>=97 && c<=122)){
                return false;
            }
            return true;
        } */
        //vector<Produccion> getProducciones(string nt);
};

int main(){
    Gramatica ll1("gramatica.txt");
    return 0;
}