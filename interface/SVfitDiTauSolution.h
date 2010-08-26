#ifndef AnalysisDataFormats_TauAnalysis_SVfitDiTauSolution_h
#define AnalysisDataFormats_TauAnalysis_SVfitDiTauSolution_h

#include "AnalysisDataFormats/TauAnalysis/interface/SVfitLegSolution.h"

#include "DataFormats/Candidate/interface/Candidate.h"

#include <string>

class SVfitDiTauSolution 
{
 public:
  SVfitDiTauSolution(SVfitLegSolution::polarizationHypothesisType, SVfitLegSolution::polarizationHypothesisType);
  ~SVfitDiTauSolution();

  /// access to position of primary event vertex (tau lepton production vertex);
  /// refitted by SVfit algorithm after excluding from fit tracks associated to tau lepton decay products
  const reco::Candidate::Point& eventVertexPosition() const { return eventVertexPosition_; }

  /// access to individual tau lepton decay "legs"
  const SVfitLegSolution& leg1() const { return leg1_; }
  const SVfitLegSolution& leg2() const { return leg2_; }

  /// access to missing transverse momentum
  /// refitted by SVfit algorithm
  double metPx() const { return metPx_; }
  double metPy() const { return metPy_; }

  /// access likelihood values of all/individual plugins
  /// used by SVfit to reconstruct this solution
  double logLikelihood() const;
  double logLikelihood(const std::string&) const;

  friend class SVfitAlgorithm;

 private:
  /// position of primary event vertex (tau lepton production vertex);
  /// refitted by SVfit algorithm after excluding from fit tracks associated to tau lepton decay products
  const reco::Candidate::Point eventVertexPosition_;

  /// individual tau lepton decay "legs"
  const SVfitLegSolution& leg1_;
  const SVfitLegSolution& leg2_;

  /// missing transverse momentum
  /// refitted by SVfit algorithm
  double metPx_;
  double metPy_; 

  /// likelihood values of individual plugins
  /// used by SVfit to reconstruct this solution
    std::map<std::string, double> logLikelihoods_; // key = name of plugin; value = log(likelihood)
};

#endif

