// Jacob Zamore
// 2423782
// zamore@chapman.edu
// CPSC-350-01
// PA2
// Header file for a FileProcessor class (modified from PA1)
#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H
#include <string>
#include <fstream>
using namespace std;
class FileProcessor{
    public:
        FileProcessor();
        virtual ~FileProcessor();
        int* readFile(string inputFile);
        void logEntry(string dataToLog, string outputFile);
};
#endif