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

class StaticCurrencySource : public ICryptoCurrencySourceParser {
public:
    virtual ~StaticCurrencySource();
    StaticCurrencySource();
    virtual void parseSource(CryptoCurrencyGraph &graph);
};

#endif /* defined(__CryptoCurrencyGraphAnalyser__StaticCurrencySource__) */
