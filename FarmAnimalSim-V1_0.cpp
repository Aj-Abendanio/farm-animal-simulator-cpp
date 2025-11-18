// Farm Animal Simulator 
// Version: 1.0
// Author: AJ Abendanio | FEU Tech | BSCS-AI

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

void playCow();
bool checkPermanentBan(const string &filename);
void writePermanentBan(const string &filename);

void playTamaraw();
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

            system("cls");
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
        cout << "Your mission is to keep your animal alive. Sounds easy?\n"
                "Absolutely NOT. Random scenarios are waiting for you. Your choices will either\n"
                "save your animal... or send it straight to heaven. Good luck!!!\n\n";
        cout << "GAME MECHANICS:\n"
                "- Each game gives you 15 completely random scenarios.\n"
                "- Choices affect your animal's health. Some help, some hurt,\n"
                "  and some will make you question your life choices.\n"
                "- Health hitting 0 means your animal dies (will lead to BAN).\n"
                "- If you survive all 15, you WIN.\n"
                "- If your animal survives, you can play again.\n"
                "- Press 'X' anytime to escape to the main menu.\n\n";
        cout << "Choose which animal you would like to take care of: \n";
        cout << string(70, '=') << endl;
        cout << "  |   [1] Chicken   |   [2] Cow   |   [3] Tamaraw   |   [4] Exit   |\n";
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

                char exit;
                cout << "\nReturn to main menu [R] or Quit entire game [Q] ?: ";
                cin >> exit;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (exit == 'Q' || exit == 'q') {
                cout << "\nGoodbye, Farmer " << playerName << "! Thanks for Playing Farm Animal Simulator <3\n";
                    Sleep(1200);
                    return 0;
                }
                break;
            }

            case 2: {
                //Plays Cow game
                system("cls");
                playCow();

                char exit;
                cout << "\nReturn to main menu [R] or Quit entire game [Q] ?: ";
                cin >> exit;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (exit == 'Q' || exit == 'q') {
                cout << "\nGoodbye, Farmer " << playerName << "! Thanks for Playing Farm Animal Simulator <3\n";
                    Sleep(1200);
                    return 0;
                }
                break;
            }

            case 3: {
                //Plays Tamaraw game
                system("cls");
                playTamaraw();

                char exit;
                cout << "\nReturn to main menu [R] or Quit entire game [Q] ?: ";
                cin >> exit;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                if (exit == 'Q' || exit == 'q') {
                cout << "\nGoodbye, Farmer " << playerName << "! Thanks for Playing Farm Animal Simulator <3\n";
                    Sleep(1200);
                    return 0;
                }
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

//Ban
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
    cout << "Press X to quit game.\n\n";

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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
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

//Cow Game
void playCow() {
    const string saveFile = "save.txt";
    int health = 50;
    bool used[30] = {false};

    cout << "==================== Farm Animal Simulator - COW ====================\n\n";
    cout << "Press X to quit game.\n\n";

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
            cout << "You saw a rare, endangered, and super poisonous snake moving towards your cow!\n";
            cout << "A. Kill the snake\nB. Spare the snake and sacrifice the cow\nC. Panic and call 911\n";
            cout << "What will you do?!: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=0;
            else if(ans=='B') health-=100;
            else health+=0;
        }
        else if (scenario == 1) {
            cout << "Your cow is very hungry.\n";
            cout << "A. Cat food\nB. Blue grass\nC. Hay\n";
            cout << "What will you feed it?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health-=10;
            else if(ans=='B') health+=5;
            else health+=3;
        }
        else if (scenario == 2) {
            cout << "Your cow is dirty. Time to take a bath.\n";
            cout << "A. Head & Shoulders Shampoo\nB. Perla\nC. Dog shampoo\n";
            cout << "What will you use?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health-=10;
            else if(ans=='B') health-=5;
            else health+=5;
        }
        else if (scenario == 3) {
            cout << "It's time to clean your cow's hoof\n";
            cout << "A. Watch Nate the Hoof Guy's tiktok and follow it\nB. Ask ChatGPT how to do it\nC. Search a video on how to do it in YouTube\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=7;
            else if(ans=='B') health+=2;
            else health+=5;
        }
        else if (scenario == 4) {
            cout << "Your cow keeps staring at a bush near the fence.\n";
            cout << "A. Ask ChatGPT why\nB. Let it stare at the bush\nC. Hurry the cow inside the barn\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=0;
            else if(ans=='B') health-=5;
            else health+=0;
        }
        else if (scenario == 5) {
            cout << "It's time to milk your cow today\n";
            cout << "A. Just one\nB. Three times\nC. Five times\n";
            cout << "How many times will yu milk it?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health-=2;
            else if(ans=='B') health+=10;
            else health-=5;
        }
        else if (scenario == 6) {
            cout << "Your cow’s nose looks dry and cracked.\n";
            cout << "A. Apply petroleum jelly\nB. Give it more water\nC. Play Goat Simulator instead\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=0;
            else if(ans=='B') health+=5;
            else health-=5;
        }
        else if (scenario == 7) {
            cout << "Your cow is in heat.\n";
            cout << "A. Play WAP by Cardi B\nB. Find another cow for it\nC. Hire Chicago Bull's Bull\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health-=5;
            else if(ans=='B') health-=10;
            else health+=10;
        }
        else if (scenario == 8) {
            cout << "The cow keeps mooing loudly for no reason.\n";
            cout << "A. Check if it's the first of the month then do a dance\nB. Be clingy and give it hugs\nC. Moo with it\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=0;
            else if(ans=='B') health+=10;
            else health-=5;
        }
        else if (scenario == 9) {
            cout << "Your cow keeps following you everywhere\n";
            cout << "A. Slap its ass\nB. Ignore it\nC. Scold it\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=0;
            else if(ans=='B') health+=5;
            else health-=5;
        }
        else if (scenario == 10) {
            cout << "You saw a swollen spot on your cow's leg\n";
            cout << "A. Poke it to see its reaction\nB. Apply cold compress\nC. Make it walk on a treadmill\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=10;
            else if(ans=='B') health-=5;
            else health-=5;
        }
        else if (scenario == 11) {
            cout << "It's raining outside and your cow is alone in the field.\n";
            cout << "A. Tie it under a tree\nB. Make it wear a raincoat\nC. Scream at it tell it to head inside the barn\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health-=5;
            else if(ans=='B') health+=10;
            else health+=0;
        }
        else if (scenario == 12) { 
            cout << "The barn is full of manure.\n";
            cout << "A. Hire John Marston to clean it\nB. Clean it yourself\nC. Let your cow eat and clean the manure\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=15;
            else if(ans=='B') health+=5;
            else health-=15;
        }
        else if (scenario == 13) {
            cout << "Your cow's milk is light yellow.\n";
            cout << "A. Nothing\nB. Keep milking it\nC. Take it to the Albularyo\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=10;
            else if(ans=='B') health+5;
            else health-=5;
        }
        else if (scenario == 14) {
            cout << "Your cow wants to eat avocados.\n";
            cout << "A. Feed only one\nB. Say no\nC. Give it 10 avocados\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health-=5;
            else if(ans=='B') health+=5;
            else health-=20;
        }
        else if (scenario == 15) {
            cout << "Your cow's poop is very green!\n";
            cout << "A. Praise and give it pats\nB. Panic and rush it to the vet\nC. Do nothing and make Iced Capuccino instead\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=7;
            else if(ans=='B') health-=5;
            else health+=5;
        }
        else if (scenario == 16) {
            cout << "Your cow is lying down on the ground stiffly and not moving!\n";
            cout << "A. Do nothing\nB. Play with it\nC. Play 'Last Christmas' by Wham!\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=5;
            else if(ans=='B') health-=5;
            else health+=0;
        }
        else if (scenario == 17) {
            cout << "Your cow is following you everywhere.\n";
            cout << "A. Run away from it\nB. Watch mukbang videos together\nC. Grill a brisket in front of it\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health-=4;
            else if(ans=='B') health+=5;
            else health+=0;
        }
        else if (scenario == 18) {
            cout << "Your cow stole and ate some apples.\n";
            cout << "A. Give it a lecture\nB. Hit it\nC. Steal the apples back\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=2;
            else if(ans=='B') health-=10;
            else health+=0;
        }
        else if (scenario == 19) {
            cout << "Your cow sneezes.\n";
            cout << "A. Check if sick\nB. Make it sneeze again\nC. Ignore\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=10;
            else if(ans=='B') health+=0;
            else health-=5;
        }
        else if (scenario == 20) {
            cout << "Your cow wants to play.\n";
            cout << "A. Play Soccer with it\nB. Play pickleball, but the cow is your net\nC. Play Valorant with your cow\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=8;
            else if(ans=='B') health-=5;
            else health+=0;
        }
        else if (scenario == 21) {
            cout << "It's time to bring your cow to a regular check up but it's your favorite band's ticket sale.\n";
            cout << "A. Hire someone from facebook\nB. Ask your friend to bring your cow to the vet\nC. Let your cow go on its own\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=3;
            else if(ans=='B') health+=1;
            else health-=6;
        }
        else if (scenario == 22) {
            cout << "It is super hot today.\n";
            cout << "A. Give your cow a cold bath\nB. Add ice in your cow's water trough \nC. Give it Ice Cream\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=5;
            else if(ans=='B') health+=5;
            else health-=5;
        }
        else if (scenario == 23) {
            cout << "Your cow's head got stuck between the steel fence!\n";
            cout << "A. Call 911\nB. Break your fence\nC. Use sheer force to free your cow\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=0;
            else if(ans=='B') health+=2;
            else health-=5;
        }
        else if (scenario == 24) {
            cout << "Your partner is jealous of your cow because you're giving it more attention.\n";
            cout << "A. Scold your partner be more clingy to your cow\nB. Spend more time with the cow\nC. Scold the cow for making your girlfriend jealous\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=15;
            else if(ans=='B') health+=5;
            else health-=5;
        }
        else if (scenario == 25) {
            cout << "Your cow drinks from the fish pond.\n";
            cout << "A. Yell and scare it away\nB. Let it drink\nC. Do nothing\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=8;
            else if(ans=='B') health-=5;
            else health-=3;
        }
        else if (scenario == 26) {
            cout << "Today is your me day but your cow stepped on a bee.\n";
            cout << "A. Check on your cow\nB. Do nothing\nC. Find the dead bee\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=4;
            else if(ans=='B') health-=7;
            else health+=0;
        }
        else if (scenario == 27) {
            cout << "Your cow suddenly stucked its head into the mud.\n";
            cout << "A. Let it do what it wants and doomscroll in TikTok\nB. Pull it away from the mud puddle\nC. Push your head into the mud too\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=6;
            else if(ans=='B') health-=3;
            else health+=0;
        }
        else if (scenario == 28) {
            cout << "Your cow is not moving.\n";
            cout << "A. Drag it and make it walk around\nB. Le it be\nC. Stare at it\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health-=4;
            else if(ans=='B') health+=5;
            else health+=0;
        }
        else if (scenario == 29) {
            cout << "Your cow doesn't want to go back in the barn yet.\n";
            cout << "A. Let it outside durin the night\nB. Yell and force it inside the barn\nC. Ask your partner to bring the cow inside the barn\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=-12;
            else if(ans=='B') health+=10;
            else health+=0;
        }

        cout << "\nCurrent Health: " << health << "\n";
        cout << "\n------------------------\n\n";
        Sleep(700);

        if (health <= 0) {
            cout << "Your cow has died. Game Over. YOU CAN'T PLAY THE GAME AGAIN!!!\n";
            writePermanentBan(saveFile);
            Sleep(1200);
            exit(0);
        }
    }

    cout << "\nHealth at end: " << health << "\n";
    cout << "\n==================== GAME END ====================\n";
    if (health >= 80) cout << "Your cow is VERY HEALTHY! Great job!\n";
    else if (health >= 50) cout << "Your cow is okay, but could be better.\n";
    else cout << "Your cow is weak. Try again.\n";

}

