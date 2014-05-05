//
//  CryptoCurrencyGraph.cpp
//  CryptoCurrencyGraphAnalyser
//
//  Created by Henry Schimke on 4/19/14.
//  Copyright (c) 2014 Henry Schimke. All rights reserved.
//

#include "CryptoCurrencyGraph.h"

CryptoCurrencyGraph::CryptoCurrencyGraph(){
    this->data_set = std::map<std::string, CryptoCurrencyGraphNodeSPtr>();
    this->transaction_fee = 0;
}

CryptoCurrencyGraph::CryptoCurrencyGraph(double tf){
    this->data_set = std::map<std::string, CryptoCurrencyGraphNodeSPtr>();
    this->transaction_fee = tf;
}

CryptoCurrencyGraph::~CryptoCurrencyGraph(){
    std::for_each(this->data_set.begin(), this->data_set.end(),
                  [](std::pair<std::string, CryptoCurrencyGraphNodeSPtr> entry){
                      entry.second.reset();
                  });
}

void CryptoCurrencyGraph::addNode(std::string node_name){
    CryptoCurrencyGraphNodeSPtr node = this->getOrAddNodeByName(node_name);
    
    if(this->data_set.find(node->getName()) == this->data_set.end()){
        this->data_set[node->getName()] = node;
    }
    
    return;
}

CryptoCurrencyGraphNodeSPtr CryptoCurrencyGraph::getOrAddNodeByName(std::string node_name){
    if(this->data_set.find(node_name) == this->data_set.end()){
        CryptoCurrencyGraphNodeSPtr node = CryptoCurrencyGraphNodeSPtr(new CryptoCurrencyGraphNode(node_name));
        this->data_set[node_name] = node;
    }
    
    return this->data_set[node_name];
}

double CryptoCurrencyGraph::getBestConversionRate(std::string start, std::string end){
    
    std::vector<std::tuple<std::string, double>> paths = std::vector<std::tuple<std::string, double>>();
    
    recurisveGraphExamination(getOrAddNodeByName(start), getOrAddNodeByName(end), std::string(), paths);
    
    double best = std::numeric_limits<double>::min();
    std::string best_path;
    
    for(std::tuple<std::string, double> &t:paths){
        std::cout << std::get<0>(t) << CRYPTO_CURRENCY_GRAPH_COST_OUTPUT_STRING_SEP << std::get<1>(t) << std::endl;
        
        if ((best < std::get<1>(t)) && (std::get<1>(t) != 0)) {
            best = std::get<1>(t);
            best_path = std::get<0>(t);
        }
    }
    
    std::cout <<"Found best path: " << best_path << CRYPTO_CURRENCY_GRAPH_COST_OUTPUT_STRING_SEP << best << std::endl;
    
    return best;
}

void CryptoCurrencyGraph::recurisveGraphExamination(CryptoCurrencyGraphNodeSPtr position,
                                                    CryptoCurrencyGraphNodeSPtr target,
                                                    std::string path,
                                                    std::vector<std::tuple<std::string, double>>& collected_paths){
    if (position->getName() == target->getName()) {
        // Path is good, save and move on
        
        std::stringstream path_builder = std::stringstream();
        
        std::istringstream iss(path+CRYPTO_CURRENCY_GRAPH_STRING_DELIMITER+position->getName());
        std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
            std::istream_iterator<std::string>{}};

        std::string stp = "";
        double start = 1.0;
        for(std::string &s : tokens){
            if( !stp.empty()){
                start = start * getSimpleConversionRate(stp, s);
                path_builder << CRYPTO_CURRENCY_GRAPH_OUTPUT_STRING_LINKER;
            }
            stp = s;
            
            path_builder << s;
        }
        
        collected_paths.push_back(std::tuple<std::string, double>(path_builder.str(), start));
        return;
    }else if( path.find(position->getName()) != std::string::npos ){
        // Path is bad, give up
        return;
    }else{
        // Path is incomplete, keep going
        for (std::pair<const std::string,double>& pair: position->links) {
            CryptoCurrencyGraphNodeSPtr nd = getOrAddNodeByName(pair.first);
            recurisveGraphExamination(nd, target, path + CRYPTO_CURRENCY_GRAPH_STRING_DELIMITER + position->getName(), collected_paths);
        }
        return;
    }
}

double CryptoCurrencyGraph::getSimpleConversionRate(std::string start, std::string end){
    CryptoCurrencyGraphNodeSPtr start_node = this->getOrAddNodeByName(start);
    double link_rate = start_node->getLinkRate(end);
    
    // Should this be + or -?  I'm not certain since I haven't played out the conversion correctly
    // in my head.
    return link_rate - (link_rate * this->transaction_fee);
}

void CryptoCurrencyGraph::addLink(std::string source_node_name, std::string target_node_name, double rate){
    this->getOrAddNodeByName(source_node_name)->addLink(target_node_name, rate);
    
    return;
}