/*
 * MagnificationCoefficients.h
 *
 *  Created on: 17 Sep 2014
 *      Author: mcoombes
 */

#include <string>

#pragma once

namespace RICHMirrorAlignment
{

  class MagnificationCoefficients
  {
  public:
    MagnificationCoefficients();
    virtual
    ~MagnificationCoefficients();

    void SetPrimaryPositiveXCoefficient(double _primaryPositiveX);

    void SetPrimaryNegativeXCoefficient(double _primaryNegativeX);

    void SetPrimaryPositiveYCoefficient(double _primaryPositiveY);

    void SetPrimaryNegativeYCoefficient(double _primaryNegativeY);

    double GetPrimaryMirrorXCoefficient();

    double GetPrimaryMirrorYCoefficient();

    void SetSecondaryPositiveXCoefficient(double _secondaryPositiveX);

    void SetSecondaryNegativeXCoefficient(double _secondaryNegativeX);

    void SetSecondaryPositiveYCoefficient(double _secondaryPositiveY);

    void SetSecondaryNegativeYCoefficient(double _secondaryNegativeY);

    double GetSecondaryMirrorXCoefficient();

    double GetSecondaryMirrorYCoefficient();

  private:
    std::string m_mirrorPair;
    double m_primaryPositiveX;
    double m_primaryNegativeX;
    double m_primaryPositiveY;
    double m_primaryNegativeY;

    double m_secondaryPositiveX;
    double m_secondaryNegativeX;
    double m_secondaryPositiveY;
    double m_secondaryNegativeY;
  };


} /* namespace RICHMirrorAlignment */

