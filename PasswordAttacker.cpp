/**
 * @name Deniz Mutlu
 */
/**
 * Problem
Passwords are widely used in our lives: for ATMs, online forum logins, mobile device unlock and door access. Everyone
 cares about password security. However, attackers always find ways to steal our passwords. Here is one possible
 situation:

Assume that Eve, the attacker, wants to steal a password from the victim Alice. Eve cleans up the keyboard beforehand.
 After Alice types the password and leaves, Eve collects the fingerprints on the keyboard. Now she knows which keys are
 used in the password. However, Eve won't know how many times each key has been pressed or the order of the keystroke
 sequence.

To simplify the problem, let's assume that Eve finds Alice's fingerprints only occurs on M keys. And she knows,
 by another method, that Alice's password contains N characters. Furthermore, every keystroke on the keyboard only
 generates a single, unique character. Also, Alice won't press other irrelevant keys like 'left', 'home', 'backspace'
 and etc.

Here's an example. Assume that Eve finds Alice's fingerprints on M=3 key '3', '7' and '5', and she knows that Alice's
 password is N=4-digit in length. So all the following passwords are possible: 3577, 3557, 7353 and 5735. (And, in fact,
 there are 32 more possible passwords.) -> returns 36.

However, these passwords are not possible:

1357  // There is no fingerprint on key '1'
3355  // There is fingerprint on key '7',
         so '7' must occur at least once.
357   // Eve knows the password must be a 4-digit number.
 */

#include <iostream>

using namespace std;

[[maybe_unused]] std::string ttt([[maybe_unused]] const std::string &k, int m);

int passwordSolver(int n, int m);

[[maybe_unused]] double combination(double number, double n);

double permutation(double number, double n);

double factoriel(double number);

int main() {
    int m; // password contains m different keys.
    int n; // password contains n digits.
    std::cin >> n >> m;
    if (m >= 3 && n >= 3 && m <= n) {
        std::cout << "number of digits " << n << std::endl;
        std::cout << "number of keys " << m << std::endl;
        passwordSolver(n, m);
    } else {
        std::cout << "impossible password" << std::endl;
    }
    ttt("", 5);

//    delete &ttt;
//std::cout << combination(31,12);
    return 0;
}

[[nodiscard]] int passwordSolver(int n, int m) {
//    int nMinusM = n - m;
//    int keysquare = m;
//    int solution;
//    for (int i = 1; i < nMinusM; i++) {
//        keysquare *= keysquare;
//    }
//    solution = factoriel(m) * factoriel(n) / m * factoriel(n - m);
//    return solution;
    int k = 1;
    for (int i = 0; i < n - m; i++) {
        k *= m;
    }
    int solution = 1;
    solution *= k;
    solution *= factoriel(m);
    solution *= factoriel(n-m+1);
//    solution *= combination(n-m,m);
    std::cout << solution << std::endl;

    int abc;
    return 0;
}

double permutation(double number, double n) {
    double numberFactoriel = factoriel(number);
    double nFactoriel = factoriel(number - n);
    return numberFactoriel / nFactoriel;
}

[[maybe_unused]] double combination(double number, double n) {
    return permutation(number, n) / factoriel(n);
}

double factoriel(double number) {
    double factoriel = 1;
    for (double i = 1; i < number + 1; i++) {
        factoriel *= i;
    }
    return factoriel;
}

[[maybe_unused]] std::string ttt([[maybe_unused]] const std::string &k, int m) {
    return "234";
}
