#include "NotaFiscalManager.hpp"
#include <ctime>

NotaFiscalManager::NotaFiscalManager(NotaFiscalDao& daoNotaFiscal) : daoNotaFiscal(daoNotaFiscal) {}

void NotaFiscalManager::crieNotaFiscal(int pagamentoId) {
    int id = daoNotaFiscal.getNextId();
    std::time_t data = std::time(nullptr);
    NotaFiscal nota(id, data, pagamentoId);
    daoNotaFiscal.addNotaFiscal(nota);
}
