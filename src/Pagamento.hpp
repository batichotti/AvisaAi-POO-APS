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

enum SituacaoPagamento {
    EM_HAVER,
    QUITADO,
    PARCIALMENTE_PAGO
};

class Pagamento {
public:
    Pagamento();
    Pagamento(int id, float valor, std::time_t data, FormaPagamento forma, SituacaoPagamento situacao, int pedidoId);

    int getId() const;
    float getValor() const;
    std::time_t getData() const;
    FormaPagamento getForma() const;
    SituacaoPagamento getSituacao() const;
    int getPedidoId() const;
    FormaPagamento getFormaPagamento() const;

private:
    int id;
    float valor;
    std::time_t data;
    FormaPagamento forma;
    SituacaoPagamento situacao;
    int pedidoId;
};
