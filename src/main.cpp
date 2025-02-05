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

class CadastrarPagamento : public UseCase {
public:
    void execute() override {
        std::cout << "Executando Cadastrar Pagamento" << std::endl;
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
public:
    void addUseCase(UseCase* useCase) {
        useCases.push_back(useCase);
    }

    void display() {
        std::cout << "Menu Principal" << std::endl;
        for (size_t i = 0; i < useCases.size(); ++i) {
            std::cout << i + 1 << ". " << useCases[i]->getName() << std::endl;
        }
        std::cout << "0. Sair" << std::endl;
    }

    void executeUseCase(int choice) {
        if (choice > 0 && choice <= useCases.size()) {
            useCases[choice - 1]->execute();
        } else {
            std::cout << "Escolha inválida" << std::endl;
        }
    }
};

int main() {
    DaoManager daoManager;
    DvoManager dvoManager;
    PedidoManager pedidoManager(&daoManager, &dvoManager);
    ClienteManager clienteManager(&daoManager, &dvoManager);

    Menu menu;
    menu.addUseCase(new RealizarPedido(&pedidoManager, &clienteManager));
    menu.addUseCase(new CadastrarPagamento());
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
