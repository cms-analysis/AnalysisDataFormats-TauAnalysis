#ifndef __AnalysisDataFormats_TauAnalysis_CompositeRefCandidateT1T2MEt_h__
#define __AnalysisDataFormats_TauAnalysis_CompositeRefCandidateT1T2MEt_h__

/** \class CompositeRefCandidateT1T2MEt
 *
 * Combination of leptonic and hadronic decay products 
 * of a pair of tau leptons plus missing transverse momentum 
 * (representing the undetected momentum carried away by the neutrinos 
 *  produced in the two tau decays) 
 * 
 * \authors Colin Bernet,
 *          Michal Bluj,
 *          Christian Veelken
 *
 * \version $Revision: 1.1 $
 *
 * $Id: CompositeRefCandidateT1T2MEt.h,v 1.1 2009/01/29 13:22:18 veelken Exp $
 *
 */

#include "DataFormats/Candidate/interface/CandidateFwd.h" 
#include "DataFormats/Candidate/interface/Candidate.h" 
#include "DataFormats/Candidate/interface/LeafCandidate.h" 
#include "DataFormats/Common/interface/Ref.h"

template<typename T1, typename T2>
class CompositeRefCandidateT1T2MEt : public reco::LeafCandidate 
{
  typedef std::vector<T1> T1Collection;
  typedef edm::Ref<T1Collection> T1Ref;
  typedef std::vector<T2> T2Collection;
  typedef edm::Ref<T2Collection> T2Ref;

 public:

  /// default constructor
  CompositeRefCandidateT1T2MEt() {}

  /// constructor with MEt
  CompositeRefCandidateT1T2MEt(const T1Ref leg1, const T2Ref leg2, const reco::CandidatePtr met)
    : leg1_(leg1), leg2_(leg2), met_(met) {}

  /// constructor without MEt
  CompositeRefCandidateT1T2MEt(const T1Ref leg1, const T2Ref leg2)
    : leg1_(leg1), leg2_(leg2) {}

  /// destructor
  ~CompositeRefCandidateT1T2MEt() {}

  /// access to daughter particles
  const T1Ref leg1() const { return leg1_; }
  const T2Ref leg2() const { return leg2_; }
 
  /// access to missing transverse momentum
  const reco::CandidatePtr met() const { return met_; }

  // get sum of charge of visible decay products
  // (not need to declare it in CompositeRefCandidateT1T2MEt; 
  //  already declared in Candidate base-class)

  /// get four-momentum of visible decay products
  const reco::Candidate::LorentzVector& p4Vis() const { return p4Vis_; }

  /// get four-momentum and scaling factors for momenta of visible decay products
  /// computed by collinear approximation
  const reco::Candidate::LorentzVector& p4CollinearApprox() const { return p4CollinearApprox_; }
  double x1CollinearApprox() const { return x1CollinearApprox_; }
  double x2CollinearApprox() const { return x2CollinearApprox_; }
  bool collinearApproxIsValid() const { return collinearApproxIsValid_; }

  /// get "pseudo" four-momentum computed by CDF method
  /// (for a description of the method, see e.g. CDF note 8972)
  const reco::Candidate::LorentzVector& p4CDFmethod() const { return p4CDFmethod_; }

  /// get transverse mass of visible decay products + missing transverse momentum
  double mt12MET() const { return mt12MET_; }

  /// get transverse mass of first/second
  /// visible decay product + missing transverse momentum
  double mt1MET() const { return mt1MET_; }
  double mt2MET() const { return mt2MET_; }

  /// get acoplanarity angle (angle in transverse plane) between visible decay products
  double dPhi12() const { return dPhi12_; } 

  /// get separation in eta-phi between visible decay products
  double dR12() const { return dR12_; }

  /// get minimal/maximal pseudo-rapidity of visible decay products
  double visEtaMin() const { return visEtaMin_; }
  double visEtaMax() const { return visEtaMax_; }
  
  /// get acoplanarity angle (angle in transverse plane) between first/second
  /// visible decay product and missing transverse momentum
  double dPhi1MET() const { return dPhi1MET_; }
  double dPhi2MET() const { return dPhi2MET_; }

