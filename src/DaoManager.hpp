#pragma once

#include "ClienteDao.hpp"
#include "PedidoDao.hpp"

class DaoManager {
public:
    DaoManager();
    ClienteDao* getClienteDao();
    PedidoDao* getPedidoDao();

private:
    ClienteDao* clienteDao;
    PedidoDao* pedidoDao;
};
