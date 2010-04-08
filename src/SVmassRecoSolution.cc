#include "AnalysisDataFormats/TauAnalysis/interface/SVmassRecoSolution.h"

std::ostream& operator<<(std::ostream& stream, const SVmassRecoSolution& solution) 
{
  stream << "<SVmassRecoSolution::print>:" << std::endl;
  stream << " rank = " << solution.rank() << ": log-likelihood = " << solution.logLikelihood() << std::endl;
  stream << " (results of Migrad fit = " << solution.migradStatus() << ", SV fit = " << solution.migradStatus() << ")" << std::endl;
  stream << " leg 1: Pt = " << solution.p4VisLeg1().pt()/solution.x1() << "," 
	 << " eta = " << solution.p4VisLeg1().eta() << "," << " phi = " << solution.p4VisLeg1().phi() << std::endl;  
  stream << " (x1 = " << solution.x1() << ", mScale1 = " << solution.mScale1() << ")" << std::endl;
  stream << " leg 2: Pt = " << solution.p4VisLeg2().pt()/solution.x2() << "," 
	 << " eta = " << solution.p4VisLeg2().eta() << "," << " phi = " << solution.p4VisLeg2().phi() << std::endl;
  stream << " (x2 = " << solution.x2() << ", mScale2 = " << solution.mScale2() << ")" << std::endl;
  stream << " M = " << solution.p4().mass() << std::endl;
  return stream;
}
