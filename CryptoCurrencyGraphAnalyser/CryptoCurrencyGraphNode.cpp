//
//  CryptoCurrencyGraphNode.cpp
//  CryptoCurrencyGraphAnalyser
//
//  Created by Henry Schimke on 4/19/14.
//  Copyright (c) 2014 Henry Schimke. All rights reserved.
//

#include "CryptoCurrencyGraphNode.h"
#include <string>

CryptoCurrencyGraphNode::CryptoCurrencyGraphNode(std::string name){
    this->currency_name = std::string(name);
}

CryptoCurrencyGraphNode::CryptoCurrencyGraphNode(){
    this->currency_name = "UNDEF";
}

CryptoCurrencyGraphNode::~CryptoCurrencyGraphNode(){
    
}

std::string CryptoCurrencyGraphNode::getName(){
    return this->currency_name;
}

void CryptoCurrencyGraphNode::addLink(std::string name, double cost){
    this->links[name]=cost;
}

double CryptoCurrencyGraphNode::getLinkCost(std::string name){
    double return_value;
    
    if(this->links.find(name) == this->links.end()){
        return_value = -1;
    }else{
        return_value = this->links[name];
    }

    return return_value;
}