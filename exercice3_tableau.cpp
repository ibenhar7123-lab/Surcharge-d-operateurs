#include <iostream>
#include <stdexcept>
using namespace std;

class Tableau {
private:
    int* data;
    int taille;

public:
    // Constructeur : alloue dynamiquement et initialise à 0
    Tableau(int taille) : data(nullptr), taille(taille) {
        if (taille <= 0) {
            throw invalid_argument("La taille doit être strictement positive");
        }
        data = new int[taille];
        for (int i = 0; i < taille; i++) {
            data[i] = 0;
        }
    }

    // Constructeur de copie (copie profonde, évite le double delete)
    Tableau(const Tableau& autre) : data(new int[autre.taille]), taille(autre.taille) {
        for (int i = 0; i < taille; i++) {
            data[i] = autre.data[i];
        }
    }

    // Opérateur d'affectation (copie profonde)
    Tableau& operator=(const Tableau& autre) {
        if (this != &autre) {
            delete[] data;
            taille = autre.taille;
            data = new int[taille];
            for (int i = 0; i < taille; i++) {
                data[i] = autre.data[i];
            }
        }
        return *this;
    }

    // Destructeur : libère la mémoire
    ~Tableau() {
        delete[] data;
        cout << "[Destructeur] Mémoire libérée" << endl;
    }

    // Surcharge de [] (lecture/écriture) avec vérification des bornes
    int& operator[](int index) {
        if (index < 0 || index >= taille) {
            throw out_of_range("Index invalide : " + to_string(index));
        }
        return data[index];
    }

    // Version const (lecture seule)
    const int& operator[](int index) const {
        if (index < 0 || index >= taille) {
            throw out_of_range("Index invalide : " + to_string(index));
        }
        return data[index];
    }

    int getTaille() const { return taille; }
};

int main() {
    try {
        Tableau t(5);

        // Écriture via []
        for (int i = 0; i < t.getTaille(); i++) {
            t[i] = (i + 1) * 10;
        }

        // Lecture via []
        for (int i = 0; i < t.getTaille(); i++) {
            cout << "t[" << i << "] = " << t[i] << endl;
        }

        // Accès hors bornes -> exception
        cout << "\nAccès à t[10] :" << endl;
        cout << t[10] << endl;
    }
    catch (const out_of_range& e) {
        cerr << "Exception : " << e.what() << endl;
    }
    catch (const invalid_argument& e) {
        cerr << "Exception : " << e.what() << endl;
    }

    return 0;
}
