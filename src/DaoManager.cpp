#include "DaoManager.hpp"

DaoManager::DaoManager() {
    clienteDao = new ClienteDao();
    pedidoDao = new PedidoDao();
}

PedidoDao* DaoManager::getPedidoDao() {
    return pedidoDao;
}

ClienteDao* DaoManager::getClienteDao() {
    return clienteDao;
}
