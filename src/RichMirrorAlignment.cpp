//============================================================================
// Name        : RichMirrorAlignment.cpp
// Author      : Matt Coombes
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "FitResultsReader.h"
#include "FitResults.h"
#include <vector>
#include <map>

#include "MagnificationCoefficientFileReader.h"
#include "MagnificationCoefficients.h"

using namespace RICHMirrorAlignment;

using namespace std;

int main() {



  //Get Current Mirror Positions

  //Get list of RICH mirror Pairs

  //Get Misalignment
  FitResultsReader fit("../exampleFiles/Rich1MirrCombinTotalTiltsMrad_10m12c_p0p2fix_Gs1Gb1Mp9Wi7.0Fv1Cm0Ct0.3Sm1_R1MU_2012_RAWCollision11_i6.txt");
  std::vector<FitResults> fitResults = fit.GetFitResults();

  //Get Magnification Coefficients
  MagnificationCoefficientFileReader magnificationCoefficientReader;
  magnificationCoefficientReader.ReadPrimaryMirrorPositiveXRotation("../exampleFiles/Rich1FixedMirrCoeff_pri_zerYnegZ_1.0mr.txt");
  magnificationCoefficientReader.ReadPrimaryMirrorPositiveYRotation("../exampleFiles/Rich1FixedMirrCoeff_pri_zerYnegZ_1.0mr.txt");
  magnificationCoefficientReader.ReadPrimaryMirrorNegativeXRotation("../exampleFiles/Rich1FixedMirrCoeff_pri_zerYnegZ_1.0mr.txt");
  magnificationCoefficientReader.ReadPrimaryMirrorNegativeYRotation("../exampleFiles/Rich1FixedMirrCoeff_pri_zerYnegZ_1.0mr.txt");


  std::map<std::string,MagnificationCoefficients> magnificationCoefficients = magnificationCoefficientReader.GetMagnificationCoefficients();

  std::cout << magnificationCoefficients["0000"].GetPrimaryMirrorXCoefficient();
  std::cout << magnificationCoefficients["0000"].GetPrimaryMirrorYCoefficient();

  // FitResultsReader magnificationCoeffs("../exampleFiles/Rich1FixedMirrCoeff_pri_zerYnegZ_1.0mr.txt");
 // MagnificationCoefficents magCoeff("../exampleFiles/Rich1FixedMirrCoeff_pri_zerYnegZ_1.0mr.txt");

  //Calculate Mirror tilts

  //Update Mirror Positions


  for (vector<FitResults>::iterator it = fitResults.begin(); it != fitResults.end(); ++it)
    {
      cout << (*it).MirrorPair() << " ";
      cout << (*it).X() << " ";
      cout << (*it).XErr() << " ";
      cout << (*it).Y() << " ";
      cout << (*it).YErr() << " " << endl;
    }
      cout << "!!" << endl; // prints !!
	return 0;
}
