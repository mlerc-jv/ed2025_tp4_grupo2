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


// clase ProductoFisico (hereda de producto) - Abril Carrillo

class ProductoFisico : public Producto {
private:
    float peso;

public:
    // const.
    ProductoFisico(string nombre, float precio, int codigo, int stock, float peso)
        : Producto(nombre, precio, codigo, stock) {
        this->peso = peso;
    }

    // peso del producto físico
    void mostrarPeso() {
        cout << "Peso del producto: " << peso << " kg" << endl;
    }

    // get y set para peso
    float obtenerPeso() {
        return peso;
    }

    void setPeso(float peso) {
        this->peso = peso;
    }
};
