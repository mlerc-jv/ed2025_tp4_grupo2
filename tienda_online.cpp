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
// -
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
// -
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
// -
// Clase Pedido-Antonella

class Pedido {
private:
	Cliente cliente;
	vector<Producto> productos;
	float total;
	
public:
	Pedido(Cliente cliente, vector<Producto> productos)
		: cliente(cliente), productos(productos) {
		total = calcularTotal();
	}
	
	float calcularTotal() {
		float suma = 0;
		for (auto p : productos) {
			suma += p.obtenerPrecio();
		}
		return suma;
	}
	
	void mostrarResumen() {
		cout << "\nResumen del pedido:\n";
		cliente.mostrarCliente();
		cout << "\nProductos comprados:\n";
		for (auto p : productos) {
			p.mostrarInformacion();
			cout << "-------------------\n";
		}
		cout << "Total a pagar: $" << total << endl;
	}
};
//-
//main-Antonella


int main() {
	
	ProductoFisico prod1("Notebook",93000.0, 101, 5, 2.5);
	ProductoFisico prod2("Mouse", 12350.0, 102, 20, 0.2);
	
	
	ProductoDigital prod3("App de peliculas", 10.0, 201, 999, 50, "PDF");
	
	Cliente cliente("Valentina", 13);
	
	Carrito carrito;
	carrito.agregarProducto(prod1);
	carrito.agregarProducto(prod2);
	carrito.agregarProducto(prod3); 
	
	carrito.mostrarCarrito();
	
	Pedido pedido(cliente, carrito.obtenerProductos());
	
	cliente.agregarCompra("Notebook, Mouse, Archivo de películas (links)");
	
	pedido.mostrarResumen();
	
	return 0;
}