/*
 * FitResultsReader.h
 *
 *  Created on: 16 Sep 2014
 *      Author: mcoombes
 */

#pragma once

#include <string>
#include <vector>



namespace RICHMirrorAlignment
{
  class FitResults;

  class FitResultsReader
  {
  public:
    FitResultsReader(std::string _fileName);
    ~FitResultsReader();
    std::vector<FitResults>& GetFitResults();


  private:
    void ReadFitResultsFileLines(std::string _fileName);
    void SetFitResults(std::vector<std::string>& _fileLines);
    std::vector<FitResults> m_fitResults;
  };

} /* namespace RICHMirrorAlignment */

