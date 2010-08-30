#ifndef AnalysisDataFormats_TauAnalysis_SVfitLegSolution_h
#define AnalysisDataFormats_TauAnalysis_SVfitLegSolution_h

#include "DataFormats/Candidate/interface/Candidate.h"

class SVfitLegSolution 
{
 public:
  enum polarizationHypothesisType { kLeftHanded, kRightHanded, kUnknown };

  SVfitLegSolution();
  SVfitLegSolution(polarizationHypothesisType);
  ~SVfitLegSolution();
  
  /// access to momentum of visible + invisible decay products
  /// in laboratory frame
  reco::Candidate::LorentzVector p4() const { return (p4Vis_ + p4Invis_); }

  /// access to momentum of visible decay products,
  /// in laboratory and tau lepton rest-frame
  const reco::Candidate::LorentzVector& p4Vis() const { return p4Vis_; }
  const reco::Candidate::LorentzVector& p4VisRestFrame() const { return p4VisRestFrame_; }

  /// access to momentum of invisible decay products (neutrinos produced in tau decay);
  /// reconstructed by SVfit algorithm,
  /// in laboratory and tau lepton rest-frame    
  const reco::Candidate::LorentzVector& p4Invis() const { return p4Invis_; }
  const reco::Candidate::LorentzVector& p4InvisRestFrame() const { return p4InvisRestFrame_; }

  /// access to position of secondary vertex (tau lepton decay vertex);
  /// reconstructed by SVfit algorithm
  const reco::Candidate::Vector& tauFlightPath() const { return tauFlightPath_; }

  /// access to polarization hypothesis used by SVfit in reconstruction of this solution
  polarizationHypothesisType polarizationHypothesis() const { return polarizationHypothesis_; }

  double cosThetaRest() const { return p4VisRestFrame().Vect().Unit().Dot(tauFlightPath_.Unit()); }

 private:

  template<typename T1, typename T2> friend class SVfitAlgorithm;

  /// polarization hypothesis used by SVfit in reconstruction of this solution
  polarizationHypothesisType polarizationHypothesis_;

  /// momentum of visible decay products,
  /// in laboratory and tau lepton rest-frame
  reco::Candidate::LorentzVector p4Vis_;
  reco::Candidate::LorentzVector p4VisRestFrame_;

  /// momentum of invisible decay products (neutrinos produced in tau decay);
  /// reconstructed by SVfit algorithm,
  /// in laboratory and tau lepton rest-frame
  reco::Candidate::LorentzVector p4Invis_; 
  reco::Candidate::LorentzVector p4InvisRestFrame_; 

  /// position of reconstructed tau lepton decay vertex;
  /// reconstructed by SVfit algorithm
  reco::Candidate::Vector tauFlightPath_;
};

#endif
