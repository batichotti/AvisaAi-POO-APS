#include "Cliente.hpp"

Cliente::Cliente(int id, const std::string& nome, const std::string& documentoIdentificador, const std::string& endereco, const std::string& telefone, const std::string& email, const std::string& categoria)
    : id(id), nome(nome), documentoIdentificador(documentoIdentificador), endereco(endereco), telefone(telefone), email(email), categoria(categoria) {}

int Cliente::getId() const {
    return id;
}

std::string Cliente::getNome() const {
    return nome;
}

std::string Cliente::getDocumentoIdentificador() const {
    return documentoIdentificador;
}

std::string Cliente::getEndereco() const {
    return endereco;
}

std::string Cliente::getTelefone() const {
    return telefone;
}

std::string Cliente::getEmail() const {
    return email;
}

std::string Cliente::getCategoria() const {
    return categoria;
}

// ...existing code...
