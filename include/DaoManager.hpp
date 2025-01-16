#pragma once

#include "PedidoDao.hpp"
#include "ClienteDao.hpp"

class DaoManager {
    PedidoDao* getPedidoDao();
    ClienteDao* getClienteDao();
};
