#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <regex>

using namespace std;

regex minuteRegex("(\\d+)");
regex teamNameRegex("\"(.*)\"");
regex playerNameRegex("by  *([a-zA-Z ]*)\\b");
regex matchScoreRegex("\"(.*)\"  *-  *\"(.*)\"  *(\\d+):(\\d+)");
regex goalAutorRegex(" *([a-zA-Z ]*)\\b  *");

smatch match;

class FootballStatisticsManager {
private:
    struct Player {
        string name;
        int totalGoals;
        int scoreOpens;
        unordered_map<int, int> goalsByMinute;
        string team;
    };

    struct Team {
        string name;
        int totalGoals;
        int totalMatches;
        int scoreOpens;
    };

    unordered_map<string, Team> teams;
    unordered_map<string, Player> players;

    void addMatch(const string& firstTeamName, const string& secondTeamName,
                  int firstScore, int secondScore) {

        if (teams.find(firstTeamName) == teams.end())
            addTeam(firstTeamName);
        if (teams.find(secondTeamName) == teams.end())
            addTeam(secondTeamName);
        
        teams[firstTeamName].totalGoals += firstScore;
        ++teams[firstTeamName].totalMatches;
        teams[secondTeamName].totalGoals += secondScore;
        ++teams[secondTeamName].totalMatches;
        
        string line;
        int minTimeFirst = 100;
        int minTimeSecond = 100;
        string scoreOpensPlayerNameFirst = "";
        string scoreOpensPlayerNameSecond = "";

        for (int i = 0; i < firstScore; ++i) {

            getline(cin, line);
            string autor = extractGoalAutor(line);
            int minute = extractMinute(line);
            // cout << "playerName = " << '"' << autor << '"' << " minute = " << minute << endl;

            if (players.find(autor) == players.end())
                addPlayer(firstTeamName, autor);
            ++players[autor].totalGoals;
            ++players[autor].goalsByMinute[minute];

            if (minute < minTimeFirst) {
                minTimeFirst = minute;
                scoreOpensPlayerNameFirst = autor;
            }

        }

        for (int i = 0; i < secondScore; ++i) {

            getline(cin, line);
            string autor = extractGoalAutor(line);
            int minute = extractMinute(line);
            // cout << "playerName = " << '"' << autor << '"' << " minute = " << minute << endl;

            if (players.find(autor) == players.end())
                addPlayer(secondTeamName, autor);
            ++players[autor].totalGoals;
            ++players[autor].goalsByMinute[minute];
            
            if (minute < minTimeSecond) {
                minTimeSecond = minute;
                scoreOpensPlayerNameSecond = autor;
            }

        }

        if (minTimeFirst < minTimeSecond) {
            ++teams[firstTeamName].scoreOpens;
            ++players[scoreOpensPlayerNameFirst].scoreOpens;
        } else if (minTimeFirst > minTimeSecond) {
            ++teams[secondTeamName].scoreOpens;
            ++players[scoreOpensPlayerNameSecond].scoreOpens;
        }
    }

    void addTeam(const string& teamName) {
        Team team;
        team.name = teamName;
        team.totalGoals = 0;
        team.totalMatches = 0;
        team.scoreOpens = 0;
        teams[teamName] = team;
    }

    void addPlayer(const string& teamName, const string& playerName) {
        Player player;
        player.name = playerName;
        player.totalGoals = 0;
        player.scoreOpens = 0;
        player.team = teamName;
        players[playerName] = player;
    }

    int totalGoalsFor(const string& teamName) {
        if (teams.find(teamName) != teams.end())
            return teams[teamName].totalGoals;
        return 0;
    }

    double meanGoalsPerGameFor(const string& teamName) {
        if (teams.find(teamName) != teams.end())
            return static_cast<double>(teams[teamName].totalGoals) / teams[teamName].totalMatches;
        return 0.0;
    }

    int totalGoalsBy(const string& playerName) {
        if (players.find(playerName) != players.end())
            return players[playerName].totalGoals;
        return 0;
    }

    double meanGoalsPerGameBy(const string& playerName) {
        if (players.find(playerName) != players.end())
            return static_cast<double>(players[playerName].totalGoals) / teams[players[playerName].team].totalMatches;
        return 0.0;
    }

    int goalsOnMinuteBy(int minute, const string& playerName) {
        if (players.find(playerName) != players.end() &&
            players[playerName].goalsByMinute.find(minute) != players[playerName].goalsByMinute.end())
            return players[playerName].goalsByMinute[minute];
        return 0;
    }

    int goalsOnFirstMinutesBy(int minutes, const string& playerName) {
        if (players.find(playerName) == players.end()) return 0;
        int goals = 0;
        for (auto& goal : players[playerName].goalsByMinute) {
            if (1 <= goal.first && goal.first <= minutes) {
                goals += goal.second;
            }
        }
        return goals;
    }

    int goalsOnLastMinutesBy(int minutes, const string& playerName) {
        if (players.find(playerName) == players.end()) return 0;
        int goals = 0;
        for (auto& goal : players[playerName].goalsByMinute) {
            if ((91 - minutes) <= goal.first && goal.first <= 90) {
                goals += goal.second;
            }
        }
        return goals;
    }

