#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <map>

using namespace std;

vector<pair<string, string>> split(string s, string separator)
{
    vector<pair<string, string>> result;
    string token;

    vector<string> states = {"INITIAL", "Q1", "Q2", "DEATH_STATE"};
    set<string> keywords = {"int", "bool", "double", "long", "string", "char"};
    set<string> symbols = {"+", "-", "*", "/", "=", "(", ")", "{", "}", ";", ":", ",", "<", ">", "!", "&", "|", "[", "]", "%"};
    string state = states[0];
    map<string, string> transitions = {
        {"INITIAL", ""},
        {"Q1", "Identificador"},
        {"Q2", "Palabra Reservada"},
        {"DEATH_STATE", "Invalido"}
    };


    for (int i = 0; i < s.size(); i++)
    {
        if(state == "INITIAL"){
            cout << state << endl;
            if(isdigit(s[i])){
                state = states[3];
                cout << s[i] << " " << state << endl;
            } 
        }
        if (s[i] != separator[0])
        {
            token += s[i];
            if(state != states[3]){
                string letter = "";
                letter += s[i];
                state = states[1];
                cout << token << " " << state << endl;
                if(symbols.find(letter) != symbols.end()){
                    state = states[3];
                    cout << token << " " << state << endl;
                }
            }
        }
        else
        {
            if (keywords.find(token) != keywords.end())
            {
                state = states[2];
            }
            cout << token << " " << state << endl << endl;
            result.push_back(make_pair(token, transitions[state]));
            token = "";
            state = states[0];
        }
    }
    if (keywords.find(token) != keywords.end())
            {
                state = states[2];
            }
            cout << token << " " << state << endl << endl;
    result.push_back(make_pair(token, transitions[state]));
    return result;
}


int main(int argc, char const *argv[])
{
    vector<string> lines;
    string s;
    while (getline(cin, s))
    {
        if(s == "exit"){
            break;
        }
        lines.push_back(s);
    }
    cout << endl;
    vector<vector<pair<string, string>>> results;
    for(int i = 0; i < lines.size(); i++){
        vector<pair<string, string>> result = split(lines[i], " ");
        results.push_back(result);
        cout << "TEST #" << i + 1 << endl;
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i].first << " " << result[i].second << endl;
        }
        cout << endl;
    }
    cout << "RESULTS" << endl;
    for (int i = 0; i < results.size(); i++)
    {
        cout << "TEST #" << i + 1 << endl;
        for (int j = 0; j < results[i].size(); j++)
        {
            cout << results[i][j].first << " " << results[i][j].second << endl;
        }
        cout << endl;
    }
    return 0;
}