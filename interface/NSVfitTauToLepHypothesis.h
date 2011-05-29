#ifndef AnalysisDataFormats_TauAnalysis_NSVfitTauToLepHypothesis_h
#define AnalysisDataFormats_TauAnalysis_NSVfitTauToLepHypothesis_h

#include "AnalysisDataFormats/TauAnalysis/interface/NSVfitTauDecayHypothesisBase.h"
#include "AnalysisDataFormats/TauAnalysis/interface/NSVfitTauDecayHypothesis.h"

template <typename T1, typename T2>
class NSVfitTauToLepHypothesis : public T2
{
 public:
  NSVfitTauToLepHypothesis() {}
  NSVfitTauToLepHypothesis(const edm::Ptr<reco::Candidate>& particle, const std::string& name, int barcode)
    : T2(particle, name, barcode)
  {}
  NSVfitTauToLepHypothesis(const NSVfitTauToLepHypothesis& bluePrint)
    : T2(bluePrint) 
  {}
  ~NSVfitTauToLepHypothesis() {}

  virtual NSVfitTauToLepHypothesis* clone() const { return new NSVfitTauToLepHypothesis(*this); }

  virtual NSVfitTauToLepHypothesis& operator=(const NSVfitTauToLepHypothesis& bluePrint)
  {
    T2::operator =(bluePrint);
    return (*this);
  }

  template<typename T1_type> friend class NSVfitTauToLepBuilder;
};

#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Muon.h"

typedef NSVfitTauToLepHypothesis<pat::Electron, NSVfitTauDecayHypothesisBase> NSVfitTauToElecHypothesisBase;
typedef NSVfitTauToLepHypothesis<pat::Electron, NSVfitTauDecayHypothesis> NSVfitTauToElecHypothesis;
typedef NSVfitTauToLepHypothesis<pat::Muon, NSVfitTauDecayHypothesisBase> NSVfitTauToMuHypothesisBase;
typedef NSVfitTauToLepHypothesis<pat::Muon, NSVfitTauDecayHypothesis> NSVfitTauToMuHypothesis;

#endif
