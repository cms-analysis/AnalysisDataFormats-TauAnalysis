#ifndef AnalysisDataFormats_TauAnalysis_SVfitWtauNuSolution_h
#define AnalysisDataFormats_TauAnalysis_SVfitWtauNuSolution_h

#include "DataFormats/Candidate/interface/Candidate.h"
#include "DataFormats/CLHEP/interface/AlgebraicObjects.h"

#include "AnalysisDataFormats/TauAnalysis/interface/SVfitLegSolution.h"
#include "AnalysisDataFormats/TauAnalysis/interface/tauAnalysisAuxFunctions.h"

#include "DataFormats/Candidate/interface/Candidate.h"

#include <TMath.h>

#include <string>
#include <iostream>

class SVfitWtauNuSolution
{
 public:
  SVfitWtauNuSolution();
  ~SVfitWtauNuSolution();

  /// access to position of primary event vertex (tau lepton production vertex);
  /// refitted by SVfit algorithm after excluding from fit tracks associated to tau lepton decay products
  ///
  /// NB: error on position returned by eventVertexErrSVrefitted method not 100% correct,
  ///     as uncertainty on "correction" to primary event vertex position
  ///     determined by SVfit algorithm is not taken into account
  ///
  bool eventVertexSVrefittedIsValid() const { return eventVertexIsValid_; }
  AlgebraicVector3 eventVertexPosSVrefitted() const { return (eventVertexPosition_ + eventVertexPositionShift_); }
  const AlgebraicSymMatrix33& eventVertexErrSVrefitted() const { return eventVertexPositionErr_; }

  const AlgebraicVector3& eventVertexShiftSVrefitted() const { return eventVertexPositionShift_; }

  double leg1DecayDistance() const {
    return TauAnalysis_namespace::compDecayDistance(eventVertexPosSVrefitted(), leg1_.decayVertexPos());
  }

  reco::Candidate::Vector leg1FlightPath() const {
    return reco::Candidate::Vector(
        leg1_.decayVertexPos().At(0) - eventVertexPosSVrefitted().At(0),
        leg1_.decayVertexPos().At(1) - eventVertexPosSVrefitted().At(1),
        leg1_.decayVertexPos().At(2) - eventVertexPosSVrefitted().At(2));
  }

  /// access to momentum of both tau lepton decay "legs"
  reco::Candidate::LorentzVector p4() const { return (leg1_.p4() + nu_); }
  reco::Candidate::LorentzVector p4Vis() const { return leg1_.p4Vis(); }
  reco::Candidate::LorentzVector p4Invis() const { return leg1_.p4Invis() + nu_; }

  /// access to reconstructed transverse mass
  double mt() const { return p4().mt(); }

  /// access to individual tau lepton decay "legs"
  const SVfitLegSolution& leg1() const { return leg1_; }
  const reco::Candidate::LorentzVector& nu() const { return nu_; }

  /// access likelihood values of all/individual plugins
  /// used by SVfit to reconstruct this solution
  double negLogLikelihood() const;
  double negLogLikelihood(const std::string&) const;

  const std::map<std::string, double>& negLogLikelihoods() const {
    return negLogLikelihoods_;
  }

  bool isValidSolution() const { return (minuitStatus_ == 0); }
  int minuitStatus() const { return minuitStatus_; }

  template<typename T> friend class SVfitAlgorithmWtauNu;

 private:
  /// position of primary event vertex (tau lepton production vertex);
  /// refitted by SVfit algorithm after excluding from fit tracks associated to tau lepton decay products
  AlgebraicVector3 eventVertexPosition_;
  AlgebraicSymMatrix33 eventVertexPositionErr_;
  AlgebraicVector3 eventVertexPositionShift_;
  bool eventVertexIsValid_;

  /// individual tau lepton decay "legs"
  SVfitLegSolution leg1_;
  reco::Candidate::LorentzVector nu_;

  /// likelihood values of individual plugins
  /// used by SVfit to reconstruct this solution
  std::map<std::string, double> negLogLikelihoods_; // key = name of plugin; value = -log(likelihood)

  /// convergence status of Minuit log-likelihood minimization
  /// (1 = fit suceeded to converge, 0 = fit failed to converged)
  int minuitStatus_;
};

std::ostream& operator<<(std::ostream& stream, const SVfitWtauNuSolution& solution);

#endif

