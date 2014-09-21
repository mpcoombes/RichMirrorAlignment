/*
 * MagnificationCoefficientFileReader.cpp
 *
 *  Created on: 17 Sep 2014
 *      Author: mcoombes
 */

#include "MagnificationCoefficientFileReader.h"
#include "FileReader.h"
#include "MagnificationCoefficients.h"

#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

namespace RICHMirrorAlignment
{

  MagnificationCoefficientFileReader::MagnificationCoefficientFileReader()
  {
    // TODO Auto-generated constructor stub

  }

  MagnificationCoefficientFileReader::~MagnificationCoefficientFileReader()
  {
    // TODO Auto-generated destructor stub
  }

  std::map<std::string,MagnificationCoefficients> MagnificationCoefficientFileReader::GetMagnificationCoefficients()
  {
    return m_magnificationCoefficients;
  }


  std::vector<std::string>& CleanVector(std::vector<std::string>& clean_elements, std::vector<std::string>& elements)
          {

    for (std::vector<std::string>::iterator el = elements.begin(); el != elements.end(); ++el)
      {
        if (!(*el).empty())
          {
            std::cout << *el << std::endl;
            clean_elements.push_back(*el);
          }
      }
    return clean_elements;
          }

  std::vector<std::string>& SplitVector(std::vector<std::string>& elements, std::vector<std::string>::iterator line)
            {
    boost::split( elements, (*line), boost::is_any_of("\t "));
    std::vector<std::string> clean_elements;
    clean_elements = CleanVector(clean_elements, elements);
    elements = clean_elements;
    return elements;
            }

  void MagnificationCoefficientFileReader::ReadPrimaryMirrorPositiveXRotation(std::string _primaryPositveXRotationFileName)
  {
    FileReader fileReader;
    std::vector<std::string> fileLines;
    fileLines = fileReader.GetVectorFromFile(_primaryPositveXRotationFileName,fileLines);
    std::vector<std::string>::iterator endOfLines = fileLines.end();
    for (std::vector<std::string>::iterator line = fileLines.begin(); line != endOfLines; ++line)
      {
        std::vector<std::string> elements;
        elements = SplitVector(elements, line);
        m_magnificationCoefficients[elements[0]].SetPrimaryPositiveXCoefficient(boost::lexical_cast<double>(elements[1]));
      }
  }

  void MagnificationCoefficientFileReader::ReadPrimaryMirrorNegativeXRotation(std::string _primaryNegativeXRotationFileName)
  {
    FileReader fileReader;
    std::vector<std::string> fileLines;
    fileLines = fileReader.GetVectorFromFile(_primaryNegativeXRotationFileName,fileLines);
    std::vector<std::string>::iterator endOfLines = fileLines.end();
    for (std::vector<std::string>::iterator line = fileLines.begin(); line != endOfLines; ++line)
      {
        std::vector<std::string> elements;
        elements = SplitVector(elements, line);
        m_magnificationCoefficients[elements[0]].SetPrimaryNegativeXCoefficient(boost::lexical_cast<double>(elements[1]));
      }
  }

  void MagnificationCoefficientFileReader::ReadPrimaryMirrorPositiveYRotation(std::string _primaryPositveYRotationFileName)
  {
    FileReader fileReader;
    std::vector<std::string> fileLines;
    fileLines = fileReader.GetVectorFromFile(_primaryPositveYRotationFileName,fileLines);
    std::vector<std::string>::iterator endOfLines = fileLines.end();
    for (std::vector<std::string>::iterator line = fileLines.begin(); line != endOfLines; ++line)
      {
        std::vector<std::string> elements;
        elements = SplitVector(elements, line);
        m_magnificationCoefficients[elements[0]].SetPrimaryPositiveYCoefficient(boost::lexical_cast<double>(elements[1]));
      }
  }

  void MagnificationCoefficientFileReader::ReadPrimaryMirrorNegativeYRotation(std::string _primaryNegativeXRotationFileName)
  {
    FileReader fileReader;
    std::vector<std::string> fileLines;
    fileLines = fileReader.GetVectorFromFile(_primaryNegativeXRotationFileName,fileLines);
    std::vector<std::string>::iterator endOfLines = fileLines.end();
    for (std::vector<std::string>::iterator line = fileLines.begin(); line != endOfLines; ++line)
      {
        std::vector<std::string> elements;
        elements = SplitVector(elements, line);
        m_magnificationCoefficients[elements[0]].SetPrimaryNegativeYCoefficient(boost::lexical_cast<double>(elements[1]));
      }
  }


} /* namespace RICHMirrorAlignment */
