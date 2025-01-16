#include "PedidoDao.hpp"


PedidoDao::PedidoDao() {
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

std::vector<Pedido> PedidoDao::retrievePedidosPorCliente(const std::string& clienteDocumentoIdentificador) {
    std::vector<Pedido> pedidosCliente;
    for (const auto& pedido : pedidos) {
        if (pedido.getClienteDocumentoIdentificador() == clienteDocumentoIdentificador) {
            pedidosCliente.push_back(pedido);
        }
    }
    return pedidosCliente;
}