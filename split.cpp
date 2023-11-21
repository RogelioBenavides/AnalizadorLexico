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

    cout << state << endl;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != separator[0])
        {
            token += s[i];
            if(state != states[3]){
                string letter = "";
                letter += s[i];
                state = states[1];
                cout << token << " " << state << endl;
                cout << letter << endl;
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
            cout << token << " " << state << endl;
            result.push_back(make_pair(token, transitions[state]));
            token = "";
            state = states[0];
        }
    }
    if (keywords.find(token) != keywords.end())
            {
                state = states[2];
            }
            cout << token << " " << state << endl;
    result.push_back(make_pair(token, transitions[state]));
    return result;
}


int main(int argc, char const *argv[])
{
    string s = "Hello!Marce int";
    vector<pair<string, string>> result = split(s, " ");
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i].first << " " << result[i].second << endl;
    }

    return 0;
}