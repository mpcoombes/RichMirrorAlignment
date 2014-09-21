/*
 * MagnificationCoefficients.cpp
 *
 *  Created on: 17 Sep 2014
 *      Author: mcoombes
 */

#include "MagnificationCoefficients.h"
#include "FileReader.h"

namespace RICHMirrorAlignment
{

  MagnificationCoefficients::MagnificationCoefficients()
  {

  }

  MagnificationCoefficients::~MagnificationCoefficients()
  {
    // TODO Auto-generated destructor stub
  }

  void MagnificationCoefficients::SetPrimaryPositiveXCoefficient(double _primaryPositiveX)
  {
    m_primaryPositiveX = _primaryPositiveX;
  }

  void MagnificationCoefficients::SetPrimaryNegativeXCoefficient(double _primaryNegativeX)
  {
    m_primaryNegativeX = _primaryNegativeX;
  }

  void MagnificationCoefficients::SetPrimaryPositiveYCoefficient(double _primaryPositiveY)
  {
    m_primaryPositiveY = _primaryPositiveY;
  }

  void MagnificationCoefficients::SetPrimaryNegativeYCoefficient(double _primaryNegativeY)
  {
    m_primaryNegativeY = _primaryNegativeY;
  }

  double MagnificationCoefficients::GetPrimaryMirrorXCoefficient()
  {
    return (m_primaryPositiveX + m_primaryNegativeX)/2.0F;
  }

  double MagnificationCoefficients::GetPrimaryMirrorYCoefficient()
  {
    return (m_primaryPositiveY + m_primaryNegativeY)/2.0F;
  }

  void MagnificationCoefficients::SetSecondaryPositiveXCoefficient(double _secondaryPositiveX)
   {
     m_secondaryPositiveX = _secondaryPositiveX;
   }

   void MagnificationCoefficients::SetSecondaryNegativeXCoefficient(double _secondaryNegativeX)
   {
     m_secondaryNegativeX = _secondaryNegativeX;
   }

   void MagnificationCoefficients::SetSecondaryPositiveYCoefficient(double _secondaryPositiveY)
   {
     m_secondaryPositiveY = _secondaryPositiveY;
   }

   void MagnificationCoefficients::SetSecondaryNegativeYCoefficient(double _secondaryNegativeY)
   {
     m_secondaryNegativeY = _secondaryNegativeY;
   }

   double MagnificationCoefficients::GetSecondaryMirrorXCoefficient()
   {
     return (m_secondaryPositiveX + m_secondaryNegativeX)/2.0F;
   }

   double MagnificationCoefficients::GetSecondaryMirrorYCoefficient()
   {
     return (m_secondaryPositiveY + m_secondaryNegativeY)/2.0F;
   }


} /* namespace RICHMirrorAlignment */
