#pragma once

#include "ClienteDao.hpp"
#include "PedidoDao.hpp"
#include "PagamentoDao.hpp"

class DaoManager {
public:
    DaoManager();
    ClienteDao* getClienteDao();
    PedidoDao* getPedidoDao();
    PagamentoDao* getPagamentoDao();

private:
    ClienteDao* clienteDao;
    PedidoDao* pedidoDao;
    PagamentoDao* pagamentoDao;
};
