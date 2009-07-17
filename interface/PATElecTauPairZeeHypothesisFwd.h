#ifndef AnalysisDataFormats_TauAnalysis_PATElecTauPairZeeHypothesisFwd_h
#define AnalysisDataFormats_TauAnalysis_PATElecTauPairZeeHypothesisFwd_h

#include "AnalysisDataFormats/TauAnalysis/interface/PATElecTauPairZeeHypothesis.h"

#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/Common/interface/RefProd.h"
#include "DataFormats/Common/interface/RefVector.h"

#include <vector>

/// collection of PATElecTauPairZeeHypothesis objects
typedef std::vector<PATElecTauPairZeeHypothesis> PATElecTauPairZeeHypothesisCollection;

/// persistent reference to a PATElecTauPairZeeHypothesis object
typedef edm::Ref<PATElecTauPairZeeHypothesisCollection> PATElecTauPairZeeHypothesisRef;

/// references to PATElecTauPairZeeHypothesis collection
typedef edm::RefProd<PATElecTauPairZeeHypothesisCollection> PATElecTauPairZeeHypothesisRefProd;

/// vector of references to PATElecTauPairZeeHypothesis objects all in the same collection
typedef edm::RefVector<PATElecTauPairZeeHypothesisCollection> PATElecTauPairZeeHypothesisRefVector;

#endif
