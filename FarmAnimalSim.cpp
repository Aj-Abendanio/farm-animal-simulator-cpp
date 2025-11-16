// FarmAnimalSim.cpp
// Updated: Permanent death saved to save.txt if an animal dies.
// Author: AJ Abendanio

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <fstream>
#include <limits>

using namespace std;

void playChicken();
bool checkPermanentBan(const string &filename);
void writePermanentBan(const string &filename);

int main() {
    srand((unsigned)time(0));

    const string saveFile = "save.txt";

    //Permanent BAN if animal dies and then dev code to reset for testing
    if (checkPermanentBan(saveFile)) {

        system("cls");
        cout << string(69, '=') << "\n\n";
        cout << "\t\t\tFARM ANIMAL SIMULATOR\n\n";
        cout << string(69, '=') << "\n\n";

        cout << "YOU ARE BANNED FOREVER\n\n";
        cout << "You killed your animal in a previous session.\n";
        cout << "Because of this, you are PERMANENTLY BANNED from playing!!\n";
        cout << "No second chances. No retries. NOTHING.\n";
        cout << "Go and reclect what you did.\n\n";
        cout << string(69, '-') << "\n";
        cout << "For dev privileges, enter dev code to lift ban.\n"; //FASDevRESET303
        cout << string(69, '-') << "\n\n";

        cout << "Developer override code (press Enter to skip): ";
        string devCode;
        getline(cin, devCode);

        if (devCode == "FASDevRESET303") {
            ofstream fout(saveFile, ios::trunc);
            fout << "ALIVE\n";
            fout.close();

            cout << "\nDeveloper override accepted.\n";
            cout << "Permanent death has been RESET.\n";
            Sleep(1600);
        }
        else {
            cout << "\nInvalid code.\n";
            cout << "You are still BANNED.\n";
            cout << "Goodbye.\n";
            Sleep(1800);
            return 0;
        }
    }

    //Game Intro (loading dots)
    cout << string(69, '=') << "\n\n";
    cout << "\t\t\tFarm Animal Simulator\n\n";
    cout << string(69, '=') << "\n";

    for (int i = 0; i < 10; ++i) {
        Sleep(400);
        cout << (i == 0 ? "\t\t\t      ." : ".");
    }
    cout << "\n\n";

    //Signing up (nickname)
    string playerName;
    cout << "Welcome, Farmer!\n";
    cout << "\nEnter your nickname: ";
    getline(cin, playerName);
    cout << "\nHello, Farmer " << playerName << "! Let's get started.\n";
    Sleep(1200);

    //Terms of agreement
    char agree;
    bool validInput = false;

    while (!validInput) {
        system("cls");

        cout << string(69, '=') << "\n\n";
        cout << "\t\t\tFarm Animal Simulator\n\n";
        cout << string(69, '=') << "\n\n";

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
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (agree == 'Y' || agree == 'y') {
            cout << "\nGreat! Let's begin.\n";
            validInput = true;
            Sleep(900);
        } 
        else if (agree == 'N' || agree == 'n') {
            cout << "\nYou have disagreed with the terms. Goodbye :<\n";
            Sleep(1500);
            return 0;
        } 
        else {
            cout << "\nInvalid input. Please enter Y or N only.\n";
            Sleep(1200);
        }
    }

    Sleep(800);
    system("cls");

    //Main menu loop (game choices)
    bool playing = true;
    while (playing) {
        system("cls");
        cout << "Welcome to Farm Animal Simulator, Farmer " << playerName << "!\n\n";
        cout << "Choose which animal you would like to take care of: \n";
        cout << string(70, '=') << endl;
        cout << "  |   [1] Chicken   |   [2] Cow   |   [3] Tamaraw   |   [4] Exit   |" << endl;
        cout << string(70, '=') << endl;

        int animalChoice;
        cout << "\nEnter your choice (1, 2, 3, or 4): ";
        cin >> animalChoice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(animalChoice) {
            case 1: {
                //Plays Chicken game
                system("cls");
                playChicken();

                char again;
                cout << "\nReturn to main menu? (Y/N): ";
                cin >> again;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (again == 'N' || again == 'n') {
                    cout << "\nThanks for playing! Goodbye, Farmer " << playerName << "!\n";
                    Sleep(1200);
                    return 0;
                }
                break;
            }

            case 2: {
                //Plays Cow game
                system("cls");
                playCow();

                char again;
                cout << "\nReturn to main menu? (Y/N): ";
                cin >> again;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (again == 'N' || again == 'n') {
                    cout << "\nThanks for playing! Goodbye, Farmer " << playerName << "!\n";
                    Sleep(1200);
                    return 0;
                }
                break;
            }

            case 3: {
                // Placeholder for Tamaraw game
                system("cls");
                cout << "Tamaraw game not implemented yet. Coming soon!\n";
                Sleep(1200);
                // After placeholder, ask whether to return to menu
                break;
            }

            case 4: {
                cout << "\nGoodbye, Farmer " << playerName << "! Thanks for Playing Farm Animal Simulator <3\n";
                Sleep(1000);
                return 0;
            }

            default:
                cout << "Invalid choice. Choose 1, 2, 3, or 4 only.";
                Sleep(1000);
                break;
        }
    }

    return 0;
}

