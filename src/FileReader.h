/*
 * FileReader.h
 *
 *  Created on: 16 Sep 2014
 *      Author: mcoombes
 */

#pragma once

#include <vector>

namespace RICHMirrorAlignment
{

  class FileReader
  {
  public:
    FileReader();
    virtual
    ~FileReader();
    std::vector<std::string>& GetVectorFromFile(std::string _inputFile, std::vector<std::string>& _vec);

  };

} /* namespace RICHMirrorAlignment */

