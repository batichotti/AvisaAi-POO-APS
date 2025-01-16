#include "Pagamento.hpp"

Pagamento::Pagamento() : id(0), valor(0.0), data(std::time(nullptr)), forma(DINHEIRO), pedidoId(0) {}

Pagamento::Pagamento(int id, float valor, std::time_t data, FormaPagamento forma)
    : id(id), valor(valor), data(data), forma(forma), pedidoId(0) {}

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

int Pagamento::getPedidoId() const {
    return pedidoId;
}
