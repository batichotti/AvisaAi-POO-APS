#pragma once

#include "DaoManager.hpp"
#include "DvoManager.hpp"
#include "ClienteDvo.hpp"
#include "Pedido.hpp"
#include <vector>
#include <string>

class PedidoManager {
public:
    PedidoManager(DaoManager* daoManager, DvoManager* dvoManager);
    std::vector<Pedido> listePedidos(std::string documentoIdentificador);

private:
    DaoManager* daoManager;
    DvoManager* dvoManager;
    PedidoDao* daoPedido;
    ClienteDvo* clienteDvo;
};
