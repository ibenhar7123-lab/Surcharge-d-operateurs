#include <iostream>
#include <string>
using namespace std;

class Produit {
private:
    string nom;
    double prix;
    int quantite;

public:
    Produit(const string& nom, double prix, int quantite)
        : nom(nom), prix(prix), quantite(quantite) {}

    // Fonction amie : accède aux membres privés, mais n'est PAS une méthode de la classe
    friend ostream& operator<<(ostream& os, const Produit& p);
};

// Définition de la fonction amie (hors de la classe)
ostream& operator<<(ostream& os, const Produit& p) {
    os << "Produit : " << p.nom
       << " | Prix : " << p.prix << " DH"
       << " | Quantité : " << p.quantite;
    return os;  // retourner le flux permet le chaînage avec <<
}

int main() {
    Produit p1("Clavier", 150.0, 10);
    Produit p2("Souris", 80.5, 25);

    cout << p1 << endl;
    cout << p2 << endl;

    // Chaînage possible
    cout << "Stock :\n" << p1 << "\n" << p2 << endl;

    return 0;
}
