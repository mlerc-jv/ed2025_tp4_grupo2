#include <bits/stdc++.h>
using namespace std;

// clase producto - abril

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

	void mostrarInformacion() { 
		cout << "Nombre del producto: " << nombre << endl; 
		cout << "Precio: $" << precio << endl; 
		cout << "Código: " << codigo << endl; 
		cout << "Stock disponible: " << stock << endl;  
	}
	
	
	string obtenerNombre () { return nombre; }
	void setNombre(string nombre) { this->nombre = nombre; }
	
	float obtenerPrecio() { return precio; }
	void setPrecio(float precio) { this->precio = precio; }
	
	int obtenerCodigo() { return codigo; }
	void setCodigo(int codigo) { this->codigo = codigo; }
	
	int obtenerStock() { return stock; }
	void setStock(int stock) { this->stock = stock; }
};

// clase productofisico (hereda de Producto) - abril

class ProductoFisico : public Producto {
private:
	float peso;
	
public:
	ProductoFisico(string nombre, float precio, int codigo, int stock, float peso)
		: Producto(nombre, precio, codigo, stock) {
		this->peso = peso;
	}
	
	void mostrarInformacion() {
		Producto::mostrarInformacion();
		cout << "Peso del producto: " << peso << " kg" << endl;
	}
	
	float obtenerPeso() { return peso; }
	void setPeso(float peso) { this->peso = peso; }
};
class ProductoDigital : public Producto {
private:
	float tamanoMB;
	string formato;
	
public:
	ProductoDigital(string nombre, float precio, int codigo, int stock, float tamanoMB, string formato)
		: Producto(nombre, precio, codigo, stock), tamanoMB(tamanoMB), formato(formato) {}
	
	float getTamano() const { return tamanoMB; }
	string getFormato() const { return formato; }
	
	void setTamano(float nuevoTamano) { tamanoMB = nuevoTamano; }
	void setFormato(string nuevoFormato) { formato = nuevoFormato; }
	
	void mostrarInformacion() {
		Producto::mostrarInformacion();
		cout << "Tamaño: " << tamanoMB << " MB" << endl;
		cout << "Formato: " << formato << endl;
	}
};
// Clase Cliente - Jimena

class Cliente {
private:
	string nombre;
	int id;
	string historialCompras;
	
public:
	Cliente(string nombre, int id) {
		this->nombre = nombre;
		this->id = id;
		historialCompras = "";
	}
	
	void agregarCompra(string descripcion) {
		historialCompras += descripcion + "\n";
	}
	
	void mostrarCliente() {
		cout << "Cliente: " << nombre << endl;
		cout << "ID: " << id << endl;
		cout << "Historial de compras:\n" << historialCompras << endl;
	}
	
	
	string obtenerNombre() { return nombre; }
	void setNombre(string nombre) { this->nombre = nombre; }
	
	int obtenerID() { return id; }
	void setID(int id) { this->id = id; }
	
	string obtenerHistorial() { return historialCompras; }
};

// Clase Carrito -Jimena

class Carrito {
private:
	vector<Producto> productos;
	
public:
	void agregarProducto(Producto p) {
		productos.push_back(p);
	}
	
	void eliminarUltimoProducto() {
		if (!productos.empty()) {
			productos.pop_back();
		}
	}
	
	void mostrarCarrito() {
		cout << "Productos en el carrito:\n";
		for (auto p : productos) {
			p.mostrarInformacion();
			cout << "-------------------\n";
		}
	}
	
	vector<Producto> obtenerProductos() {
		return productos;
	}
};