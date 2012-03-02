#include "AnalysisDataFormats/TauAnalysis/interface/NSVfitEventHypothesisBase.h"
#include "AnalysisDataFormats/TauAnalysis/interface/NSVfitEventHypothesis.h"
#include "AnalysisDataFormats/TauAnalysis/interface/NSVfitEventHypothesisByIntegration.h"
#include "AnalysisDataFormats/TauAnalysis/interface/NSVfitResonanceHypothesisBase.h"
#include "AnalysisDataFormats/TauAnalysis/interface/NSVfitResonanceHypothesis.h"
#include "AnalysisDataFormats/TauAnalysis/interface/NSVfitResonanceHypothesisByIntegration.h"
#include "AnalysisDataFormats/TauAnalysis/interface/NSVfitResonanceHypothesisSummary.h"
#include "AnalysisDataFormats/TauAnalysis/interface/NSVfitSingleParticleHypothesisBase.h"
#include "AnalysisDataFormats/TauAnalysis/interface/NSVfitTauToDaughtersHypothesisBaseT1T2.h"
#include "AnalysisDataFormats/TauAnalysis/interface/NSVfitTauToHadHypothesis.h"

#include "AnalysisDataFormats/TauAnalysis/interface/PFMEtSignCovMatrix.h"

#include "DataFormats/Common/interface/AssociationVector.h"
#include "DataFormats/Common/interface/RefProd.h"
#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/Common/interface/Ptr.h"
#include "DataFormats/Common/interface/Wrapper.h"
#include "DataFormats/Common/interface/OwnVector.h"

#include "DataFormats/PatCandidates/interface/Electron.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/PatCandidates/interface/Tau.h"
#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/MET.h"

namespace {
  struct AnalysisDataFormats_TauAnalysis_dictionary {

    /// create dictionaries for
    ///  o std::vector<edm::Ptr<pat::Jet> >
    /// as these dictionaries are not yet created in DataFormats/PatCandidates/src/classes.h
    std::vector<edm::Ptr<pat::Jet> > dummyPATJetPtrCollection;

    /// create dictionaries for
    ///  o edm::Ptr<reco::CaloJet>
    ///  o edm::Ptr<reco::PFJet>
    /// as these dictionaries are not yet created in DataFormats/JetReco/src/classes.h
    edm::Ptr<reco::CaloJet> dummyCaloJetPtr;
    edm::Ptr<reco::PFJet> dummyPFJetPtr;
    std::vector<edm::Ptr<reco::Jet> > dummyJetPtrCollection;

    /// create dictionaries for
    ///  o edm::Ptr<reco::GenParticle>
    /// as these dictionaries are not yet created in DataFormats/HepMCCandidate/src/classes.h
    edm::Ptr<reco::GenParticle> dummyGenParticlePtr;

    /// create dictionaries for
    ///  o edm::Ptr<reco::Track>
    ///  o edm::Ptr<reco::GsfTrack>
    /// as these dictionaries are not yet created in DataFormats/TrackReco/src/classes.h (DataFormats/GsfTrackReco/src/classes.h)
    edm::Ptr<reco::Track> dummyTrackPtr;
    edm::Ptr<reco::GsfTrack> dummyGsfTrackPtr;

    /// create disctionaries for MET covariance matrix
    /// computed by (PF)MET significance algorithm
    PFMEtSignCovMatrix dummyPFMEtSignCovMatrix;
    edm::Wrapper<PFMEtSignCovMatrix> dummyPFMEtSignCovMatrixWrapper;

    /// create dictionaries for NSVfit solution data-formats
    NSVfitEventHypothesisBase dummyNSVfitEventHypothesisBase;
    NSVfitEventHypothesis dummyNSVfitEventHypothesis;
    NSVfitEventHypothesisByIntegration dummyNSVfitEventHypothesisByIntegration;
    NSVfitResonanceHypothesisBase dummyNSVfitResonanceHypothesisBase;
    NSVfitResonanceHypothesis dummyNSVfitResonanceHypothesis;
    NSVfitResonanceHypothesisByIntegration dummyNSVfitResonanceHypothesisByIntegration;
    NSVfitResonanceHypothesisSummary dummyNSVfitResonanceHypothesisSummary;
    NSVfitTauToElecHypothesisBase dummyNSVfitTauToElecHypothesisBase;
    NSVfitTauToElecHypothesis dummyNSVfitTauToElecHypothesis;
    NSVfitTauToMuHypothesisBase dummyNSVfitTauToMuHypothesisBase;
    NSVfitTauToMuHypothesis dummyNSVfitTauToMuHypothesis;
    NSVfitTauToHadHypothesisBase dummyNSVfitTauToHadHypothesisBase;
    NSVfitTauToHadHypothesis dummyNSVfitTauToHadHypothesis;
    std::vector<NSVfitEventHypothesisBase> dummyNSVfitEventHypothesisBaseCollection;
    std::vector<NSVfitEventHypothesis> dummyNSVfitEventHypothesisCollection;
    std::vector<NSVfitEventHypothesisByIntegration> dummyNSVfitEventHypothesisByIntegrationCollection;
    edm::Wrapper<std::vector<NSVfitEventHypothesisBase> > dummyNSVfitEventHypothesisBaseCollectionWrapper;
    edm::Wrapper<std::vector<NSVfitEventHypothesis> > dummyNSVfitEventHypothesisCollectionWrapper;
    edm::Wrapper<std::vector<NSVfitEventHypothesisByIntegration> > dummyNSVfitEventHypothesisByIntegrationCollectionWrapper;
    std::vector<NSVfitEventHypothesisBase*> dummyNSVfitEventHypothesisBasePtrCollection;
    edm::OwnVector<NSVfitEventHypothesisBase, edm::ClonePolicy<NSVfitEventHypothesisBase> > dummyNSVfitEventHypothesisBaseOwnVector;
    std::vector<NSVfitResonanceHypothesisBase*> dummyNSVfitResonanceHypothesisBasePtrCollection;
    edm::OwnVector<NSVfitResonanceHypothesisBase, edm::ClonePolicy<NSVfitResonanceHypothesisBase> > dummyNSVfitResonanceHypothesisBaseOwnVector;
    std::vector<NSVfitResonanceHypothesisSummary> dummyNSVfitResonanceHypothesisSummaryCollection;
    std::auto_ptr<TH1> dummyTH1Ptr;
    std::vector<NSVfitSingleParticleHypothesisBase*> dummyNSVfitSingleParticleHypothesisBasePtrCollection;
    edm::OwnVector<NSVfitSingleParticleHypothesisBase, edm::ClonePolicy<NSVfitSingleParticleHypothesisBase> >  dummyNSVfitSingleParticleHypothesisBaseOwnVector;
  };
}
