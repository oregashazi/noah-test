#include <algorithm>
#include <iostream>
#include "GoodCurrentGames.h"

using namespace std;
int main() {

    GoodCurrentGames shop;
    shop.addUser(User("noah", "1234", 300));
    shop.addUser(User("nico", "456", 20));
    shop.addGame(Game("Fortnite", 100));
    shop.addGame(Game("Minecraft", 30));
    shop.addGame(Game("Zelda", 60));
    //shop.addGame(Game("ABC", 45));


    string loginname;
    while (true) {

        cout << endl << endl << endl;
        if (loginname.size() != 0) {
            cout << "Eingeloggter Benutzer: " << loginname << endl;
            cout << "Deine aktuellen Spiele: " << endl;

            for (auto game : shop.user(loginname).getGames()) {
                cout << game->getTitle() << endl;
            }
        }
        cout << "'1' Registrieren Sie einen neuen Nutzer." << endl;
        cout << "'2' List all Users: Gibt alle registierten Benutzer aus." << endl;
        cout << "'3' List all Games: Gibt alle Spiele in der Sammlung aus." << endl;
        cout << "'4' Login" << endl;
        cout << "'5' Logout" << endl;
        cout << "'6' Exit" << endl;
        if (loginname.size() != 0) {
            cout << "'7' Buy Game: Kaufe ein Spiel mit deinen Credits." << endl;
        }

        int choice;
        cin >> choice;


        string name;
        string passwd;
        int credit;

        switch (choice) {
            case 1:
                cout << "Wie soll der Benutzer heißen?" << endl;
                cin >> name;
                cout << "Wie soll das Password sein?" << endl;
                cin >> passwd;
                cout << "Wie viel Geld hat der Benutzer?" << endl;
                cin >> credit;
                if (shop.addUser(User(name, passwd, credit))) {
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
                    cout << "Moeglicherweise ist das Passwort oder der Benutzername falsch!" << endl;
                }

            break;

            case 5:
                if (loginname.size() != 0) {
                    loginname = "";
                }
                 break;
            case 6:
                return 0;
            case 7:
                int gameid;
            int price;
            if (loginname.size() != 0) {
                cout << "Geben Sie die ID des Spiels an:" << endl;
                cin >> gameid;
                for (Game game : shop.getGames()) {  // Verwende Referenzen, um Änderungen vorzunehmen
                    if (gameid == game.getId()) {
                        price = game.getPrice();
                        cout << "Der Preis betraegt " << price << endl;
                        if (shop.user(loginname).getCredit() < price) {
                            cout << "Leider hast du zu wenig Geld, um das Spiel zu kaufen. Du hast nur noch: " << shop.user(loginname).getCredit() << endl;
                        } else {
                            cout << "_____ id -> " << game.getId() << endl;
                            shop.user(loginname).addGame(&game);  // Spiel wird dem Benutzer hinzugefügt
                            shop.user(loginname).removeCredit(price);  // Abzug der Credits
                            cout << "Du hast das Spiel erfolgreich gekauft. Du hast nun nur noch " << shop.user(loginname).getCredit() << " Credits verfuegbar." << endl;
                        }
                    }
                }
            }
            break;

            default:
                cout << "Ungueltige Auswahl. Bitte versuchen Sie es erneut." << endl;
            break;
        }

    }

}

