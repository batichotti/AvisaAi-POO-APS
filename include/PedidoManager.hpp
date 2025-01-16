#pragma once

#include <vector>
#include <string>
#include "DaoManager.hpp"
#include "Pedido.hpp"

class PedidoManager {
private:
    DaoManager* daoManager;
    PedidoDao* daoPedido;
    ClienteDao* daoCliente;

public:
    PedidoManager(DaoManager* daoManager);
    std::vector<Pedido> listePedidos(std::string documentoIdentificador);
};
