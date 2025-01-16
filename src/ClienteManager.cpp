#include "ClienteManager.hpp"
#include "Cliente.hpp"
#include "ClienteDao.hpp"

ClienteManager::ClienteManager(DaoManager* daoManager) {
    this->daoManager = daoManager;
    this->daoCliente = daoManager->getClienteDao();
}

std::vector<Cliente> ClienteManager::listeClientes() {
    return daoCliente->list();
}
