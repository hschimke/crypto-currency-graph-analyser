//
//  CryptoCurrencyGraphNode.h
//  CryptoCurrencyGraphAnalyser
//
//  Created by Henry Schimke on 4/19/14.
//  Copyright (c) 2014 Henry Schimke. All rights reserved.
//

#ifndef __CryptoCurrencyGraphAnalyser__CryptoCurrencyGraphNode__
#define __CryptoCurrencyGraphAnalyser__CryptoCurrencyGraphNode__

#include <string>
#include <map>

class CryptoCurrencyGraphNode{
public:
    CryptoCurrencyGraphNode(std::string name);
    CryptoCurrencyGraphNode();
    std::string getName();
    virtual ~CryptoCurrencyGraphNode();
    void addLink(std::string name, double rate);
    double getLinkRate( std::string name);
    std::map<std::string, double> links;
protected:
    std::string currency_name;
};

#endif /* defined(__CryptoCurrencyGraphAnalyser__CryptoCurrencyGraphNode__) */
