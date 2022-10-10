#include "std_lib_facilities.h"
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

bool isNum(string str);
int parseInt(string str);

int parseInt(string str) {

    int n = atoi(str.c_str());
    return n;
}

bool isNum(string str)

{
    stringstream sin(str);
    double d;
    char c;
    if (!(sin >> d))
    {
        return false;
    }
    if (sin >> c)
    {
        return false;
    }
    return true;
}

vector<int> flipCoin(vector<int> x, int y[3], int b) {//

    for (int i = 0; i < b; i++) {//put the array to "coin"
        if (x[y[i] - 1] == 1) //1 is the front side 0 is the back side
            x[y[i] - 1] = 0;
        else if (x[y[i] - 1] == 0) {
            if (x[y[b - 1] - 1] == 0 && b > 1) {//when the largest number is "0", it cannot be turned
                for (int i = 0; i < b; i++) {
                    y[i] = 4;
                    cout << "y" << i << "=" << y[i];
                }
                error("The right most coin is facing head can't choose this one please choose again");
            }
            x[y[i] - 1] = 1;
        }
    }
    for (int i = 0; i < b; i++)
        y[i] = 4;

    return x;
}

void playView(int totalSum, int round, vector<int>coin, vector<string> player, int n) {
    cout << "                                         " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "Ronud : " << round << endl;
    cout << "                                     " << "     There are" << "[" << totalSum << "]" << "coins are facing up." << endl;
    cout << "                                     " << " " << " " << " " << " " << " " << " " << " " << "-----------------------------" << endl;
    cout << "                                     " << " " << " " << " " << " " << " " << " " << " ";
    for (int i = 0; i < 10; i++) {
        if (coin[i] == 1)
            cout << "H" << "  ";
        if (coin[i] == 0)
            cout << "T" << "  ";
    }
    cout << endl;
    cout << "                                     " << " " << " " << " " << " " << " " << " " << " " << "-----------------------------" << endl;
    cout << "                                     " << " " << " " << " " << " " << " " << " " << " " << "1  2  3  4  5  6  7  8  9  10" << endl;
    cout << endl;
    cout << "                                           " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << "[" << player[n] << "]" << endl;
    cout << "                                    " << "       Please choose how many to turn (1-3): ";
}

void colorPrint(const char* s, int color)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
    printf(s);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | 7);
    cout << endl;
}


void logo() {
    cout << "                                                      ___________" << endl;
    cout << "                                                     /           \\   " << endl;
    cout << "                                                    /             \\  " << endl;
    cout << "                                                   /               \\  " << endl;
    cout << "                                                   |   COIN FLIP   | " << endl;
    cout << "                                                   \\              /" << endl;
    cout << "                                                    \\            /" << endl;
    cout << "                                                     \\__________/" << endl;
    for (int i = 0; i < 12; i++) {
        cout << endl;
    }
}
void Welcome() {                                                
    cout << "                                                      ___________" << endl;
    cout << "                                                     /           \\   "  << endl;
    cout << "                                                    /             \\  "  << endl;
    cout << "                                                   /               \\  " << endl;
    cout << "                                                   |   COIN FLIP   | "    << endl;
    cout << "                                                   \\              /" << endl;
    cout << "                                                    \\            /" << endl;
    cout << "                                                     \\__________/" << endl;
    for (int i = 0; i < 4;i++) {
        cout << endl;
    }
    cout << "                                "; colorPrint("PlayerA and PlayerB flip the coin game, a total of [10] coins", 4);
    cout << "                                "; colorPrint("PlayerA flips first, PlayerB flips back, in turn, each time you can flip[1 - 3]coins",4);
    cout << "                                "; colorPrint("Player who filp the 10th coin is the winner", 4);
    cout << endl;
    cout << "                                "; colorPrint("[Menu] : Press 'q' to[Quit]    Press 'r' to[Rule]",4);
    cout << endl;
    cout << "                                "; colorPrint(" _______________________________________________" ,8);
}

void cleanScreen() {
    for (int i = 0; i < 21; i++) {
        cout << endl;
    }
    logo();
}

void Rule() {
    cout << "                                           " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " " << " [Rule]" << endl;
    cout << "                               "; colorPrint("__________________________________________________________________________________________" ,8);
    cout << "                                "; colorPrint("PlayerA and PlayerB flip the coin game, a total of {10} coins" ,1);
    cout << "                                "; colorPrint("PlayerA flips first, PlayerB flips back, in turn, each time you can flip {1-3} coins" ,1);
    cout << "                                "; colorPrint("Player who filp the 10th coin is the winner" ,1);
    cout << "                                "; colorPrint("__________________________________________________________________________________________" ,1);
}

