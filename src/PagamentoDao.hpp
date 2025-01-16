#pragma once

#include "Pagamento.hpp"
#include <vector>

class PagamentoDAO {
public:
    void adicionarPagamento(const Pagamento& pagamento);
    Pagamento buscarPagamento(int id);
    std::vector<Pagamento> listarPagamentos();
    void atualizarPagamento(const Pagamento& pagamento);
    void removerPagamento(int id);
};
