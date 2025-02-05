#pragma once

#include "ClienteDao.hpp"
#include "PedidoDao.hpp"
#include "PagamentoDao.hpp"
#include "NotaFiscalDao.hpp"

class DaoManager {
public:
    DaoManager();
    ClienteDao* getClienteDao();
    PedidoDao* getPedidoDao();
    PagamentoDao* getPagamentoDao();
    NotaFiscalDao* getNotaFiscalDao();

private:
    ClienteDao* clienteDao;
    PedidoDao* pedidoDao;
    PagamentoDao* pagamentoDao;
    NotaFiscalDao* notaFiscalDao;
};
