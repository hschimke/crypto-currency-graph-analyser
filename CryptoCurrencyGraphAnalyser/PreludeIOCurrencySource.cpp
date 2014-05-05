//
//  PreludeIOCurrencySource.cpp
//  CryptoCurrencyGraphAnalyser
//
//  Created by Henry Schimke on 4/27/14.
//  Copyright (c) 2014 Henry Schimke. All rights reserved.
//

#include "PreludeIOCurrencySource.h"

PreludeIOCurrencySource::PreludeIOCurrencySource(){
    this->include_usd_endpoints = true;
}

PreludeIOCurrencySource::PreludeIOCurrencySource(bool include_usd_endpoints){
    this->include_usd_endpoints = include_usd_endpoints;
}

PreludeIOCurrencySource::~PreludeIOCurrencySource(){}

void PreludeIOCurrencySource::parseSource(CryptoCurrencyGraph &graph){
    this->parseSource( graph, EMPTY_CRYPTOCURRENCY_NAME_PREFIX);
}

void PreludeIOCurrencySource::parseSource(CryptoCurrencyGraph &graph, std::string name_prefix){
    std::string btc_data = this->getBTCStringData();
    
    // Parse BTC Pairings
    addPairingsFromJSON(graph, btc_data, name_prefix);
    
    if (this->include_usd_endpoints) {
        std::string usd_data = this->getUSDStringData();
        
        // Parse USD Pairings
        addPairingsFromJSON(graph, usd_data, name_prefix);
    }
    
    return;
}

void PreludeIOCurrencySource::addPairingsFromJSON(CryptoCurrencyGraph &graph, std::string data, std::string name_prefix){
    boost::property_tree::ptree pt;
    std::istringstream dins (data);
    boost::property_tree::read_json(dins, pt);
    
    std::string currency_endpoint = pt.get<std::string>("from");
    
    for( boost::property_tree::ptree::value_type &v: pt.get_child("pairings") ){
        double link_rate;
        std::string pair;
        
        if (v.second.get<std::string>("last_trade.rate") != "null") {
            
            link_rate =v.second.get<double>("last_trade.rate");
            pair = v.second.get<std::string>("pair");
            
            graph.addLink(this->getPrefixedName(currency_endpoint, name_prefix),
                          this->getPrefixedName(pair, name_prefix),
                          (1/link_rate));
            
            graph.addLink(this->getPrefixedName(pair, name_prefix),
                          this->getPrefixedName(currency_endpoint, name_prefix),
                          link_rate);
        }
    }
}

std::string PreludeIOCurrencySource::getBTCStringData(){
    CURL* curl; //our curl object
    std::string BTC_callback_write_data = std::string();
    
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    
    curl_easy_setopt(curl, CURLOPT_URL, PRELUDE_IO_BTC_PAIRING_API_URI);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &PreludeIOCurrencySource::curlWriter);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &BTC_callback_write_data);
    //    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); //tell curl to output its progress
    
    curl_easy_perform(curl);
    
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    
    return BTC_callback_write_data;
}

std::string PreludeIOCurrencySource::getUSDStringData(){
    CURL* curl; //our curl object
    std::string USD_callback_write_data = std::string();
    
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    
    curl_easy_setopt(curl, CURLOPT_URL, PRELUDE_IO_USD_PAIRING_API_URI);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &PreludeIOCurrencySource::curlWriter);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &USD_callback_write_data);
    //    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); //tell curl to output its progress
    
    curl_easy_perform(curl);
    
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    
    return USD_callback_write_data;
}

size_t PreludeIOCurrencySource::curlWriter(char *data, size_t size, size_t nmemb, std::string *buffer) {
    size_t result = 0;
    if (buffer != NULL) {
        buffer->append(data, size * nmemb);
        result = size * nmemb;
    }
    return result;
}