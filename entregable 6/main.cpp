#include <iostream>
#include <vector>
using namespace std;

int main() {
    uint32_t n;
    string s, t;
    cin >> n >> s >> t;

    vector<uint32_t> pos_ab, pos_ba, res;

    // Vemos las posiciones donde podemos swapear
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            if (s[i] == 'a') {
                pos_ab.push_back(i + 1);
            } else {
                pos_ba.push_back(i + 1);
            }
        }
    }

    // Caso en que no podemos:
    if (pos_ab.size() % 2 != pos_ba.size() % 2) {
        cout << -1 << endl;
        return 0;
    }
    
    // Casos en que podemos:
    // Vectores con longitud par
    if (pos_ab.size() % 2 == 0) {
        //
        for (unsigned int i : pos_ab) {
            res.push_back(i);
        }
        for (unsigned int i : pos_ba) {
            res.push_back(i);
        }
    } else {
        // Vectores con longitud impar
        uint32_t ult = pos_ab.back();
        pos_ab.push_back(ult);
        pos_ba.push_back(ult);

        for (unsigned int i : pos_ab) {
            res.push_back(i);
        }
        for (unsigned int i : pos_ba) {
            res.push_back(i);
        }
    }

    // Imprimo res:
    cout << res.size() / 2 << endl;
    for (int i = 0; i < res.size(); i += 2) {
        cout << res[i] << " " << res[i + 1] << endl;
    }

    return 0;
}
