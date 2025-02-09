#include <iostream>
#include <vector>
#include "PedidoManager.hpp"
#include "ClienteManager.hpp"

class UseCase {
public:
    virtual void execute() = 0;
    virtual std::string getName() = 0;
};

class RealizarPedido : public UseCase {
private:
    PedidoManager* pedidoManager;
    ClienteManager* clienteManager;

public:
    RealizarPedido(PedidoManager* pm, ClienteManager* cm) : pedidoManager(pm), clienteManager(cm) {}

    void execute() override {
        std::string documento, descricao;
        std::cout << "Digite o documento do cliente: ";
        std::cin >> documento;
        std::cout << "Digite a descrição do pedido: ";
        std::cin.ignore();
        std::getline(std::cin, descricao);

        Cliente cliente = clienteManager->busqueCliente(documento);
        if (!cliente.getDocumentoIdentificador().empty()) {
            pedidoManager->criePedido(documento, 0, std::time(nullptr), descricao);
        } else {
            std::cout << "Documento do cliente inválido" << std::endl;
        }
        
    }

    std::string getName() override {
        return "Realizar Pedido";
    }
};

class RealizarPagamento : public UseCase {
private:
    PedidoManager* pedidoManager;
    ClienteManager* clienteManager;
    std::string documento;

public:
    RealizarPagamento(PedidoManager* pm, ClienteManager* cm) : pedidoManager(pm), clienteManager(cm) {}

    void execute() override {
        std::cout << "Executando Cadastrar Pagamento" << std::endl;
        std::cout << "Digite o documento do cliente para listar seus pedidos: ";
        std::cin >> documento;

        Cliente cliente = clienteManager->busqueCliente(documento);
        if (!cliente.getDocumentoIdentificador().empty()) {
            std::cout << "Pedidos do cliente " << cliente.getNome() << std::endl;
            std::vector<Pedido> pedidos = pedidoManager->listePedidosCliente(cliente.getDocumentoIdentificador(), Situacao::ABERTO);
        } else {
            std::cout << "Documento do cliente inválido" << std::endl;
        }
    }
    std::string getName() override {
        return "Cadastrar Pagamento";
    }
};

class AtualizarSituacaoPedido : public UseCase {
public:
    void execute() override {
        std::cout << "Executando Atualizar Situação do Pedido" << std::endl;
    }
    std::string getName() override {
        return "Atualizar Situacao Pedido";
    }
};

class AtualizarSituacaoPagamento : public UseCase {
public:
    void execute() override {
        std::cout << "Executando Atualizar Situação do Pagamento" << std::endl;
    }
    std::string getName() override {
        return "Atualizar Situacao Pagamento";
    }
};

class BuscarPedido : public UseCase {
public:
    void execute() override {
        std::cout << "Executando Buscar Pedido" << std::endl;
    }
    std::string getName() override {
        return "Buscar Pedido";
    }
};

class BuscarPagamento : public UseCase {
public:
    void execute() override {
        std::cout << "Executando Buscar Pagamento" << std::endl;
    }
    std::string getName() override {
        return "Buscar Pagamento";
    }
};

class Menu {
private:
    std::vector<UseCase*> useCases;
    DaoManager* daoManager;
public:
    Menu(DaoManager* daoManager) : daoManager(daoManager){}

    void addUseCase(UseCase* useCase) {
        useCases.push_back(useCase);
    }

    void display() {
        std::cout << "Menu Principal" << std::endl;
        for (size_t i = 0; i < useCases.size(); ++i) {
            std::cout << i + 1 << ". " << useCases[i]->getName() << std::endl;
        }
        std::cout << useCases.size() + 1 << ". Mostrar todos os pedidos" << std::endl;
        std::cout << "0. Sair" << std::endl;
    }

    void executeUseCase(int choice) {
        if (choice > 0 && choice <= useCases.size()) {
            useCases[choice - 1]->execute();
        } else if (choice == useCases.size() + 1) {
            mostrarTodosOsPedidos();
        } else {
            std::cout << "Escolha inválida" << std::endl;
        }
    }

    void mostrarTodosOsPedidos() {
        std::vector<Pedido> pedidos = daoManager->getPedidoDao()->getAllPedidos();
        for (const Pedido& pedido : pedidos) {
            std::cout << "Pedido ID: " << pedido.getId() << ", Descrição: " << pedido.getDescricao() << ", Situação: " << pedido.getSituacao() << std::endl;
        }
    }
};

void setup(DaoManager* daoManager) {
    Cliente cliente1("Cliente 1", "12345678901", "Endereco 1", "Telefone 1", "email1@example.com", CategoriaCliente::PESSOA_FISICA);
    Cliente cliente2("Cliente 2", "98765432109", "Endereco 2", "Telefone 2", "email2@example.com", CategoriaCliente::PESSOA_JURIDICA);
    daoManager->getClienteDao()->adicionarCliente(cliente1);
    daoManager->getClienteDao()->adicionarCliente(cliente2);

    Pedido pedido1(1, std::time(nullptr), "Descricao Pedido 1", Situacao::ABERTO, "12345678901");
    Pedido pedido2(2, std::time(nullptr), "Descricao Pedido 2", Situacao::ABERTO, "98765432109");
    daoManager->getPedidoDao()->addPedido(pedido1);
    daoManager->getPedidoDao()->addPedido(pedido2);

    Pagamento pagamento1(1, 100.0f, std::time(nullptr), FormaPagamento::DINHEIRO, SituacaoPagamento::QUITADO);
    Pagamento pagamento2(2, 200.0f, std::time(nullptr), FormaPagamento::CREDITO, SituacaoPagamento::EM_HAVER);
    daoManager->getPagamentoDao()->adicionarPagamento(pagamento1);
    daoManager->getPagamentoDao()->adicionarPagamento(pagamento2);

    NotaFiscal notaFiscal1(1, std::time(nullptr), 1);
    NotaFiscal notaFiscal2(2, std::time(nullptr), 2);
    daoManager->getNotaFiscalDao()->addNotaFiscal(notaFiscal1);
    daoManager->getNotaFiscalDao()->addNotaFiscal(notaFiscal2);
}

int main() {
    DaoManager daoManager;
    DvoManager dvoManager;
    PedidoManager pedidoManager(&daoManager, &dvoManager);
    ClienteManager clienteManager(&daoManager, &dvoManager);

    setup(&daoManager);

    Menu menu(&daoManager);
    menu.addUseCase(new RealizarPedido(&pedidoManager, &clienteManager));
    menu.addUseCase(new RealizarPagamento(&pedidoManager, &clienteManager));
    menu.addUseCase(new AtualizarSituacaoPedido());
    menu.addUseCase(new AtualizarSituacaoPagamento());
    menu.addUseCase(new BuscarPedido());
    menu.addUseCase(new BuscarPagamento());

    int choice;
    do {
        menu.display();
        std::cout << "Digite sua escolha: ";
        std::cin >> choice;
        if (choice != 0) {
            menu.executeUseCase(choice);
        }
    } while (choice != 0);

    std::cout << "Saindo..." << std::endl;
    return 0;
}
