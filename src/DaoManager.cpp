#include "DaoManager.hpp"

DaoManager::DaoManager() {
    clienteDao = new ClienteDao();
}

ClienteDao* DaoManager::getClienteDao() {
    return clienteDao;
}
