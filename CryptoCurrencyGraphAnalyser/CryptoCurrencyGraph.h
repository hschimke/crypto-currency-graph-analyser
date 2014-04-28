//
//  CryptoCurrencyGraph.h
//  CryptoCurrencyGraphAnalyser
//
//  Created by Henry Schimke on 4/19/14.
//  Copyright (c) 2014 Henry Schimke. All rights reserved.
//

#ifndef __CryptoCurrencyGraphAnalyser__CryptoCurrencyGraph__
#define __CryptoCurrencyGraphAnalyser__CryptoCurrencyGraph__

#include "CryptoCurrencyGraphNode.h"
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <tuple>
#include <limits>

#define CRYPTO_CURRENCY_GRAPH_STRING_DELIMITER " "

class CryptoCurrencyGraph{
public:
    CryptoCurrencyGraph();
    CryptoCurrencyGraph(double tf);
    virtual ~CryptoCurrencyGraph();
    virtual bool addNode(std::string node_name);
    virtual bool addLink(std::string source_node_name, std::string target_node_name, double cost);
    
    virtual double getSimpleConversionCost( std::string start, std::string end);
    virtual double getBestConversionCost(std::string start, std::string end);
    
private:
    std::map<std::string, CryptoCurrencyGraphNode*> data_set;
    CryptoCurrencyGraphNode& getOrAddNodeByName( std::string node_name);
    void recurisveGraphExamination( CryptoCurrencyGraphNode& position, CryptoCurrencyGraphNode& target, std::string path, std::vector<std::tuple<std::string, double>>& collected_paths );
    double transaction_fee;
};

#endif /* defined(__CryptoCurrencyGraphAnalyser__CryptoCurrencyGraph__) */
