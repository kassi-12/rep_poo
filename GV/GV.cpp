#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Voyage {
public:
    int identifiant;
    string destination;
    string date_depart;
    string date_retour;
    double prix;
    int nb_places_disponibles;

    Voyage(int identifiant, string destination, string date_depart, string date_retour, double prix, int nb_places_disponibles) {
        this->identifiant = identifiant;
        this->destination = destination;
        this->date_depart = date_depart;
        this->date_retour = date_retour;
        this->prix = prix;
        this->nb_places_disponibles = nb_places_disponibles;
    }

    void reserver_place() {
        if (nb_places_disponibles > 0) {
            nb_places_disponibles -= 1;
            cout << "Place reservee avec succes !" << endl;
        } else {
            cout << "Aucune place disponible !" << endl;
        }
    }

    void annuler_reservation() {
        if (nb_places_disponibles > 0) {
            nb_places_disponibles += 1;
            cout << "Reservation annulee avec succes !" << endl;
        } else {
            cout << "Aucune reservation a annuler !" << endl;
        }
    }

    virtual void afficher_details() {
        cout << "Details du voyage : " << endl;
        cout << "- Destination : " << destination << endl;
        cout << "- Dates : " << date_depart << " - " << date_retour << endl;
        cout << "- Prix : " << prix << " DH" << endl;
        cout << "- Places disponibles : " << nb_places_disponibles << endl;
    }

    virtual ~Voyage() {}
};

class Client {
public:
    string nom;
    string email;
    vector<Voyage*> liste_voyages_reserves;

    Client(string nom, string email) {
        this->nom = nom;
        this->email = email;
    }

    void reserver_voyage(Voyage* voyage) {
        voyage->reserver_place();
        liste_voyages_reserves.push_back(voyage);
        cout << "Voyage reserve avec succes !" << endl;
    }

    void annuler_reservation(Voyage* voyage) {
        for (auto it = liste_voyages_reserves.begin(); it != liste_voyages_reserves.end(); ++it) {
            if (*it == voyage) {
                voyage->annuler_reservation();
                liste_voyages_reserves.erase(it);
                cout << "Reservation annulee avec succes !" << endl;
                return;
            }
        }
        cout << "Aucune reservation a annuler !" << endl;
    }

    void afficher_details() {
        cout << "Details du client : " << endl;
        cout << "- Nom : " << nom << endl;
        cout << "- Email : " << email << endl;
        cout << "- Voyages reserves : " << endl;
        for (auto it = liste_voyages_reserves.begin(); it != liste_voyages_reserves.end(); ++it) {
            (*it)->afficher_details();
        }
    }
};

class AgenceVoyage {
public:
    vector<Voyage*> liste_voyages;
    vector<Client*> liste_clients;

    void ajouter_voyage(Voyage* voyage) {
        liste_voyages.push_back(voyage);
    }

    void ajouter_client(Client* client) {
        liste_clients.push_back(client);
    }

    vector<Voyage*> rechercher_voyage_par_destination_ou_dates(string query) {
        vector<Voyage*> resultats;
        for (auto& voyage : liste_voyages) {
            if (voyage->destination == query || voyage->date_depart == query || voyage->date_retour == query) {
                resultats.push_back(voyage);
            }
        }
        return resultats;
    }

    Voyage* rechercher_voyage_par_id(int id) {
        for (auto& voyage : liste_voyages) {
            if (voyage->identifiant == id) {
                return voyage;
            }
        }
        return nullptr;
    }

    Client* rechercher_client_par_id(int id) {
        if (id > 0 && id <= liste_clients.size()) {
            return liste_clients[id - 1];
        }
        return nullptr;
    }

    void traiter_reservation(Client* client, Voyage* voyage) {
        if (voyage->nb_places_disponibles > 0) {
            client->reserver_voyage(voyage);
        } else {
            cout << "Aucune place disponible !" << endl;
        }
    }
};

class Destination {
public:
    string nom;
    string description;
    double cout_moyen;

    Destination(string nom, string description, double cout_moyen) {
        this->nom = nom;
        this->description = description;
        this->cout_moyen = cout_moyen;
    }

    void afficher_details() {
        cout << "Details de la destination : " << endl;
        cout << "- Nom : " << nom << endl;
        cout << "- Description : " << description << endl;
        cout << "- Cout moyen : " << cout_moyen << " DH" << endl;
    }
};

class Forfait {
public:
    string nom;
    string description;
    vector<Voyage*> liste_voyages_inclus;

    Forfait(string nom, string description) : nom(nom), description(description) {}

