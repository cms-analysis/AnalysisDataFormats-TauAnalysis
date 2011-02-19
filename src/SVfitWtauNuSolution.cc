#include "AnalysisDataFormats/TauAnalysis/interface/SVfitWtauNuSolution.h"

#include "FWCore/MessageLogger/interface/MessageLogger.h"

SVfitWtauNuSolution::SVfitWtauNuSolution()
  : eventVertexIsValid_(false)
{}

SVfitWtauNuSolution::~SVfitWtauNuSolution()
{
// nothing to be done yet
}

double SVfitWtauNuSolution::negLogLikelihood() const
{
  double negLogLikelihoodSum = 0.;

  for ( std::map<std::string, double>::const_iterator negLogLikelihood = negLogLikelihoods_.begin();
	negLogLikelihood != negLogLikelihoods_.end(); ++negLogLikelihood ) {
    negLogLikelihoodSum += negLogLikelihood->second;
  }

  return negLogLikelihoodSum;
}

double SVfitWtauNuSolution::negLogLikelihood(const std::string& plugin) const
{
  std::map<std::string, double>::const_iterator negLogLikelihood = negLogLikelihoods_.find(plugin);
  if ( negLogLikelihood != negLogLikelihoods_.end() ) {
    return negLogLikelihood->second;
  } else {
    edm::LogError ("SVfitWtauNuSolution::negLogLikelihood")
      << " No plugin of name = " << plugin << " was used to reconstruct this solution !!";
    return -1.;
  }
}

//
//-------------------------------------------------------------------------------
//

std::ostream& operator<<(std::ostream& stream, const SVfitWtauNuSolution& solution)
{
  stream << "<SVfitWtauNuSolution::print>:" << std::endl;
  stream << " isValid = " << solution.isValidSolution() << ": log-likelihood = " << solution.negLogLikelihood() << std::endl;
  stream << " (status of Minuit fit = " << solution.minuitStatus() << ")" << std::endl;
  stream << " Pt = " << solution.p4().pt() << std::endl;
  reco::Candidate::LorentzVector leg1P4 = solution.leg1().p4();
  stream << " leg 1: Pt = " << leg1P4.pt() << ", eta = " << leg1P4.eta() << ", phi = " << leg1P4.phi() << std::endl;
  stream << " (x1 = " << solution.leg1().x();
  stream << ", mScale1 = " << solution.leg1().p4InvisRestFrame().mass() << ")" << std::endl;
  stream << " leg 2: Pt = " << solution.nu().pt() << ", phi = " << solution.nu().phi() << std::endl;
  stream << " Mt = " << solution.mt();
  stream << std::endl;
  // Print likelihoods.
  stream << " -- Likelihoods: " << std::endl;
  for ( std::map<std::string, double>::const_iterator negLogLikelihood = solution.negLogLikelihoods().begin();
	negLogLikelihood != solution.negLogLikelihoods().end(); ++negLogLikelihood ) {
    stream << " - " << negLogLikelihood->first << " = " << negLogLikelihood->second << std::endl;
  }
  return stream;
}


