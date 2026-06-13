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
    std::string res = "";
    std::string* arr = new std::string[totalBales + 1];
    auto rem_it = circle.begin();
    size_t rem_count = circle.size();
    for (size_t i = 0; i < rem_count; ++i) {
        arr[(*rem_it).originIndex] = "хитрый купец";
        rem_it.next();
    }
    for (int i = 1; i <= totalBales; ++i) {
        if (arr[i] != "хитрый купец") {
            arr[i] = "второй купец";
        }
        res += "позиция " + std::to_string(i) + ": " + arr[i] + "\n";
    }
    delete[] arr;
    return res;
}