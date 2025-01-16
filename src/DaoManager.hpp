#pragma once

#include "ClienteDao.hpp"

class DaoManager {
public:
    DaoManager();
    ClienteDao* getClienteDao();

private:
    ClienteDao* clienteDao;
};
