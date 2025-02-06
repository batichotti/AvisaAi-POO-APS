#pragma once

#include "Pedido.hpp"
#include <vector>

class PedidoDao {
public:
    PedidoDao();
    void addPedido(const Pedido& pedido);
    Pedido getPedidoById(int id);
    std::vector<Pedido> getAllPedidos();
    void atualizarPedido(const Pedido& pedido);
    void removerPedido(int id);
    std::vector<Pedido> busquePedidosCliente(const std::string& clienteDocumentoIdentificador);
    std::vector<Pedido> busquePedidosClienteSituacao(const std::string& clienteDocumentoIdentificador, Situacao situacao);
    void salvarPedido(const Pedido& pedido);
private:
    std::vector<Pedido> pedidos;
};