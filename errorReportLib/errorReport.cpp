#include <iostream>
#include <fstream>
#include "errorReport.hpp"
using namespace std;
using namespace err;
void errorReport::setError(string error)
{
    try
    {
        this->errorsP.push_back(error);
        this->errorsF.push_back(error);
    }
    catch(...) {setError("Unknown error in \"setError\"");if(errorOutFile.is_open()){ writeErrors();}}
}
void errorReport::printErrors()
{
    cerr << "Initialized error report"  << "..." << endl;
for (string error : errorsP)
{
cerr << "error: " << error << "..." << endl;
}
}

void errorReport::writeErrors()
{
    if (!errorOutFile.is_open()) {setError("Please designate an error file with the \"setErrorFile\" function");}
    else 
    {
    try
    {
        if(!writeCalled) { errorOutFile << "Initialized error report"  << "..." << endl; writeCalled = true;}
    for (string error : errorsF)
    {
     errorOutFile << "error: " << errorsF.back() << "..." << endl;
     errorsF.pop_back();
    }
    errorsF.shrink_to_fit();
    }
    catch(...){setError("Unknown error in \"writeErrors\"");}
    }
}
void errorReport::setErrorFile(string fileName, bool reset)
{
    try
    {
    this->fileName = fileName;
    errorOutFile.open(this->fileName, ios::app);
    if (reset) {resetFile();}
    if (!errorOutFile.is_open()) {setError("The provided error file could not be opened");}
    }
    catch(...){setError("Unknown error in \"setErrorsFile\"");if(errorOutFile.is_open()){ writeErrors();}}
}

vector<string> errorReport::getErrors()
{
    return this->errorsP;
}

void errorReport::resetFile()
{
    try
    {
    if (!errorOutFile.is_open()) { setError("Can not reset: Please designate an error file with the \"setErrorFile\" function");}
    ofstream* resetF = new ofstream;
    resetF->open(this->fileName,(ios::out | ios::trunc));
    if (!resetF->is_open()) { setError("Reset file not opened");}
    resetF->close();
    delete resetF;
    resetF = nullptr;
    }
    catch(...) {setError("Unknown error in \"resetFile\""); if(errorOutFile.is_open()){ writeErrors();}}
}



errorReport::~errorReport()
{
    try
    {
    if (errorOutFile.is_open()) { errorOutFile.close();}
    }
    catch(...) {setError("Unknown error in error report destructor...");}
}
