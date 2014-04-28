//
//  ICryptoCurrencySourceParser.h
//  CryptoCurrencyGraphAnalyser
//
//  Created by Henry Schimke on 4/19/14.
//  Copyright (c) 2014 Henry Schimke. All rights reserved.
//

#ifndef CryptoCurrencyGraphAnalyser_ICryptoCurrencySourceParser_h
#define CryptoCurrencyGraphAnalyser_ICryptoCurrencySourceParser_h

#include "CryptoCurrencyGraph.h"

#define EMPTY_CRYPTOCURRENCY_NAME_PREFIX ""

class ICryptoCurrencySourceParser{
public:
    virtual ~ICryptoCurrencySourceParser() {};
    virtual void parseSource(CryptoCurrencyGraph &graph) = 0;
    virtual void parseSource(CryptoCurrencyGraph &graph, std::string name_prefix) = 0;
};


#endif
