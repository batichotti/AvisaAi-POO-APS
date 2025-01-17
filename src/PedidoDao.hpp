#pragma once

#include "Pedido.hpp"
#include <vector>

class PedidoDao {
public:
    void addPedido(const Pedido& pedido);
    Pedido getPedidoById(int id);
    std::vector<Pedido> getAllPedidos();
    void atualizarPedido(const Pedido& pedido);
    void removerPedido(int id);
    std::vector<Pedido> retrievePedidosPorCliente(const std::string& clienteDocumentoIdentificador);
private:
    std::vector<Pedido> pedidos;
};