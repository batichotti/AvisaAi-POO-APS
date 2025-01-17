#include "NotaFiscalManager.hpp"
#include <ctime>
#include <iostream>
#include <sstream>

NotaFiscalManager::NotaFiscalManager(NotaFiscalDao& daoNotaFiscal) : daoNotaFiscal(daoNotaFiscal) {}

void NotaFiscalManager::crieNotaFiscal(int pagamentoId) {
    int id = daoNotaFiscal.getNextId();
    std::time_t data = std::time(nullptr);
    NotaFiscal nota(id, data, pagamentoId);
    daoNotaFiscal.addNotaFiscal(nota);
}

std::string NotaFiscalManager::crieRelatorio(const std::vector<NotaFiscal>& notasFiscais) const {
    std::ostringstream relatorio;
    for (const auto& nota : notasFiscais) {
        std::time_t data = nota.getData();
        relatorio << "ID: " << nota.getId() << ", Data: " << std::ctime(&data) << ", Pagamento ID: " << nota.getPagamentoId() << std::endl;
    }
    std::string relatorioStr = relatorio.str();
    std::cout << relatorioStr;
    return relatorioStr;
}

std::string NotaFiscalManager::emitirRelatorioVendas(std::time_t dataInicio, std::time_t dataFim) const {
    std::vector<NotaFiscal> notasFiscais = daoNotaFiscal.listeNotasFiscais(dataInicio, dataFim);
    return crieRelatorio(notasFiscais);
}
