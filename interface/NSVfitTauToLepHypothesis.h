#ifndef AnalysisDataFormats_TauAnalysis_NSVfitTauToLepHypothesis_h
#define AnalysisDataFormats_TauAnalysis_NSVfitTauToLepHypothesis_h

#include "AnalysisDataFormats/TauAnalysis/interface/NSVfitTauDecayHypothesis.h"

template <typename T>
class NSVfitTauToLepHypothesis : public NSVfitTauDecayHypothesis
{
 public:
  NSVfitTauToLepHypothesis() {}
  NSVfitTauToLepHypothesis(const edm::Ptr<reco::Candidate>& particle, const std::string& name, int barcode)
    : NSVfitTauDecayHypothesis(particle, name, barcode)
  {}
  NSVfitTauToLepHypothesis(const NSVfitTauToLepHypothesis& bluePrint)
    : NSVfitTauDecayHypothesis(bluePrint) 
  {}
  ~NSVfitTauToLepHypothesis() {}

  virtual NSVfitTauToLepHypothesis* clone() const { return new NSVfitTauToLepHypothesis(*this); }

  virtual NSVfitTauToLepHypothesis<T>& operator=(const NSVfitTauToLepHypothesis& bluePrint)
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
