#include "Pagamento.hpp"

Pagamento::Pagamento() : id(0), valor(0.0), data(std::time(nullptr)), forma(DINHEIRO), situacao(EM_HAVER), pedidoId(0) {}

Pagamento::Pagamento(int id, float valor, std::time_t data, FormaPagamento forma, SituacaoPagamento situacao, int pedidoId)
    : id(id), valor(valor), data(data), forma(forma), situacao(situacao), pedidoId(pedidoId) {}

int Pagamento::getId() const {
    return id;
}

float Pagamento::getValor() const {
    return valor;
}

std::time_t Pagamento::getData() const {
    return data;
}

FormaPagamento Pagamento::getForma() const {
    return forma;
}

SituacaoPagamento Pagamento::getSituacao() const {
    return situacao;
}

int Pagamento::getPedidoId() const {
    return pedidoId;
}

FormaPagamento Pagamento::getFormaPagamento() const {
    return forma;
}
