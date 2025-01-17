#pragma once

#include <ctime>

class NotaFiscal {
public:
    NotaFiscal();
    NotaFiscal(int id, std::time_t data, int pagamentoId);

    int getId() const;
    std::time_t getData() const;
    int getPagamentoId() const;

private:
    int id;
    std::time_t data;
    int pagamentoId;
};
