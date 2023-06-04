#include <iostream>
#include <algorithm>
#include "MagicalContainer.hpp"

void MagicalContainer :: addElement(int element) //addElement
{ 
    bool contains = (std::find(mysticalElements.begin(), mysticalElements.end(), element) != mysticalElements.end());
    if(!contains){
        this ->mysticalElements.push_back(element);
    }
}

void MagicalContainer :: removeElement(int element){ //removeElement
    this -> mysticalElements.erase(std::remove(mysticalElements.begin(), mysticalElements.end(), element), mysticalElements.end());
}

int MagicalContainer :: size()const{ //return size of container
    return this -> mysticalElements.size();
}

std::vector<int>  MagicalContainer :: getElements()const{ //get Elements of container
    return this ->mysticalElements;
}