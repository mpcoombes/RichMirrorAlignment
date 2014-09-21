/*
 * FitResultsReader.cpp
 *
 *  Created on: 16 Sep 2014
 *      Author: mcoombes
 */

#include "FitResultsReader.h"
#include "FileReader.h"
#include "FitResults.h"
#include <boost/algorithm/string.hpp>
#include <string>
#include <vector>


namespace RICHMirrorAlignment
{

  FitResultsReader::FitResultsReader(std::string _fileName)
  {
    ReadFitResultsFileLines(_fileName);
  }

  FitResultsReader::~FitResultsReader()
  {
  }

  void FitResultsReader::ReadFitResultsFileLines(std::string _fileName)
  {
    FileReader fileReader;
    std::vector<std::string> fileLines;
    fileLines = fileReader.GetVectorFromFile(_fileName,fileLines);
    SetFitResults(fileLines);
  }

  void FitResultsReader::SetFitResults(std::vector<std::string>& _fileLines)
  {
    // std::for_each(begin(_fileLines),end(_fileLines));
    std::vector<std::string>::iterator end = _fileLines.end();
    for (std::vector<std::string>::iterator line = _fileLines.begin(); line != end; ++line)
      {
        boost::replace_all((*line)," ","#");
        std::vector<std::string> elements;
        boost::split( elements, (*line), boost::is_any_of("#"));
        std::vector<std::string> clean_elements;

        for (std::vector<std::string>::iterator el = elements.begin(); el != elements.end(); ++el)
          {
            if (!(*el).empty())
              {
                clean_elements.push_back(*el);
              }
          }
            m_fitResults.push_back(clean_elements);

      }
  }

  std::vector<FitResults>& FitResultsReader::GetFitResults()
  {
    return m_fitResults;
  }

} /* namespace RICHMirrorAlignment */
