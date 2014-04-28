//
//  StaticCurrencySource.h
//  CryptoCurrencyGraphAnalyser
//
//  Created by Henry Schimke on 4/20/14.
//  Copyright (c) 2014 Henry Schimke. All rights reserved.
//

#ifndef __CryptoCurrencyGraphAnalyser__StaticCurrencySource__
#define __CryptoCurrencyGraphAnalyser__StaticCurrencySource__

#include "ICryptoCurrencySourceParser.h"
#include "CurrencySourcePrefixedNameMaker.h"

class StaticCurrencySource : public ICryptoCurrencySourceParser, public CurrencySourcePrefixedNameMaker {
public:
    virtual ~StaticCurrencySource();
    StaticCurrencySource();
    virtual void parseSource(CryptoCurrencyGraph &graph);
    virtual void parseSource(CryptoCurrencyGraph &graph, std::string name_prefix);
};

#endif /* defined(__CryptoCurrencyGraphAnalyser__StaticCurrencySource__) */
