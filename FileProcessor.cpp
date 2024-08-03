// Jacob Zamore
// 2423782
// zamore@chapman.edu
// CPSC-350-01
// PA2
// Implementation file for a FileProcessor class (modified from PA1)
#include "FileProcessor.h"
#include "World.h"
#include <iostream>
#include <fstream>
FileProcessor::FileProcessor(){};
FileProcessor::~FileProcessor(){};

int* FileProcessor::readFile(string inputFile) {
    // Reads game specs file so that Level knows how to create itself
    int*  gameSpecsArray = new int[8];
    // Create our input file stream
    ifstream inputStream;
    // Open our input file so that it can be read from
    inputStream.open(inputFile);
    for (int i=0; i<8; ++i) {
        inputStream >> gameSpecsArray[i];
    }
    // Close our file stream
    inputStream.close();
    return gameSpecsArray;
}

void FileProcessor::logEntry(string dataToLog,string outputFile) {
    // Logs game happenings to output file
    ofstream outputStream;
    outputStream.open(outputFile, ios::app); 
    outputStream << dataToLog << endl;
    outputStream.close();
}