    int scoreOpensByTeam(const string& teamName) {
        if (teams.find(teamName) != teams.end())
            return teams[teamName].scoreOpens;
        return 0;
    }

    int scoreOpensByPlayer(const string& playerName) {
        if (players.find(playerName) != players.end())
            return players[playerName].scoreOpens;
        return 0;
    }

    string extractTeamName(const string& input) {
        regex_search(input, match, teamNameRegex);
        return match[1].str();
    }

    string extractPlayerName(const string& input) {
        regex_search(input, match, playerNameRegex);
        return match[1].str();
    }

    int extractMinute(const string& input) {
        regex_search(input, match, minuteRegex);
        return stoi(match[1]);
    }

    pair<string, string> extractMatchTeams(const string& input) {
        regex_search(input, match, matchScoreRegex);
        return make_pair(match[1].str(), match[2].str());
    }

    pair<int, int> extractMatchScores(const string& input) {
        regex_search(input, match, matchScoreRegex);
        return make_pair(stoi(match[3]), stoi(match[4]));
    }

    string extractGoalAutor(const string& input) {
        regex_search(input, match, goalAutorRegex);
        return match[1].str();
    }

public:
    void processInput(const string& input) {
        if (input.find("Total goals for") != string::npos) {
            string teamName = extractTeamName(input);
            // cout << "teamName = "<< '"' << teamName << '"' <<endl;
            int totalGoals = totalGoalsFor(teamName);
            cout << totalGoals << endl;
        } else if (input.find("Mean goals per game for") != string::npos) {
            string teamName = extractTeamName(input);
            // cout << "teamName = "<< '"' << teamName << '"' <<endl;
            double meanGoals = meanGoalsPerGameFor(teamName);
            cout << meanGoals << endl;
        } else if (input.find("Total goals by") != string::npos) {
            string playerName = extractPlayerName(input);
            // cout << "playerName = "<< '"' << playerName << '"' <<endl;
            int totalGoals = totalGoalsBy(playerName);
            cout << totalGoals << endl;
        } else if (input.find("Mean goals per game by") != string::npos) {
            string playerName = extractPlayerName(input);
            // cout << "playerName = "<< '"' << playerName << '"' <<endl;
            double meanGoals = meanGoalsPerGameBy(playerName);
            cout << meanGoals << endl;
        } else if (input.find("Goals on minute") != string::npos) {
            int minute = extractMinute(input);
            string playerName = extractPlayerName(input);
            // cout << "playerName = "<< '"' << playerName << '"' <<endl;
            int goals = goalsOnMinuteBy(minute, playerName);
            cout << goals << endl;
        } else if (input.find("Goals on first") != string::npos) {
            int minute = extractMinute(input);
            string playerName = extractPlayerName(input);
            // cout << "playerName = "<< '"' << playerName << '"' <<endl;
            int goals = goalsOnFirstMinutesBy(minute, playerName);
            cout << goals << endl;
        } else if (input.find("Goals on last") != string::npos) {
            int minute = extractMinute(input);
            string playerName = extractPlayerName(input);
            // cout << "playerName = "<< '"' << playerName << '"' <<endl;
            int goals = goalsOnLastMinutesBy(minute, playerName);
            cout << goals << endl;
        } else if (input.find("Score opens by") != string::npos) {
            int opens;
            if (input.find("\"") != string::npos) {
                string teamName = extractTeamName(input);
                // cout << "teamName = "<< '"' << teamName << '"' <<endl;
                opens = scoreOpensByTeam(teamName);
            } else {
                string playerName = extractPlayerName(input);
                // cout << "playerName = "<< '"' << playerName << '"' <<endl;
                opens = scoreOpensByPlayer(playerName);
            }
            cout << opens << endl;
        } else if (input.find(":") != string::npos) {
            pair<string, string> matchTeamNames = extractMatchTeams(input);
            pair<int, int> matchTeamScores = extractMatchScores(input);
            // cout << "firstTeamName = \"" << matchTeamNames.first << "\" scores = " << matchTeamScores.first << " secondTeamName = \"" << matchTeamNames.second << "\" scores = " << matchTeamScores.second << endl;
            addMatch(matchTeamNames.first, matchTeamNames.second, matchTeamScores.first, matchTeamScores.second);
        }
    }

    void printStatistics() {
        cout << "teams:" << endl;
        for (auto& team : teams) {
            cout << team.first << " scoreOpens = " << team.second.scoreOpens << " totalGoals = " << team.second.totalGoals << " totalMatches = " << team.second.totalMatches << endl;
        }
        cout << "players:" << endl;
        for (auto& player : players) {
            cout << player.first << " scoreOpens = " << player.second.scoreOpens << " totalGoals = " << player.second.totalGoals << " team = " << player.second.team << " goalsByMinute: ";
            for (auto& goal : player.second.goalsByMinute) {
                cout << goal.first << "' x" << goal.second << " ";
            }
            cout << endl;
        }
    }

};


int main() {

    FootballStatisticsManager manager;

    string line;
    while (getline(cin, line)) {
        if (line.empty()) {
            break;
        }
        manager.processInput(line);
    }

    // manager.printStatistics();

    return 0;

}