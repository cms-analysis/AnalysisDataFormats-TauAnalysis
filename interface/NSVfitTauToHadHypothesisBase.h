#ifndef AnalysisDataFormats_TauAnalysis_NSVfitTauToHadHypothesisBase_h
#define AnalysisDataFormats_TauAnalysis_NSVfitTauToHadHypothesisBase_h

#include "AnalysisDataFormats/TauAnalysis/interface/NSVfitTauDecayHypothesisBase.h"

#include "DataFormats/PatCandidates/interface/Tau.h"
#include "DataFormats/CLHEP/interface/AlgebraicObjects.h"

class NSVfitTauToHadHypothesisBase : public NSVfitTauDecayHypothesisBase
{
 public:

  NSVfitTauToHadHypothesisBase() {}
  NSVfitTauToHadHypothesisBase(const edm::Ptr<reco::Candidate>& particle, const std::string& name, int barcode)
    : NSVfitTauDecayHypothesisBase(particle, name, barcode)
  {}
  NSVfitTauToHadHypothesisBase(const NSVfitTauToHadHypothesisBase&);
  ~NSVfitTauToHadHypothesisBase() {}

  virtual NSVfitTauToHadHypothesisBase* clone() const { return new NSVfitTauToHadHypothesisBase(*this); }

  virtual NSVfitTauToHadHypothesisBase& operator=(const NSVfitTauToHadHypothesisBase&);
};

#endif
