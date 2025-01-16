#pragma once

#include <string>
#include <ctime>

enum FormaPagamento {
    DINHEIRO,
    PIX,
    DEBITO,
    CREDITO,
    BOLETO,
    CHEQUE
};

class Pagamento {
public:
    Pagamento();
    Pagamento(int id, float valor, std::time_t data, FormaPagamento forma);

    int getId() const;
    float getValor() const;
    std::time_t getData() const;
    FormaPagamento getForma() const;
    int getPedidoId() const;

private:
    int id;
    float valor;
    std::time_t data;
    FormaPagamento forma;
    int pedidoId;
};
