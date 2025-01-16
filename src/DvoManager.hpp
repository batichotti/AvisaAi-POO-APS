#pragma once

#include "ClienteDvo.hpp"

class DvoManager {
public:
    DvoManager();
    ClienteDvo* getClienteDvo();

private:
    ClienteDvo* clienteDvo;
};
