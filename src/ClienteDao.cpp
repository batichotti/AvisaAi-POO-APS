#include "ClienteDao.hpp"

void ClienteDao::adicionarCliente(const Cliente& cliente) {
    clientes.push_back(cliente);
}

Cliente ClienteDao::buscarCliente(int id) {
    for (const auto& cliente : clientes) {
        if (cliente.getId() == id) {
            return cliente;
        }
    }
    return Cliente();
}

std::vector<Cliente> ClienteDao::listarClientes() {
    return clientes;
}

void ClienteDao::atualizarCliente(const Cliente& cliente) {
    for (size_t i = 0; i < clientes.size(); ++i) {
        if (clientes[i].getId() == cliente.getId()) {
            clientes[i] = cliente;
            return;
        }
    }
}

void ClienteDao::removerCliente(int id) {
    for (size_t i = 0; i < clientes.size(); ++i) {
        if (clientes[i].getId() == id) {
            clientes.erase(clientes.begin() + i);
            return;
        }
    }
}
