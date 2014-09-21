/*
 * FitResults.h
 *
 *  Created on: 16 Sep 2014
 *      Author: mcoombes
 */

#pragma once

#include <vector>
#include <string>

namespace RICHMirrorAlignment
{

  class FitResults
  {
  public:
    FitResults(std::vector<std::string>& _results);
    virtual
    ~FitResults();
    std::string MirrorPair();
    double X() const;
    double Y() const;
    double XErr() const;
    double YErr() const;

  private:
    std::vector<std::string> m_results;
  };

} /* namespace RICHMirrorAlignment */

