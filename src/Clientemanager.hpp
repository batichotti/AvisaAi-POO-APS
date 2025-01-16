#pragma once

#include <vector>
#include <memory>
#include "DaoManager.hpp"
#include "ClienteDao.hpp"
#include "Cliente.hpp"

class ClienteManager {
public:
    ClienteManager(DaoManager* daoManager);
    std::vector<Cliente> listeClientes();

private:
    ClienteDao* daoCliente;
    DaoManager* daoManager;
};
