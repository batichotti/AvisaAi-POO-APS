#pragma once

#include "DaoManager.hpp"
#include "Pedido.hpp"
#include <vector>

class PagamentoManager {
public:
    PagamentoManager(DaoManager* daoManager);
    Pagamento buscarPagamentoPorPedido(const Pedido& pedido);
    void criarPagamento(int pedidoId, float valor, FormaPagamento forma, SituacaoPagamento situacao);
    Pagamento busquePagamento(int pedidoId);
private:
    DaoManager* daoManager;
};
