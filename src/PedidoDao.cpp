#include "PedidoDao.hpp"


PedidoDao::PedidoDao() {
}

void PedidoDao::addPedido(const Pedido& pedido) {
    int newId = pedidos.empty() ? 1 : pedidos.back().getId() + 1;
    Pedido newPedido = pedido;
    newPedido.setId(newId);
    pedidos.push_back(newPedido);
}

Pedido PedidoDao::getPedidoById(int id) {
    for (const Pedido pedido : pedidos) {
        if (pedido.getId() == id) {
            return pedido;
        }
    }
    return Pedido();
}

std::vector<Pedido> PedidoDao::listePedidos() {
    return pedidos;
}

std::vector<Pedido> PedidoDao::busquePedidosCliente(const std::string& clienteDocumentoIdentificador) {
    std::vector<Pedido> pedidosCliente;
    for (const Pedido pedido : pedidos) {
        if (pedido.getClienteDocumentoIdentificador() == clienteDocumentoIdentificador) {
            pedidosCliente.push_back(pedido);
        }
    }
    return pedidosCliente;
}

std::vector<Pedido> PedidoDao::busquePedidosClienteSituacao(const std::string& clienteDocumentoIdentificador, Situacao situacao) {
    std::vector<Pedido> pedidosCliente;
    for (const Pedido pedido : pedidos) {
        if (pedido.getClienteDocumentoIdentificador() == clienteDocumentoIdentificador) {
            pedidosCliente.push_back(pedido);
        }
    }
    return pedidosCliente;
}

void PedidoDao::atualizePedido(const Pedido& pedido) {
    for (int i = 0; i < pedidos.size(); ++i) {
        if (pedidos[i].getId() == pedido.getId()) {
            pedidos[i] = pedido;
            return;
        }
    }
}

void PedidoDao::removerPedido(int id) {
    for (int i = 0; i < pedidos.size(); ++i) {
        if (pedidos[i].getId() == id) {
            pedidos.erase(pedidos.begin() + i);
            return;
        }
    }
}
