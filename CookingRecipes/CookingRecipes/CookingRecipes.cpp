// CookingRecipes.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "StaticCooking.h"
using namespace std;

vector<string> askIngrediets() {
    vector<string> ingredients;
    string ingredient;
    cout << "Enter your ingredients (type 'exit' to finish):" << endl;
    while (true) {
        cin >> ingredient;
        transform(ingredient.begin(), ingredient.end(), ingredient.begin(), ::toupper);
        if (ingredient == "EXIT") {
            break;
        }
        ingredients.push_back(ingredient);
    }
    return ingredients;
}


void findRecipes(vector<string> userIngredients) {
    vector<vector<string>> recipes = {
        {"TOMATO", "CHEESE", "PASTA"},
        {"FLOUR", "BUTTER"},
        {"LETTUCE", "TOMATO", "CUCUMBER", "OIL"}
    };
    vector<string> recipeNames = { "Macarroni", "Bread", "Salad" };

    bool foundAny = false;
    for (int i = 0; i < recipes.size(); i++) {
        if (canMakeRecipe(recipes[i], userIngredients)) {
            cout << "You can make: " << recipeNames[i] << endl;
            foundAny = true;
        }
    }

    if (!foundAny) {
        cout << "You don't have the ingredients for any of the recipes." << endl;
    }
}

int main() {
    vector<string> userIngredients = askIngrediets();
    findRecipes(userIngredients);
    return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
