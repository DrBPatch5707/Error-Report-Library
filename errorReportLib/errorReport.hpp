#include <vector>
#include <string>
#include <fstream>
using namespace std;
/**
 * @details the namespace for Error Report
 */
namespace err
{
/**
 * @brief Provides a method to log errors and allows multiple ways to output these errors
 */
class errorReport
{
public:
    /**
     * @brief Sets up to log the list of errors that have been found, into the provided text file.
     * 
     *  @details
     *  Must be called before any opperations that you want to log errors for.
     *  Errors are only loged to the file when @ref err::errorReport::writeErrors "writeErrors()" is called.
     * 
     * @param fileName: File to record errors in. (relative to the errorReport.hpp and errorReport.cpp files)
     * 
     * @param reset: Do you want to reset the file before errors are recorded to it?
     */
    void setErrorFile(string fileName, bool reset = false);
    /**
     * @brief Describe your error
     * @details
     * (e.g.  \code setError("invalid index at exampleFunction()"); \endcode )
     */
    void setError(string error);
    /**
     * @brief Prints list of errors that have been found to the console.
     */
    void printErrors();
    /**
     * @brief Writes remaining errors to file
     * 
     * @details
     * Errors are written in the inverse order that they are produced, at the point this function is called
     */
    void writeErrors();
    /**
     * @warning Do NOT call unless you want to reset the error output file. 
     * @details
     * Should only be called if  @ref err::errorReport::setErrorFile "setErrorFile()" has been called and provided with an output file.
     */
    void resetFile();
    /**
     * @brief Returns the curent full list of errors
     * 
     * 
     * @return  vector<string> 
     */
    vector<string> getErrors();
    ~errorReport();
private:
vector<string> errorsP;
vector<string> errorsF;
string fileName;
ofstream errorOutFile;
bool writeCalled = false;
};
}

