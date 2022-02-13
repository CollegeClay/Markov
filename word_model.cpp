/*
   CSCI 262 Data Structures, Fall 2019, Project 4 - Markov

   Author: Lucas Henke

   Modified: 10/24/2019
*/

#include "word_model.h"

#include <sstream>

#include <iostream>

void word_model::initialize(string text, int order) {

    vector<string> words;
    string word = "";
    string key;

    stringstream sin(text);
    int count = 0;
    while(!sin.eof()){
        sin >> word;
        words.push_back(word);
    }

    for(int w = 0 ; w < words.size(); w++){
        key = "";

        for(int o = 0; o < order; o++){
            key += words[(w+o) % words.size()] + " ";
        }

        wMap[key].push_back((words[(w+order) % words.size()]));
    }



}


string word_model::generate(int size) {

    map<string, vector<string>>::iterator it;
    string seed = "";

    string result = "";
    int c = 0;
    int random = rand() % wMap.size();
    for(it = wMap.begin(); it != wMap.end(); it++){
        if(random == c){
            seed = it->first;
            break;
        }
        c++;
    }

    for(int i = 0; i < size; i++){
        string nWord = "";
        if(wMap[seed].size() == 1){
            nWord = wMap[seed][0];
        }else{
            nWord = wMap[seed][rand() % wMap[seed].size()];
        }
        nWord += " ";
        result += nWord;
        seed = seed.substr(seed.find(' ') + 1) + nWord;
    }
    return result;
}


