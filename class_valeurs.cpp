#include "class_valeurs.h"

using namespace std;

Valeurs::Valeurs()
{}

Valeurs::Valeurs(Int_t ref, Double_t A2, Double_t A4, Double_t Q2_ref_0, Double_t Q2_ref_90, Double_t Q2_ref_180, Double_t Q2_ref_270, Double_t Q4_ref_0, Double_t Q4_ref_90, Double_t Q4_ref_180, Double_t Q4_ref_270, Double_t F2_1, Double_t F2_2, Double_t F2_3, Double_t F4_1, Double_t F4_2, Double_t F4_3, Double_t Q2_0, Double_t Q2_90, Double_t Q2_180, Double_t Q2_270, Double_t Q4_0, Double_t Q4_90, Double_t Q4_180, Double_t Q4_270)
{
  ref_peak=ref;
  A_ref[0]=A2;
  A_ref[1]=A4;
  Q2_ref[0]=Q2_ref_0;
  Q2_ref[1]=Q2_ref_90;
  Q2_ref[2]=Q2_ref_180;
  Q2_ref[3]=Q2_ref_270;
  Q4_ref[0]=Q4_ref_0;
  Q4_ref[1]=Q4_ref_90;
  Q4_ref[2]=Q4_ref_180;
  Q4_ref[3]=Q4_ref_270;
  F2[0]=F2_1;
  F2[1]=F2_2;
  F2[2]=F2_3;
  F4[0]=F4_1;
  F4[1]=F4_2;
  F4[2]=F4_3;
  Q2[0]=Q2_0;
  Q2[1]=Q2_90;
  Q2[2]=Q2_180;
  Q2[3]=Q2_270;
  Q4[0]=Q4_0;
  Q4[1]=Q4_90;
  Q4[2]=Q4_180;
  Q4[3]=Q4_270;
}

Valeurs::~Valeurs()
{}

Double_t Valeurs::A2(Double_t W0_ref, Double_t W90_ref, Double_t W180_ref, Double_t W270_ref, Double_t W0, Double_t W90, Double_t W180, Double_t W270) const
{
  Double_t R2 = (1-W0)*3/8+(W90-1);
  Double_t R2_ref = (1-W0_ref)*3/8+(W90_ref-1);
  Double_t R4 = 0.5*(1-W0)-(W90-1);
  Double_t R4_ref = 0.5*(1-W0_ref)-(W90_ref-1);
  Double_t E2 = (Q2[1]-Q2[0])/Q2[0];
  Double_t E4 = (Q4[1]-Q4[0])/Q4[0];
  Double_t E2_ref = (Q2_ref[1]-Q2_ref[0])/Q2_ref[0];
  Double_t E4_ref = (Q4_ref[1]-Q4_ref[0])/Q4_ref[0];
  return A_ref[0]*(R2*(7+3*E4)+R4*3*E4)*(-49/8-21*E4_ref/8-28*E2_ref/8)/((R2_ref*(7+3*E4_ref)+R4_ref*3*E4_ref)*(-49/8-21*E4/8-28*E2/8));
}

Double_t Valeurs::A4(Double_t W0_ref, Double_t W90_ref, Double_t W180_ref, Double_t W270_ref, Double_t W0, Double_t W90, Double_t W180, Double_t W270) const
{
  Double_t R2 = (1-W0)*3/8+(W90-1);
  Double_t R2_ref = (1-W0_ref)*3/8+(W90_ref-1);
  Double_t R4 = 0.5*(1-W0)-(W90-1);
  Double_t R4_ref = 0.5*(1-W0_ref)-(W90_ref-1);
  Double_t E2 = (Q2[1]-Q2[0])/Q2[0];
  Double_t E4 = (Q4[1]-Q4[0])/Q4[0];
  Double_t E2_ref = (Q2_ref[1]-Q2_ref[0])/Q2_ref[0];
  Double_t E4_ref = (Q4_ref[1]-Q4_ref[0])/Q4_ref[0];
  return A_ref[1]*(R4*(7+4*E2)+R2*4*E2)*(-49/8-21*E4_ref/8-28*E2_ref/8)/((R4_ref*(7+4*E2_ref)+R2_ref*4*E2_ref)*(-49/8-21*E4/8-28*E2/8));
}