//Banner
bool checkPermanentBan(const string &filename) {
    ifstream fin(filename.c_str());
    if (!fin.is_open()) return false;
    string line;
    getline(fin, line);
    fin.close();
    while (!line.empty() && isspace(line.back())) line.pop_back();
    while (!line.empty() && isspace(line.front())) line.erase(line.begin());
    if (line == "DEAD") return true;
    return false;
}

void writePermanentBan(const string &filename) {
    ofstream fout(filename.c_str(), ios::trunc);
    if (fout.is_open()) {
        fout << "DEAD\n";
        fout.close();
    }
}

//Chicken Game
void playChicken() {
    const string saveFile = "save.txt";
    int health = 50;
    bool used[30] = {false};

    cout << "==================== Farm Animal Simulator - CHICKEN ====================\n\n";
    Sleep(800);

    for (int i = 0; i < 15; i++) {
        int scenario;
        do {
            scenario = rand() % 30;
        } while (used[scenario]);
        used[scenario] = true;

        char ans;
        cout << "\nScenario " << (i + 1) << ":\n";

        if (scenario == 0) {
            cout << "Your chicken looks hungry. What will you feed it?\n";
            cout << "A. B-MEG Integra 4000\nB. Acana Organic\nC. Rotisserie Chicken\n";
            cout << "Give it: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health+=10;
            else if(ans=='B') health-=5;
            else health+=0;
        }
        else if (scenario == 1) {
            cout << "Your chicken seems thirsty. What will you give it?\n";
            cout << "A. Cobra Energy Drink\nB. Hot water\nC. Cold water\n";
            cout << "Give it: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health-=10;
            else if(ans=='B') health-=5;
            else health+=10;
        }
        else if (scenario == 2) {
            cout << "Your chicken is dirty. Time to take a bath.\n";
            cout << "A. Johnson's Baby Shampoo\nB. TRESemme Keratin Smooth Shampoo\nC. Dog shampoo\n";
            cout << "What will you use?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health+=10;
            else if(ans=='B') health-=10;
            else health+=0;
        }
        else if (scenario == 3) {
            cout << "Your chicken is super hyper.\n";
            cout << "A. Lecture it\nB. Lock it inside\nC. Check Lazada Payday Sale\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health+=0;
            else if(ans=='B') health-=5;
            else health+=0;
        }
        else if (scenario == 4) {
            cout << "Your chicken is looking for food on the ground.\n";
            cout << "A. Help it find grains\nB. Give it Inasal Chicken Flavored Snack\nC. Look for Grain Detector in Facebook Marketplace\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health+=5;
            else if(ans=='B') health-=5;
            else health+=0;
        }
        else if (scenario == 5) {
            cout << "Your chicken looks sleepy.\n";
            cout << "A. Do a TikTok Live and show your chicken\nB. Stare at it\nC. Play 'Tensionado' loudly on repeat\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health+=0;
            else if(ans=='B') health+=10;
            else health-=5;
        }
        else if (scenario == 6) {
            cout << "It's raining hard.\n";
            cout << "A. Open an umbrella and follow your chicken around\nB. Open a can of beer and relapse while listening to sad OPM\nC. Bring it inside your house\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health+=0;
            else if(ans=='B') health-=5;
            else health+=5;
        }
        else if (scenario == 7) {
            cout << "Your chicken is scared.\n";
            cout << "A. Show it a jumpscare video\nB. Laugh and record it\nC. Ask ChatGPT what to do\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health-=5;
            else if(ans=='B') health+=0;
            else health+=10;
        }
        else if (scenario == 8) {
            cout << "Your chicken seems lonely.\n";
            cout << "A. Bring it to Andoks and show the rotating chickens\nB. Buy a chicken plushie from Miniso\nC. Put a mirror beside it\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health+=10;
            else if(ans=='B') health+=0;
            else health-=5;
        }
        else if (scenario == 9) {
            cout << "Your chicken laid an egg!\n";
            cout << "A. Feed it to your chicken\nB. Throw it away because you still have 2 dozens from Landers\nC. Scold chicken for laying only one egg\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health+=10;
            else if(ans=='B') health+=0;
            else health-=5;
        }
        else if (scenario == 10) {
            cout << "Your chicken won't move.\n";
            cout << "A. Ask a Psychiatrist for help\nB. Rush it to St. Luke's Medical Center BGC\nC. Bring it to the Albularyo\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health+=0;
            else if(ans=='B') health+=10;
            else health-=5;
        }
        else if (scenario == 11) {
            cout << "Your chicken found a worm.\n";
            cout << "A. Let it eat the worm\nB. Buy an outfit for your chicken in TikTok Shop\nC. Scream at it and take the worm away\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health+=10;
            else if(ans=='B') health+=0;
            else health-=5;
        }
        else if (scenario == 12) {
            cout << "Chicken coop smells strong.\n";
            cout << "A. Hire CleanTok to clean the coop\nB. Just buy a new chicken coop\nC. Blame the chicken duh\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health+=10;
            else if(ans=='B') health+=0;
            else health-=5;
        }
        else if (scenario == 13) {
            cout << "A stray cat approaches your chicken.\n";
            cout << "A. Say pspspspsp\nB. Give it cat food\nC. Yell and scare it away\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health-=5;
            else if(ans=='B') health+=0;
            else health+=10;
        }
        else if (scenario == 14) {
            cout << "Your chicken is sunbathing.\n";
            cout << "A. Give it sunglasses\nB. Splash water\nC. Put an umbrella over it\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health+=10;
            else if(ans=='B') health+=0;
            else health-=5;
        }
        else if (scenario == 15) {
            cout << "Your chicken follows you.\n";
            cout << "A. Give it food\nB. Run away\nC. Tell it to stop\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health+=10;
            else if(ans=='B') health+=0;
            else health-=5;
        }
        else if (scenario == 16) {
            cout << "Your chicken pooped on your shoe!\n";
            cout << "A. Scream and throw a tantrum because it was an expensive shoe\nB. Buy a new shoe\nC. Feed your chicken Rotisserie Chicken as revenge\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health-=5;
            else if(ans=='B') health+=0;
            else health+=10;
        }
        else if (scenario == 17) {
            cout << "Your chicken is bored.\n";
            cout << "A. Make it run on a treadmill\nB. Watch anime with it\nC. Eat a Rotisserie Chicken in front of it\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health+=10;
            else if(ans=='B') health+=0;
            else health-=5;
        }
        else if (scenario == 18) {
            cout << "Your chicken won't stop crowing.\n";
            cout << "A. Crow back at it\nB. Tell it to shut up\nC. Tape the beak\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health+=0;
            else if(ans=='B') health+=10;
            else health-=5;
        }
        else if (scenario == 19) {
            cout << "Your chicken sneezes.\n";
            cout << "A. Check if sick\nB. Make it sneeze again\nC. Ignore\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health+=10;
            else if(ans=='B') health+=0;
            else health-=5;
        }
        else if (scenario == 20) {
            cout << "A loud noise startles your chicken.\n";
            cout << "A. Play 'Beautiful Boy' by John Lennon to calm it\nB. Do nothing\nC. Record for TikTok\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health+=10;
            else if(ans=='B') health+=0;
            else health-=5;
        }
        else if (scenario == 21) {
            cout << "Your chicken is angry at you!\n";
            cout << "A. Growl like a wolf at it\nB. Tell it to stop\nC. Throw chicken feed at it\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health+=10;
            else if(ans=='B') health+=0;
            else health-=5;
        }
        else if (scenario == 22) {
            cout << "Your chicken scratches the ground.\n";
            cout << "A. Help look for bugs\nB. Spray water\nC. Leave it\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health+=10;
            else if(ans=='B') health+=0;
            else health-=5;
        }
        else if (scenario == 23) {
            cout << "Your chicken breathes heavily.\n";
            cout << "A. Give water\nB. Block path\nC. Ignore\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health+=10;
            else if(ans=='B') health+=0;
            else health-=5;
        }
        else if (scenario == 24) {
            cout << "Your chicken wants attention.\n";
            cout << "A. Call it clingy and tease it\nB. Avoid eye contact\nC. Say 'later'\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health+=10;
            else if(ans=='B') health+=0;
            else health-=5;
        }
        else if (scenario == 25) {
            cout << "Your chicken is shedding feathers.\n";
            cout << "A. Check if cold\nB. Laugh at it\nC. Bathe in organic anti-balding shampoo\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health+=10;
            else if(ans=='B') health+=0;
            else health-=5;
        }
        else if (scenario == 26) {
            cout << "Your chicken wants food again.\n";
            cout << "A. Give it a gourmet dish\nB. Feed egg\nC. Tell it no\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health+=10;
            else if(ans=='B') health+=0;
            else health-=5;
        }
        else if (scenario == 27) {
            cout << "A cockroach lands nearby.\n";
            cout << "A. Let chicken chase it\nB. Kill it\nC. Scream and panic\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health+=10;
            else if(ans=='B') health+=0;
            else health-=5;
        }
        else if (scenario == 28) {
            cout << "Your chicken stares at you.\n";
            cout << "A. Stare back\nB. Take funny pics of it\nC. Scare it away\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health+=10;
            else if(ans=='B') health+=0;
            else health-=5;
        }
        else if (scenario == 29) {
            cout << "Your chicken wants to explore mud.\n";
            cout << "A. Throw it in the mud\nB. Stop it\nC. Let stay in coop\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if(ans=='A') health+=10;
            else if(ans=='B') health+=0;
            else health-=5;
        }

        cout << "\nCurrent Health: " << health << "\n";
        cout << "\n------------------------\n\n";
        Sleep(700);

        if (health <= 0) {
            cout << "Your chicken has died. Game Over. YOU CAN'T PLAY THE GAME AGAIN!!!\n";
            writePermanentBan(saveFile);
            Sleep(1200);
            exit(0);
        }
    }

    cout << "\nHealth at end: " << health << "\n";
    cout << "\n==================== GAME END ====================\n";
    if (health >= 80) cout << "Your chicken is VERY HEALTHY! Great job!\n";
    else if (health >= 50) cout << "Your chicken is okay, but could be better.\n";
    else cout << "Your chicken is weak. Try again.\n";

}