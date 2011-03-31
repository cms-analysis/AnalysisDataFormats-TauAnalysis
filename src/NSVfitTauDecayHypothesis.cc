#include "AnalysisDataFormats/TauAnalysis/interface/NSVfitTauDecayHypothesis.h"

NSVfitTauDecayHypothesis::NSVfitTauDecayHypothesis(const NSVfitTauDecayHypothesis& bluePrint)
  : NSVfitSingleParticleHypothesisBase(bluePrint),
    p4invis_rf_(bluePrint.p4invis_rf_),
    p4vis_rf_(bluePrint.p4vis_rf_),
    p3Vis_unit_(bluePrint.p3Vis_unit_),
    visMass_(bluePrint.visMass_),
    visEnFracX_(bluePrint.visEnFracX_),
    decay_angle_rf_(bluePrint.decay_angle_rf_),
    decayVertexPos_(bluePrint.decayVertexPos_),
    flightPath_(bluePrint.flightPath_),
    decayDistance_(bluePrint.decayDistance_),
    decayMode_(bluePrint.decayMode_),
    polarization_(bluePrint.polarization_)
{}

NSVfitSingleParticleHypothesisBase& NSVfitTauDecayHypothesis::operator =(const NSVfitTauDecayHypothesis& bluePrint)
{
  NSVfitSingleParticleHypothesisBase::operator =(bluePrint);
  p4invis_rf_ = bluePrint.p4invis_rf_;
  p4vis_rf_ = bluePrint.p4vis_rf_;
  p3Vis_unit_ = bluePrint.p3Vis_unit_;
  visMass_ = bluePrint.visMass_;
  visEnFracX_ = bluePrint.visEnFracX_;
  decay_angle_rf_ = bluePrint.decay_angle_rf_;
  decayVertexPos_ = bluePrint.decayVertexPos_;
  flightPath_ = bluePrint.flightPath_;
  decayDistance_ = bluePrint.decayDistance_;
  decayMode_ = bluePrint.decayMode_;
  polarization_ = bluePrint.polarization_;
  return (*this);
}
