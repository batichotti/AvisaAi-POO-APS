#pragma once

#include "DaoManager.hpp"
#include "DvoManager.hpp"
#include "ClienteDvo.hpp"
#include "Pedido.hpp"
#include <vector>
#include <string>
#include <ctime>

class PedidoManager {
public:
    PedidoManager(DaoManager* daoManager, DvoManager* dvoManager);
    std::vector<Pedido> listePedidos(std::string documentoIdentificador);
    std::vector<Pedido> listePedidosCliente(std::string documentoIdentificador, Situacao situacao = Situacao::ABERTO);
    void criePedido(const std::string& clienteDocumentoIdentificador, int id, std::time_t date, const std::string& descricao);
    void realizarPedido(const std::string& documento, const std::string& descricao, std::time_t date = std::time(nullptr));

private:
    DaoManager* daoManager;
    DvoManager* dvoManager;
    PedidoDao* daoPedido;
    ClienteDvo* clienteDvo;
};
