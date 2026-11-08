#include <iostream>
using namespace std;

class Vecteur2D {
private:
    double x;
    double y;

public:
    // Constructeur (valeurs par défaut : vecteur nul)
    Vecteur2D(double x = 0, double y = 0) : x(x), y(y) {}

    // Surcharge de l'opérateur + : retourne un NOUVEAU vecteur
    Vecteur2D operator+(const Vecteur2D& autre) const {
        return Vecteur2D(x + autre.x, y + autre.y);
    }

    void afficher() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    Vecteur2D v1(1.5, 2.0);
    Vecteur2D v2(3.0, 4.5);

    cout << "v1 = "; v1.afficher();
    cout << "v2 = "; v2.afficher();

    Vecteur2D v3 = v1 + v2;   // équivaut à v1.operator+(v2)
    cout << "v1 + v2 = "; v3.afficher();

    // Chaînage possible grâce au retour par valeur
    Vecteur2D v4 = v1 + v2 + Vecteur2D(1, 1);
    cout << "v1 + v2 + (1,1) = "; v4.afficher();

    return 0;
}
