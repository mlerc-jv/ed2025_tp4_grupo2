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
// clase productofisico Y productodigital (hereda de Producto) - abril

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

// Clase Carrito -Jime
class Carrito {
private:
	vector<ProductoFisico> productosFisicos;
	vector<ProductoDigital> productosDigitales;
public:
	void agregarProductoFisico(ProductoFisico p) {
		productosFisicos.push_back(p);
	}
	void agregarProductoDigital(ProductoDigital p) {
		productosDigitales.push_back(p);
	}
	void eliminarProductoPorCodigo(int codigo) {
		for (int i = 0; i < productosFisicos.size(); ++i) {
			if (productosFisicos[i].obtenerCodigo() == codigo) {
				productosFisicos.erase(productosFisicos.begin() + i);
				return;
			}
		}
		for (int i = 0; i < productosDigitales.size(); ++i) {
			if (productosDigitales[i].obtenerCodigo() == codigo) {
				productosDigitales.erase(productosDigitales.begin() + i);
				return;
			}
		}
	}
	void mostrarCarrito() {
		cout << "Productos en el carrito:\n";
		for (ProductoFisico p : productosFisicos) {
			cout << "-Producto Físico-" << endl;
			p.mostrarInformacion();
			cout << "-------------------\n";
		}
		for (ProductoDigital p : productosDigitales) {
			cout << "-Producto Digital-" << endl;
			p.mostrarInformacion();
			cout << "-------------------\n";
		}
	}
	vector<Producto> obtenerTodosLosProductos() {
		vector<Producto> todos;
		for (ProductoFisico p : productosFisicos) todos.push_back(p);
		for (ProductoDigital p : productosDigitales) todos.push_back(p);
		return todos;
	}
};

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
		for (Producto p : productos) {
			suma += p.obtenerPrecio();
		}
		return suma;
	}
	void mostrarResumen() {
		cout << "\nResumen del pedido:\n";
		cliente.mostrarCliente();
		cout << "\nProductos comprados:\n";
		for (Producto p : productos) {
			p.mostrarInformacion();
			cout << "-------------------\n";
		}
		cout << "Total a pagar: $" << total << endl;
	}
};

// Productos disponibles
vector<ProductoFisico> productosFisicos = {
	ProductoFisico("Notebook", 93000.0, 101, 23, 1.8),
		ProductoFisico("Mouse", 12350.0, 102, 17, 0.138)
};

vector<ProductoDigital> productosDigitales = {
	ProductoDigital("App de peliculas", 3246.0, 305, 9, 50, "APK"),
		ProductoDigital("Curso de ventas - online", 48500 , 567, 8 , 34, "HTML")
};

void mostrarProductosDisponibles() {
	cout << "\n-- Productos Físicos Disponibles --\n";
	for (auto& p : productosFisicos) {
		p.mostrarInformacion();
		cout << "-------------------\n";
	}
	cout << "-- Productos Digitales Disponibles --\n";
	for (auto& p : productosDigitales) {
		p.mostrarInformacion();
		cout << "-------------------\n";
	}
}

ProductoFisico* buscarFisico(int codigo) {
	for (auto& p : productosFisicos)
		if (p.obtenerCodigo() == codigo) return &p;
	return nullptr;
}

ProductoDigital* buscarDigital(int codigo) {
	for (auto& p : productosDigitales)
		if (p.obtenerCodigo() == codigo) return &p;
	return nullptr;
}

//main-Antonella

int main() {
	Cliente cliente("Valentina", 13);
	Carrito carrito;
	bool salir = false;
	while (!salir) {
		cout << "\n--- MENU ---\n";
		cout << "1. Ver productos disponibles\n";
		cout << "2. Agregar producto al carrito\n";
		cout << "3. Eliminar producto del carrito\n";
		cout << "4. Ver productos en el carrito\n";
		cout << "5. Confirmar pedido\n";
		cout << "6. Salir\n";
		cout << "Seleccione una opción: ";
		int opcion, codigo;
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			mostrarProductosDisponibles();
			break;
		case 2:
			cout << "Ingrese código del producto a agregar: ";
			cin >> codigo;
			if (auto* pf = buscarFisico(codigo))
				carrito.agregarProductoFisico(*pf);
			else if (auto* pd = buscarDigital(codigo))
				carrito.agregarProductoDigital(*pd);
			else
				cout << "Código no encontrado.\n";
			break;
		case 3:
			cout << "Ingrese código del producto a eliminar: ";
			cin >> codigo;
			carrito.eliminarProductoPorCodigo(codigo);
			break;
		case 4:
			carrito.mostrarCarrito();
			break;
		case 5: {
			vector<Producto> productos = carrito.obtenerTodosLosProductos();
			if (productos.empty()) {
				cout << "El carrito está vacío.\n";
			} else {
				Pedido pedido(cliente, productos);
				cliente.agregarCompra("Pedido confirmado");
				pedido.mostrarResumen();
			}
			break;
		}
		case 6:
			salir = true;
			break;
		default:
			cout << "Opción no válida.\n";
		}
	}
	return 0;
}