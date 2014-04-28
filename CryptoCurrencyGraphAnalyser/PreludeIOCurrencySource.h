//
//  PreludeIOCurrencySource.h
//  CryptoCurrencyGraphAnalyser
//
//  Created by Henry Schimke on 4/27/14.
//  Copyright (c) 2014 Henry Schimke. All rights reserved.
//

#ifndef __CryptoCurrencyGraphAnalyser__PreludeIOCurrencySource__
#define __CryptoCurrencyGraphAnalyser__PreludeIOCurrencySource__

#include "ICryptoCurrencySourceParser.h"
#include <iostream>
#include <string>
#include <curl/curl.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>

#define PRELUDE_IO_BTC_PAIRING_API_URI "https://api.prelude.io/pairings/btc"
#define PRELUDE_IO_USD_PAIRING_API_URI "https://api.prelude.io/pairings/usd"

class PreludeIOCurrencySource : public ICryptoCurrencySourceParser {
public:
    virtual ~PreludeIOCurrencySource();
    PreludeIOCurrencySource();
    virtual void parseSource(CryptoCurrencyGraph &graph);
    virtual void parseSource(CryptoCurrencyGraph &graph, std::string name_prefix);
private:
    //std::string BTC_callback_write_data;
    //std::string USD_callback_write_data;
    
    std::string getBTCStringData();
    std::string getUSDStringData();
    
    static size_t curlWriter(char *data, size_t size, size_t nmemb, std::string *buffer);
    void addPairingsFromJSON( CryptoCurrencyGraph& graph, std::string data, std::string name_prefix );
};

#endif /* defined(__CryptoCurrencyGraphAnalyser__PreludeIOCurrencySource__) */
