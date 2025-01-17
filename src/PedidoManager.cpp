#include "PedidoManager.hpp"
#include <stdexcept>

PedidoManager::PedidoManager(DaoManager* daoManager, DvoManager* dvoManager) {
    this->daoManager = daoManager;
    this->dvoManager = dvoManager;
    this->daoPedido = daoManager->getPedidoDao();
    this->clienteDvo = dvoManager->getClienteDvo();
}

std::vector<Pedido> PedidoManager::listePedidos(std::string documentoIdentificador) {
    if (clienteDvo->validarDocumento(documentoIdentificador)) {
        return daoPedido->busquePedidosCliente(documentoIdentificador);
    } else {
        return std::vector<Pedido>();
    }
}

void PedidoManager::criePedido(const std::string& clienteDocumentoIdentificador, int id, std::time_t date, const std::string& descricao) {
    if (clienteDvo->validarDocumento(clienteDocumentoIdentificador)) {
        Pedido novoPedido(id, date, descricao, ABERTO, clienteDocumentoIdentificador);
        daoPedido->salvarPedido(novoPedido);
    } else {
        throw std::invalid_argument("Documento inválido");
    }
}

void PedidoManager::realizarPedido(const std::string& documento, const std::string& descricao, std::time_t date) {
    if (!clienteDvo->validarDocumento(documento)) {
        throw std::invalid_argument("Documento inválido");
    }
    Cliente cliente = daoManager->getClienteDao()->buscarCliente(documento);
    if (cliente.getDocumentoIdentificador().empty()) {
        throw std::invalid_argument("Cliente não encontrado");
    }
    int id = daoPedido->getAllPedidos().size() + 1;
    criePedido(documento, id, date, descricao);
}
