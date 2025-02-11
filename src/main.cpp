#include <iostream>
#include <vector>
#include <cstdlib> //para std::rand
#include <ctime>
#include <iomanip> //para ter o std::setprecision
#include "PedidoManager.hpp"
#include "ClienteManager.hpp"
#include "PagamentoManager.hpp"

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

        Cliente cliente = clienteManager->busqueCliente(documento);
        if (cliente.getDocumentoIdentificador().empty()) {
            std::cout << "Documento do cliente inválido" << std::endl;
            return;
        }

        std::cout << "Digite a descrição do pedido: ";
        std::cin.ignore();
        std::getline(std::cin, descricao);

        pedidoManager->criePedido(documento, 0, std::time(nullptr), descricao);
    }

    std::string getName() override {
        return "Realizar Pedido";
    }
};

class RealizarPagamento : public UseCase {
private:
    PedidoManager* pedidoManager;
    ClienteManager* clienteManager;
    PagamentoManager* pagamentoManager;
    std::string documento;

    float calcularValorAPagar(FormaPagamento fp) {
        float valor = 50 + (std::rand() % 951);
        switch (fp){
        case FormaPagamento::DINHEIRO:
            valor = valor * 0.95;
            break;
            case FormaPagamento::DEBITO:
                valor = valor * 1.05;
                break;
            case FormaPagamento::CREDITO:
                valor = valor * 1.1;
                break;
            case FormaPagamento::PIX:
            valor = valor * 0.97;
            break;
        
        default:
            break;
        }
        return valor;
    }

public:
    RealizarPagamento(PedidoManager* pm, ClienteManager* cm, PagamentoManager* pgm) 
        : pedidoManager(pm), clienteManager(cm), pagamentoManager(pgm) {
        std::srand(std::time(nullptr));
    }

    void execute() override {
        std::cout << "Executando Cadastrar Pagamento" << std::endl;
        std::cout << "Digite o documento do cliente para listar seus pedidos: ";
        std::cin >> documento;

        Cliente cliente = clienteManager->busqueCliente(documento);
        if (cliente.getDocumentoIdentificador().empty()) {
            std::cout << "Documento do cliente inválido" << std::endl;
            return;
        }

        std::cout << "Pedidos do cliente " << cliente.getNome() << std::endl;
        std::vector<Pedido> pedidos = pedidoManager->listePedidosCliente(cliente.getDocumentoIdentificador(), Situacao::ABERTO);
        if (!pedidos.empty()) {
            for (int i = 0; i < pedidos.size(); ++i) {
                std::cout << i + 1 << ". Pedido ID: " << pedidos[i].getId() << ", Descrição: " << pedidos[i].getDescricao() << std::endl;
            }
            int escolha;
            std::cout << "Escolha o pedido para realizar o pagamento: ";
            std::cin >> escolha;
            if (escolha > 0 && escolha <= pedidos.size()) {
                std::cout << "Escolha a forma de pagamento: " << std::endl;
                std::cout << "1. Dinheiro" << std::endl;
                std::cout << "2. Pix" << std::endl;
                std::cout << "3. Débito" << std::endl;
                std::cout << "4. Crédito" << std::endl;
                std::cout << "5. Boleto" << std::endl;
                std::cout << "6. Cheque" << std::endl;
                int formaEscolha;
                std::cin >> formaEscolha;
                
                FormaPagamento forma;
                switch (formaEscolha) {
                    case 1: forma = FormaPagamento::DINHEIRO; break;
                    case 2: forma = FormaPagamento::PIX; break;
                    case 3: forma = FormaPagamento::DEBITO; break;
                    case 4: forma = FormaPagamento::CREDITO; break;
                    case 5: forma = FormaPagamento::BOLETO; break;
                    case 6: forma = FormaPagamento::CHEQUE; break;
                    default: 
                    std::cout << "Forma de pagamento inválida" << std::endl;
                    return;
                }
                float valor = calcularValorAPagar(forma);
                std::cout << "Valor a ser pago: R$ " << std::fixed << std::setprecision(2) << valor << std::endl;
                
                std::cout << "Confirma o pagamento? (s/n): ";
                char confirmacao;
                std::cin >> confirmacao;
                if (confirmacao == 's' || confirmacao == 'S') {
                    pagamentoManager->criarPagamento(pedidos[escolha - 1].getId(), valor, forma, SituacaoPagamento::QUITADO);
                    std::cout << "Pagamento realizado para o pedido ID: " << pedidos[escolha - 1].getId() << std::endl;
                } else {
                    std::cout << "Pagamento cancelado" << std::endl;
                }
            } else {
                std::cout << "Escolha inválida" << std::endl;
            }
        } else {
            std::cout << "Nenhum pedido em aberto encontrado para este cliente" << std::endl;
        }
    }

    std::string getName() override {
        return "Realizar Pagamento";
    }
};

