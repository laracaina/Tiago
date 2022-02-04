#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

class Producto
{
protected:
    int idProducto;
    bool esVegano, esSinTACC, stock, estado;
    char nombreProducto[100];
    float precio;
    bool tieneDescuento;
    float descuento;

public:
    void Cargar();
    void Mostrar();
    bool leerEnDisco(int pos);
    bool grabarEnDisco();
    bool grabarEnDisco(int pos);
    void bajaProducto();
    bool getEsVegano();
    bool getEsSinTacc();
    bool getStock();
    float getPrecio();
    bool getTieneDescuento();
    float getDescuento();
    int getId();
    static void listarProductos();
    static void agregarProductos();
    static void eliminarProducto();
    static void listarProductosVeganos();
    static void listarProductosSinTACC();
    static void listarProductosEnStock();
    static void productosEconomicos();
    static void buscarProductoID();
    static void backUpProductos();
};

#endif // PRODUCTOS_H_INCLUDED