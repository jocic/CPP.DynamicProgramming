#include <iostream>
#include <map>
#include <cstdlib>

using namespace std;

/**
 * Generic Dynamic Programming implementation.
 *
 * @author    Djordje Jocic <office@djordjejocic.com>
 * @copyright 2022 All Rights Reserved
 * @version   1.0.0
 *
 * @param int n
 *   N-th number of element in the Fibonacci sequence
 *   that the function should return.
 * @return int
 *   Value of the N-th element in the Fibonacci sequence.
 */
int fib_dyn(int n) {

    if (n <= 2) {
        return 1;
    }

    return fib_dyn(n - 1) + fib_dyn(n - 2);
}

/**
 * DP implementation optimized with the Memoization pattern.
 *
 * @author    Djordje Jocic <office@djordjejocic.com>
 * @copyright 2022 All Rights Reserved
 * @version   1.0.0
 *
 * @param int n
 *   N-th number of element in the Fibonacci sequence
 *   that the function should return.
 * @return int
 *   Value of the N-th element in the Fibonacci sequence.
 */
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

/**
 * DP implementation optimized with the Tabulation pattern.
 *
 * @author    Djordje Jocic <office@djordjejocic.com>
 * @copyright 2022 All Rights Reserved
 * @version   1.0.0
 *
 * @param int n
 *   N-th number of element in the Fibonacci sequence
 *   that the function should return.
 * @return int
 *   Value of the N-th element in the Fibonacci sequence.
 */
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

/**
 * Arbitrary solution to the problem.
 *
 * @author    Djordje Jocic <office@djordjejocic.com>
 * @copyright 2022 All Rights Reserved
 * @version   1.0.0
 *
 * @param int n
 *   N-th number of element in the Fibonacci sequence
 *   that the function should return.
 * @return int
 *   Value of the N-th element in the Fibonacci sequence.
 */
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

/**
 * Test implementation for the "001-fib" problem.
 *
 * Problem: Write a function `fib(n)` that takes in a
 * number as an argument. The function should return
 * the n-th number of the Fibonacci sequence.
 *
 * @author    Djordje Jocic <office@djordjejocic.com>
 * @copyright 2022 All Rights Reserved
 * @version   1.0.0
 *
 * @param int argc
 *   Number of passed arguments.
 * @return char* argv[]
 *   Array containing passed arguments.
 */
int main(int argc, char* argv[]) {

    cout << "FIB (DP - Unoptimized): " << fib_dyn(16) << endl;
    cout << "FIB (DP - Memoization): " << fib_dynm(124) << endl;
    cout << "FIB (DP - Tabulation): " << fib_dynt(232) << endl;
    cout << "FIB (DP - Arbitrary): " << fib_reg(300) << endl;

    return 0;
}
