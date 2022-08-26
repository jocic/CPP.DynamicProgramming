#include <iostream>
#include <map>
#include <cstdlib>

using namespace std;

int fib_dyn(int n) {

    if (n <= 2) {
        return 1;
    }

    return fib_dyn(n - 1) + fib_dyn(n - 2);
}

int fib_dynm(int n) {

    static map<int,int> m = {};

    auto search = m.find(n);

    if (search != m.end()) {
        return search->first;
    }

    if (n <= 2) {
        return 1;
    }

    int result = fib_dynm(n - 1) + fib_dynm(n - 2);

    m.insert({ n, result });

    return result;
}

int fib_dynt(int n) {

    int  n_max = n + 1;
    int* tab   = (int*)calloc(n_max, sizeof(int));

    tab[1] = 1;

    for (int i = 0, j = 1, k = 2;
         i < n; i++, j = i + 1, k = i + 2) {

        if (j < n_max) {
            tab[j] += tab[i];
        }

        if (k < n_max) {
            tab[k] += tab[i];
        }
    }

    return tab[n];
}

int fib_reg(int n) {
    \
    int prev = 1;
    int curr = 1;

    int temp;

    for (int i = 2; i < n; i++) {
        temp  = curr;
        curr += prev;
        prev  = temp;
    }

    return curr;
}

int main() {

    cout << "FIB (DYN): " << fib_dyn(16) << endl;
    cout << "FIB (DYNM): " << fib_dynm(1244) << endl;
    cout << "FIB (DYNT): " << fib_dynt(16) << endl;
    cout << "FIB (REG): " << fib_reg(16) << endl;

    return 0;
}
