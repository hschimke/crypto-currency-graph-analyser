//
//  CryptsyCurrencySource.h
//  CryptoCurrencyGraphAnalyser
//
//  Created by Henry Schimke on 4/19/14.
//  Copyright (c) 2014 Henry Schimke. All rights reserved.
//

#ifndef __CryptoCurrencyGraphAnalyser__CryptsyCurrencySource__
#define __CryptoCurrencyGraphAnalyser__CryptsyCurrencySource__

#include "ICryptoCurrencySourceParser.h"
#include <iostream>
#include <string>
#include <curl/curl.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>

#define CRYPTSY_URI "http://pubapi.cryptsy.com/api.php?method=marketdatav2 "

class CryptsyCurrencySource : public ICryptoCurrencySourceParser {
public:
    virtual ~CryptsyCurrencySource();
    CryptsyCurrencySource();
    virtual void parseSource(CryptoCurrencyGraph &graph);
    virtual void parseSource(CryptoCurrencyGraph &graph, std::string name_prefix);
private:
    std::string curl_callback_write_data;
    
    static size_t curlWriter(char *data, size_t size, size_t nmemb, std::string *buffer);
};

#endif /* defined(__CryptoCurrencyGraphAnalyser__CryptsyCurrencySource__) */
