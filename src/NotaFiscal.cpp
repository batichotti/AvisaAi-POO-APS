#include "NotaFiscal.hpp"

NotaFiscal::NotaFiscal() : id(0), data(std::time(nullptr)), pagamentoId(0) {}

NotaFiscal::NotaFiscal(int id, std::time_t data, int pagamentoId) : id(id), data(data), pagamentoId(pagamentoId) {}

int NotaFiscal::getId() const {
    return id;
}

std::time_t NotaFiscal::getData() const {
    return data;
}

int NotaFiscal::getPagamentoId() const {
    return pagamentoId;
}
