#ifndef AnalysisDataFormats_TauAnalysis_NSVfitTauToHadHypothesisBase_h
#define AnalysisDataFormats_TauAnalysis_NSVfitTauToHadHypothesisBase_h

#include "AnalysisDataFormats/TauAnalysis/interface/NSVfitTauDecayHypothesisBase.h"

class NSVfitTauToHadHypothesisBase : public NSVfitTauDecayHypothesisBase
{
 public:

  NSVfitTauToHadHypothesisBase() {}
  NSVfitTauToHadHypothesisBase(const edm::Ptr<reco::Candidate>& particle, const std::string& name, int barcode)
    : NSVfitSingleParticleHypothesisBase(particle, name, barcode)
  {}
  NSVfitTauToHadHypothesisBase(const NSVfitTauToHadHypothesisBase& bluePrint)
    : NSVfitSingleParticleHypothesisBase(bluePrint),
      NSVfitTauDecayHypothesisBase(bluePrint)
  {}
  ~NSVfitTauToHadHypothesisBase() {}

  NSVfitSingleParticleHypothesisBase* clone() const { return new NSVfitTauToHadHypothesisBase(*this); }
  NSVfitSingleParticleHypothesisBase* reduceToBase() const { 
    return this->clone(); 
  }

  NSVfitTauToHadHypothesisBase& operator=(const NSVfitTauToHadHypothesisBase& bluePrint)
  { 
    NSVfitTauDecayHypothesisBase::operator=(bluePrint);
    return (*this);
  }
};

#endif
