#include <iostream>
#include <string>
using namespace std;
// Clase Producto - Abril Carrillo
class Producto {
private: 
    string nombre; 
    float precio; 
    int codigo; 
    int stock; 

public: 
    Producto(string nombre, float precio, int codigo, int stock) {
        this->nombre = nombre; 
        this->precio = precio; 
        this->codigo = codigo;
        this->stock  = stock;
    }
// info del producto
void mostrarInformacion() { 
     cout << "Nombre del producto: " << nombre << endl; 
     cout << "Precio: $" << precio << endl; 
     cout << "Codigo: " << codigo << endl; 
     cout << "Stock disponible: " << stock << endl;  
}
// get y set
string obtenerNombre () {
return nombre; 
}

void setNombre(string nombre) {
    this->nombre = nombre;
}

float obtenerPrecio() {
return precio;
}

void setPrecio(float precio) {
this->precio = precio;
}

int obtenerCodigo() {
    return codigo; 
}

void setCodigo(int codigo) {
    this->codigo = codigo;
}

int obtenerStock() {
    return stock; 
}

void setStock(int stock) {
    this->stock = stock;
}
};