#ifndef dataProcessing_h
#define dataProcessing_h

#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
using namespace std;

// Data of text code
string readingLineStr(const string filePath, int readLine) {
    // Create file reading task
    ifstream readingFile; // Create file I - O value 
    readingFile.open(filePath, ios::in); // Write file I - O
    // Error determine
    if(readLine == 0 && readLine < 0) /* Read 0 line error; #304 */
        exit(1);
    else if(readingFile.fail()) /* Read file not had error; #404 */
        exit(1);

    // Read out
    string buffer; int i = 0;
    while(getline(readingFile, buffer) && i < readLine - 1) {
        i += 1;
    }

    return buffer;
}

bool deleteFile(const string filePath) {
    if(remove(filePath.c_str()) == 0)
        return true;
    else
        return false;
}

bool filePresence(const string filePath) {
    fstream readingFile; readingFile.open(filePath, ios::in);
    if(!readingFile.fail())
        return true;
    else
        return false;    
}

bool changeFileName(const string filePath,const string changedFileName) {
    if(rename(filePath.c_str(), changedFileName.c_str()) == 0)
        return true;
    else
        return false;
}

bool createFile(const string filePath) {
     fstream readingFile; readingFile.open(filePath, ios::in | ios::app);
    if(!readingFile.fail())
        return true;
    else
        return false;
}
    
#endif