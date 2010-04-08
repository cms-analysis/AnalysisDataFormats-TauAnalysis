#ifndef __AnalysisDataFormats_TauAnalysis_CollinearApproxCompatibility_h__
#define __AnalysisDataFormats_TauAnalysis_CollinearApproxCompatibility_h__

/** \class CollinearApproxCompatibility
 *
 * Compatibility of observed tau decay products
 * with M --> tau+ tau- mass hypothesis 
 * of decay of resonance of mass M into tau-pairs,
 * reconstructed via collinear approximation
 * 
 * \authors Christian Veelken (UC Davis)
 *
 * \version $Revision: 1.1 $
 *
 * $Id: CollinearApproxCompatibility.h,v 1.1 2010/03/31 16:22:40 veelken Exp $
 *
 */

#include <iostream>

class CollinearApproxCompatibility
{
 public:

  /// default constructor
  CollinearApproxCompatibility() {}

  /// destructor
  ~CollinearApproxCompatibility() {}

  /// get data-members
  int minuitFitStatus() const { return minuitFitStatus_; }
  double minuitFitChi2() const { return minuitFitChi2_; }
  double x1() const { return x1_; }
  double x1Err() const { return x1Err_; }
  double x2() const { return x2_; }
  double x2Err() const { return x2Err_; }
  
 private:
  
  /// allow only SVmassRecoFitter to change values of data-members
  friend class CollinearApproxFitter; 

  /// set data-members
  void setMinuitStatus(int status) { minuitFitStatus_ = status; }
  void setMinuitChi2(double chi2) { minuitFitChi2_ = chi2; }
  void setX1(double x) { x1_ = x; }
  void setX1Err(double xErr) { x1Err_ = xErr; }
  void setX2(double x) { x2_ = x; }
  void setX2Err(double xErr) { x2Err_ = xErr; }

  /// data-members
  int minuitFitStatus_;
  double minuitFitChi2_;
  double x1_;
  double x1Err_;
  double x2_;
  double x2Err_;
};

std::ostream& operator<<(std::ostream& stream, const CollinearApproxCompatibility& collinearApproxCompatibility);

#endif
