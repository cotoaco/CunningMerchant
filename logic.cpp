#include "logic.h"
MerchantSolver::MerchantSolver(int n, int m, int k)
    : n(n), m(m), k(k) {}
std::string MerchantSolver::solve() {
    CircularList<Bale> circle;
    int totalBales = 2 * n;
    for (int i = 1; i <= totalBales; ++i) {
        circle.push_back({i, "хитрый купец"});
    }
    auto it = circle.begin();
    for (int i = 1; i < m; ++i) {
        it.next();
    }
    for (int thrown = 0; thrown < n; ++thrown) {
        for (int step = 0; step < k; ++step) {
            it.next();
        }
        (*it).owner = "обычный купец";
        circle.eraseAndNext(it);
    }
    std::string* arr = new std::string[totalBales + 1];
    auto rem_it = circle.begin();
    size_t rem_count = circle.size();
    for (size_t i = 0; i < rem_count; ++i) {
        arr[(*rem_it).originIndex] = "хитрый купец";
        rem_it.next();
    }
    std::string cunningMerchantPos = "";
    for (int i = 1; i <= totalBales; ++i) {
        if(arr[i] == "хитрый купец") {
            cunningMerchantPos += std::to_string(i) + ", ";
        }
    }
    if (!cunningMerchantPos.empty()){
        cunningMerchantPos.pop_back();
        cunningMerchantPos.pop_back();
    }
    std::string res = "";
    res += "\n Позиции тюков хитрого купца: [" + cunningMerchantPos + "]\n";
    delete[] arr;
    return res;
}