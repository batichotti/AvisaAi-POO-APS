#include "Pedido.hpp"


Pedido::Pedido() : id(0), date(std::time(nullptr)), descricao(""), situacao(ABERTO) {}

Pedido::Pedido(int id, std::time_t date, const std::string& descricao, Situacao situacao)
    : id(id), date(date), descricao(descricao), situacao(situacao) {}

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
