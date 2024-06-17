#include <iostream>
#include <vector>
using namespace std;

class Edificio {
public:
    int altura;
    int ancho;

    Edificio(int alturaEdificio, int anchoEdificio){
        altura = alturaEdificio;
        ancho = anchoEdificio;
    }
};

class Skyline {
public:
    vector<Edificio> edificios;
    int caso;

    Skyline(int cant_edificios, int caso){
        edificios.reserve(cant_edificios);
        this->caso = caso;
    }

    void agregarEdificio(Edificio edificio){
        edificios.push_back(edificio);
    }

    int maxSubsecuenciaCreciente(){
        vector<int> widths(edificios.size(), 0);

        for (int i = 0; i < edificios.size(); ++i) {
            widths[i] = edificios[i].ancho;
        }

        for (int i = 1; i < edificios.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if(edificios[i].altura > edificios[j].altura && widths[i] < edificios[i].ancho + widths[j]){
                    widths[i] = widths[j] + edificios[i].ancho;
                }
            }
        }

        int maxValue = 0;
        for (int width : widths) {
            if(width > maxValue){
                maxValue = width;
            }
        }
        return maxValue;
    }

    int maxSubsecuenciaDecreciente(){
        vector<int> widths(edificios.size(), 0);

        for (int i = 0; i < edificios.size(); ++i) {
            widths[i] = edificios[i].ancho;
        }

        for (int i = 1; i < edificios.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if(edificios[i].altura < edificios[j].altura && widths[i] < edificios[i].ancho + widths[j]){
                    widths[i] = widths[j] + edificios[i].ancho;
                }
            }
        }

        int maxValue = 0;
        for (int width : widths) {
            if(width > maxValue){
                maxValue = width;
            }
        }
        return maxValue;
    }

    int crece_(){
        return maxSubsecuenciaCreciente() >= maxSubsecuenciaDecreciente();
    }
};

int main() {
    int cant_casos;
    cin >> cant_casos;

    vector<Skyline> casos_totales;

    for (int i = 0; i < cant_casos; ++i) {
        int cantidad_edificios;
        cin >> cantidad_edificios;

        vector<int> alturas(cantidad_edificios);
        vector<int> anchos(cantidad_edificios);

        for (int j = 0; j < cantidad_edificios; ++j) {
            cin >> alturas[j];
        }

        for (int j = 0; j < cantidad_edificios; ++j) {
            cin >> anchos[j];
        }

        Skyline skyline(cantidad_edificios, i + 1);

        for (int j = 0; j < cantidad_edificios; ++j) {
            Edificio building(alturas[j], anchos[j]);
            skyline.agregarEdificio(building);
        }
        casos_totales.push_back(skyline);
    }

    for (size_t j = 0; j < casos_totales.size(); j++) {
        string result;

        if (casos_totales[j].crece_()) {
            result = "Increasing (" + to_string(casos_totales[j].maxSubsecuenciaCreciente()) + "). " + "Decreasing (" + to_string(
                    casos_totales[j].maxSubsecuenciaDecreciente()) + ").";
        } else {
            result = "Decreasing (" + to_string(casos_totales[j].maxSubsecuenciaDecreciente()) + "). " + "Increasing (" + to_string(
                    casos_totales[j].maxSubsecuenciaCreciente()) + ").";
        }

        cout << "Case " << casos_totales[j].caso << ". " << result << endl;
    }

}
