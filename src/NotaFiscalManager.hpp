#pragma once

#include "NotaFiscalDao.hpp"

class NotaFiscalManager {
public:
    NotaFiscalManager(NotaFiscalDao& daoNotaFiscal);
    void crieNotaFiscal(int pagamentoId);

private:
    NotaFiscalDao& daoNotaFiscal;
};
