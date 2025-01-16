#include "PedidoManager.hpp"

PedidoManager::PedidoManager(DaoManager* daoManager, DvoManager* dvoManager) {
    this->daoManager = daoManager;
    this->dvoManager = dvoManager;
    this->daoPedido = daoManager->getPedidoDao();
    this->clienteDvo = dvoManager->getClienteDvo();
}

std::vector<Pedido> PedidoManager::listePedidos(std::string documentoIdentificador) {
    if (clienteDvo->validarDocumento(documentoIdentificador)) {
        return daoPedido->retrievePedidosPorCliente(documentoIdentificador);
    } else {
        return std::vector<Pedido>();
    }
}
