#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

typedef long long ll;

int main() {

    double n;
    cin >> n;

    cout << fixed << setprecision(10) << n << endl;

    ll diagonal_number = ceil(-0.5 + sqrt((8 * n + 1) / 4));
    cout << "diagonal_number' = " << -0.5 + sqrt((8 * n + 1) / 4) << endl;
    cout << "diagonal_number = " << diagonal_number << endl;

    ll number_in_diagonal = n - (diagonal_number * (diagonal_number - 1) / 2 + 1) + 1;
    cout << "number_in_diagonal = " << number_in_diagonal << endl;

    if (diagonal_number % 2 == 0)
        cout << diagonal_number - number_in_diagonal + 1 << "/" << number_in_diagonal << endl;
    else
        cout << number_in_diagonal << "/" << diagonal_number - number_in_diagonal + 1 << endl;
    
    return 0;

}
