/*
 * MagnificationCoefficientFileReader.h
 *
 *  Created on: 17 Sep 2014
 *      Author: mcoombes
 */

#pragma once

#include <map>

namespace RICHMirrorAlignment
{
  class MagnificationCoefficients;

  class MagnificationCoefficientFileReader
  {
  public:
    MagnificationCoefficientFileReader();
    virtual
    ~MagnificationCoefficientFileReader();

    std::map<std::string,MagnificationCoefficients> GetMagnificationCoefficients();

    void ReadPrimaryMirrorPositiveXRotation(std::string __primaryPositveXRotationFileName);
    void ReadPrimaryMirrorNegativeXRotation(std::string __primaryNegativeXRotationFileName);
    void ReadPrimaryMirrorPositiveYRotation(std::string __primaryPositveYRotationFileName);
    void ReadPrimaryMirrorNegativeYRotation(std::string __primaryNegativeYRotationFileName);



  private:
    std::map<std::string,MagnificationCoefficients> m_magnificationCoefficients;
  };

} /* namespace RICHMirrorAlignment */