  /// clone  object
  CompositeRefCandidateT1T2MEt<T1,T2>* clone() const { return new CompositeRefCandidateT1T2MEt<T1,T2>(*this); }

 private:
  
  /// allow only CompositeRefCandidateT1T2MEtAlgorithm to change values of data-members
  template<typename T1_type, typename T2_type> friend class CompositeRefCandidateT1T2MEtAlgorithm; 

  /// set four-momentum of visible decay products
  void setP4Vis(const reco::Candidate::LorentzVector& p4) { p4Vis_ = p4; } 
  /// set four-momentum and scaling factors for momenta of visible decay products
  /// computed by collinear approximation
  void setCollinearApproxQuantities(const reco::Candidate::LorentzVector& p4, double x1, double x2, bool isValid)
  {
    p4CollinearApprox_ = p4;
    x1CollinearApprox_ = x1;
    x2CollinearApprox_ = x2;
    collinearApproxIsValid_ = isValid;
  }
  /// set "pseudo" four-momentum computed by CDF method
  /// (for a description of the method, see e.g. CDF note 8972)
  void setP4CDFmethod(const reco::Candidate::LorentzVector& p4) { p4CDFmethod_ = p4; }
  /// set transverse mass of visible decay products + missing transverse momentum
  void setMt12MET(double mt) { mt12MET_ = mt; }
  /// set transverse mass of first/second
  /// visible decay product + missing transverse momentum
  void setMt1MET(double mt) { mt1MET_ = mt; }
  void setMt2MET(double mt) { mt2MET_ = mt; }
  /// set acoplanarity angle (angle in transverse plane) between visible decay products
  void setDPhi12(double dPhi) { dPhi12_ = dPhi; }
  /// set separation in eta-phi between visible decay products
  void setDR12(double dR) { dR12_ = dR; }
  /// set minimal/maximal pseudo-rapidity of visible decay products
  void setVisEtaMin(double eta) { visEtaMin_ = eta; }
  void setVisEtaMax(double eta) { visEtaMax_ = eta; }
  /// set acoplanarity angle (angle in transverse plane) between first/second
  /// visible decay product and missing transverse momentum
  void setDPhi1MET(double dPhi) { dPhi1MET_ = dPhi; }
  void setDPhi2MET(double dPhi) { dPhi2MET_ = dPhi; }

  /// references/pointers to decay products
  T1Ref leg1_;
  T2Ref leg2_;
  reco::CandidatePtr met_;

  /// four-momentum of visible decay products
  reco::Candidate::LorentzVector p4Vis_;
  /// four-momentum and scaling factors for momenta of visible decay products computed by collinear approximation
  reco::Candidate::LorentzVector p4CollinearApprox_;
  bool collinearApproxIsValid_;
  double x1CollinearApprox_;
  double x2CollinearApprox_;
  /// "pseudo" four-momentum computed by CDF method
  reco::Candidate::LorentzVector p4CDFmethod_;
  /// transverse mass of visible decay products + missing transverse momentum
  double mt12MET_;
  /// transverse mass of first/second visible decay product + missing transverse momentum
  double mt1MET_;
  double mt2MET_;
  /// acoplanarity angle (angle in transverse plane) between visible decay products
  double dPhi12_;
  /// separation in eta-phi between visible decay products
  double dR12_;
  /// minimal/maximal pseudo-rapidity of visible decay products
  double visEtaMin_;
  double visEtaMax_;
  /// acoplanarity angle (angle in transverse plane) between first/second
  /// visible decay product and missing transverse momentum
  double dPhi1MET_;
  double dPhi2MET_;
};

#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Tau.h"

typedef CompositeRefCandidateT1T2MEt<reco::Candidate, reco::Candidate> DiCandidatePair;
typedef CompositeRefCandidateT1T2MEt<pat::Electron, pat::Tau> PATElecTauPair;
typedef CompositeRefCandidateT1T2MEt<pat::Muon, pat::Tau> PATMuTauPair;
typedef CompositeRefCandidateT1T2MEt<pat::Tau, pat::Tau> PATDiTauPair;
typedef CompositeRefCandidateT1T2MEt<pat::Electron, pat::Muon> PATElecMuPair;

#endif
