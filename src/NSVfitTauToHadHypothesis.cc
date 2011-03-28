#include "AnalysisDataFormats/TauAnalysis/interface/NSVfitTauToHadHypothesis.h"

NSVfitTauToHadHypothesis::NSVfitTauToHadHypothesis(const NSVfitTauToHadHypothesis& bluePrint)
  : NSVfitTauDecayHypothesis(bluePrint),
    decay_angle_VMrho_(bluePrint.decay_angle_VMrho_),
    mass2_VMrho_(bluePrint.mass2_VMrho_),
    decay_angle_VMa1_(bluePrint.decay_angle_VMa1_),
    decay_angle_VMa1r_theta_(bluePrint.decay_angle_VMa1r_theta_),
    decay_angle_VMa1r_phi_(bluePrint.decay_angle_VMa1r_phi_),
    mass2_VMa1_(bluePrint.mass2_VMa1_),
    fittedVertex_(bluePrint.fittedVertex_) 
{}

NSVfitTauDecayHypothesis& NSVfitTauToHadHypothesis::operator=(const NSVfitTauToHadHypothesis& bluePrint)
{
  NSVfitTauDecayHypothesis::operator=(bluePrint);
  decay_angle_VMrho_ = bluePrint.decay_angle_VMrho_;
  mass2_VMrho_ = bluePrint.mass2_VMrho_;
  decay_angle_VMa1_ = bluePrint.decay_angle_VMa1_;
  decay_angle_VMa1r_theta_ = bluePrint.decay_angle_VMa1r_theta_;
  decay_angle_VMa1r_phi_ = bluePrint.decay_angle_VMa1r_phi_;
  mass2_VMa1_ = bluePrint.mass2_VMa1_;
  fittedVertex_ = bluePrint.fittedVertex_;
  return (*this);
}
