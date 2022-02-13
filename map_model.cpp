/*
   CSCI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Lucas Henke

   Modified: 10/24/2019
*/

#include "map_model.h"

#include <iostream>

using namespace std;
void map_model::initialize(string text, int order) {

    for(int a = 0; a < text.length(); a++){
        string key = "";

        for(int b = 0; b < order; b++){
            key += text[(a+b) % text.length()];
        }

        cMap[key].push_back(text[(a+order) % text.length()]);
    }


}

string map_model::generate(int size) {
    map<string, vector<char>>::iterator it;
    string seed = "";

    string result = "";
    int c = 0;
    int random = (rand() % cMap.size());
    for(it = cMap.begin(); it != cMap.end(); it++){
        if(random == c){
            seed = it->first;
            break;
        }
        c++;
    }


    for(int i = 0; i < size; i++){
        char nChar;
        if(cMap[seed].size() == 1){
            nChar = cMap[seed][0];
        }else{
            nChar = cMap[seed][rand() % cMap[seed].size()];
        }

        result += nChar;

        seed = seed.substr(1) + nChar;
    }



    return result;
}
