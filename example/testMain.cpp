#include <iostream>
#include <errorReport.hpp>
using namespace std;
int main()
{
err::errorReport testobj;
testobj.setErrorFile("../example/testErrorFile.txt", true);
testobj.setError("1a");
testobj.setError("2b");
testobj.writeErrors();
testobj.setError("3c");
testobj.setError("4d");
testobj.setError("5z");
testobj.printErrors();
testobj.writeErrors();
    return 0;
}