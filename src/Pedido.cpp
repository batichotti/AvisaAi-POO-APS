#include "Pedido.hpp"
#include <ctime>
#include <string>

Pedido::Pedido() : id(0), date(std::time(nullptr)), descricao(""), situacao(ABERTO), clienteDocumentoIdentificador("") {}

Pedido::Pedido(int id, std::time_t date, const std::string& descricao, Situacao situacao, const std::string& clienteDocumentoIdentificador)
    : id(id), date(date), descricao(descricao), situacao(situacao), clienteDocumentoIdentificador(clienteDocumentoIdentificador) {}

int Pedido::getId() const {
    return id;
}

std::time_t Pedido::getDate() const {
    return date;
}

std::string Pedido::getDescricao() const {
    return descricao;
}

Situacao Pedido::getSituacao() const {
    return situacao;
}

std::string Pedido::getClienteDocumentoIdentificador() const {
    return clienteDocumentoIdentificador;
}

void Pedido::setId(int newId) {
    id = newId;
}