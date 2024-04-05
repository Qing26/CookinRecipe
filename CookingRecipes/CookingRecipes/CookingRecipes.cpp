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
        {"LETTUCE", "TOMATO", "CUCUMBER", "OIL"},
        {"CHICKEN", "RICE", "SOY"},
        {"BEEF", "TOMATO", "ONION", "GARLIC", "PASTA"},
        {"EGGS", "MILK", "FLOUR", "SUGAR"}, 
        {"BEANS", "RICE", "AVOCADO", "TOMATO"},
        {"POTATO", "EGGS", "ONION", "OIL"}
    };
    vector<string> recipeNames = { "Macarroni", "Bread", "Salad","Chicken with rice","Spaguettis","Pancakes","Burrito","Tortilla" };

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
