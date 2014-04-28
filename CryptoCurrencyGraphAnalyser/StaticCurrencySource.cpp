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
    
    graph.addLink("BTC", "DOGE", 0.5);
        graph.addLink("DOGE", "BTC", 0.5);
    graph.addLink("BTC", "RDD", 0.05);
    graph.addLink("BTC", "LTC", 0.75);
    graph.addLink("LTC", "BTC", 0.75);
    graph.addLink("DOGE", "LTC", 1.15);
    graph.addLink("LTC", "RDD", 0.005);
    graph.addLink("DOGE", "RDD", 0.75);
    graph.addLink("BTC", "FKE", 0.9);
    graph.addLink("FKE", "LTC", 0.11);
    
    graph.addLink("A", "B", 1);
    graph.addLink("A", "C", 1);
    graph.addLink("B", "C", 1);
    graph.addLink("B", "D", 1);
    graph.addLink("C", "A", 1);
    graph.addLink("C", "D", 1);
    
    return;
}