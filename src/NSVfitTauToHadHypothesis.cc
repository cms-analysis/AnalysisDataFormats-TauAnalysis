#include "AnalysisDataFormats/TauAnalysis/interface/NSVfitTauToHadHypothesis.h"

NSVfitTauToHadHypothesis::NSVfitTauToHadHypothesis(const NSVfitTauToHadHypothesis& bluePrint)
  : NSVfitSingleParticleHypothesisBase(bluePrint),
    p3Vis_unit_(bluePrint.p3Vis_unit_),
    visEnFracX_(bluePrint.visEnFracX_),
    decay_angle_rf_(bluePrint.decay_angle_rf_),
    decay_angle_VMrho_(bluePrint.decay_angle_VMrho_),
    mass2_VMrho_(bluePrint.mass2_VMrho_),
    decay_angle_VMa1_(bluePrint.decay_angle_VMa1_),
    decay_angle_VMa1r_theta_(bluePrint.decay_angle_VMa1r_theta_),
    decay_angle_VMa1r_phi_(bluePrint.decay_angle_VMa1r_phi_),
    mass2_VMa1_(bluePrint.mass2_VMa1_),
    decayVertexPos_(bluePrint.decayVertexPos_),
    flightPath_(bluePrint.flightPath_),
    decayDistance_(bluePrint.decayDistance_),
    decayMode_(bluePrint.decayMode_),
    polarization_(bluePrint.polarization_)
{}

NSVfitSingleParticleHypothesisBase& NSVfitTauToHadHypothesis::operator =(const NSVfitTauToHadHypothesis& bluePrint)
{
  NSVfitSingleParticleHypothesisBase::operator =(bluePrint);
  p3Vis_unit_ = bluePrint.p3Vis_unit_;
  visEnFracX_ = bluePrint.visEnFracX_;
  decay_angle_rf_ = bluePrint.decay_angle_rf_;
  decay_angle_VMrho_ = bluePrint.decay_angle_VMrho_;
  mass2_VMrho_ = bluePrint.mass2_VMrho_;
  decay_angle_VMa1_ = bluePrint.decay_angle_VMa1_;
  decay_angle_VMa1r_theta_ = bluePrint.decay_angle_VMa1r_theta_;
  decay_angle_VMa1r_phi_ = bluePrint.decay_angle_VMa1r_phi_;
  mass2_VMa1_ = bluePrint.mass2_VMa1_;
  decayVertexPos_ = bluePrint.decayVertexPos_;
  flightPath_ = bluePrint.flightPath_;
  decayDistance_ = bluePrint.decayDistance_;
  decayMode_ = bluePrint.decayMode_;
  polarization_ = bluePrint.polarization_;
  return (*this);
}
