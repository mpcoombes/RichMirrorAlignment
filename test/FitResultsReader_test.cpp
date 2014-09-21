/*
 * FitResultsReader_test.cpp
 *
 *  Created on: 16 Sep 2014
 *      Author: mcoombes
 */

#include "../src/FitResultsReader.h"
#include "../src/FitResults.h"
#include <assert.h>
#include <vector>
#include <string>

using namespace RICHMirrorAlignment;


  std::string inputFile = "../exampleFiles/Rich1MirrCombinTotalTiltsMrad_10m12c_p0p2fix_Gs1Gb1Mp9Wi7.0Fv1Cm0Ct0.3Sm1_R1MU_2012_RAWCollision11_i6.txt";
  bool TestThatMirrorPairNumberReadCorrectly()
  {
    FitResultsReader fit(inputFile);
    std::vector<FitResults> fitResults = fit.GetFitResults();
    std::string MirrorPair = fitResults[0].MirrorPair();
    if (MirrorPair == "0000")
      {
        return true;
      }
  }


int main()
{
  TestThatMirrorPairNumberReadCorrectly();
}
