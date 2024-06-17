#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define infinity 0x7FFFFFFF

using namespace std;

class Graph {
public:
    vector<vector<pair<int, int>>> weights;
    explicit Graph(int n) : weights(n) {} // Initialize weights with n empty vectors
};

// calcular costo minimo entre dos vertices.
int costoMinimo(string clave1, string clave2){
    int minCosto = 0;
    for (int i = 0; i < 4; ++i) {
        minCosto += min(abs(clave1[i] - clave2[i]), 10 - abs(clave1[i] - clave2[i]));
    }
    return minCosto;
}

// AGM prim
int AGM_prim(const Graph& g, int n) {
    // Miro las adyacencias al vértice donde estoy parado.
    // Si ya fue visitado, no lo visito.
    // Si no fue visitado, entonces:
    //     - Lo marco como visitado.
    //     - Acumulo los menores pesos en res.
    //     - Miro las adyacencias desde un nuevo vértice (determinado por a).
    // Repito n = |V| veces el procedimiento.

    int res = 0, k = 0;
    // Forma de implementar un min-heap.
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> queue;
    vector<bool> visitados(n, false); // Initialize all vertices as unvisited
    // Empezamos desde (0,0) y construimos la solución.
    
    queue.emplace(0,0);
    while (k < n) {
        int a = queue.top().second;
        int w = queue.top().first;
        queue.pop();

        if (!visitados[a]) {
            visitados[a] = true;
            res += w;
            for (int i = 0; i < g.weights[a].size(); ++i) {
                // Como mi "comparación" en el heap es el peso, lo pongo primero.
                queue.emplace(g.weights[a][i].second, g.weights[a][i].first);
            }
            ++k;
        }
    }
    return res;
}


// Codigo principal
int main() {
    int T, n, v, c, mst;
    cin >> T;

    while(T--) {
        string claveCero = "0000";
        v = infinity; // tendrá el mínimo costo de 0 a cualquier lock (luego del primer for)
        cin >> n;

        vector<string> claves(n);
        for (int i = 0; i < n; ++i) {
            cin >> claves[i];
            v = min(v, costoMinimo(claveCero,claves[i]));
        }

        // preparo el grafo
        Graph g(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                c = costoMinimo(claves[i], claves[j]);
                g.weights[i].emplace_back(j, c);
                g.weights[j].emplace_back(i, c);
            }
        }
        // imprime el costo de 0000 -> cualq. vertice + costo del AGM.
        mst = AGM_prim(g, n);
        cout << v + mst << "\n";
    }

    return 0;
}
