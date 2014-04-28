//
//  CurrencySourcePrefixedNameMaker.cpp
//  CryptoCurrencyGraphAnalyser
//
//  Created by Henry Schimke on 4/28/14.
//  Copyright (c) 2014 Henry Schimke. All rights reserved.
//

#include "CurrencySourcePrefixedNameMaker.h"

std::string CurrencySourcePrefixedNameMaker::getPrefixedName(std::string name, std::string name_prefix){
    if (name_prefix.empty()) {
        return name;
    }else{
        return name_prefix + name;
    }
}