#pragma once

#include "NotaFiscal.hpp"
#include <vector>

class NotaFiscalDao {
public:
    void addNotaFiscal(const NotaFiscal& nota);
    NotaFiscal getNotaFiscalById(int id) const;
    int getNextId() const;

private:
    std::vector<NotaFiscal> notasFiscais;
};
