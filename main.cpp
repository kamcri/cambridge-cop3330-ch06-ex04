/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Kameryn Cambridge
 */

#include "std_lib_facilities.h"
#include <iostream>


class Name_value{
public:
    string name;
    int value;
};

//vector storing all the names and values
vector<Name_value> Name_value_vec;

//check if names are the same
bool Name_check(string name, vector<Name_value> Name_value_vec){
    for(int i = 0; i < Name_value_vec.size(); i++){
        if(name == Name_value_vec[i].name){
            return true;
        }
    }
    return false;
}

int main(){
    //declare a new name value object
    Name_value nv;

    //get user input for a string name and int value
    cout << "Enter a name and value pair(Joe 17).\nTo exit, enter 'NoName 0'.\n";
    string str;
    int num;
    while(cin >> str >> num && str != "NoName" || num != 0){
        //add it to Name_value nv
        nv.name = str;
        nv.value = num;

        //check name to make sure it is unique 
        if(Name_check(str, Name_value_vec) == true){
            cerr << str << " has already been entered.\n";
            break;
        }

        //pushback to vector
        Name_value_vec.push_back(nv);
    }
    //print 
    cout << "List of all pairs: \n";
    for(int i = 0; i < Name_value_vec.size(); i++){
        cout << Name_value_vec[i].name << " " << Name_value_vec[i].value << ".\n";
    }
    return 0;
}
