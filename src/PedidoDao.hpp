#pragma once

#include "Pedido.hpp"
#include <vector>

class PedidoDao {
public:
    PedidoDao();
    void addPedido(const Pedido& pedido);
    Pedido getPedidoById(int id);
    std::vector<Pedido> getAllPedidos();
    std::vector<Pedido> retrievePedidosPorCliente(const std::string& clienteDocumentoIdentificador);
private:
    std::vector<Pedido> pedidos;
};