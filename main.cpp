#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string answer = "\n";
    int questionNumber = 0;
    int correctAnswers = 0;
    int notMatched = 0;
    int firstGuesses = 0;
    int strikes = 0;
    int rounds = 0;
    int team1Points = 0;
    int team2Points = 0;
    int scoreKeeper = 0;
    int teamSelection;
    vector<vector<string> > setlist = { {{"What are the top 4 things you think of when you hear the word \"Easter\"?"} ,
                                               {"Bunny - 49"} ,
                                               {"Egg - 23"} ,
                                               {"Sunday - 16"} ,
                                               {"Basket - 12"} },
                                       {{"Name the top 4 colors that remind you of Easter."},
                                               {"Pink - 34"},
                                               {"Yellow - 27"},
                                               {"Green - 24"},
                                               {"Blue - 15"} },
                                       {{"What are the top 4 events hosted on Easter Sunday?"},
                                               {"Easter Egg Hunt - 43"},
                                               {"Easter Supper - 31"},
                                               {"Church Service - 20"},
                                               {"Egg Dying - 06"} },
                                       {{"Name the top 5 famous animals the Easter Bunny would most likely sit next to\nat a famous animals convention."},
                                               {"Mickey Mouse - 29"},
                                               {"The Geico Gecko - 24"},
                                               {"Tony the Tiger - 20"},
                                               {"Rudolph - 19"},
                                               {"Kermit the Frog - 08"} },
                                       {{"Name 5 things you wouldn't want the Easter Bunny to leave in your basket."},
                                               {"Poop - 32"},
                                               {"Rotten Eggs - 24"},
                                               {"Dirt - 23"},
                                               {"Candy Wrappers - 18"},
                                               {"Nothing - 03"} },
                                       {{"Besides the Easter Bunny, name 6 famous rabbits/bunnies."},
                                               {"Bugs Bunny - 41"},
                                               {"Roger Rabbit - 21"},
                                               {"Peter Cottontail - 15"},
                                               {"The Energizer Bunny - 12"},
                                               {"The White Rabbit (Alice in Wonderland) - 07"},
                                               {"Velveteen - 04"} },
                                       {{"Name 6 other icons that fill in for the Easter Bunny if it got the flu."},
                                               {"Santa Claus - 33"},
                                               {"Tooth Fairy - 26"},
                                               {"Cupid - 19"},
                                               {"Bugs Bunny - 16"},
                                               {"Parents - 04"},
                                               {"Mother Nature - 02"} }
    };

    cout << "Welcome to Easter-Themed Family Fued!!\n";
    cout << "The rules work exactly like the original game show, but these surveys are limited to Easter-themed questions.\n\n";
    while (rounds < setlist.size()) {
        rounds++;
        cout << setlist[questionNumber][0] << endl;
        while (correctAnswers < setlist[questionNumber].size() - 1 && strikes < 3) {
            getline(cin, answer);
            if (answer == "")
                getline(cin, answer);
            firstGuesses++;
            for (int i = 1; i < setlist[questionNumber].size(); i++) {
                if (setlist[questionNumber][i].find(answer) != string::npos) {
                    cout << "It's on the board, you get "
                         << setlist[questionNumber][i][setlist[questionNumber][i].size() - 2]
                         << setlist[questionNumber][i][setlist[questionNumber][i].size() - 1] << " points!\n";
                    scoreKeeper += (setlist[questionNumber][i][setlist[questionNumber][i].size() - 2] - '0') * 10;
                    scoreKeeper += setlist[questionNumber][i][setlist[questionNumber][i].size() - 1] - '0';
                    correctAnswers++;
                    setlist[questionNumber][i] = "";
                    i = setlist[questionNumber].size();
                } else {
                    notMatched++;
                }
                if (notMatched == setlist[questionNumber].size() - 1 && (firstGuesses > 2)){
                    cout << "Strike " << strikes + 1 << "!\n";
                    strikes++;
                } else if (notMatched == setlist[questionNumber].size() - 1 && !(firstGuesses > 2)){
                    cout << "Sorry, it is not on the board.\n";
                }
            }
            notMatched = 0;
            answer = "\n";
        }
        firstGuesses = 0;
        if (strikes == 3) {
            cout << "The playing team got 3 strikes! What is the other team's guess to potentially steal the points?\n";
            getline(cin, answer);
            if (answer == "")
                getline(cin, answer);
            for (int i = 1; i < setlist[questionNumber].size(); i++) {
                if (setlist[questionNumber][i].find(answer) != string::npos) {
                    cout << "It's on the board, you stole the points!\n";
                    scoreKeeper += (setlist[questionNumber][i][setlist[questionNumber][i].size() - 2] - '0') * 10;
                    scoreKeeper += setlist[questionNumber][i][setlist[questionNumber][i].size() - 1] - '0';
                    i = setlist[questionNumber].size();
                } else {
                    notMatched++;
                }
                if (notMatched == setlist[questionNumber].size() - 1) {
                    cout << "It is not on the board. No points stolen.\n\n";
                }
            }
            notMatched = 0;
            answer = "\n";
        }
        cout << "Which team received those points? 1 or 2?\n";
        cin >> teamSelection;
        switch(teamSelection)
        {
            case 1:
                cout << "Team 1 gained " << scoreKeeper << " points!\n";
                team1Points += scoreKeeper;
                break;
            case 2:
                cout << "Team 2 gained " << scoreKeeper << " points!\n";
                team2Points += scoreKeeper;
                break;
        }
        scoreKeeper = 0;
        cout << "\n\nThe current scores are:\nTeam 1: " << team1Points << "\tTeam 2: " << team2Points;
        answer = "\n";
        firstGuesses = 0;
        cin.clear();
        if (questionNumber != setlist.size() - 1)
            cout << "\n\nNext Survey Question!\n";
        else {
            cout << "\n\nThat's the end of the game! The winning team is: ";
            if (team1Points > team2Points)
                cout << "Team 1!\n";
            else
                cout << "Team 2!\n";
        }
        questionNumber++;
        correctAnswers = 0;
        strikes = 0;
        correctAnswers = 0;
        cin.clear();
    }
}

/*vector<vector<string>> setlist = { {{"What are the top 4 things you think of when you hear the word \"Easter\"?"} ,
                                       {"Bunny - 49"} ,
                                       {"Egg - 23"} ,
                                       {"Sunday - 16"} ,
                                       {"Basket - 12"} },
                                       {{"Name the top 4 colors that remind you of Easter."},
                                        {"Pink - 34"},
                                        {"Yellow - 27"},
                                        {"Green - 24"},
                                        {"Blue - 15"} },
                                       {{"What are the top 4 events hosted on Easter Sunday?"},
                                        {"Easter Egg Hunt - 43"},
                                        {"Easter Supper - 31"},
                                        {"Egg Dying - 20"},
                                        {"Easter Lunch - 06"} }
                                       };*/