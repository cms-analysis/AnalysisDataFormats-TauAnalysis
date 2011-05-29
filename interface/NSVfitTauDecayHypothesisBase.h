#ifndef AnalysisDataFormats_TauAnalysis_NSVfitTauDecayHypothesisBase_h
#define AnalysisDataFormats_TauAnalysis_NSVfitTauDecayHypothesisBase_h

/*
 * NSVfitTauDecayHypothesisBase
 *
 * Class which holds a representation of a decay of a tau lepton.
 *
 * NOTE: this "Base"-class is used to make persistent solutions of NSVfitAlgorithmByIntegration;
 *       solutions of NSVfitAlgorithmByLikelihoodMaximization are of derrived type NSVfitTauDecayHypothesis
 *
 * Authors: Evan K. Friis, Christian Veelken, UC Davis
 *
 */

#include "AnalysisDataFormats/TauAnalysis/interface/NSVfitSingleParticleHypothesisBase.h"

class NSVfitTauDecayHypothesisBase : virtual public NSVfitSingleParticleHypothesisBase
{
 public:
  NSVfitTauDecayHypothesisBase() {}
  NSVfitTauDecayHypothesisBase(const edm::Ptr<reco::Candidate>& particle,
      const std::string& name, int barcode)
    : NSVfitSingleParticleHypothesisBase(particle, name, barcode) 
  {}
  ~NSVfitTauDecayHypothesisBase() {}
  // Copy constructors
  NSVfitTauDecayHypothesisBase(const NSVfitTauDecayHypothesisBase&);
  virtual NSVfitTauDecayHypothesisBase* clone() const { return new NSVfitTauDecayHypothesisBase(*this); }
  virtual NSVfitTauDecayHypothesisBase& operator=(const NSVfitTauDecayHypothesisBase&);

  /// tau lepton hadronic decay mode
  /// (as defined in DataFormats/TauReco/interface/PFTauDecayMode.h)
  int decayMode() const { return decayMode_; }

 protected:

  /// tau lepton hadronic decay mode
  int decayMode_;
};

#endif /* end of include guard: AnalysisDataFormats_TauAnalysis_NSVfitTauDecayHypothesisBase_h */
