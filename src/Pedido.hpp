#pragma once

#include <string>
#include <ctime>

enum Situacao {
    QUITADO,
    ABERTO,
    PARCIALMENTE_PAGO
};

class Pedido {
public:
    Pedido();
    Pedido(int id, std::time_t date, const std::string& descricao, Situacao situacao);

    int getId() const;
    std::time_t getDate() const;
    std::string getDescricao() const;
    Situacao getSituacao() const;

private:
    int id;
    std::time_t date;
    std::string descricao;
    Situacao situacao;
};
