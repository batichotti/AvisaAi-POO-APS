#pragma once

#include "Pedido.hpp"
#include <string>

class PedidoDvo {
public:
    PedidoDvo();
    bool validarPedido(const Pedido& pedido) const;
};
