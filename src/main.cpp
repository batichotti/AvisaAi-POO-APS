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
        std::cout << "Enter client document: ";
        std::cin >> documento;
        std::cout << "Enter order description: ";
        std::cin.ignore();
        std::getline(std::cin, descricao);

        Cliente cliente = clienteManager->busqueCliente(documento);
        if (cliente.getDocumentoIdentificador() == documento) {
            pedidoManager->criePedido(documento, 0, std::time(nullptr), descricao);
            std::cout << "Order created successfully" << std::endl;
        } else {
            std::cout << "Client not found" << std::endl;
        }
    }

    std::string getName() override {
        return "Realizar Pedido";
    }
};

class CadastrarPagamento : public UseCase {
public:
    void execute() override {
        std::cout << "Executing Cadastrar Pagamento" << std::endl;
    }
    std::string getName() override {
        return "Cadastrar Pagamento";
    }
};

class AtualizarSituacaoPedido : public UseCase {
public:
    void execute() override {
        std::cout << "Executing Atualizar Situacao Pedido" << std::endl;
    }
    std::string getName() override {
        return "Atualizar Situacao Pedido";
    }
};

class AtualizarSituacaoPagamento : public UseCase {
public:
    void execute() override {
        std::cout << "Executing Atualizar Situacao Pagamento" << std::endl;
    }
    std::string getName() override {
        return "Atualizar Situacao Pagamento";
    }
};

class BuscarPedido : public UseCase {
public:
    void execute() override {
        std::cout << "Executing Buscar Pedido" << std::endl;
    }
    std::string getName() override {
        return "Buscar Pedido";
    }
};

class BuscarPagamento : public UseCase {
public:
    void execute() override {
        std::cout << "Executing Buscar Pagamento" << std::endl;
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
        std::cout << "Main Menu" << std::endl;
        for (size_t i = 0; i < useCases.size(); ++i) {
            std::cout << i + 1 << ". " << useCases[i]->getName() << std::endl;
        }
        std::cout << "0. Exit" << std::endl;
    }

    void executeUseCase(int choice) {
        if (choice > 0 && choice <= useCases.size()) {
            useCases[choice - 1]->execute();
        } else {
            std::cout << "Invalid choice" << std::endl;
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
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        if (choice != 0) {
            menu.executeUseCase(choice);
        }
    } while (choice != 0);

    std::cout << "Exiting..." << std::endl;
    return 0;
}
