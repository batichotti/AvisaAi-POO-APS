#include "PedidoDao.hpp"

// ...existing code...

PedidoDao::PedidoDao() {
    // Constructor implementation
}

void PedidoDao::addPedido(const Pedido& pedido) {
    pedidos.push_back(pedido);
}

Pedido PedidoDao::getPedidoById(int id) {
    for (const auto& pedido : pedidos) {
        if (pedido.getId() == id) {
            return pedido;
        }
    }
    return Pedido();
}

std::vector<Pedido> PedidoDao::getAllPedidos() {
    return pedidos;
}
