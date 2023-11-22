//Rogelio Eduardo Benavides de la Rosa 574161
//Marcela Alejandra Elizondo Rojas 608979
//Proyecto Final Teoría de Autómatas
//21 de noviembre del 2023
//"Damos nuestra palabra que hemos realizado esta actividad con integridad académica."
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <map>

using namespace std;

//Funcion que recibe la cadena y el espacio para separarlo
vector<pair<string, string>> split(string s, string separator)
{
    vector<pair<string, string>> result;
    string token;

    //Estados del Automata, Incial, Q1 es identificador, Q2 es Palabra Reservada y DEAT STATE el estado trampa 
    vector<string> states = {"INITIAL", "Q1", "Q2", "DEATH_STATE"};
    //Set de Palabras reservadas
    set<string> keywords = {"int", "bool", "double", "long", "string", "char"};
    //Set de símbolos que no pueden ester en los identificadores
    set<string> symbols = {"+", "-", "*", "/", "=", "(", ")", "{", "}", ";", ":", ",", "<", ">", "!", "&", "|", "[", "]", "%"};
    //Se empieza el el estado incial
    string state = states[0];
    //Mapa que idntifica al estado con el string de salida 
    map<string, string> transitions = {
        {"INITIAL", ""},
        {"Q1", "Identificador"},
        {"Q2", "Palabra Reservada"},
        {"DEATH_STATE", "Invalido"}
    };

    //Por cada caracter en el token hace las siguientes validaciones
    for (int i = 0; i < s.size(); i++)
    {
        //Si hay un número en el estado inicial se va directo al DEATH STATE
        if(state == "INITIAL"){
            cout << state << endl;
            if(isdigit(s[i])){
                state = states[3];
                //Imprime el estado actual
                cout << s[i] << " " << state << endl;
            } 
        }
        //Si el caracter no es un " ", se van agregando para fornar el token
        if (s[i] != separator[0])
        {
            token += s[i];
            if(state != states[3]){
                string letter = "";
                letter += s[i];
                state = states[1];
                //Imprime el estado actual
                cout << token << " " << state << endl;
                //Si ino de estos tokens es un símbolo no válido, se va al DEATH STATE
                if(symbols.find(letter) != symbols.end()){
                    state = states[3];
                    //Imprime el estado actual
                    cout << token << " " << state << endl;
                }
            }
        }
        else
        {
            //Si el token está en el set de keywords, es un identificador
            if (keywords.find(token) != keywords.end())
            {
                //Llega al estado 2 por ser identificador
                state = states[2];
            }
            //Imprime el estado actual
            cout << token << " " << state << endl << endl;
            //Se agrega a los resultados el token y su string de salida
            result.push_back(make_pair(token, transitions[state]));
            token = "";
            //Vuelve a iniciar porque ya se completó el token
            state = states[0];
        }
    }
    //Si el token está en el set de keywords, es un identificador
    if (keywords.find(token) != keywords.end())
            {
                state = states[2];
            }
            //Imprime el estado actual
            cout << token << " " << state << endl << endl;
    //Se agrega a los resultados el token y su string de salida
    result.push_back(make_pair(token, transitions[state]));
    //Retorna el par de los tokens y sus strings de salida
    return result;
}


int main(int argc, char const *argv[])
{
    //Un vector para las líneas del archivo que se lea
    vector<string> lines;
    //String para leer la línea de código
    string s;
    //Se lee
    while (getline(cin, s))
    {
        if(s == "exit"){
            break;
        }
        lines.push_back(s);
    }
    cout << endl;
    //Vector para guardar los pares que retorne la función de los tokens y sus strings de salida
    vector<vector<pair<string, string>>> results;
    //Para cada línea leína
    for(int i = 0; i < lines.size(); i++){
        //Se llama a la función y se guardan los token y sus strings de salida de cada línea
        vector<pair<string, string>> result = split(lines[i], " ");
        //Se agrega al vector results
        results.push_back(result);
        //Se imprime para cada línea leída
        cout << "TEST #" << i + 1 << endl;
        for (int i = 0; i < result.size(); i++)
        {
            //Se imprime el token y su string de salida
            cout << result[i].first << " " << result[i].second << endl;
        }
        cout << endl;
    }
    //Se imprimen los resultados finales de cada token en resumen
    cout << "RESULTS" << endl;
    for (int i = 0; i < results.size(); i++)
    {
        cout << "TEST #" << i + 1 << endl;
        for (int j = 0; j < results[i].size(); j++)
        {
            //Se imprime el token y su string de salida
            cout << results[i][j].first << " " << results[i][j].second << endl;
        }
        cout << endl;
    }
    // Que se cierre el programa cuando de enter
    cin.get();
    return 0;
}