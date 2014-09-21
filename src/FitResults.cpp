/*
 * FitResults.cpp
 *
 *  Created on: 16 Sep 2014
 *      Author: mcoombes
 */

#include "FitResults.h"
#include <vector>
#include <string>
#include <boost/lexical_cast.hpp>

namespace RICHMirrorAlignment
{

  FitResults::FitResults(std::vector<std::string>& _results)
  {
        m_results = _results;
  }

  FitResults::~FitResults()
  {
    // TODO Auto-generated destructor stub
  }

  std::string FitResults::MirrorPair()
  {
    return m_results.at(0);
  }

  double FitResults::X() const
  {
    return boost::lexical_cast<double>(m_results.at(1));
  }

  double FitResults::Y() const
  {
    return boost::lexical_cast<double>(m_results.at(3));
  }
  double FitResults::XErr() const
  {
    return boost::lexical_cast<double>(m_results.at(2));
  }
  double FitResults::YErr() const
  {
    return boost::lexical_cast<double>(m_results.at(4));
  }


} /* namespace RICHMirrorAlignment */
