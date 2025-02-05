#include "DaoManager.hpp"

DaoManager::DaoManager() {
    clienteDao = new ClienteDao();
    pedidoDao = new PedidoDao();
    pagamentoDao = new PagamentoDao();
    notaFiscalDao = new NotaFiscalDao();
}

PedidoDao* DaoManager::getPedidoDao() {
    return pedidoDao;
}

ClienteDao* DaoManager::getClienteDao() {
    return clienteDao;
}

PagamentoDao* DaoManager::getPagamentoDao() {
    return pagamentoDao;
}

NotaFiscalDao* DaoManager::getNotaFiscalDao() {
    return notaFiscalDao;
}
