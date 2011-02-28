#ifndef AnalysisDataFormats_TauAnalysis_NSVfitTauToLepHypothesis_h
#define AnalysisDataFormats_TauAnalysis_NSVfitTauToLepHypothesis_h

#include "AnalysisDataFormats/TauAnalysis/interface/NSVfitSingleParticleHypothesisBase.h"

template <typename T>
class NSVfitTauToLepHypothesis : public NSVfitSingleParticleHypothesisBase
{
 public:
  NSVfitTauToLepHypothesis() {}
  NSVfitTauToLepHypothesis(const edm::Ptr<reco::Candidate>& particle, const std::string& name, int barcode) 
    : NSVfitSingleParticleHypothesisBase(particle, name, barcode)
  {}
  ~NSVfitTauToLepHypothesis() {}

  /// decay angle in tau lepton rest-frame
  double decay_angle_rf() const { return decay_angle_rf_; }

  /// momenta of visible (electron/muon) and invisible (neutrinos)
  /// decay products in tau lepton rest-frame
  const reco::Candidate::LorentzVector& p4vis_rf()   const { return p4vis_rf_;   }
  const reco::Candidate::LorentzVector& p4invis_rf() const { return p4invis_rf_; }  

  friend class NSVfitTauToLepBuilder;

 private:
  /// decay angle in tau lepton rest-frame
  double decay_angle_rf_;

  /// momenta of visible (electron/muon) and invisible (neutrinos)
  /// decay products in tau lepton rest-frame
  reco::Candidate::LorentzVector p4invis_rf_;
  reco::Candidate::LorentzVector p4vis_rf_;
};

#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Muon.h"

typedef NSVfitTauToLepHypothesis<pat::Electron> NSVfitTauToElecHypothesis;
typedef NSVfitTauToLepHypothesis<pat::Muon>     NSVfitTauToMuHypothesis;

#endif
