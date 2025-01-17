#pragma once

#include <vector>
#include <memory>
#include "DaoManager.hpp"
#include "ClienteDao.hpp"
#include "Cliente.hpp"
#include "DvoManager.hpp"

class ClienteManager {
public:
    ClienteManager(DaoManager* daoManager, DvoManager* dvoManager);
    std::vector<Cliente> listeClientes();
    Cliente busqueCliente(const std::string& documento);

private:
    ClienteDao* daoCliente;
    DaoManager* daoManager;
    DvoManager* dvoManager;
};
