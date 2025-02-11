#include "PagamentoDao.hpp"

std::vector<Pagamento> pagamentos;

void PagamentoDao::adicionarPagamento(const Pagamento& pagamento) {
    pagamentos.push_back(pagamento);
}

Pagamento PagamentoDao::buscarPagamento(int id) {
    for (int i = 0; i < pagamentos.size(); ++i) {
        if (pagamentos[i].getId() == id) {
            return pagamentos[i];
        }
    }
    return Pagamento();
}

std::vector<Pagamento> PagamentoDao::listarPagamentos() {
    return pagamentos;
}

void PagamentoDao::atualizarPagamento(const Pagamento& pagamento) {
    for (int i = 0; i < pagamentos.size(); ++i) {
        if (pagamentos[i].getId() == pagamento.getId()) {
            pagamentos[i] = pagamento;
            return;
        }
    }
}

void PagamentoDao::removerPagamento(int id) {
    for (int i = 0; i < pagamentos.size(); ++i) {
        if (pagamentos[i].getId() == id) {
            pagamentos.erase(pagamentos.begin() + i);
            return;
        }
    }
}

Pagamento PagamentoDao::busquePagamentoPorPedidoId(int pedidoId) {
    for (const Pagamento pagamento : listarPagamentos()) {
        if (pagamento.getPedidoId() == pedidoId) {
            return pagamento;
        }
    }
    return Pagamento();
}
