#include "PagamentoManager.hpp"

PagamentoManager::PagamentoManager(DaoManager* daoManager) : daoManager(daoManager) {}

Pagamento PagamentoManager::buscarPagamentoPorPedido(const Pedido& pedido) {
    std::vector<Pagamento> pagamentos = daoManager->getPagamentoDao()->listarPagamentos();

    for (const auto& pagamento : pagamentos) {
        if (pagamento.getPedidoId() == pedido.getId()) {
            return pagamento;
        }
    }

    return Pagamento();
}

void PagamentoManager::criarPagamento(int pedidoId, float valor, FormaPagamento forma, SituacaoPagamento situacao) {
    int id = daoManager->getPagamentoDao()->listarPagamentos().size() + 1;
    Pagamento pagamento(id, valor, std::time(nullptr), forma, situacao, pedidoId);
    daoManager->getPagamentoDao()->adicionarPagamento(pagamento);
}

Pagamento PagamentoManager::busquePagamento(int pedidoId) {
    return daoManager->getPagamentoDao()->busquePagamentoPorPedidoId(pedidoId);
}

std::vector<Pagamento> PagamentoManager::listarPagamentos() {
    return daoManager->getPagamentoDao()->listarPagamentos();
}
