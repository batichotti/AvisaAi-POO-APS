#include "ClienteDvo.hpp"

ClienteDvo::ClienteDvo(int id, const std::string& nome, const std::string& documentoIdentificador, const std::string& endereco, const std::string& telefone, const std::string& email, CategoriaCliente categoria)
    : id(id), nome(nome), documentoIdentificador(documentoIdentificador), endereco(endereco), telefone(telefone), email(email), categoria(categoria) {}

int ClienteDvo::getId() const {
    return id;
}

std::string ClienteDvo::getNome() const {
    return nome;
}

std::string ClienteDvo::getDocumentoIdentificador() const {
    return documentoIdentificador;
}

std::string ClienteDvo::getEndereco() const {
    return endereco;
}

std::string ClienteDvo::getTelefone() const {
    return telefone;
}

std::string ClienteDvo::getEmail() const {
    return email;
}

CategoriaCliente ClienteDvo::getCategoria() const {
    return categoria;
}

bool ClienteDvo::validarDocumento() const {
    return !documentoIdentificador.empty() && documentoIdentificador.size() >= 8;
}
