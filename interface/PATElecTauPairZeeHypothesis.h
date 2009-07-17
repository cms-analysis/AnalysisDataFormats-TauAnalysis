#ifndef __AnalysisDataFormats_TauAnalysis_PATElecTauPairZeeHypothesis_h__
#define __AnalysisDataFormats_TauAnalysis_PATElecTauPairZeeHypothesis_h__

/** \class PATElecTauPairZeeHypothesis
 *
 * Information about compatibility of an elecron + tau-jet pair
 * with the hypothesis of being a pair of electron,
 * resulting from a Z --> e+ e- decay
 * 
 * \author Christian Veelken, UC Davis
 *
 * \version $Revision: 1.2 $
 *
 * $Id: PATElecTauPairZeeHypothesis.h,v 1.2 2009/07/16 14:13:33 veelken Exp $
 *
 */

#include "DataFormats/Common/interface/Ptr.h"

#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/JetReco/interface/CaloJet.h"
#include "DataFormats/JetReco/interface/PFJet.h"
#include "DataFormats/TrackReco/interface/Track.h"
#include "DataFormats/EgammaCandidates/interface/GsfElectron.h"
#include "DataFormats/GsfTrackReco/interface/GsfTrack.h"

#include "DataFormats/Candidate/interface/Particle.h"

#include "AnalysisDataFormats/TauAnalysis/interface/CompositePtrCandidateT1T2MEt.h"

class PATElecTauPairZeeHypothesis
{
  typedef edm::Ptr<PATElecTauPair> PATElecTauPairPtr;
  typedef edm::Ptr<reco::GenParticle> GenParticlePtr;
  typedef edm::Ptr<reco::CaloJet> CaloJetPtr;
  typedef edm::Ptr<reco::PFJet> PFJetPtr;
  typedef edm::Ptr<reco::Track> TrackPtr;
  typedef edm::Ptr<reco::GsfElectron> GsfElectronPtr;
  typedef edm::Ptr<reco::GsfTrack> GsfTrackPtr;

 public:
  /// default constructor 
  PATElecTauPairZeeHypothesis() {}

  /// constructor 
  PATElecTauPairZeeHypothesis(const PATElecTauPairPtr& elecTauPair)
    : elecTauPair_(elecTauPair) {}

  /// destructor
  ~PATElecTauPairZeeHypothesis() {}

  /// access to reconstructed electron + tau-jet pair
  PATElecTauPairPtr elecTauPair() const { return elecTauPair_; }
  
  /// access to generated electrons
  /// (if matching reconstructed electron + tau-jet pair) 
  const GenParticlePtr genElec1() const { return genElec1_; }
  const GenParticlePtr genElec2() const { return genElec2_; }

  enum { kCaloJet, kPFJet, kRecoTrack, kGsfElecron, kGsfTrack, kUndefined };

  /// get combination of electron1 and electron2 four-vectors 
  /// that best match nominal Z0 mass
  const reco::Particle::LorentzVector& p4Elec1bestMatch() const { return p4Elec1bestMatch_; }
  int typeElec1bestMatch() const { return typeElec1bestMatch_; }
  const reco::Particle::LorentzVector& p4Elec2bestMatch() const { return p4Elec2bestMatch_; }
  int typeElec2bestMatch() const { return typeElec2bestMatch_; }

  /// access to CaloJet, PFJet, recoTrack, gsfElectron, gsfTrack
  /// matched to first electron
  const CaloJetPtr elec1matchedCaloJet() const { return elec1matchedCaloJet_; }
  const PFJetPtr elec1matchedPFJet() const { return elec1matchedPFJet_; }
  const TrackPtr elec1matchedTrack() const { return elec1matchedTrack_; }
  const GsfElectronPtr elec1matchedGsfElectron() const { return elec1matchedGsfElectron_; }
  const GsfTrackPtr elec1matchedGsfTrack() const { return elec1matchedGsfTrack_; }

  /// access to CaloJet, PFJet, recoTrack, gsfElectron, gsfTrack
  /// matched to second electron
  const CaloJetPtr elec2matchedCaloJet() const { return elec2matchedCaloJet_; }
  const PFJetPtr elec2matchedPFJet() const { return elec2matchedPFJet_; }
  const TrackPtr elec2matchedTrack() const { return elec2matchedTrack_; }
  const GsfElectronPtr elec2matchedGsfElectron() const { return elec2matchedGsfElectron_; }
  const GsfTrackPtr elec2matchedGsfTrack() const { return elec2matchedGsfTrack_; }

 private:

  /// allow only PATElecTauPairZeeHypothesisAlgorithm to change values of data-members
  friend class PATElecTauPairZeeHypothesisAlgorithm;

  /// reference to electron + tau-pair object
  PATElecTauPairPtr elecTauPair_;

  /// generated electrons
  /// (if matching reconstructed electron + tau-jet pair) 
  GenParticlePtr genElec1_;
  GenParticlePtr genElec2_;

  /// combination of electron1 and electron2 four-vectors 
  /// that best match nominal Z0 mass
  reco::Particle::LorentzVector p4Elec1bestMatch_; 
  int typeElec1bestMatch_;
  reco::Particle::LorentzVector p4Elec2bestMatch_; 
  int typeElec2bestMatch_;

  /// references to CaloJet, PFJet, recoTrack, gsfElectron, gsfTrack
  /// matched to first (hypothetic) electron
  CaloJetPtr elec1matchedCaloJet_;
  PFJetPtr elec1matchedPFJet_;
  TrackPtr elec1matchedTrack_;
  GsfElectronPtr elec1matchedGsfElectron_;
  GsfTrackPtr elec1matchedGsfTrack_;

  /// references to CaloJet, PFJet, recoTrack, gsfElectron, gsfTrack
  /// matched to second (hypothetic) electron
  CaloJetPtr elec2matchedCaloJet_;
  PFJetPtr elec2matchedPFJet_;
  TrackPtr elec2matchedTrack_;
  GsfElectronPtr elec2matchedGsfElectron_;
  GsfTrackPtr elec2matchedGsfTrack_;
};

#endif
