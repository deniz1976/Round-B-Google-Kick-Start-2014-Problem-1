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

The first line of the input gives the number of test cases, T.

For the next T lines, each contains two space-separated numbers M and N, indicating a test case.

For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the total number of possible passwords modulo 1000000007(109+7).

T = 15.
1 ≤ M ≤ N ≤ 7.

4
1 1
3 4
5 5
15 15
 
Case #1: 1
Case #2: 36
Case #3: 120
Case #4: 674358851

 */

#include <iostream>

const int MOD = 1000000007;

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

long long power(long long base, int exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp & 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return result;
}

long long modInverse(long long a) {
    return power(a, MOD - 2);
}

long long nCr(int n, int r) {
    if (r > n) return 0;
    long long num = factorial(n);
    long long den = (factorial(r) * factorial(n - r)) % MOD;
    return (num * modInverse(den)) % MOD;
}

long long calculatePasswords(int M, int N) {
    long long result = 0;
    
    for (int m = 0; m <= M; m++) {
        long long term = nCr(M, m);
        term = (term * power(M - m, N)) % MOD;
        if (m % 2 == 0) {
            result = (result + term) % MOD;
        } else {
            result = (result - term + MOD) % MOD;
        }
    }
    
    return result;
}

int main() {
    int T;
    std::cin >> T;
    
    for (int t = 1; t <= T; t++) {
        int M, N;
        std::cin >> M >> N;
        
        long long result = calculatePasswords(M, N);
        std::cout << "Case #" << t << ": " << result << std::endl;
    }
    
    return 0;
}
