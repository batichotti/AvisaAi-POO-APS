#pragma once

#include <vector>
#include "Cliente.hpp"

class ClienteDao {
public:
    void adicionarCliente(const Cliente& cliente);
    Cliente buscarCliente(const std::string& documentoIdentificador);
    std::vector<Cliente> list();
    void atualizarCliente(const Cliente& cliente);
    void removerCliente(const std::string& documentoIdentificador);
    Cliente retrieve(const std::string& documentoIdentificador);

private:
    std::vector<Cliente> clientes;
};