class BuscarPedido : public UseCase {
private:
    PedidoManager* pedidoManager;
    ClienteManager* clienteManager;

public:
    BuscarPedido(PedidoManager* pm, ClienteManager* cm) : pedidoManager(pm), clienteManager(cm) {}

    void execute() override {
        std::string documento;
        std::cout << "Digite o documento do cliente para listar seus pedidos: ";
        std::cin >> documento;

        Cliente cliente = clienteManager->busqueCliente(documento);
        if (cliente.getDocumentoIdentificador().empty()) {
            std::cout << "Documento do cliente inválido" << std::endl;
            return;
        }

        std::cout << "Pedidos do cliente " << cliente.getNome() << std::endl;
        std::vector<Pedido> pedidos = pedidoManager->listePedidosCliente(cliente.getDocumentoIdentificador());
        if (pedidos.empty()) {
            std::cout << "Nenhum pedido encontrado para este cliente" << std::endl;
            return;
        }
        for (int i = 0; i < pedidos.size(); ++i) {
            std::cout << i + 1 << ". Pedido ID: " << pedidos[i].getId() << ", Descrição: " << pedidos[i].getDescricao() << std::endl;
        }
        int escolha;
        std::cout << "Escolha o pedido para visualizar detalhes: ";
        std::cin >> escolha;
        if (escolha > 0 && escolha <= pedidos.size()) {
            Pedido pedido = pedidos[escolha - 1];
            std::cout << "Detalhes do Pedido ID: " << pedido.getId() << std::endl;
            std::cout << "Descrição: " << pedido.getDescricao() << std::endl;
            std::cout << "Situação: ";
            switch (pedido.getSituacao()) {
                case Situacao::ENTREGUE: std::cout << "ENTREGUE"; break;
                case Situacao::RESOLVIDO: std::cout << "RESOLVIDO"; break;
                case Situacao::EM_ANDAMENTO: std::cout << "EM ANDAMENTO"; break;
                case Situacao::ABERTO: std::cout << "ABERTO"; break;
                case Situacao::CANCELADO: std::cout << "CANCELADO"; break;
            }
            std::cout << std::endl;
        } else {
            std::cout << "Escolha inválida" << std::endl;
        }
    }

    std::string getName() override {
        return "Buscar Pedido";
    }
};

class BuscarPagamento : public UseCase {
private:
    PedidoManager* pedidoManager;
    PagamentoManager* pagamentoManager;
    ClienteManager* clienteManager;

public:
    BuscarPagamento(PedidoManager* pm, PagamentoManager* pgm, ClienteManager* cm) 
        : pedidoManager(pm), pagamentoManager(pgm), clienteManager(cm) {}

    void execute() override {
        std::vector<Pedido> pedidos = pedidoManager->listeTodosPedidos();
        if (!pedidos.empty()) {
            for (int i = 0; i < pedidos.size(); ++i) {
                std::cout << i + 1 << ". Pedido ID: " << pedidos[i].getId() << ", Descrição: " << pedidos[i].getDescricao() << std::endl;
            }
            int escolha;
            std::cout << "Escolha o pedido para visualizar detalhes do pagamento: ";
            std::cin >> escolha;
            if (escolha > 0 && escolha <= pedidos.size()) {
                Pedido pedido = pedidos[escolha - 1];
                Pagamento pagamento = pagamentoManager->busquePagamento(pedido.getId());
                if (pagamento.getValor() == 0) {
                    std::cout << "Nenhum pagamento encontrado para este pedido" << std::endl;
                    return;
                }
                std::cout << "Detalhes do Pagamento para Pedido ID: " << pedido.getId() << std::endl;
                std::cout << "Valor: R$ " << pagamento.getValor() << std::endl;
                std::cout << "Forma de Pagamento: ";
                switch (pagamento.getFormaPagamento()) {
                    case FormaPagamento::DINHEIRO: std::cout << "DINHEIRO"; break;
                    case FormaPagamento::PIX: std::cout << "PIX"; break;
                    case FormaPagamento::DEBITO: std::cout << "DEBITO"; break;
                    case FormaPagamento::CREDITO: std::cout << "CREDITO"; break;
                    case FormaPagamento::BOLETO: std::cout << "BOLETO"; break;
                    case FormaPagamento::CHEQUE: std::cout << "CHEQUE"; break;
                }
                std::cout << std::endl;
                std::cout << "Situação: " << pagamento.getSituacao() << std::endl;
            } else {
                std::cout << "Escolha inválida" << std::endl;
            }
        } else {
            std::cout << "Nenhum pedido com pagamento encontrado para este cliente" << std::endl;
        }
    }

    std::string getName() override {
        return "Buscar Pagamento";
    }
};

class MostrarTodosPedidos : public UseCase {
private:
    DaoManager* daoManager;

public:
    MostrarTodosPedidos(DaoManager* dm) : daoManager(dm) {}

