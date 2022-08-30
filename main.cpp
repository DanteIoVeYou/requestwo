#include "unittest.h"
int main()
{
    UnitTest *unit_test = new UnitTest();
    unit_test->TestParseURL1();
    unit_test->TestParseURL2();
    unit_test->TestParseURL3();
    unit_test->TestParseURL4();
    delete(unit_test);
    return 0;
}