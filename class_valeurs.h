#ifndef __class_valeurs_h__
#define __class_valeurs_h__ 1

#include <vector>
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <stdlib.h>

#include "TROOT.h"

/// \file class_valeurs.h
/// \brief Valeurs

using namespace std;

/// \class Valeurs
/// \brief Class containing all the needed values to compute delta
class Valeurs
{
private :
Int_t ref_peak; ///< Energy of reference peak
vector<Double_t> A_ref; ///< A coefficients for the reference peak
vector<Double_t> Q2_ref; ///< Q2 coefficients for the reference peak
vector<Double_t> Q4_ref; ///< Q4 coefficients for the reference peak
vector<Double_t> F2; ///< F2 coefficients for the peak of interest
vector<Double_t> F4; ///< F4 coefficients for the peak of interest
vector<Double_t> Q2; ///< Q2 coefficients for the peak of interest
vector<Double_t> Q4; ///< Q4 coefficients for the peak of interest

public :
/// \brief Default constructor
Valeurs();
/// \brief Surdefine constructor
Valeurs(Int_t ref, Double_t A2, Double_t A4, Double_t Q2_ref_0, Double_t Q2_ref_90, Double_t Q2_ref_180, Double_t Q2_ref_270, Double_t Q4_ref_0, Double_t Q4_ref_90, Double_t Q4_ref_180, Double_t Q4_ref_270, Double_t F2_1, Double_t F2_2, Double_t F2_3, Double_t F4_1, Double_t F4_2, Double_t F4_3, Double_t Q2_0, Double_t Q2_90, Double_t Q2_180, Double_t Q2_270, Double_t Q4_0, Double_t Q4_90, Double_t Q4_180, Double_t Q4_270);
/// \brief Default destructor
~Valeurs();

/// \return ref_peak
Int_t get_ref() const;

/// \return A2 coefficient 
vector <Double_t> A2(Double_t W0_ref, Double_t W90_ref, Double_t W180_ref, Double_t W270_ref, Double_t W0, Double_t W90, Double_t W180, Double_t W270) const;

/// \return A4 coefficient 
vector <Double_t> A4(Double_t W0_ref, Double_t W90_ref, Double_t W180_ref, Double_t W270_ref, Double_t W0, Double_t W90, Double_t W180, Double_t W270) const;

/// \return delta2 +/- coefficient
vector<vector<Double_t> > Delta_2(Double_t W0_ref, Double_t W90_ref, Double_t W180_ref, Double_t W270_ref, Double_t W0, Double_t W90, Double_t W180, Double_t W270) const;

/// \return delta4 +/- coefficient
vector<vector<Double_t> > Delta_4(Double_t W0_ref, Double_t W90_ref, Double_t W180_ref, Double_t W270_ref, Double_t W0, Double_t W90, Double_t W180, Double_t W270) const;

};

#endif
