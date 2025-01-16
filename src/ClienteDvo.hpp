#pragma once

#include <string>
#include "Cliente.hpp"

class ClienteDvo {
public:
    ClienteDvo(int id, const std::string& nome, const std::string& documentoIdentificador, const std::string& endereco, const std::string& telefone, const std::string& email, CategoriaCliente categoria);
    int getId() const;
    std::string getNome() const;
    std::string getDocumentoIdentificador() const;
    std::string getEndereco() const;
    std::string getTelefone() const;
    std::string getEmail() const;
    CategoriaCliente getCategoria() const;
    bool validarDocumento() const;

private:
    int id;
    std::string nome;
    std::string documentoIdentificador;
    std::string endereco;
    std::string telefone;
    std::string email;
    CategoriaCliente categoria;
};
