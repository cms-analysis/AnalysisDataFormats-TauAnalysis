#ifndef __AnalysisDataFormats_TauAnalysis_SVmassRecoSolution_h__
#define __AnalysisDataFormats_TauAnalysis_SVmassRecoSolution_h__

/** \class SVmassRecoSolution
 *
 * All information about one solution 
 * of secondary vertex based mass reconstruction algorithm
 * 
 * \authors Evan K. Friis,
 *          Christian Veelken (UC Davis)
 *
 * \version $Revision: 1.8 $
 *
 * $Id: SVmassRecoSolution.h,v 1.8 2010/03/29 17:05:33 veelken Exp $
 *
 */

#include "DataFormats/Candidate/interface/CandidateFwd.h" 
#include "DataFormats/Candidate/interface/Candidate.h" 

// "forward" declaration of SVmassRecoFitter algorithm
// (needed in order to declare SVmassRecoFitter as friend)
namespace svMassReco { 
  template<typename T1_type, typename T2_type> class SVmassRecoFitter; 
}

class SVmassRecoSolution
{
 public:

  /// default constructor
  SVmassRecoSolution() {}

  /// constructor with rank, validity flag passed as arguments
    SVmassRecoSolution(bool isValid, int rank) 
    : isValidSolution_(isValid),
      rank_(rank)
  {}

  /// destructor
  ~SVmassRecoSolution() {}

  /// get visible four momenta computed by SV method
  /// (recomputed at secondary vertex)
  const reco::Candidate::LorentzVector& p4VisLeg1() const { return p4VisLeg1_; };
  const reco::Candidate::LorentzVector& p4VisLeg2() const { return p4VisLeg2_; };
  /// get scaling factors for momenta of visible decay products
  /// computed by SV method
  double x1() const { return x1_; }
  double x2() const { return x2_; }
  /// get four-momentum computed by SV method
  const reco::Candidate::LorentzVector& p4() const { return p4SVmethod_; };
  /// get positions of reconstructed primary event vertex 
  /// and of reconstructed tau decay vertices
  const reco::Candidate::Point& primaryVertexPosSVrefitted() const { return primaryVertexPosSVrefitted_; }
  const reco::Candidate::Point& decayVertexPosLeg1() const { return decayVertexPosLeg1_; };
  const reco::Candidate::Point& decayVertexPosLeg2() const { return decayVertexPosLeg2_; };
  /// get flag indicating whether or not solution for invariant mass 
  /// computed by SV algorithm is valid or not
  bool isValidSolution() const { return isValidSolution_; }
  int migradStatus() const { return migradStatus_; }
  int svFitStatus() const { return svFitStatus_; }
  /// get mass scale parameters for visible tau decay products
  /// used internally by SV algorithm for constraining solutions
  double mScale1() const { return mScale1_; }
  double mScale2() const { return mScale2_; }
  /// get log-likelihood value of solution
  /// (of missing Et fit only)
  double logLikelihood() const { return nll_; }
  double logLikelihoodMEt() const { return nllMEt_; }
  /// get "rank" of solution
  int rank() const { return rank_; }

  // auxiliary operator for sorting solutions by log-likelihood value
  bool operator<(const SVmassRecoSolution& rhs) const { return (nll_ < rhs.nll_); }

 private:
  
  /// allow only SVmassRecoFitter to change values of data-members
  template<typename T1_type, typename T2_type> friend class svMassReco::SVmassRecoFitter; 

  /// set variables computed by secondary vertex based mass reconstruction
  void setP4VisLeg1(const reco::Candidate::LorentzVector& p4VisLeg1) { p4VisLeg1_ = p4VisLeg1; }
  void setP4VisLeg2(const reco::Candidate::LorentzVector& p4VisLeg2) { p4VisLeg2_ = p4VisLeg2; }
  void setX1(double x1) { x1_ = x1; }
  void setX2(double x2) { x2_ = x2; }
  void setP4(const reco::Candidate::LorentzVector& p4) { p4SVmethod_ = p4; }
  void setSVrefittedPrimaryVertexPos(const reco::Candidate::Point& pos) { primaryVertexPosSVrefitted_ = pos; }
  void setDecayVertexPosLeg1(const reco::Candidate::Point& pos) { decayVertexPosLeg1_ = pos; }
  void setDecayVertexPosLeg2(const reco::Candidate::Point& pos) { decayVertexPosLeg2_ = pos; }
  void setIsValidSolution(bool isValid) { isValidSolution_ = isValid; }
  void setMigradStatus(int result) { migradStatus_ = result; }
  void setSVfitStatus(int result) { svFitStatus_ = result; }
  void setMscale1(double mScale) { mScale1_ = mScale; }
  void setMscale2(double mScale) { mScale2_ = mScale; }
  void setLogLikelihood(double nll) { nll_ = nll; }
  void setLogLikelihoodMEt(double nll) { nllMEt_ = nll; }
  void setRank(int rank) { rank_ = rank; }

  /// visible four momenta computed by SV method
  /// (recomputed at secondary vertex)
  reco::Candidate::LorentzVector p4VisLeg1_;
  reco::Candidate::LorentzVector p4VisLeg2_;
  /// scaling factors for momenta of visible decay products
  double x1_;
  double x2_;
  /// four-momentum of di-tau system computed by SV method
  reco::Candidate::LorentzVector p4SVmethod_;
  /// positions of reconstructed primary event vertex 
  /// and of reconstructed tau decay vertices
  reco::Candidate::Point primaryVertexPosSVrefitted_;
  reco::Candidate::Point decayVertexPosLeg1_;
  reco::Candidate::Point decayVertexPosLeg2_;
  /// flag indicating whether or not solution for invariant mass 
  /// computed by SV algorithm is valid or not
  bool isValidSolution_;
  int migradStatus_;
  int svFitStatus_;
  /// mass scale parameters for visible tau decay products
  /// used internally by SV algorithm for constraining solutions
  double mScale1_;
  double mScale2_;
  /// log-likelihood value of solution
  /// (of missing Et fit only)
  double nll_;
  double nllMEt_;
  /// rank of solution
  /// (corresponding to index in list of a total of four possible solutions, 
  ///  sorted by log-likelihood so that the most probable solution has rank zero)
  int rank_;
};

std::ostream& operator<<(std::ostream& stream, const SVmassRecoSolution& solution);

#endif
