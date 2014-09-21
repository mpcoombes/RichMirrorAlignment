/*
 * FileReader.cpp
 *
 *  Created on: 16 Sep 2014
 *      Author: mcoombes
 */

#include "FileReader.h"

#include <vector>
#include <fstream>

namespace RICHMirrorAlignment
{

  FileReader::FileReader()
  {
    // TODO Auto-generated constructor stub

  }

  FileReader::~FileReader()
  {
    // TODO Auto-generated destructor stub
  }

  std::vector<std::string>& FileReader::GetVectorFromFile(std::string _inputFile, std::vector<std::string>& _vec)
  {
    std::vector <std::string> info;
    std::ifstream file(_inputFile.c_str());
    std::string line;

    while ( getline(file, line))
      {
        info.push_back(line);
      }

    unsigned int size = (unsigned int)info.size();

    for (unsigned int j=0; j<size; ++j)
      {
        _vec.push_back(info[j]);
      }

    return _vec;

  }

//  void FileReader::GetVectorOf(std::string _fileName)
//  {
//    FileReader fileReader;
//    std::vector<std::string> fileLines;
//    fileLines = fileReader.GetVectorFromFile(_fileName,fileLines);
//    SetFitResults(fileLines);
//  }
//
//  void FitResultsReader::SetFitResults(std::vector<std::string>& _fileLines)
//  {
//    // std::for_each(begin(_fileLines),end(_fileLines));
//    std::vector<std::string>::iterator end = _fileLines.end();
//    for (std::vector<std::string>::iterator line = _fileLines.begin(); line != end; ++line)
//      {
//        boost::replace_all((*line)," ","#");
//        std::vector<std::string> elements;
//        boost::split( elements, (*line), boost::is_any_of("#"));
//        std::vector<std::string> clean_elements;
//
//        for (std::vector<std::string>::iterator el = elements.begin(); el != elements.end(); ++el)
//          {
//            if (!(*el).empty())
//              {
//                clean_elements.push_back(*el);
//              }
//          }
//            m_fitResults.push_back(clean_elements);
//
//      }
//  }
//
//  std::vector<FitResults>& FitResultsReader::GetFitResults()
//  {
//    return m_fitResults;
//  }


} /* namespace RICHMirrorAlignment */
