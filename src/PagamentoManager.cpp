#include "PagamentoManager.hpp"

Pagamento PagamentoManager::buscarPagamentoPorPedido(const Pedido& pedido) {
    std::vector<Pagamento> pagamentos = pagamentoDAO.listarPagamentos();

    for (const auto& pagamento : pagamentos) {
        if (pagamento.getPedidoId() == pedido.getId()) {
            return pagamento;
        }
    }

    // Retornar um pagamento padrão ou lançar uma exceção se não encontrado
    return Pagamento();
}
