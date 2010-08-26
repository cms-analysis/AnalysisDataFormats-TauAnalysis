#ifndef AnalysisDataFormats_TauAnalysis_SVfitLegSolution_h
#define AnalysisDataFormats_TauAnalysis_SVfitLegSolution_h

#include "DataFormats/Candidate/interface/Candidate.h"

class SVfitLegSolution 
{
 public:
  enum polarizationHypothesisType { kLeftHanded, kRightHanded };

  SVfitLegSolution(polarizationHypothesisType);
  ~SVfitLegSolution();
  
  /// access to momentum of visible decay products
  const reco::Candidate::LorentzVector& p4Vis() const { return p4Vis_; }

  /// access to momentum of invisible decay products (neutrinos produced in tau decay);
  /// reconstructed by SVfit algorithm
  const reco::Candidate::LorentzVector& p4Invis() const { return p4Invis_; }

  /// access to position of secondary vertex (tau lepton decay vertex);
  /// reconstructed by SVfit algorithm
  const reco::Candidate::Point& decayVertexPosition() const { return decayVertexPosition_; }

  /// access to angle between tau lepton "flight" direction and visible decay products,
  /// computed in tau lepton rest frame
  double thetaRest() const { return thetaRest_; }

  /// access to tau lepton "flight" distance (distance between production and decay vertex of tau lepton);
  /// reconstructed by SVfit algorithm
  double flightDistance() const { return flightDistance_; }

  friend class SVfitAlgorithm;

 private:

  /// polarization hypothesis used by SVfit in reconstruction of this solution
  polarizationHypothesisType polarizationHypothesis_;

  /// momentum of visible decay products
  reco::Candidate::LorentzVector p4Vis_;

  /// momentum of invisible decay products (neutrinos produced in tau decay);
  /// reconstructed by SVfit algorithm
  reco::Candidate::LorentzVector p4Invis_;  

  /// position of reconstructed tau lepton decay vertex;
  /// reconstructed by SVfit algorithm
  reco::Candidate::Point decayVertexPosition_;

  /// angle between tau lepton "flight" direction and visible decay products,
  /// computed in tau lepton rest frame
  double thetaRest_;

  /// tau lepton "flight" distance (distance between production and decay vertex of tau lepton);
  /// reconstructed by SVfit algorithm
  double flightDistance_;
};

#endif
