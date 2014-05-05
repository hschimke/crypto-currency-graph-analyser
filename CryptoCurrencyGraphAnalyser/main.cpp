//
//  main.cpp
//  CryptoCurrencyGraphAnalyser
//
//  Created by Henry Schimke on 4/19/14.
//  Copyright (c) 2014 Henry Schimke. All rights reserved.
//

#include <iostream>
#include "ICryptoCurrencySourceParser.h"
#include "CryptoCurrencyGraph.h"
#include "CryptsyCurrencySource.h"
#include "StaticCurrencySource.h"
#include "PreludeIOCurrencySource.h"
#include <iomanip>
#include <memory>

//#define START_CUR "BTC"
//#define END_CUR "RDD"

//#define START_CUR "A"
//#define END_CUR "D"

#define START_CUR "RDD"
#define END_CUR "BTC"

typedef std::unique_ptr<ICryptoCurrencySourceParser> ICryptoCurrencySourceParserUPtr;

int main(int argc, const char * argv[])
{
    std::cout << "Program Start" << std::endl;
    
    ICryptoCurrencySourceParserUPtr source_parser;
    //ICryptoCurrencySourceParserUPtr secondary_source_parser;
    
    //source_parser = ICryptoCurrencySourceParserUPtr( new CryptsyCurrencySource() );
    //source_parser = ICryptoCurrencySourceParserUPtr( new StaticCurrencySource() );
    source_parser = ICryptoCurrencySourceParserUPtr( new PreludeIOCurrencySource() );
    
    CryptoCurrencyGraph graph = CryptoCurrencyGraph(0.01);
    
    //source_parser->parseSource(graph, "P:");
    //secondary_source_parser->parseSource(graph, "C:");
    
    source_parser->parseSource(graph);
    
    double best = graph.getBestConversionCost(START_CUR, END_CUR);
    double simple =graph.getSimpleConversionCost(START_CUR, END_CUR);
    
    double start_currency = 50000;
    
    std::cout << std::setprecision(10);
    std::cout << std::fixed;
    
    std::cout   << "Best Possible Conversion: "
                << best
                << " :: "
                << start_currency
                << "->"
                << (start_currency*best)
                << std::endl;
    
    std::cout   << "Simple Conversion: "
                << simple
                << " :: "
                << start_currency
                << "->"
                << (start_currency*simple)
                << std::endl;
    
    source_parser.reset();
    //secondary_source_parser.reset();
    
    return 0;
}

