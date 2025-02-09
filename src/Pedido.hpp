#pragma once

#include <string>
#include <ctime>

enum Situacao {
    ENTREGUE,
    RESOLVIDO,
    EM_ANDAMENTO,
    ABERTO,
    CANCELADO
};

class Pedido {
public:
    Pedido();
    Pedido(int id, std::time_t date, const std::string& descricao, Situacao situacao, const std::string& clienteDocumentoIdentificador);

    int getId() const;
    std::time_t getDate() const;
    std::string getDescricao() const;
    Situacao getSituacao() const;
    std::string getClienteDocumentoIdentificador() const;
    void setId(int newId);

private:
    int id;
    std::time_t date;
    std::string descricao;
    Situacao situacao;
    std::string clienteDocumentoIdentificador;
};