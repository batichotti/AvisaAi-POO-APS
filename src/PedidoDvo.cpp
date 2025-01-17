#include "PedidoDvo.hpp"

PedidoDvo::PedidoDvo() {}

bool PedidoDvo::validarPedido(const Pedido& pedido) const {
    return pedido.getId() > 0 && !pedido.getDescricao().empty() && !pedido.getClienteDocumentoIdentificador().empty();
}
