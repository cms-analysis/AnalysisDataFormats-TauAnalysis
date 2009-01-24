#ifndef AnalysisDataFormats_TauAnalysis_DiTauCandidateFwd_h
#define AnalysisDataFormats_TauAnalysis_DiTauCandidateFwd_h

#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/Common/interface/RefProd.h"
#include "DataFormats/Common/interface/RefVector.h"

#include <vector>

class DiTauCandidate;

// collection of DiTauCandidate objects
typedef std::vector<DiTauCandidate> DiTauCandidateCollection;
  
// persistent reference to a DiTauCandidate
typedef edm::Ref<DiTauCandidateCollection> DiTauCandidateRef;
  
// references to DiTauCandidate collection
typedef edm::RefProd<DiTauCandidateCollection> DiTauCandidateRefProd;

// vector of references to DiTauCandidate objects all in the same collection
typedef edm::RefVector<DiTauCandidateCollection> DiTauCandidateRefVector;

#endif
