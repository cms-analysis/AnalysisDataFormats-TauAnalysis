#include "AnalysisDataFormats/TauAnalysis/interface/SVfitDiTauSolution.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"

SVfitDiTauSolution::SVfitDiTauSolution()
{}

SVfitDiTauSolution::SVfitDiTauSolution(SVfitLegSolution::polarizationHypothesisType leg1PolarizationHypothesis, 
				       SVfitLegSolution::polarizationHypothesisType leg2PolarizationHypothesis)
  : leg1_(leg1PolarizationHypothesis),
    leg2_(leg2PolarizationHypothesis)
{}

SVfitDiTauSolution::~SVfitDiTauSolution()
{
// nothing to be done yet
}

double SVfitDiTauSolution::logLikelihood() const
{
  double logLikelihoodSum = 0.;

  for ( std::map<std::string, double>::const_iterator logLikelihood = logLikelihoods_.begin();
	logLikelihood != logLikelihoods_.end(); ++logLikelihood ) {
    logLikelihoodSum += logLikelihood->second;
  }

  return logLikelihoodSum;
}
 
double SVfitDiTauSolution::logLikelihood(const std::string& plugin) const
{
  std::map<std::string, double>::const_iterator logLikelihood = logLikelihoods_.find(plugin);
  if ( logLikelihood != logLikelihoods_.end() ) {
    return logLikelihood->second;
  } else {
    edm::LogError ("SVfitDiTauSolution::logLikelihood") 
      << " No plugin of name = " << plugin << " was used to reconstruct this solution !!";
    return -1.;
  }
}


