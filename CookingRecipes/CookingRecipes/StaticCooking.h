#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool canMakeRecipe(vector<string> recipeIngredients, vector<string> userIngredients) {
    for (int i = 0; i < recipeIngredients.size(); i++) {
        bool found = false;
        for (int j = 0; j < userIngredients.size(); j++) {
            if (recipeIngredients[i] == userIngredients[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}