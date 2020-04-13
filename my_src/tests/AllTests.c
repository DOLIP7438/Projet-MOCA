#include <stdio.h>

#include "CuTest.h"
#include "AllTests.h"

CuSuite *MaTestSuite();
void RunAllTests (void){
  CuString *output = CuStringNew ();
  CuSuite *suite = CuSuiteNew ();

  CuSuiteAddSuite (suite,MaTestSuite ());

  CuSuiteRun (suite);
  CuSuiteSummary (suite, output);
  CuSuiteDetails (suite, output);
  printf ("%s\n", output->buffer);
}
