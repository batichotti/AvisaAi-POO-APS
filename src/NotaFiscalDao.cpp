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
