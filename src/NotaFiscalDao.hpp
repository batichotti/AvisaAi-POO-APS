#pragma once

#include "NotaFiscal.hpp"
#include <vector>
#include <ctime>

class NotaFiscalDao {
public:
    void addNotaFiscal(const NotaFiscal& nota);
    NotaFiscal getNotaFiscalById(int id) const;
    int getNextId() const;
    std::vector<NotaFiscal> listeNotasFiscais(std::time_t dataInicio, std::time_t dataFim) const;
    std::vector<NotaFiscal> list() const;

private:
    std::vector<NotaFiscal> notasFiscais;
};
