#pragma once

#include "ClienteDvo.hpp"
#include <vector>

class DvoManager {
public:
    DvoManager();
    std::vector<ClienteDvo> getClienteDvo();

private:
    std::vector<ClienteDvo> clienteDvo;
};
