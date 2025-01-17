#pragma once

#include "NotaFiscalDao.hpp"
#include <vector>
#include <string>

class NotaFiscalManager {
public:
    NotaFiscalManager(NotaFiscalDao& daoNotaFiscal);
    void crieNotaFiscal(int pagamentoId);
    std::string crieRelatorio(const std::vector<NotaFiscal>& notasFiscais) const;
    std::string emitirRelatorioVendas(std::time_t dataInicio, std::time_t dataFim) const;

private:
    NotaFiscalDao& daoNotaFiscal;
};
