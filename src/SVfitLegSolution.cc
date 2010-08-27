#include "AnalysisDataFormats/TauAnalysis/interface/SVfitLegSolution.h"

SVfitLegSolution::SVfitLegSolution()
  : polarizationHypothesis_(kUnknown)
{}

SVfitLegSolution::SVfitLegSolution(polarizationHypothesisType polarizationHypothesis)
  : polarizationHypothesis_(polarizationHypothesis)
{}

SVfitLegSolution::~SVfitLegSolution()
{
// nothing to be done yet
}

