//
//  CryptsyCurrencySource.cpp
//  CryptoCurrencyGraphAnalyser
//
//  Created by Henry Schimke on 4/19/14.
//  Copyright (c) 2014 Henry Schimke. All rights reserved.
//

#include "CryptsyCurrencySource.h"

CryptsyCurrencySource::CryptsyCurrencySource(){
    this->curl_callback_write_data = std::string();
}

CryptsyCurrencySource::~CryptsyCurrencySource(){}

void CryptsyCurrencySource::parseSource(CryptoCurrencyGraph &graph){
    this->parseSource(graph, EMPTY_CRYPTOCURRENCY_NAME_PREFIX);
}

void CryptsyCurrencySource::parseSource(CryptoCurrencyGraph &graph, std::string name_prefix){
    CURL* curl; //our curl object
    
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    
    curl_easy_setopt(curl, CURLOPT_URL, CRYPTSY_URI);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &CryptsyCurrencySource::curlWriter);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &curl_callback_write_data);
//    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); //tell curl to output its progress
    
    curl_easy_perform(curl);
    
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    
       // std::cout << this->curl_callback_write_data;
    
    boost::property_tree::ptree pt;
    std::istringstream dins (this->curl_callback_write_data);
    boost::property_tree::read_json(dins, pt);
    
    
    BOOST_FOREACH(boost::property_tree::ptree::value_type &v, pt.get_child("return.markets")){
        std::string dg = std::string(v.first.data());
        size_t p = dg.find("/");

        double link_cost;
        
        link_cost =pt.get<double>("return.markets." + std::string(v.first.data()) + ".lasttradeprice");
        
        graph.addLink(this->getPrefixedName(dg.substr(p+1), name_prefix),
                      this->getPrefixedName(dg.substr(0,p), name_prefix),
                      (1/link_cost));
        
        graph.addLink(this->getPrefixedName(dg.substr(0,p), name_prefix),
                      this->getPrefixedName(dg.substr(p+1), name_prefix),
                      link_cost);
    }
    
    return;
}

size_t CryptsyCurrencySource::curlWriter(char *data, size_t size, size_t nmemb, std::string *buffer) {
    size_t result = 0;
    if (buffer != NULL) {
        buffer->append(data, size * nmemb);
        result = size * nmemb;
    }
    return result;
}