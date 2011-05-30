#include "AnalysisDataFormats/TauAnalysis/interface/NSVfitTauDecayHypothesisBase.h"

NSVfitTauDecayHypothesisBase::NSVfitTauDecayHypothesisBase(const NSVfitTauDecayHypothesisBase& bluePrint)
  : NSVfitSingleParticleHypothesisBase(bluePrint),
    decayMode_(bluePrint.decayMode_)
{}

NSVfitTauDecayHypothesisBase& NSVfitTauDecayHypothesisBase::operator=(const NSVfitTauDecayHypothesisBase& bluePrint)
{
  NSVfitSingleParticleHypothesisBase::operator=(bluePrint);
  decayMode_ = bluePrint.decayMode_;
  return (*this);
}
