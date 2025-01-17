#pragma once

#include <vector>
#include "Cliente.hpp"

class ClienteDao {
public:
    void adicionarCliente(const Cliente& cliente);
    Cliente buscarCliente(int id);
    std::vector<Cliente> listarClientes();
    void atualizarCliente(const Cliente& cliente);
    void removerCliente(int id);
private:
    std::vector<Cliente> clientes;
};
