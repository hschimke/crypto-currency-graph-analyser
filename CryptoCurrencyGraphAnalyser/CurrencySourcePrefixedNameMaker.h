//
//  CurrencySourcePrefixedNameMaker.h
//  CryptoCurrencyGraphAnalyser
//
//  Created by Henry Schimke on 4/28/14.
//  Copyright (c) 2014 Henry Schimke. All rights reserved.
//

#ifndef __CryptoCurrencyGraphAnalyser__CurrencySourcePrefixedNameMaker__
#define __CryptoCurrencyGraphAnalyser__CurrencySourcePrefixedNameMaker__

#include <string>

class CurrencySourcePrefixedNameMaker{
protected:
    virtual std::string getPrefixedName( std::string name, std::string name_prefix);
};

#endif /* defined(__CryptoCurrencyGraphAnalyser__CurrencySourcePrefixedNameMaker__) */
