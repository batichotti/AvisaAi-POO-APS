#include "ClienteDvo.hpp"

ClienteDvo::ClienteDvo(){

}

bool ClienteDvo::validarDocumento(const std::string &documentoIdentificador) const {
    return !documentoIdentificador.empty() && documentoIdentificador.size() >= 8;
}
