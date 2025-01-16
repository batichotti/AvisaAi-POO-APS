#include "PedidoManager.hpp"
#include "Pedido.hpp"
#include "PedidoDao.hpp"
#include "DvoManager.hpp"

PedidoManager::PedidoManager(DaoManager* daoManager) {
    this->daoManager = daoManager;
    this->daoPedido = daoManager->getPedidoDao();
    this->dvoManager = daoManager->getDvoManager();
}

std::vector<Pedido> PedidoManager::listePedidos(std::string documentoIdentificador) {
    if (dvoManager->isDocumentoValido(documentoIdentificador)) {
        return daoPedido->retrievePedidosPorCliente(documentoIdentificador);
    } else {
        return std::vector<Pedido>();
    }
}
