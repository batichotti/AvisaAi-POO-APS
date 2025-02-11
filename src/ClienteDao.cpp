#include "ClienteDao.hpp"

void ClienteDao::adicionarCliente(const Cliente& cliente) {
    clientes.push_back(cliente);
}

Cliente ClienteDao::buscarCliente(const std::string& documentoIdentificador) {
    for (const Cliente cliente : clientes) {
        if (cliente.getDocumentoIdentificador() == documentoIdentificador) {
            return cliente;
        }
    }
    return Cliente();
}

std::vector<Cliente> ClienteDao::list() {
    return clientes;
}

void ClienteDao::atualizarCliente(const Cliente& cliente) {
    for (int i = 0; i < clientes.size(); ++i) {
        if (clientes[i].getDocumentoIdentificador() == cliente.getDocumentoIdentificador()) {
            clientes[i] = cliente;
            return;
        }
    }
}

void ClienteDao::removerCliente(const std::string& documentoIdentificador) {
    for (int i = 0; i < clientes.size(); ++i) {
        if (clientes[i].getDocumentoIdentificador() == documentoIdentificador) {
            clientes.erase(clientes.begin() + i);
            return;
        }
    }
}

Cliente ClienteDao::retrieve(const std::string& documentoIdentificador) {
    for (const Cliente cliente : clientes) {
        if (cliente.getDocumentoIdentificador() == documentoIdentificador) {
            return cliente;
        }
    }
    return Cliente();
}
