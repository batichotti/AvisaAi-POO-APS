#include "DvoManager.hpp"

DvoManager::DvoManager() {
    clienteDvo = new ClienteDvo();
}

ClienteDvo* DvoManager::getClienteDvo() {
    return clienteDvo;
}
