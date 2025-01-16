#include "PagamentoDao.hpp"

std::vector<Pagamento> pagamentos;

void PagamentoDAO::adicionarPagamento(const Pagamento& pagamento) {
    pagamentos.push_back(pagamento);
}

Pagamento PagamentoDAO::buscarPagamento(int id) {
    for (size_t i = 0; i < pagamentos.size(); ++i) {
        if (pagamentos[i].getId() == id) {
            return pagamentos[i];
        }
    }
    return Pagamento();
}

std::vector<Pagamento> PagamentoDAO::listarPagamentos() {
    return pagamentos;
}

void PagamentoDAO::atualizarPagamento(const Pagamento& pagamento) {
    for (size_t i = 0; i < pagamentos.size(); ++i) {
        if (pagamentos[i].getId() == pagamento.getId()) {
            pagamentos[i] = pagamento;
            return;
        }
    }
}

void PagamentoDAO::removerPagamento(int id) {
    for (size_t i = 0; i < pagamentos.size(); ++i) {
        if (pagamentos[i].getId() == id) {
            pagamentos.erase(pagamentos.begin() + i);
            return;
        }
    }
}
