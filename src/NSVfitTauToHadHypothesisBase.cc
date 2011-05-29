#include "AnalysisDataFormats/TauAnalysis/interface/NSVfitTauToHadHypothesisBase.h"

NSVfitTauToHadHypothesisBase::NSVfitTauToHadHypothesisBase(const NSVfitTauToHadHypothesisBase& bluePrint)
  : NSVfitTauDecayHypothesisBase(bluePrint)
{}

NSVfitTauToHadHypothesisBase& NSVfitTauToHadHypothesisBase::operator=(const NSVfitTauToHadHypothesisBase& bluePrint)
{
  NSVfitTauDecayHypothesisBase::operator=(bluePrint);
  return (*this);
}