void Menu() {
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "                                "; colorPrint("_______________________________________________",8);
    cout << "                                         "; colorPrint("Quit  press   [q] ",5);
    cout << "                                         "; colorPrint("Rules press   [r] ",5);
    cout << "                                         "; colorPrint("Press [Enter any word] to continue",5);
    cout << "                                "; colorPrint("_______________________________________________",8);
    cout << endl;
    cout << endl;
    cout << endl;
}

int main() {
    Welcome();
    vector<string> player(2);
    vector<int>totalCoinNum;
    vector<int>coin;
    static int totalSum = 10;
    string InputString;
    player[0] = "Player_A";
    player[1] = "Player_B";
    int select = 0, playerID = 0, roundCounter = 0, round = 1;
    int len[3] = { 4,4,4 };

    for (int i = 0; i < 10; i++) {
        coin.push_back(1);
    }

    while (totalSum){

        if (roundCounter % 2 == 0 && roundCounter != 0){//round calculator
            round++;
            cleanScreen();
        }

        playView(totalSum,round,coin,player,playerID);

        try {
            string str;
            cin >> str;
            if (!isNum(str)){
                error("Please enter a number");
                cleanScreen();
                continue;
            }
            cleanScreen();
            select = parseInt(str);

            if (select > 3 || select < 1){
                error("Can only choose {1-3}, please select again");
                cleanScreen();
                continue;
            }

            if (select > totalSum){
                cout << "                                                Still left" << "[" << totalSum << "]" << "coin£¬" << endl;
                error("                                                Cannot select more coins than the remaining coins, please select again");
                select = 0;
                cout << endl;
                continue;
            }
            cout << "                                           Please choose which coin to flip: ";
            int inputNum;
            if (select == 1){
                try{
                    while (cin >> InputString){
                        if (!isNum(InputString)){
                            error("Please enter a number ");
                            break;
                        }
                        inputNum = parseInt(InputString);
                        if (inputNum > 10 || inputNum < 1){
                            error("Please enter a number from 1-10 ");
                            break;
                        }
                        totalCoinNum.push_back(inputNum);
                        break;
                    }
                }
                catch (const std::exception&){}
            }

            if (select == 2){ 
                try {
                    for (int i = 0; i < 2; i++) {
                        while (cin >> InputString) {
                            inputNum = parseInt(InputString);
                            if (inputNum == ' ')
                                break;
                            if (!isNum(InputString)) {
                                throw exception("Please enter a number from 1 - 10");
                                break;
                            }
                            inputNum = parseInt(InputString);
                            if (inputNum > 10 || inputNum < 1) {
                                throw exception("Please enter a number");
                                break;
                            }
                            totalCoinNum.push_back(inputNum);
                            break;
                        }
                        sort(totalCoinNum.begin(), totalCoinNum.end());
                    }
                }
                catch (string exception) {}
            }

            if (select == 3) {
                try {
                    for (int i = 0; i < 3; i++) {
                        while (cin >> InputString) {
                            inputNum = parseInt(InputString);
                            if (inputNum == ' ')
                                break;
                            if (!isNum(InputString)) {
                                throw exception("Please enter a number from 1 - 10");
                                break;
                            }
                            inputNum = parseInt(InputString);
                            if (inputNum > 10 || inputNum < 1) {
                                throw exception("Please enter a number");
                                break;
                            }
                            totalCoinNum.push_back(inputNum);
                            break;
                        }
                        sort(totalCoinNum.begin(), totalCoinNum.end());
                    }
                }
                catch(string exception){}
            }

            for (int i = 0; i < totalCoinNum.size(); i++) {
                len[i] = totalCoinNum[i];//Use an array to store each vector
            }

            coin = flipCoin(coin, len, totalCoinNum.size());

            totalCoinNum.clear();
            int tailConter = 0;
            for (int i = 0; i < 10; i++) { //Judgement of head and tail
                if (coin[i] == 1)
                    tailConter++;
            }

            totalSum = tailConter;//add them
            if (totalSum == 0) break;
            playerID++;
            if (playerID > 1)playerID = 0;
            roundCounter++;
            char  quit;
            Menu();
            cin >> quit;
            cleanScreen();
            if (quit == 'q')
                return 0;
            else if (quit == 'r') Rule();
            else {
                continue;
            }
        }
        catch (exception& e) {//Error catch
            cout << endl;
            cout << endl;
            totalCoinNum.clear();
            for (int i = 0; i < totalCoinNum.size(); i++)
                len[i] = 4;
            cout << "                                          " << e.what() << endl;
            if (roundCounter > 0 && round > 1 && roundCounter % 2 == 0)//When an error is reported during execution, prevent the round counter from increasing again
                roundCounter--;
            cout << endl;
            cout << endl;
            continue;
        }
        cout << endl;
        cout << endl;
        cout << "                                _______________________________________________" << endl;
    }

    cout << "                                            " << player[playerID] << " is Winner!!!!!!!!!!!!!!!!! " << endl;
    system("pause");
}



