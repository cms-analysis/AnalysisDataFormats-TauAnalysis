#ifndef __DataFormats_DiTauCandidate_h__
#define __DataFormats_DiTauCandidate_h__

#include <vector>
#include <string>

#include "DataFormats/Candidate/interface/CandidateFwd.h" 
#include "DataFormats/Candidate/interface/Candidate.h" 
#include "DataFormats/Candidate/interface/CompositePtrCandidate.h" 

#include "DataFormats/METReco/interface/MET.h"
#include "DataFormats/TauReco/interface/PFTau.h"
#include "DataFormats/PatCandidates/interface/Tau.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Electron.h"

class DiTauCandidate : public reco::CompositePtrCandidate {

 public:
  //default C-tor
  DiTauCandidate() : reco::CompositePtrCandidate(), 
    hadrTauCoefficient_(0), 
    leptTauCoefficient_(0),
    cosPhiT_(0),
    hIdx_(-1), lIdx_(-1), mIdx_(-1),
    approxValid_(false) {}
  // C-tor from values
  DiTauCandidate(int charge, const LorentzVector & p4, const Point & vtx = Point( 0, 0, 0 ),
		 double hadrTauCoefficient = 0, double leptTauCoefficient = 0, 
		 double cosPhiT = 0, bool approxValid = false) :
    reco::CompositePtrCandidate( charge, p4, vtx ),
    hadrTauCoefficient_(hadrTauCoefficient),
    leptTauCoefficient_(leptTauCoefficient),
    cosPhiT_(cosPhiT),
    hIdx_(-1), lIdx_(-1), mIdx_(-1),
    approxValid_(approxValid) {} 
  // C-tor from values
  DiTauCandidate(int charge, const PolarLorentzVector & p4, const Point & vtx = Point( 0, 0, 0 ),
		 double hadrTauCoefficient = 0, double leptTauCoefficient = 0,
		 double cosPhiT = 0, bool approxValid = false) :
    reco::CompositePtrCandidate( charge, p4, vtx ),
    hadrTauCoefficient_(hadrTauCoefficient),
    leptTauCoefficient_(leptTauCoefficient),
    cosPhiT_(cosPhiT),
    hIdx_(-1), lIdx_(-1), mIdx_(-1),
    approxValid_(approxValid) {} 
  // C-tor from a particle
  explicit DiTauCandidate( const reco::Particle & p ) : reco::CompositePtrCandidate( p ) { }  
  // D-tor
  virtual ~DiTauCandidate();

  DiTauCandidate* clone() const;

  // Print object
  virtual std::string print() const;

  // Set daughters
  void setHadrTau(const reco::CandidatePtr & cand);
  void setLeptTau(const reco::CandidatePtr & cand);
  void setMet(const reco::CandidatePtr & cand);

  // Get daughters
  reco::CandidatePtr hadrTauPtr() const { 
    return ( hIdx_>-1 && hIdx_<3) ? daughterPtr(hIdx_) : reco::CandidatePtr(); 
  }
  const reco::PFTau* pfTau() const {
    return dynamic_cast<const reco::PFTau*>( hadrTauPtr().get() );
  }
  const reco::BaseTau* recoTau() const {
    return dynamic_cast<const reco::BaseTau*>( hadrTauPtr().get() );
  }
  const reco::BaseTau* baseTau() const {
    return recoTau();
  }  
  const pat::Tau* patTau() const {
    return dynamic_cast<const pat::Tau*>( hadrTauPtr().get() );
  }
  reco::CandidatePtr leptTauPtr() const { 
    return ( lIdx_>-1 && lIdx_<3) ? daughterPtr(lIdx_) : reco::CandidatePtr(); 
  }
  const pat::Muon* patMuon() const {
    return dynamic_cast<const pat::Muon*>( leptTauPtr().get() );
  }
  const pat::Electron* patElectron() const {
    return dynamic_cast<const pat::Electron*>( leptTauPtr().get() );
  }
  reco::CandidatePtr metPtr() const {
    return ( mIdx_>-1 && mIdx_<3) ? daughterPtr(mIdx_) : reco::CandidatePtr(); 
  }
  const reco::MET* met() const {
    return dynamic_cast<const reco::MET*>( metPtr().get() );
  }

  // Get coefficients of the collinear approximation
  double hadrTauCoefficient() const { return hadrTauCoefficient_; }
  double leptTauCoefficient() const { return leptTauCoefficient_; }

  // Get angle between visible daughters (in transversal plane)
  double cosPhiT() const { return cosPhiT_; }

  bool isApproxValid() const { return approxValid_; }

 private:

  double  hadrTauCoefficient_, leptTauCoefficient_;

  double cosPhiT_;

  int hIdx_, lIdx_, mIdx_;
  
  bool approxValid_;
  
};
#endif
