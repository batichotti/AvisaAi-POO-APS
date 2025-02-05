#pragma once

#include "Pagamento.hpp"
#include <vector>

class PagamentoDao {
public:
    void adicionarPagamento(const Pagamento& pagamento);
    Pagamento buscarPagamento(int id);
    std::vector<Pagamento> listarPagamentos();
    void atualizarPagamento(const Pagamento& pagamento);
    void removerPagamento(int id);
};
