#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

int main() {
    cout << "=====================================================================\n\n";
    cout << "\t\t\tFarm Animal Simulator\n\n";
    cout << "=====================================================================\n";

    Sleep(400); cout << "\t\t\t      .";
    Sleep(400); cout << ".";
    Sleep(400); cout << ".";
    Sleep(400); cout << ".";
    Sleep(400); cout << ".";
    Sleep(400); cout << ".";
    Sleep(400); cout << ".";
    Sleep(400); cout << ".";
    Sleep(400); cout << ".";
    Sleep(400); cout << ".\n";

    string playerName;
    cout << "Welcome, Farmer!\n";
    cout << "\nEnter your nickname: ";
    getline(cin, playerName);
    cout << "\nHello, Farmer " << playerName << "! Let's get started.\n";
    Sleep(1200);

    char agree;
    bool validInput = false;

    while (!validInput) {
        system("cls");

        cout << "=====================================================================\n\n";
        cout << "\t\t\tFarm Animal Simulator\n\n";
        cout << "=====================================================================\n\n";

        cout << "Before we begin, please READ and AGREE to our terms:\n";
        cout << "\n1. You must take care of your animals responsibly.\n";
        cout << "\n2. If your animal dies, you CAN'T play the game anymore.\n";
        cout << "\n3. You promise that you will not purposely neglect your animal.\n";
        cout << "\n4. You will respect ALL animals, big or small, in-game or not.\n";
        cout << "\n5. You will not feed the cow cat food.\n";
        cout << "\n6. You will not bathe your animal with Head & Shoulders shampoo.\n";
        cout << "\n7. Crying over a dead chicken is optional, but understandable.\n";
        cout << "\n8. You agree that any bugs in the game are \"intentional features.\" :)\n";
        cout << "\nDo you accept the terms? (Y/N): ";
        cin >> agree;

        if (agree == 'Y' || agree == 'y') {
            cout << "\nGreat! Let's begin.\n";
            validInput = true;
        } 
        else if (agree == 'N' || agree == 'n') {
            cout << "\nYou have disagreed with the terms. Goodbye :<\n";
            Sleep(1500);
            exit(0);
        } 
        else {
            cout << "\nInvalid input. Please enter Y or N only.\n";
            Sleep(1200);
        }
    }

    Sleep(800);
    system("cls");

    cout << "Welcome to Farm Animal Simulator, Farmer " << playerName << "!\n";
    cout << "Choose which animal you would like to take care of: \n";
    Sleep(1500);

    return 0;
}
