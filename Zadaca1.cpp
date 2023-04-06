#include <iostream>
#include <string>
#include <map>

using namespace std;

class Uplata {
public:
    string stedac;
    double iznos;

    Uplata(string stedac, double iznos) {
        this->stedac = stedac;
        this->iznos = iznos;
    }
};

int main() {
    multimap<string, double> uplati;
    int izbor;
    do {
        cout << "1. Dodadi uplata" << endl;
        cout << "2. Prikazi uplati za daden stedac" << endl;
        cout << "3. Kraj" << endl;
        cout << "Izbor: ";
        cin >> izbor;
        switch (izbor) {
            case 1: {
                string stedac;
                double iznos;
                cout << "Stedac: ";
                cin >> stedac;
                cout << "Iznos: ";
                cin >> iznos;
                Uplata u(stedac, iznos);
                uplati.insert(pair<string, double>(u.stedac, u.iznos));
                break;
            }
            case 2: {
                string stedac;
                cout << "Stedac: ";
                cin >> stedac;
                auto range = uplati.equal_range(stedac);
                double vkupno = 0.0;
                for (auto it = range.first; it != range.second; ++it) {
                    vkupno += it->second;
                    cout << it->second << endl;
                }
                cout << "Vkupno: " << vkupno << endl;
                break;
            }
            case 3:
                cout << "Kraj" << endl;
                break;
            default:
                cout << "Nevaliden izbor" << endl;
                break;
        }
    } while (izbor != 3);

    return 0;
}
