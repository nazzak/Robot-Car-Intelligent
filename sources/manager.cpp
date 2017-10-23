#include <iostream>
#include <sstream>
#include "../headers/manager.h"
#include "../headers/definition.h"

Manager * Manager::instance = nullptr;

Manager * Manager::getInstance(){
    if(instance == nullptr){
        instance = new Manager();
    }
    return instance;
}

void Manager::update(){
    if(!sceneIsDefine())
        return;
    cleanMatrice();
    
    /*Bloc*/
    for (int16_t index = 0; index < bloc->list_bloc->size(); ++index){
        generalTable[bloc->list_bloc->at(index).first][bloc->list_bloc->at(index).second] = BLOC_DEF;
    }

    /*Chemin*/
    for (int16_t index = 0; index < chemin->list_chemin->size(); ++index){
        generalTable[chemin->list_chemin->at(index).first][chemin->list_chemin->at(index).second] = CHEMIN_DEF;
    }

    /*Car*/
    if(car->getPosition().first >= 0)
        generalTable[car->getPosition().first][car->getPosition().second] = CAR_DEF;

    /*Arrive*/
    if(arrive->getPosition().first >= 0)
        generalTable[arrive->getPosition().first][arrive->getPosition().second] = ARRIVE_DEF;
}

void Manager::cleanMatrice(){
    for (int8_t x = 0; x < getSceneCarrer(); ++x){
        for (int8_t y = 0; y < getSceneCarrer(); ++y){
            generalTable[x][y] = 0;
        }
    }
}

std::string Manager::forDevelopper(){
    stringstream buf;
    buf << "---|---|---|---|---|---|---|---\n";
    for (int8_t x = 0; x < getSceneCarrer();++x){
        for (int8_t y = 0; y < getSceneCarrer();++y){
            buf << "-" + to_string(generalTable[x][y]) + "-|";
        }
        buf << "\n";
    }
    buf << "---|---|---|---|---|---|---|---\n";
    return buf.str();
}

std::string Manager::toString(){
    stringstream buf;
    buf << "{\n";
      buf <<"\t{\"Scene\": " <<scenecarrer<<"},\n";
      buf << "\t{\"Bloc\": "<<bloc->toString()<<"},\n";
      buf << "\t{\"Arrive\": "<<arrive->toString()<<"},\n";
      buf << "\t{\"Chemin\": "<<chemin->toString()<<"}\n";
      buf << "}";
    return buf.str();
}