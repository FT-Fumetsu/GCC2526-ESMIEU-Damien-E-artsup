#include <cstdlib>
#include "RunAllTests.hpp"

using namespace Data;
int main(){
    RunAllTests<int> tester;
    tester.runAllTests();
    return 0;
}