    void execute() override {
        std::vector<Pedido> pedidos = daoManager->getPedidoDao()->listePedidos();
        if (pedidos.empty()) {
            std::cout << "Nenhum pedido encontrado." << std::endl;
            return;
        }
        for (const Pedido& pedido : pedidos) {
            std::string situacao;
            switch (pedido.getSituacao()) {
                case Situacao::ENTREGUE:
                    situacao = "ENTREGUE";
                    break;
                case Situacao::RESOLVIDO:
                    situacao = "RESOLVIDO";
                    break;
                case Situacao::EM_ANDAMENTO:
                    situacao = "EM ANDAMENTO";
                    break;
                case Situacao::ABERTO:
                    situacao = "ABERTO";
                    break;
                case Situacao::CANCELADO:
                    situacao = "CANCELADO";
                    break;
            }
            std::cout << "Pedido ID: " << pedido.getId() << ", Descrição: " << pedido.getDescricao() << ", Situação: " << situacao << std::endl;
        }
    }

    std::string getName() override {
        return "Mostrar Todos os Pedidos";
    }
};

class MostrarTodosPagamentos : public UseCase {
private:
    PagamentoManager* pagamentoManager;

public:
    MostrarTodosPagamentos(PagamentoManager* pm) : pagamentoManager(pm) {}

    void execute() override {
        std::vector<Pagamento> pagamentos = pagamentoManager->listarPagamentos();
        if (pagamentos.empty()) {
            std::cout << "Nenhum pagamento encontrado." << std::endl;
            return;
        }
        for (const Pagamento& pagamento : pagamentos) {
            std::cout << "Pagamento Pedido ID: " << pagamento.getPedidoId() << ", Valor: R$ " << pagamento.getValor() << ", Forma: ";
            switch (pagamento.getFormaPagamento()) {
                case FormaPagamento::DINHEIRO: std::cout << "DINHEIRO"; break;
                case FormaPagamento::PIX: std::cout << "PIX"; break;
                case FormaPagamento::DEBITO: std::cout << "DEBITO"; break;
                case FormaPagamento::CREDITO: std::cout << "CREDITO"; break;
                case FormaPagamento::BOLETO: std::cout << "BOLETO"; break;
                case FormaPagamento::CHEQUE: std::cout << "CHEQUE"; break;
            }
            std::cout << ", Situação: ";
            switch (pagamento.getSituacao()) {
                case SituacaoPagamento::EM_HAVER: std::cout << "EM HAVER"; break;
                case SituacaoPagamento::QUITADO: std::cout << "QUITADO"; break;
                case SituacaoPagamento::PARCIALMENTE_PAGO: std::cout << "PARCIALMENTE PAGO"; break;
            }
            std::cout << std::endl;
        }
    }

    std::string getName() override {
        return "Mostrar Todos os Pagamentos";
    }
};

class Menu {
private:
    std::vector<UseCase*> useCases;
    DaoManager* daoManager;
    PagamentoManager* pagamentoManager;
public:
    Menu(DaoManager* daoManager, PagamentoManager* pagamentoManager) 
        : daoManager(daoManager), pagamentoManager(pagamentoManager) {}

    void addUseCase(UseCase* useCase) {
        useCases.push_back(useCase);
    }

    void display() {
        std::cout << "Menu Principal" << std::endl;
        for (int i = 0; i < useCases.size(); ++i) {
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

void setup(DaoManager* daoManager) {
    Cliente cliente1("Cliente 1", "12345678901", "Endereco 1", "Telefone 1", "client1@email.com", CategoriaCliente::PESSOA_FISICA);
    Cliente cliente2("Cliente 2", "98765432100", "Endereco 2", "Telefone 2", "client2@email.com", CategoriaCliente::PESSOA_JURIDICA);
    daoManager->getClienteDao()->adicionarCliente(cliente1);
    daoManager->getClienteDao()->adicionarCliente(cliente2);

    Pedido pedido1(1, std::time(nullptr), "Descricao Pedido 1", Situacao::ENTREGUE, "12345678901");
    Pedido pedido2(2, std::time(nullptr), "Descricao Pedido 2", Situacao::ABERTO, "00736581979");
    daoManager->getPedidoDao()->addPedido(pedido1);
    daoManager->getPedidoDao()->addPedido(pedido2);
}

int main() {
    DaoManager daoManager;
    DvoManager dvoManager;
    PedidoManager pedidoManager(&daoManager, &dvoManager);
    ClienteManager clienteManager(&daoManager, &dvoManager);
    PagamentoManager pagamentoManager(&daoManager);

    setup(&daoManager);

    Menu menu(&daoManager, &pagamentoManager);
    menu.addUseCase(new RealizarPedido(&pedidoManager, &clienteManager));
    menu.addUseCase(new RealizarPagamento(&pedidoManager, &clienteManager, &pagamentoManager));
    menu.addUseCase(new BuscarPedido(&pedidoManager, &clienteManager));
    menu.addUseCase(new BuscarPagamento(&pedidoManager, &pagamentoManager, &clienteManager));
    menu.addUseCase(new MostrarTodosPedidos(&daoManager));
    menu.addUseCase(new MostrarTodosPagamentos(&pagamentoManager));

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
