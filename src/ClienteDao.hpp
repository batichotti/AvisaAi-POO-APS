#pragma once

#include <vector>
#include "Cliente.hpp"

class ClienteDao {
public:
    std::vector<Cliente> list();
};
