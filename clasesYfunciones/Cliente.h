#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

class Cliente
{
protected:
    int idCliente, dni;
    bool esSocio, estado;
    char nombre[31], apellido[31];

public:
    void Cargar();
    void Mostrar();
    bool leerEnDisco(int pos);
    bool grabarEnDisco();
    bool grabarEnDisco(int pos);
    void bajaCliente();
    bool getSocio();
    int getId();
    static void eliminarCliente();
    static void agregarClientes();
    static void listarClientes();
    static void buscarClienteID();
    static void clientesSocios();
    static void backUpClientes();
};

#endif // CLIENTE_H_INCLUDED