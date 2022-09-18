#include "unittest.h"
int main()
{
    UnitTest *unit_test = new UnitTest();
    // unit_test->TestBuildHttpRequest();
    unit_test->TestSendAndRecv();
    delete(unit_test);
    return 0;
}