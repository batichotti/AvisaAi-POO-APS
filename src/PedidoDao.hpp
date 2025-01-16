#pragma once

#include "Pedido.hpp"
#include <vector>

class PedidoDao {
public:
    PedidoDao();
    void addPedido(const Pedido& pedido);
    Pedido getPedidoById(int id);
    std::vector<Pedido> getAllPedidos();
private:
    std::vector<Pedido> pedidos;
};
