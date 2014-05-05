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
#include <memory>

#define CRYPTO_CURRENCY_GRAPH_STRING_DELIMITER " "
#define CRYPTO_CURRENCY_GRAPH_OUTPUT_STRING_LINKER "->"
#define CRYPTO_CURRENCY_GRAPH_COST_OUTPUT_STRING_SEP " :: "

typedef std::shared_ptr<CryptoCurrencyGraphNode> CryptoCurrencyGraphNodeSPtr;

class CryptoCurrencyGraph{
public:
    CryptoCurrencyGraph();
    CryptoCurrencyGraph(double tf);
    virtual ~CryptoCurrencyGraph();
    virtual void addNode(std::string node_name);
    virtual void addLink(std::string source_node_name, std::string target_node_name, double cost);
    
    virtual double getSimpleConversionCost( std::string start, std::string end);
    virtual double getBestConversionCost(std::string start, std::string end);
    
private:
    std::map<std::string, CryptoCurrencyGraphNodeSPtr> data_set;
    CryptoCurrencyGraphNodeSPtr getOrAddNodeByName( std::string node_name);
    void recurisveGraphExamination( CryptoCurrencyGraphNodeSPtr position, CryptoCurrencyGraphNodeSPtr target, std::string path, std::vector<std::tuple<std::string, double>>& collected_paths );
    double transaction_fee;
};

#endif /* defined(__CryptoCurrencyGraphAnalyser__CryptoCurrencyGraph__) */
