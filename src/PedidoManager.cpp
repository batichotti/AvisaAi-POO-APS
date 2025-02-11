#include "PedidoManager.hpp"
#include <iostream>

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

std::vector<Pedido> PedidoManager::listeTodosPedidos() {
    return daoPedido->listePedidos();
}

std::vector<Pedido> PedidoManager::listePedidosCliente(std::string documentoIdentificador, Situacao situacao) {
    if (clienteDvo->validarDocumento(documentoIdentificador)) {
        return daoPedido->busquePedidosClienteSituacao(documentoIdentificador, situacao);
    } else {
        return std::vector<Pedido>();
    }
}

void PedidoManager::criePedido(const std::string& clienteDocumentoIdentificador, int id, std::time_t date, const std::string& descricao) {
    if (clienteDvo->validarDocumento(clienteDocumentoIdentificador)) {
        Pedido novoPedido(id, date, descricao, Situacao::ABERTO, clienteDocumentoIdentificador);
        daoPedido->addPedido(novoPedido);
    } else {
        std::cout << "Documento inválido" << std::endl;
    }
}

void PedidoManager::realizarPedido(const std::string& documento, const std::string& descricao, std::time_t date) {
    if (!clienteDvo->validarDocumento(documento)) {
        std::cout << "Documento inválido" << std::endl;
    }
    Cliente cliente = daoManager->getClienteDao()->buscarCliente(documento);
    if (cliente.getDocumentoIdentificador().empty()) {
        std::cout << "Cliente não encontrado" << std::endl;
    }
    int id = daoPedido->listePedidos().size() + 1;
    criePedido(documento, id, date, descricao);
}