    void ajouter_voyage(Voyage* voyage) {
        liste_voyages_inclus.push_back(voyage);
    }

    void afficher_details() {
        cout << "Details du forfait : " << endl;
        cout << "- Nom : " << nom << endl;
        cout << "- Description : " << description << endl;
        cout << "- Voyages inclus : " << endl;
        for (auto it = liste_voyages_inclus.begin(); it != liste_voyages_inclus.end(); ++it) {
            (*it)->afficher_details();
        }
    }
};

class GuideTouristique {
public:
    string nom;
    vector<string> langues_parlees;
    int experience;

    GuideTouristique(string nom, vector<string> langues_parlees, int experience) {
        this->nom = nom;
        this->langues_parlees = langues_parlees;
        this->experience = experience;
    }

    void afficher_details() {
        cout << "Details du guide touristique : " << endl;
        cout << "- Nom : " << nom << endl;
        cout << "- Langues parlees : " << endl;
        for (auto it = langues_parlees.begin(); it != langues_parlees.end(); ++it) {
            cout << *it << endl;
        }
        cout << "- Experience : " << experience << " ans" << endl;
    }
};

class Transport {
public:
    string mode_transport;
    string compagnie;
    double coutT;

    Transport(string mode_transport, string compagnie, double coutT) {
        this->mode_transport = mode_transport;
        this->compagnie = compagnie;
        this->coutT = coutT;
    }

    void afficher_details() {
        cout << "Details du transport : " << endl;
        cout << "- Mode de transport : " << mode_transport << endl;
        cout << "- Compagnie : " << compagnie << endl;
        cout << "- Coût : " << coutT << " DH" << endl;
    }
};

class Excursion : public Voyage {
public:
    string nom;
    string description;
    int duree;
    double cout_supplementaire;

    Excursion(int identifiant, string destination, string date_depart, string date_retour, double prix, int nb_places_disponibles, string nom, string description, int duree, double cout_supplementaire)
        : Voyage(identifiant, destination, date_depart, date_retour, prix, nb_places_disponibles), nom(nom), description(description), duree(duree), cout_supplementaire(cout_supplementaire) {}

    void afficher_details() override {
        Voyage::afficher_details();
        cout << "Details de l'excursion : " << endl;
        cout << "- Nom : " << nom << endl;
        cout << "- Description : " << description << endl;
        cout << "- Duree : " << duree << " heures" << endl;
        cout << "- Coût supplementaire : " << cout_supplementaire << " DH" << endl;
    }
};

int main() {
    AgenceVoyage agence;

    Voyage* voyage1 = new Voyage(1, "London", "2024-06-01", "2024-06-10", 1500.0, 30);
    Voyage* voyage2 = new Voyage(2, "New York", "2024-07-15", "2024-07-25", 2000.0, 20);
    Voyage* voyage3 = new Voyage(3, "Tokyo", "2024-08-05", "2024-08-15", 2500.0, 25);
    Voyage* voyage4 = new Voyage(4, "Sydney", "2024-09-20", "2024-09-30", 3000.0, 15);

    Excursion* excursion1 = new Excursion(5, "Rome", "2024-07-01", "2024-07-05", 800.0, 20, "Colosseum Tour", "Guided tour of the Colosseum and ancient Rome", 3, 50.0);

    agence.ajouter_voyage(voyage1);
    agence.ajouter_voyage(voyage2);
    agence.ajouter_voyage(voyage3);
    agence.ajouter_voyage(voyage4);
    agence.ajouter_voyage(excursion1);

    Client* client1 = new Client("Alice", "alice@example.com");
    Client* client2 = new Client("Bob", "bob@example.com");

    agence.ajouter_client(client1);
    agence.ajouter_client(client2);

    cout << "Recherche de voyages par destination 'London' : " << endl;
    vector<Voyage*> resultats = agence.rechercher_voyage_par_destination_ou_dates("London");
    for (auto& voyage : resultats) {
        voyage->afficher_details();
    }

    cout << "Client 1 reserve le voyage 1 : " << endl;
    agence.traiter_reservation(client1, voyage1);
    client1->afficher_details();

    cout << "Client 2 reserve l'excursion 1 : " << endl;
    agence.traiter_reservation(client2, excursion1);
    client2->afficher_details();

    cout << "Annulation de la reservation de l'excursion 1 pour le client 2 : " << endl;
    client2->annuler_reservation(excursion1);
    client2->afficher_details();

    delete voyage1;
    delete voyage2;
    delete voyage3;
    delete voyage4;
    delete excursion1;
    delete client1;
    delete client2;

    return 0;
}
