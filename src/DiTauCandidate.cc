#include "AnalysisDataFormats/TauAnalysis/interface/DiTauCandidate.h"

#include <sstream>

using namespace reco;

DiTauCandidate::~DiTauCandidate() {}

DiTauCandidate* DiTauCandidate::clone() const {
  return new DiTauCandidate( * this );
}

void DiTauCandidate::setHadrTau(const reco::CandidatePtr & cand) {
  if(hIdx_==-1){//set if not set already
    hIdx_ = numberOfDaughters();
    addDaughter(cand);
  }
}

void DiTauCandidate::setLeptTau(const reco::CandidatePtr & cand) {
  if(lIdx_==-1){//set if not set already
    lIdx_ = numberOfDaughters();
    addDaughter(cand);
  }
}

void DiTauCandidate::setMet(const reco::CandidatePtr & cand) {
  if(mIdx_==-1){//set if not set already
    mIdx_ = numberOfDaughters();
    addDaughter(cand);
  }
}

std::string DiTauCandidate::print() const {
  std::ostringstream out;
  out << "DiTau m/px/py/pz/pt: " << mass() << '/' << px() << '/' << py() << '/' << pz() << '/' << pt() << std::endl
      << "      eta/phi: " << eta() << '/' << phi() << std::endl
      << "      hadr/lept tau coefficient: " <<  hadrTauCoefficient_ << '/' << leptTauCoefficient_  << std::endl
      << "      No. of daughters: " << numberOfDaughters() << std::endl;
  out << "      Daughters:" << std::endl;
  // Print hadronic tau 
  if( hadrTauPtr().isNonnull() ) {
    out << "      Hadronic tau (hIdx=" << hIdx_ << ") p/pt/eta/phi: "
	<< hadrTauPtr()->p() << '/' << hadrTauPtr()->pt() << '/' << hadrTauPtr()->eta() << '/' << hadrTauPtr()->phi() << std::endl
	<< "        productId/index: " << hadrTauPtr().id() << '/' << hadrTauPtr().key() << std::endl;
  }
  else {
    out << "      Hadronic tau is not available in the event (hIdx=" << hIdx_<<  ")"<< std::endl;
  }
  // Print leptonic tau 
  if( leptTauPtr().isNonnull() ) {
    out << "      Leptonic tau (lIdx=" << lIdx_ << ") p/pt/eta/phi: "
	<< leptTauPtr()->p() << '/' << leptTauPtr()->pt() << '/' << leptTauPtr()->eta() << '/' << leptTauPtr()->phi() << std::endl
	<< "        productId/index: " << leptTauPtr().id() << '/' << leptTauPtr().key() << std::endl;
  }
  else {
    out << "      Leptonic tau is not available in the event (lIdx=" << lIdx_  << ")"<< std::endl;
  }
  // Print MET
  if( metPtr().isNonnull() ) {
    out << "      MET (mIdx=" << mIdx_ << ") p/pt/eta/phi: "
	<< metPtr()->p() << '/' << metPtr()->pt() << '/' << metPtr()->eta() << '/' << metPtr()->phi() << std::endl
	<< "        productId/index: " << metPtr().id() << '/' << metPtr().key() << std::endl;
  }
  else {
    out << "      MET is not available in the event (mIdx=" << mIdx_<< ")"<< std::endl;
  }

  return out.str();
}
