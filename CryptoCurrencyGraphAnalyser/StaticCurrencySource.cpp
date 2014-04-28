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
    
    graph.addLink(name_prefix+"BTC", name_prefix+"DOGE", 0.5);
    graph.addLink(name_prefix+"DOGE", name_prefix+"BTC", 0.5);
    graph.addLink(name_prefix+"BTC", name_prefix+"RDD", 0.05);
    graph.addLink(name_prefix+"BTC", name_prefix+"LTC", 0.75);
    graph.addLink(name_prefix+"LTC", name_prefix+"BTC", 0.75);
    graph.addLink(name_prefix+"DOGE", name_prefix+"LTC", 1.15);
    graph.addLink(name_prefix+"LTC", name_prefix+"RDD", 0.005);
    graph.addLink(name_prefix+"DOGE", name_prefix+"RDD", 0.75);
    graph.addLink(name_prefix+"BTC", name_prefix+"FKE", 0.9);
    graph.addLink(name_prefix+"FKE", name_prefix+"LTC", 0.11);
    
    graph.addLink(name_prefix+"A", name_prefix+"B", 1);
    graph.addLink(name_prefix+"A", name_prefix+"C", 1);
    graph.addLink(name_prefix+"B", name_prefix+"C", 1);
    graph.addLink(name_prefix+"B", name_prefix+"D", 1);
    graph.addLink(name_prefix+"C", name_prefix+"A", 1);
    graph.addLink(name_prefix+"C", name_prefix+"D", 1);
    
    return;
}