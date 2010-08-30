#ifndef AnalysisDataFormats_TauAnalysis_SVfitDiTauSolution_h
#define AnalysisDataFormats_TauAnalysis_SVfitDiTauSolution_h

#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/CLHEP/interface/AlgebraicObjects.h"

#include "AnalysisDataFormats/TauAnalysis/interface/SVfitLegSolution.h"
#include "AnalysisDataFormats/TauAnalysis/interface/tauAnalysisAuxFunctions.h"

#include "DataFormats/Candidate/interface/Candidate.h"

#include <string>

class SVfitDiTauSolution 
{
 public:
  SVfitDiTauSolution();
  SVfitDiTauSolution(SVfitLegSolution::polarizationHypothesisType, SVfitLegSolution::polarizationHypothesisType);
  ~SVfitDiTauSolution();

  /// access to position of primary event vertex (tau lepton production vertex);
  /// refitted by SVfit algorithm after excluding from fit tracks associated to tau lepton decay products
  ///
  /// NB: error on position returned by eventVertexErrSVrefitted method not 100% correct,
  ///     as uncertainty on "correction" to primary event vertex position
  ///     determined by SVfit algorithm is not taken into account
  ///
  reco::Candidate::Point eventVertexPosSVrefitted() const { return (eventVertexPosition_ + eventVertexPositionCorr_); }
  const AlgebraicSymMatrix& eventVertexErrSVrefitted() const { return eventVertexPositionErr_; } 
  
  /// access to momentum of both tau lepton decay "legs"
  reco::Candidate::LorentzVector p4() const { return (leg1_.p4() + leg2_.p4()); }
  reco::Candidate::LorentzVector p4Vis() const { return leg1_.p4Vis() + leg2_.p4Vis(); }
  reco::Candidate::LorentzVector p4Invis() const { return leg1_.p4Invis() + leg2_.p4Invis(); }

  /// access to individual tau lepton decay "legs"
  const SVfitLegSolution& leg1() const { return leg1_; }
  const SVfitLegSolution& leg2() const { return leg2_; }

  /// access position of tau lepton decay vertices
  reco::Candidate::Point leg1DecayVertex() const { return eventVertexPosSVrefitted() + leg1().tauFlightPath(); }
  reco::Candidate::Point leg2DecayVertex() const { return eventVertexPosSVrefitted() + leg2().tauFlightPath(); }

  /// access likelihood values of all/individual plugins
  /// used by SVfit to reconstruct this solution
  double logLikelihood() const;
  double logLikelihood(const std::string&) const;

  bool isValidSolution() const { return (minuitStatus_ == 1); }
  int minuitStatus() const { return minuitStatus_; }

  template<typename T1, typename T2> friend class SVfitAlgorithm;

  std::string polarizationHypothesisName() const
  {
    SVfitLegSolution::polarizationHypothesisType leg1PolarizationHypothesis = leg1_.polarizationHypothesis();
    SVfitLegSolution::polarizationHypothesisType leg2PolarizationHypothesis = leg2_.polarizationHypothesis();
  
    if      ( leg1PolarizationHypothesis == SVfitLegSolution::kLeftHanded  && 
	      leg2PolarizationHypothesis == SVfitLegSolution::kLeftHanded  ) return "LL";
    else if ( leg1PolarizationHypothesis == SVfitLegSolution::kLeftHanded  && 
              leg2PolarizationHypothesis == SVfitLegSolution::kRightHanded ) return "LR";
    else if ( leg1PolarizationHypothesis == SVfitLegSolution::kRightHanded && 
	      leg2PolarizationHypothesis == SVfitLegSolution::kLeftHanded  ) return "RL";
    else if ( leg1PolarizationHypothesis == SVfitLegSolution::kRightHanded  && 
              leg2PolarizationHypothesis == SVfitLegSolution::kRightHanded ) return "RR";
    else return "Unknown";
  }

 private:
  /// position of primary event vertex (tau lepton production vertex);
  /// refitted by SVfit algorithm after excluding from fit tracks associated to tau lepton decay products
  reco::Candidate::Point eventVertexPosition_;
  AlgebraicSymMatrix eventVertexPositionErr_;
  reco::Candidate::Vector eventVertexPositionCorr_;

  /// individual tau lepton decay "legs"
  SVfitLegSolution leg1_;
  SVfitLegSolution leg2_;

  /// likelihood values of individual plugins
  /// used by SVfit to reconstruct this solution
  std::map<std::string, double> logLikelihoods_; // key = name of plugin; value = log(likelihood)

  /// convergence status of Minuit log-likelihood minimization
  /// (1 = fit suceeded to converge, 0 = fit failed to converged)
  int minuitStatus_;
};

#endif

