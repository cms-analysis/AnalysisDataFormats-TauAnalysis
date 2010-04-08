#include "AnalysisDataFormats/TauAnalysis/interface/CollinearApproxCompatibility.h"

std::ostream& operator<<(std::ostream& stream, const CollinearApproxCompatibility& collinearApproxCompatibility)
{
  stream << "<CollinearApproxCompatibility::print>:" << std::endl;
  stream << " chi2 = " << collinearApproxCompatibility.minuitFitChi2() << std::endl;
  stream << " (status of Minuit fit = " << collinearApproxCompatibility.minuitFitStatus() << ")" << std::endl;
  stream << " x1 = " << collinearApproxCompatibility.x1() << " +/- " << collinearApproxCompatibility.x1Err() << std::endl;
  stream << " x2 = " << collinearApproxCompatibility.x2() << " +/- " << collinearApproxCompatibility.x2Err() << std::endl;
  return stream;
}
