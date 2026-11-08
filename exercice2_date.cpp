#include <iostream>
using namespace std;

class Date {
private:
    int jour;
    int mois;
    int annee;

public:
    // Constructeur par défaut : 01/01/1970
    Date() : jour(1), mois(1), annee(1970) {}

    // Constructeur avec paramètres
    Date(int j, int m, int a) : jour(j), mois(m), annee(a) {}

    // Constructeur de copie
    Date(const Date& autre)
        : jour(autre.jour), mois(autre.mois), annee(autre.annee) {}

    // Surcharge de ==
    bool operator==(const Date& autre) const {
        return jour == autre.jour && mois == autre.mois && annee == autre.annee;
    }

    // Surcharge de != (réutilise ==)
    bool operator!=(const Date& autre) const {
        return !(*this == autre);
    }

    void afficher() const {
        cout << (jour < 10 ? "0" : "") << jour << "/"
             << (mois < 10 ? "0" : "") << mois << "/"
             << annee;
    }
};

int main() {
    Date d1(15, 3, 2024);
    Date d2(15, 3, 2024);
    Date d3(1, 9, 2025);
    Date d4;  // date par défaut

    cout << "d1 = "; d1.afficher(); cout << endl;
    cout << "d2 = "; d2.afficher(); cout << endl;
    cout << "d3 = "; d3.afficher(); cout << endl;
    cout << "d4 = "; d4.afficher(); cout << endl << endl;

    cout << boolalpha;  // affiche true/false au lieu de 1/0
    cout << "d1 == d2 : " << (d1 == d2) << endl;
    cout << "d1 == d3 : " << (d1 == d3) << endl;
    cout << "d1 != d3 : " << (d1 != d3) << endl;
    cout << "d1 != d2 : " << (d1 != d2) << endl;

    return 0;
}
