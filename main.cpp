#include <iostream>
#include "GoodCurrentGames.h"

using namespace std;
int main() {

    GoodCurrentGames shop;
    shop.addUser(User("noah", "1234"));
    shop.addUser(User("nico", "456"));
    shop.addGame(Game("fortnite", 100));
    shop.addGame(Game("rocket league", 130));
    shop.addGame(Game("msfs", 400));



    string loginname;
    while (true) {

        cout << endl << endl << endl;
        cout << "Eingeloggter Benutzer: " << loginname << endl;
        cout << "'1' Registrieren Sie einen neuen Nutzer." << endl;
        cout << "'2' List all Users: Gibt alle registierten Benutzer aus." << endl;
        cout << "'3' List all Games: Gibt alle Spiele in der Sammlung aus." << endl;
        cout << "'4' Login" << endl;
        cout << "'5' Logout" << endl;
        cout << "'6' Exit" << endl;
        int choice;
        cin >> choice;


        string name;
        string passwd;

        switch (choice) {
            case 1:
                cout << "Wie soll der Benutzer heißen?" << endl;
            cin >> name;
            cout << "Wie soll das Password sein?" << endl;
            cin >> passwd;
            if (shop.addUser(User(name, passwd))) {
                cout << "Benutzer wurde erfolgreich angelegt." << endl;
            }else {
                cout << "Fehler! Es existiert bereits ein Nutzer mit diesem Namen." << endl;
            }
            break;

            case 2:
                cout << "Das sind alle Benutzer:" << endl;
            for (auto user : shop.getUsers()) {
                cout << user.getUsername() << endl;
            }
            break;

            case 3:
                cout << "Das sind alle Spiele:" << endl;
            for (auto game: shop.getGames()) {
                cout << "ID: " << game.getId() << " Name: " << game.getTitle() << " Preis: " << game.getPrice() <<  endl;
            }
            break;

            case 4:
                cout << "Geben Sie ihr Benutzername ein:" << endl;
                cin >> name;
                cout << "Geben Sie ihr Passwort ein:" << endl;
                cin >> passwd;
                if (shop.login(name, passwd)) {
                    loginname = name;
                    cout << "Hallo, " << name << " die Anmeldung war erfolgreich!" << endl;
                }else {
                    cout << "Möglicherweise ist das Passwort oder der Benutzername falsch!" << endl;
                }

            break;

            case 5:
                if (loginname.size() != 0) {
                    loginname = "";
                }
            break;
            case 6:
                return 0;


            default:
                cout << "Ungültige Auswahl. Bitte versuchen Sie es erneut." << endl;
            break;
        }

    }

}

