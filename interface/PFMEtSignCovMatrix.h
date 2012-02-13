#ifndef __AnalysisDataFormats_TauAnalysis_PFMEtSignCovMatrix_h__
#define __AnalysisDataFormats_TauAnalysis_PFMEtSignCovMatrix_h__

/** \class PFMEtSignCovMatrix
 *
 * Covariance matrix representing expected MET resolution,
 * computed by (PF)MEt significance algorithm
 * (see CMS AN-10/400 for description of the algorithm)
 * 
 * \author Christian Veelken, UC Davis
 *
 * \version $Revision: 1.2 $
 *
 * $Id: PFMEtSignCovMatrix.h,v 1.2 2009/07/16 14:13:33 veelken Exp $
 *
 */

#include "FWCore/Utilities/interface/Exception.h"

#include <TMatrixD.h>

class PFMEtSignCovMatrix : public TMatrixD
{
 public:
  /// constructor 
  explicit PFMEtSignCovMatrix() 
    : TMatrixD(2,2)
  {}
  explicit PFMEtSignCovMatrix(const PFMEtSignCovMatrix& bluePrint) 
    : TMatrixD(bluePrint)
  {}  
  explicit PFMEtSignCovMatrix(const TMatrixD& bluePrint) 
    : TMatrixD(bluePrint)
  {
    if ( !(GetNrows() == 2 && GetNcols() == 2) )
      throw cms::Exception("PFMEtSignCovMatrix")
	<< "Matrix must have 2x2 rows and colums !!\n";
  }

  /// destructor
  ~PFMEtSignCovMatrix() {}
};

#endif
