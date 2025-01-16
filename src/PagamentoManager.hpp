#pragma once

#include "PagamentoDao.hpp"
#include "Pedido.hpp"
#include <vector>

class PagamentoManager {
public:
    Pagamento buscarPagamentoPorPedido(const Pedido& pedido);

private:
    PagamentoDAO pagamentoDAO;
};
