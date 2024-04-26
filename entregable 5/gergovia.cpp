#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int cantidadHabitantes;
    cin >> cantidadHabitantes;

    while (true) {
        if (cantidadHabitantes < 2 || cantidadHabitantes > 100000) {
            // If the input is outside the specified range, break out of the loop
            break;
        }

        vector<int> a(cantidadHabitantes);

        for (int i = 0; i < cantidadHabitantes; i++) {
            cin >> a[i];
        }

        int compra = 0;
        int venta = 0;
        unsigned long long total = 0;

        while (compra < cantidadHabitantes && venta < cantidadHabitantes) {
            while (a[compra] <= 0) {
                compra++;
                if (compra == cantidadHabitantes) {
                    cout << total << endl;
                    goto end_loop;
                }
            }

            while (a[venta] >= 0) {
                venta++;
                if (venta == cantidadHabitantes) {
                    cout << total << endl;
                    goto end_loop;
                }
            }

            if (abs(a[compra]) >= abs(a[venta])) {
                total += abs(venta - compra) * abs(a[venta]);
                a[compra] += a[venta];
                a[venta] = 0;
                venta++;
            } else {
                total += abs(venta - compra) * abs(a[compra]);
                a[venta] += a[compra];
                a[compra] = 0;
                compra++;
            }
        }
        cout << total << endl;
        end_loop:
        cin >> cantidadHabitantes;
    }

    return 0;
}
