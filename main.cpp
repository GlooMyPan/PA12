#include <string>
#include "Natuerlich.h"


// berechne n. Fibonacci-Zahl
Natuerlich fibonacci(size_t n) {
    Natuerlich fibo0 = 0;

    if (n == 0)
        return fibo0;

    Natuerlich fibo1 = 1;

    for (size_t k = 2; k <= n; ++k) {
        Natuerlich fiboK = fibo0 + fibo1;
        fibo0 = fibo1;
        fibo1 = fiboK;
    }

    return fibo1;

}  // fibonacci()


// berechne Binomialkoeffizient "n 黚er k"
/*Natuerlich binom(size_t n, size_t k) {
    if (k == 0 || k == n)
        return 1;
    return binom(n - 1, k) + binom(n - 1, k - 1);
}*/

/** mit Dynamic Programming **/
Natuerlich binom(size_t n, size_t k) {
    vector<vector<Natuerlich>> dp(n+1, vector<Natuerlich>(k+1, 0));
    for (size_t i = 0; i <= n; ++i) {
        for (size_t j = 0; j <= min(i, k); ++j) {
            if (j == 0 || j == i)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
        }
    }
    return dp[n][k];
}


/**********************************************************/

// symbolische case-Marken
char const ADDITION = '+';
char const BINOM1 = 'b';
char const BINOM2 = 'B';
char const FIBONACCI1 = 'f';
char const FIBONACCI2 = 'F';


int main(int narg, char *argv[]) {
    // gebe Usage aus
    cout << "Usage: " << argv[0] << "  m  op  n" << endl;
    cout << "       m, n: natuerliche Zahlen >= 0" << endl;
    cout << "       op  : Operator '+' 'b' 'B' 'f' 'F'" << endl;
    cout << "Berechnet Ergebnis des Ausdrucks \"m op n\"." << endl;
    cout << "   op = '+'     : Summe m + n" << endl;
    cout << "   op = 'b' 'B' : binom( m, n )" << endl;
    cout << "   op = 'f' 'F' : fibonacci( m ) [n wird ggf. ignoriert]" << endl;
    cout << "Ein ungueltiger Operator beendet das Programm." << endl;
    cout << endl;

    while (true) {
        /***  lese m und op ein  ***/

        string input;
        char op;
        cout << "m op n = ";
        cin >> input >> op;

        /***  berechne den Ausdruck  ***/

        Natuerlich ergebnis;

        switch (op) {
            case ADDITION: {
                Natuerlich m = input;
                cin >> input;            // lese n ein
                Natuerlich n = input;

                ergebnis = m + n;
                break;
            }

            case BINOM1:
            case BINOM2: {
                size_t n = atoi(input.c_str());
                cin >> input;            // lese n ein
                size_t k = atoi(input.c_str());
                ergebnis = binom(n, k);
                break;
            }

            case FIBONACCI1:
            case FIBONACCI2: {
                size_t n = atoi(input.c_str());
                ergebnis = fibonacci(n);
                break;
            }

            default:    // kein g黮tiger operator -> Abbruch
                return 0;

        }  // switch ( op )

        /***  gebe Ergebnis aus  ***/

        cout << ergebnis << endl;
        cout << endl;

    }  // while ( true )

    return 0;     // alles OK

}  // main()