//Tamaraw Game
void playTamaraw() {
    const string saveFile = "save.txt";
    int health = 50;
    bool used[30] = {false};

    cout << "==================== Farm Animal Simulator - TAMARAW ====================\n\n";
    cout << "Press X to quit game.\n\n";

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
            cout << "It's time to feed your Tamaraw\n";
            cout << "A. Bamboo leaves\nB. Blue chewy grass\nC. Caldereta\n";
            cout << "What will you feed it?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=5;
            else if(ans=='B') health+=10;
            else health-=15;
        }
        else if (scenario == 1) {
            cout << "Your Tamaraw is very dirty.\n";
            cout << "A. Give it a bath\nB. Do nothing\nC. Spray perfume on it\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health-=10;
            else if(ans=='B') health+=5;
            else health-=12;
        }
        else if (scenario == 2) {
            cout << "Your Tamaraw is itching a lot.\n";
            cout << "A. Bathe with anti lice Shampoo\nB. Give antiparasitic injection\nC. Buy a back scratcher for it\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=5;
            else if(ans=='B') health+=5;
            else health+=0;
        }
        else if (scenario == 3) {
            cout << "A group of FEU Tech students wants to see your Tamaraw.\n";
            cout << "A. Proudly show them your Tamaraw\nB. Refuse them\nC. Meet in zoom then show your tamaraw\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health-=15;
            else if(ans=='B') health+=5;
            else health+=0;
        }
        else if (scenario == 4) {
            cout << "It's time to get your Tamaraw vaccinations.\n";
            cout << "A. Hire a Tamaraw wildlife specialist\nB. Hire local vet\nC. Do it yourself\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health-=10;
            else if(ans=='B') health+=10;
            else health-=2;
        }
        else if (scenario == 5) {
            cout << "Your Tamaraw wants to eat again.\n";
            cout << "A. Feed it B-MEG Organic Feed\nB. Feed it wild fern\nC. Feed it a nutribun\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health-=5;
            else if(ans=='B') health+=7;
            else health-=16;
        }
        else if (scenario == 6) {
            cout << "Your Tamaraw's nose looks dry and cracked.\n";
            cout << "A. Apply petroleum jelly\nB. Give it more water\nC. Play Goat Simulator instead\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health-=5;
            else if(ans=='B') health+=5;
            else health-=5;
        }
        else if (scenario == 7) {
            cout << "A super typhoon is coming.\n";
            cout << "A. Install flood guards around the enclosure\nB. Move Tamaraw where the typhoon won't reach\nC. Install a giant umbrella\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=5;
            else if(ans=='B') health-=10;
            else health-=5;
        }
        else if (scenario == 8) {
            cout << "Someone is trying to steal your Tamaraw!\n";
            cout << "A. Be violent\nB. Scream at your Tamaraw to make it aggresive\nC. Do a citizens arrest to the robber\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=0;
            else if(ans=='B') health-=10;
            else health+=5;
        }
        else if (scenario == 9) {
            cout << "Your Tamaraw won't stop destroying things with its horns\n";
            cout << "A. Cut the horns shorter\nB. Do nothing\nC. Scold and lecture tamaraw\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health-=18;
            else if(ans=='B') health+=5;
            else health-=5;
        }
        else if (scenario == 10) { //this wer i stoppd
            cout << "Your Tamaraw suddenly refuses to eat anything!\n";
            cout << "A. Force feed with grass\nB. Bring gourmet organic greens\nC. Talk to it and say that it will go extict if it doesn't eat\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=10;
            else if(ans=='B') health-=5;
            else health-=5;
        }
        else if (scenario == 11) {
            cout << "You saw a rare and critically endangered 8ft alligator approaching your Tamaraw!\n";
            cout << "A. Kill the alligator\nB. Scream at your Tamaraw and tell it to run\nC. Just stand there and watch\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=0;
            else if(ans=='B') health-=100;
            else health+=8;
        }
        else if (scenario == 12) {
            cout << "Your Tamaraw suddenly runs full speed toward you!\n";
            cout << "A. Pretend to faint\nB. Scream at it\nC. Jump as high as you can\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=0;
            else if(ans=='B') health-=5;
            else health+=0;
        }
        else if (scenario == 13) {
            cout << "Your Tamaraw got stuck in the mud.\n";
            cout << "A. Nothing\nB. Tie a rope around its neck to pull it out\nC. Call a crane operator to lift it out\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=0;
            else if(ans=='B') health-=7;
            else health-=4;
        }
        else if (scenario == 14) {
            cout << "Your Tamaraw won't stop making loud noises.\n";
            cout << "A. Play white noise to calm it\nB. Mimic the sound\nC. Tell it to shut up\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=5;
            else if(ans=='B') health+=0;
            else health-=2;
        }
        else if (scenario == 15) {
            cout << "Your Tamaraw chipped its horn\n";
            cout << "A. Cut off the rest to make it even\nB. Ask ChatGPT what to do\nC. Use super glue\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health-=14;
            else if(ans=='B') health+=8;
            else health-=10;
        }
        else if (scenario == 16) {
            cout << "Your Tamaraw's fur is shedding heavily.\n";
            cout << "A. Groom it\nB. Collect the fur for no reason\nC. Take pictures of it\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=5;
            else if(ans=='B') health-=5;
            else health+=0;
        }
        else if (scenario == 17) {
            cout << "Your Tamaraw accidentaly stepped on your foot.\n";
            cout << "A. Scream loudly in agony\nB. Slap it's butt to discipline it\nC. Cry silently\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health-=4;
            else if(ans=='B') health+=5;
            else health+=0;
        }
        else if (scenario == 18) {
            cout << "Your Tamaraw is crying for no reason\n";
            cout << "A. Play a sad OPM and relapse too\nB. Play a Cocomelon video\nC. Show it a jumpscare video\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=8;
            else if(ans=='B') health-=10;
            else health-=10;
        }
        else if (scenario == 19) {
            cout << "Your Tamaraw is hyperfixating on a broom and won't stop licking it.\n";
            cout << "A. Take the broom away\nB. Let it do what it wants\nC. Build your newly bought MG ZZ Gundam Ver.Ka\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health-=7;
            else if(ans=='B') health+=0;
            else health+=30;
        }
        else if (scenario == 20) {
            cout << "Beabadoobee wants to see and pet your Tamaraw.\n";
            cout << "A. Let her see and pet your Tamaraw\nB. Refuse\nC. Invite Kim Kardashian instead\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=15;
            else if(ans=='B') health+=0;
            else health-=15;
        }
        else if (scenario == 21) {
            cout << "Your Tamaraw wants to listen to music\n";
            cout << "A. Play Carlos Agassi's music\nB. Play Lana Del Rey\nC. Play jazz music\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health-=3;
            else if(ans=='B') health+=3;
            else health+=6;
        }
        else if (scenario == 22) {
            cout << "Oh no! Your Tamaraw broke your newly built MG Full Armor Unicorn Gundam Ver.Ka.\n";
            cout << "A. Scold your cow\nB. Hit your Tamaraw \nC. Don't give Tamaraw dinner\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health-=5;
            else if(ans=='B') health+=5;
            else health-=15;
        }
        else if (scenario == 23) {
            cout << "Your Tamaraw's poop is black!\n";
            cout << "A. Call helicopter ambulance and rush to vet\nB. Do nothing\nC. Put white dye in it's next meal\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health-=10;
            else if(ans=='B') health+=8;
            else health-=5;
        }
        else if (scenario == 24) {
            cout << "Your partner is jealous of your Tamaraw because you're giving it more attention.\n";
            cout << "A. Scold your partner be more clingy to your Tamaraw\nB. Spend more time with the Tamaraw\nC. Scold the Tamaraw for making your girlfriend jealous\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health-=8;
            else if(ans=='B') health-=6;
            else health+=0;
        }
        else if (scenario == 25) {
            cout << "Your Tamaraw is now jealous of your partner because you're giving them more attention.\n";
            cout << "A. Do nothing\nB. Argue with the Tamaraw\nC. Spend more time with your Partner\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=8;
            else if(ans=='B') health-=5;
            else health+=3;
        }
        else if (scenario == 26) {
            cout << "Today is your Tamaraw's birthday!\n";
            cout << "A. Give it vanilla cake\nB. Give it chocolate cake\nC. Give it matcha cake\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health-=5;
            else if(ans=='B') health-=15;
            else health+=6;
        }
        else if (scenario == 27) {
            cout << "Your Tamaraw wants a new toy.\n";
            cout << "A. Buy a bouncy castle\nB. Buy a Barbie dream house set\nC. Buy a PS5 Pro Limited Edition\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=6;
            else if(ans=='B') health-=3;
            else health+=15;
        }
        else if (scenario == 28) {
            cout << "Your Tamaraw got overweight!\n";
            cout << "A. Put it on OMAD\nB. 1 hour of treadmill everyday\nC. Give it weightloss supplements\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health-=8;
            else if(ans=='B') health+=7;
            else health-=17;
        }
        else if (scenario == 29) {
            cout << "Your Tamaraw can't sleep.\n";
            cout << "A. Sing Ili Ili Tulog Anay\nB. Give it 1000mg of ZzzQuil\nC. Play with it until it gets tired\n";
            cout << "What will you do?: ";
            cin >> ans; ans = toupper(ans);
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (ans == 'X' || ans == 'x') {
                cout << "\nGame stopped...\n";
                Sleep(1000);
                return;
            }
            if(ans=='A') health+=-10;
            else if(ans=='B') health-=15;
            else health-=10;
        }

        cout << "\nCurrent Health: " << health << "\n";
        cout << "\n------------------------\n\n";
        Sleep(700);

        if (health <= 0) {
            cout << "Your Tamaraw has died. Game Over. YOU CAN'T PLAY THE GAME AGAIN!!!\n";
            writePermanentBan(saveFile);
            Sleep(1200);
            exit(0);
        }
    }

    cout << "\nHealth at end: " << health << "\n";
    cout << "\n==================== GAME END ====================\n";
    if (health >= 80) cout << "Your cow is VERY HEALTHY! Great job!\n";
    else if (health >= 50) cout << "Your cow is okay, but could be better.\n";
    else cout << "Your cow is weak. Try again.\n";

}