#define YY_NO_UNPUT
#include <unordered_map>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct util
{
    vector<string> values;
    int tam;
    int line;

    util() {}

    util(int line)
    {
        this->tam = 0;
        this->line = line;
    }

    util(int tam, int line)
    {
        this->tam = tam;
        this->line = line;
        values.reserve(this->tam);
    }
};

typedef vector<string> parametros;

unordered_map<string, util> variables;
unordered_map<string, parametros> functions;

void imprimir_map_util(unordered_map<string, util> m)
{
    for (auto x : m)
    {
        cout << x.first << endl;
        cout << "values:" << endl;
        for (auto y : x.second.values)
        {
            cout << y << " ";
        }
    }
}

void imprimir_map_funcs(unordered_map<string, parametros> m)
{
    for (auto x : m)
    {
        cout << x.first << endl;
        cout << "PARAMETERS: ";
        for (auto y : x.second) {
            cout << y << " ";
        }
        cout << endl;
    }
}

bool existe_variable(string name)
{
    return variables.count(name);
}

bool existe_funcion(string name)
{
    return functions.count(name);
}

bool anhadir_id_var(string name, int line, int& error_line)
{
    if (existe_variable(name))
    {
        error_line = variables[name].line;
        return false; // la variable ya existe
    }
    // se crea una variable
    variables[name] = util(line);
    return true;
}

bool anhadir_id_arreglo(string name, int tam, int line, int& error_line)
{
    if (existe_variable(name))
    {
        return false; // la variable ya existe
        error_line = variables[name].line;
    }
    // se crea una variable
    variables[name] = util(tam, line);
    return true;
}

bool modificar_variable(string name, string val)
{
    if (!existe_variable(name))
    {
        return false; // la variable no existe
    }
    variables[name].values[0] = val;
    return true;
}

bool modificar_arreglo_en_i(string name, string val, int i)
{
    if (!existe_variable(name))
    {
        return false; // la variable no existe
    }
    if (i < 0 || i >= variables[name].tam)
    {
        return false; // la variable no se puede insertar en la posicion i
    }
    variables[name].values[i] = val;
    return true;
}

bool anhadir_id_function(string name, string parameters)
{
    if (existe_funcion(name))
        return false;   // la funcion ya existe

    vector<string> par;
    stringstream streamParameters(parameters);
    string temp;
    while (getline(streamParameters, temp, ','))
        par.push_back(temp);

    functions[name] = par;
    return true;
}
