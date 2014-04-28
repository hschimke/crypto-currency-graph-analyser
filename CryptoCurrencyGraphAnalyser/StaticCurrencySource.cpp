//
//  StaticCurrencySource.cpp
//  CryptoCurrencyGraphAnalyser
//
//  Created by Henry Schimke on 4/20/14.
//  Copyright (c) 2014 Henry Schimke. All rights reserved.
//

#include "StaticCurrencySource.h"

StaticCurrencySource::StaticCurrencySource(){}
StaticCurrencySource::~StaticCurrencySource(){}

void StaticCurrencySource::parseSource(CryptoCurrencyGraph &graph){
    this->parseSource(graph, EMPTY_CRYPTOCURRENCY_NAME_PREFIX);
}
void StaticCurrencySource::parseSource(CryptoCurrencyGraph &graph, std::string name_prefix){
    
    /*
     
     Basic layout
     
     BTC -> DOG (.5)
     BTC -> RDD (.05)
     BTC -> LTC (.75)
     DOG -> LTC (1.5)
     LTC -> RDD (.005)
     DOG -> RDD (.75)
     
     */
    
    /*CryptoCurrencyGraphNode& BTC_node = graph.getOrAddNodeByName("BTC");
     CryptoCurrencyGraphNode& DOG_node =    graph.getOrAddNodeByName("DOG");
     CryptoCurrencyGraphNode& LTC_node=    graph.getOrAddNodeByName("LTC");
     CryptoCurrencyGraphNode& RDD_node=    graph.getOrAddNodeByName("RDD");*/
    
    graph.addLink(this->getPrefixedName("BTC", name_prefix),
                  this->getPrefixedName("DOGE", name_prefix),
                  0.5);
    graph.addLink(this->getPrefixedName("DOGE", name_prefix),
                  this->getPrefixedName("BTC", name_prefix),
                  0.5);
    graph.addLink(this->getPrefixedName("BTC", name_prefix),
                  this->getPrefixedName("RDD", name_prefix),
                  0.05);
    graph.addLink(this->getPrefixedName("BTC", name_prefix),
                  this->getPrefixedName("LTC", name_prefix),
                  0.75);
    graph.addLink(this->getPrefixedName("LTC", name_prefix),
                  this->getPrefixedName("BTC", name_prefix),
                  0.75);
    graph.addLink(this->getPrefixedName("DOGE", name_prefix),
                  this->getPrefixedName("LTC", name_prefix),
                  1.15);
    graph.addLink(this->getPrefixedName("LTC", name_prefix),
                  this->getPrefixedName("RDD", name_prefix),
                  0.005);
    graph.addLink(this->getPrefixedName("DOGE", name_prefix),
                  this->getPrefixedName("RDD", name_prefix),
                  0.75);
    graph.addLink(this->getPrefixedName("BTC", name_prefix),
                  this->getPrefixedName("FKE", name_prefix),
                  0.9);
    graph.addLink(this->getPrefixedName("FKE", name_prefix),
                  this->getPrefixedName("LTC", name_prefix),
                  0.11);
    return;
}