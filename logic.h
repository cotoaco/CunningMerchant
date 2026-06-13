#ifndef LOGIC_H
#define LOGIC_H
#include <string>
#include "list.h"
struct Bale {
    int originIndex;
    std::string owner;
};
class MerchantSolver {
private:
    int n;
    int m;
    int k;
public:
    MerchantSolver(int n, int m, int k);
    std::string solve();
};
#endif