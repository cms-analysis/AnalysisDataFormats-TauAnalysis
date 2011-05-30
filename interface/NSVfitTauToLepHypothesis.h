#ifndef AnalysisDataFormats_TauAnalysis_NSVfitTauToLepHypothesis_h
#define AnalysisDataFormats_TauAnalysis_NSVfitTauToLepHypothesis_h

#include "AnalysisDataFormats/TauAnalysis/interface/NSVfitTauDecayHypothesis.h"
#include "AnalysisDataFormats/TauAnalysis/interface/NSVfitTauToLepHypothesisBase.h"

template <typename T>
class NSVfitTauToLepHypothesis : public NSVfitTauDecayHypothesis
{
 public:
  NSVfitTauToLepHypothesis() {}
  NSVfitTauToLepHypothesis(const edm::Ptr<reco::Candidate>& particle, const std::string& name, int barcode)
    : NSVfitSingleParticleHypothesisBase(particle, name, barcode)
  {
    p4_ = particle->p4();
  }
  NSVfitTauToLepHypothesis(const NSVfitTauToLepHypothesis& bluePrint)
    : NSVfitSingleParticleHypothesisBase(bluePrint),
      NSVfitTauDecayHypothesis(bluePrint) 
  {}
  ~NSVfitTauToLepHypothesis() {}

  NSVfitSingleParticleHypothesisBase* clone() const { return new NSVfitTauToLepHypothesis(*this); }
  NSVfitSingleParticleHypothesisBase* reduceToBase() const { 
    return new NSVfitTauToLepHypothesisBase<T>(this->particle_, this->name_, this->barcode_);
  }

  NSVfitTauToLepHypothesis& operator=(const NSVfitTauToLepHypothesis& bluePrint)
  {
    NSVfitTauDecayHypothesis::operator =(bluePrint);
    return (*this);
  }

  template<typename T_type> friend class NSVfitTauToLepBuilder;
};

#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Muon.h"

typedef NSVfitTauToLepHypothesis<pat::Electron> NSVfitTauToElecHypothesis;
typedef NSVfitTauToLepHypothesis<pat::Muon> NSVfitTauToMuHypothesis;

#endif
