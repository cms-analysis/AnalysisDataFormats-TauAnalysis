#ifndef AnalysisDataFormats_TauAnalysis_NSVfitTauToLepHypothesisBase_h
#define AnalysisDataFormats_TauAnalysis_NSVfitTauToLepHypothesisBase_h

#include "AnalysisDataFormats/TauAnalysis/interface/NSVfitTauDecayHypothesisBase.h"

template <typename T>
class NSVfitTauToLepHypothesisBase : public NSVfitTauDecayHypothesisBase
{
 public:
  NSVfitTauToLepHypothesisBase() {}
  NSVfitTauToLepHypothesisBase(const edm::Ptr<reco::Candidate>& particle, const std::string& name, int barcode)
    : NSVfitSingleParticleHypothesisBase(particle, name, barcode)
  {}
  NSVfitTauToLepHypothesisBase(const NSVfitTauToLepHypothesisBase& bluePrint)
    : NSVfitSingleParticleHypothesisBase(bluePrint),
      NSVfitTauDecayHypothesisBase(bluePrint)
  {}
  ~NSVfitTauToLepHypothesisBase() {}

  NSVfitTauToLepHypothesisBase* clone() const { return new NSVfitTauToLepHypothesisBase(*this); }
  NSVfitSingleParticleHypothesisBase* reduceToBase() const { return this->clone(); }

  NSVfitTauToLepHypothesisBase& operator=(const NSVfitTauToLepHypothesisBase& bluePrint)
  {
    NSVfitTauDecayHypothesisBase::operator =(bluePrint);
    return (*this);
  }
};

#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Muon.h"

typedef NSVfitTauToLepHypothesisBase<pat::Electron> NSVfitTauToElecHypothesisBase;
typedef NSVfitTauToLepHypothesisBase<pat::Muon> NSVfitTauToMuHypothesisBase;

#endif
