#include <bits/stdc++.h>
using namespace std;

int extended_euclidean(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}

int mod_inv(int a, int m) {
    int x, y;
    int g = extended_euclidean(a, m, x, y);
    if (g != 1) {
        cout << "No solution!";
        return -1;
    }
    else {
        x = (x % m + m) % m;
        // cout << x << endl;
    }
    return x;
}

int main() {
    cout << mod_inv(2, 1000000007);
    return 0;
}

