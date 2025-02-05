#include "ClienteManager.hpp"
#include "Cliente.hpp"
#include "ClienteDao.hpp"
#include "ClienteDvo.hpp"
#include <iostream>

ClienteManager::ClienteManager(DaoManager* daoManager, DvoManager* dvoManager)
    : daoManager(daoManager), dvoManager(dvoManager) {
    this->daoCliente = daoManager->getClienteDao();
}

std::vector<Cliente> ClienteManager::listeClientes() {
    return daoCliente->list();
}

Cliente ClienteManager::busqueCliente(const std::string& documento) {
    ClienteDvo* clienteDvo = dvoManager->getClienteDvo();
    bool documentoValido = clienteDvo->validarDocumento(documento);
    if (documentoValido) {
        return daoCliente->retrieve(documento);
    } else {
        return Cliente(); 
    }
}
