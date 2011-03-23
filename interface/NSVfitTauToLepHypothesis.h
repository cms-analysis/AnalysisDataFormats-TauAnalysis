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
  NSVfitTauToLepHypothesis(const NSVfitTauToLepHypothesis& bluePrint)
    : NSVfitSingleParticleHypothesisBase(bluePrint),
      p4invis_rf_(bluePrint. p4invis_rf_),
      p4vis_rf_(bluePrint.p4vis_rf_),
      p3Vis_unit_(bluePrint.p3Vis_unit_),
      visMass_(bluePrint.visMass_),
      visEnFracX_(bluePrint.visEnFracX_),
      decay_angle_rf_(bluePrint.decay_angle_rf_),
      decayVertexPos_(bluePrint.decayVertexPos_),
      flightPath_(bluePrint.flightPath_),
      decayDistance_(bluePrint.decayDistance_),
      decayMode_(bluePrint.decayMode_),
      polarization_(bluePrint.polarization_)
  {}
  ~NSVfitTauToLepHypothesis() {}  

  NSVfitSingleParticleHypothesisBase* clone() const { return new NSVfitTauToLepHypothesis(*this); }
 
  virtual NSVfitSingleParticleHypothesisBase& operator=(const NSVfitTauToLepHypothesis& bluePrint)
  {
    NSVfitSingleParticleHypothesisBase::operator =(bluePrint);
    p4invis_rf_ = bluePrint. p4invis_rf_;
    p4vis_rf_ = bluePrint.p4vis_rf_;
    p3Vis_unit_ = bluePrint.p3Vis_unit_;
    visMass_ = bluePrint.visMass_;
    visEnFracX_ = bluePrint.visEnFracX_;
    decay_angle_rf_ = bluePrint.decay_angle_rf_;
    decayVertexPos_ = bluePrint.decayVertexPos_;
    flightPath_ = bluePrint.flightPath_;
    decayDistance_ = bluePrint.decayDistance_;
    decayMode_ = bluePrint.decayMode_;
    polarization_ = bluePrint.polarization_;
    return (*this);
  }

  /// momenta of visible (electron/muon) and invisible (neutrinos)
  /// decay products in tau lepton rest-frame
  const reco::Candidate::LorentzVector& p4vis_rf()   const { return p4vis_rf_;   }
  const reco::Candidate::LorentzVector& p4invis_rf() const { return p4invis_rf_; }  

  /// direction and mass of visible decay products
  const reco::Candidate::Vector& p3Vis_unit() const { return p3Vis_unit_; }
  double visMass() const { return visMass_; }

  /// energy ratio of visible decay products/tau lepton energy
  double visEnFracX() const { return visEnFracX_; }

  /// decay angle in tau lepton rest-frame
  double decay_angle_rf() const { return decay_angle_rf_; }

  /// access to position of secondary vertex (tau lepton decay vertex)
  bool hasDecayVertex() const { return true; }
  const AlgebraicVector3& decayVertexPos() const { return decayVertexPos_; }
  const reco::Candidate::Vector& flightPath() const { return flightPath_; }
  double decayDistance() const { return decayDistance_; }

  /// tau lepton hadronic decay mode
  /// (as defined in DataFormats/TauReco/interface/PFTauDecayMode.h)
  int decayMode() const { return decayMode_; }

  /// tau lepton polarization
  double polarization() const { return polarization_; }

  template<typename T_type> friend class NSVfitTauToLepBuilder;

 private:
  /// momenta of visible (electron/muon) and invisible (neutrinos)
  /// decay products in tau lepton rest-frame
  reco::Candidate::LorentzVector p4invis_rf_;
  reco::Candidate::LorentzVector p4vis_rf_;

  /// direction and mass of visible decay products
  reco::Candidate::Vector p3Vis_unit_;
  double visMass_;

  /// energy ratio of visible decay products/tau lepton energy
  double visEnFracX_;

  /// decay angle in tau lepton rest-frame
  double decay_angle_rf_;

  /// position of reconstructed tau lepton decay vertex
  AlgebraicVector3 decayVertexPos_;
  reco::Candidate::Vector flightPath_;
  double decayDistance_;

  /// tau lepton hadronic decay mode
  int decayMode_;

  /// tau lepton polarization
  double polarization_;
};

#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Muon.h"

typedef NSVfitTauToLepHypothesis<pat::Electron> NSVfitTauToElecHypothesis;
typedef NSVfitTauToLepHypothesis<pat::Muon>     NSVfitTauToMuHypothesis;

#endif
