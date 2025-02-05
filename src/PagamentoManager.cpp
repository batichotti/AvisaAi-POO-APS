#include "PagamentoManager.hpp"

Pagamento PagamentoManager::buscarPagamentoPorPedido(const Pedido& pedido) {
    std::vector<Pagamento> pagamentos = pagamentoDao.listarPagamentos();

    for (const auto& pagamento : pagamentos) {
        if (pagamento.getPedidoId() == pedido.getId()) {
            return pagamento;
        }
    }

    return Pagamento();
}
