#include "NotaFiscalDao.hpp"

void NotaFiscalDao::addNotaFiscal(const NotaFiscal& nota) {
    notasFiscais.push_back(nota);
}

NotaFiscal NotaFiscalDao::getNotaFiscalById(int id) const {
    for (const auto& nota : notasFiscais) {
        if (nota.getId() == id) {
            return nota;
        }
    }
    return NotaFiscal();
}

int NotaFiscalDao::getNextId() const {
    return notasFiscais.empty() ? 1 : notasFiscais.back().getId() + 1;
}

std::vector<NotaFiscal> NotaFiscalDao::list() const {
    return notasFiscais;
}

std::vector<NotaFiscal> NotaFiscalDao::listeNotasFiscais(std::time_t dataInicio, std::time_t dataFim) const {
    std::vector<NotaFiscal> result;
    for (const auto& nota : notasFiscais) {
        if (nota.getData() >= dataInicio && nota.getData() <= dataFim) {
            result.push_back(nota);
        }
    }
    return result;
}
