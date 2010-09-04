#include "AnalysisDataFormats/TauAnalysis/interface/SVfitDiTauSolution.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"

SVfitDiTauSolution::SVfitDiTauSolution()
  : eventVertexIsValid_(false)
{}

SVfitDiTauSolution::SVfitDiTauSolution(SVfitLegSolution::polarizationHypothesisType leg1PolarizationHypothesis, 
				       SVfitLegSolution::polarizationHypothesisType leg2PolarizationHypothesis)
  : eventVertexIsValid_(false),
    leg1_(leg1PolarizationHypothesis),
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

//
//-------------------------------------------------------------------------------
//

std::ostream& operator<<(std::ostream& stream, const SVfitDiTauSolution& solution) 
{
  stream << "<SVfitDiTauSolution::print>:" << std::endl;
  stream << " isValid = " << solution.isValidSolution() << ": log-likelihood = " << solution.logLikelihood() << std::endl;
  stream << " (status of Minuit fit = " << solution.minuitStatus() << ")" << std::endl;
  stream << " Pt = " << solution.p4().pt() << std::endl;
  reco::Candidate::LorentzVector leg1P4 = solution.leg1().p4();
  stream << " leg 1: Pt = " << leg1P4.pt() << ", eta = " << leg1P4.eta() << ", phi = " << leg1P4.phi() << std::endl;  
  stream << " (x1 = " << solution.leg1().x();
  if ( solution.leg1().hasErrorEstimates() ) stream << " + " << solution.leg1().xErrUp() << " - " << solution.leg1().xErrDown();
  stream << ", mScale1 = " << solution.leg1().p4InvisRestFrame().mass() << ")" << std::endl;
  reco::Candidate::LorentzVector leg2P4 = solution.leg2().p4();
  stream << " leg 2: Pt = " << leg2P4.pt() << ", eta = " << leg2P4.eta() << ", phi = " << leg2P4.phi() << std::endl;  
  stream << " (x2 = " << solution.leg2().x();
  if ( solution.leg2().hasErrorEstimates() ) stream << " + " << solution.leg2().xErrUp() << " - " << solution.leg2().xErrDown();
  stream << ", mScale2 = " << solution.leg2().p4InvisRestFrame().mass() << ")" << std::endl;
  stream << " M = " << solution.mass();
  if ( solution.hasErrorEstimates() ) stream << " + " << solution.massErrUp() << " - " << solution.massErrDown();
  stream << std::endl;
  return stream;
}


