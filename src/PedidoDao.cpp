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

std::vector<Pedido> PedidoDao::busquePedidosCliente(const std::string& clienteDocumentoIdentificador) {
    std::vector<Pedido> pedidosCliente;
    for (const auto& pedido : pedidos) {
        if (pedido.getClienteDocumentoIdentificador() == clienteDocumentoIdentificador) {
            pedidosCliente.push_back(pedido);
        }
    }
    return pedidosCliente;
}

std::vector<Pedido> PedidoDao::busquePedidosClienteSituacao(const std::string& clienteDocumentoIdentificador, Situacao situacao) {
    std::vector<Pedido> pedidosCliente;
    for (const auto& pedido : pedidos) {
        if (pedido.getClienteDocumentoIdentificador() == clienteDocumentoIdentificador) {
            pedidosCliente.push_back(pedido);
        }
    }
    return pedidosCliente;
}

void PedidoDao::atualizarPedido(const Pedido& pedido) {
    for (size_t i = 0; i < pedidos.size(); ++i) {
        if (pedidos[i].getId() == pedido.getId()) {
            pedidos[i] = pedido;
            return;
        }
    }
}

void PedidoDao::removerPedido(int id) {
    for (size_t i = 0; i < pedidos.size(); ++i) {
        if (pedidos[i].getId() == id) {
            pedidos.erase(pedidos.begin() + i);
            return;
        }
    }
}

void PedidoDao::salvarPedido(const Pedido& pedido) {
    pedidos.push_back(pedido);
}