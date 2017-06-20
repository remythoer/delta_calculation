#include "class_valeurs.h"

using namespace std;

Valeurs::Valeurs()
{}

Valeurs::Valeurs(Int_t ref, Double_t A2, Double_t A4, Double_t Q2_ref_0, Double_t Q2_ref_90, Double_t Q2_ref_180, Double_t Q2_ref_270, Double_t Q4_ref_0, Double_t Q4_ref_90, Double_t Q4_ref_180, Double_t Q4_ref_270, Double_t F2_1, Double_t F2_2, Double_t F2_3, Double_t F4_1, Double_t F4_2, Double_t F4_3, Double_t Q2_0, Double_t Q2_90, Double_t Q2_180, Double_t Q2_270, Double_t Q4_0, Double_t Q4_90, Double_t Q4_180, Double_t Q4_270)
{
  ref_peak=ref;
  A_ref.push_back(A2);
  A_ref.push_back(A4);
  Q2_ref.push_back(Q2_ref_0);
  Q2_ref.push_back(Q2_ref_90);
  Q2_ref.push_back(Q2_ref_180);
  Q2_ref.push_back(Q2_ref_270);
  Q4_ref.push_back(Q4_ref_0);
  Q4_ref.push_back(Q4_ref_90);
  Q4_ref.push_back(Q4_ref_180);
  Q4_ref.push_back(Q4_ref_270);
  F2.push_back(F2_1);
  F2.push_back(F2_2);
  F2.push_back(F2_3);
  F4.push_back(F4_1);
  F4.push_back(F4_2);
  F4.push_back(F4_3);
  Q2.push_back(Q2_0);
  Q2.push_back(Q2_90);
  Q2.push_back(Q2_180);
  Q2.push_back(Q2_270);
  Q4.push_back(Q4_0);
  Q4.push_back(Q4_90);
  Q4.push_back(Q4_180);
  Q4.push_back(Q4_270);
}

Valeurs::~Valeurs()
{}

Int_t Valeurs::get_ref() const
{
  return ref_peak;
}

vector <Double_t> Valeurs::A2(Double_t W0_ref, Double_t W90_ref, Double_t W180_ref, Double_t W270_ref, Double_t W0, Double_t W90, Double_t W180, Double_t W270, Double_t ErrW0_ref, Double_t ErrW90_ref, Double_t ErrW180_ref, Double_t ErrW270_ref, Double_t ErrW0, Double_t ErrW90, Double_t ErrW180, Double_t ErrW270, vector<Double_t> & SqErrA2) const
{
  vector <Double_t> R2;
  vector <Double_t> SqErrR2;
  vector <Double_t> R2_ref;
  vector <Double_t> SqErrR2_ref;
  vector <Double_t> R4;
  vector <Double_t> SqErrR4;
  vector <Double_t> R4_ref;
  vector <Double_t> SqErrR4_ref;
  vector <Double_t> E2;
  vector <Double_t> E2_ref;
  vector <Double_t> E4;
  vector <Double_t> E4_ref;
  vector <Double_t> A2;

  R2.push_back((1-W0)*3/8+(W90-1));
  R2.push_back((1-W180)*3/8+(W90-1));
  R2.push_back((1-W180)*3/8+(W270-1));
  R2.push_back((1-W0)*3/8+(W270-1));

  SqErrR2.push_back(9*ErrW0*ErrW0/64+ErrW90*ErrW90);
  SqErrR2.push_back(9*ErrW180*ErrW180/64+ErrW90*ErrW90);
  SqErrR2.push_back(9*ErrW180*ErrW180/64+ErrW270*ErrW270);
  SqErrR2.push_back(9*ErrW0*ErrW0/64+ErrW270*ErrW270);
  
  R2_ref.push_back((1-W0_ref)*3/8+(W90_ref-1));
  R2_ref.push_back((1-W180_ref)*3/8+(W90_ref-1));
  R2_ref.push_back((1-W180_ref)*3/8+(W270_ref-1));
  R2_ref.push_back((1-W0_ref)*3/8+(W270_ref-1));

  SqErrR2_ref.push_back(9*ErrW0_ref*ErrW0_ref/64+ErrW90_ref*ErrW90_ref);
  SqErrR2_ref.push_back(9*ErrW180_ref*ErrW180_ref/64+ErrW90_ref*ErrW90_ref);
  SqErrR2_ref.push_back(9*ErrW180_ref*ErrW180_ref/64+ErrW270_ref*ErrW270_ref);
  SqErrR2_ref.push_back(9*ErrW0_ref*ErrW0_ref/64+ErrW270_ref*ErrW270_ref);

  R4.push_back(0.5*(1-W0)-(W90-1));
  R4.push_back(0.5*(1-W180)-(W90-1));
  R4.push_back(0.5*(1-W180)-(W270-1));
  R4.push_back(0.5*(1-W0)-(W270-1));

  SqErrR4.push_back(ErrW0*ErrW0/4+ErrW90*ErrW90);
  SqErrR4.push_back(ErrW180*ErrW180/4+ErrW90*ErrW90);
  SqErrR4.push_back(ErrW180*ErrW180/4+ErrW270*ErrW270);
  SqErrR4.push_back(ErrW0*ErrW0/4+ErrW270*ErrW270);

  R4_ref.push_back(0.5*(1-W0_ref)-(W90_ref-1));
  R4_ref.push_back(0.5*(1-W180_ref)-(W90_ref-1));
  R4_ref.push_back(0.5*(1-W180_ref)-(W270_ref-1));
  R4_ref.push_back(0.5*(1-W0_ref)-(W270_ref-1));

  SqErrR4_ref.push_back(ErrW0_ref*ErrW0_ref/4+ErrW90_ref*ErrW90_ref);
  SqErrR4_ref.push_back(ErrW180_ref*ErrW180_ref/4+ErrW90_ref*ErrW90_ref);
  SqErrR4_ref.push_back(ErrW180_ref*ErrW180_ref/4+ErrW270_ref*ErrW270_ref);
  SqErrR4_ref.push_back(ErrW0_ref*ErrW0_ref/4+ErrW270_ref*ErrW270_ref);

  E2.push_back((Q2[1]-Q2[0])/Q2[0]);
  E2.push_back((Q2[1]-Q2[2])/Q2[2]);
  E2.push_back((Q2[3]-Q2[2])/Q2[2]);
  E2.push_back((Q2[3]-Q2[0])/Q2[0]);

  E4.push_back((Q4[1]-Q4[0])/Q4[0]);
  E4.push_back((Q4[1]-Q4[2])/Q4[2]);
  E4.push_back((Q4[3]-Q4[2])/Q4[2]);
  E4.push_back((Q4[3]-Q4[0])/Q4[0]);

  E2_ref.push_back((Q2_ref[1]-Q2_ref[0])/Q2_ref[0]);
  E2_ref.push_back((Q2_ref[1]-Q2_ref[2])/Q2_ref[2]);
  E2_ref.push_back((Q2_ref[3]-Q2_ref[2])/Q2_ref[2]);
  E2_ref.push_back((Q2_ref[3]-Q2_ref[0])/Q2_ref[0]);

  E4_ref.push_back((Q4_ref[1]-Q4_ref[0])/Q4_ref[0]);
  E4_ref.push_back((Q4_ref[1]-Q4_ref[2])/Q4_ref[2]);
  E4_ref.push_back((Q4_ref[3]-Q4_ref[2])/Q4_ref[2]);
  E4_ref.push_back((Q4_ref[3]-Q4_ref[0])/Q4_ref[0]);

  for(Int_t i=0; i<4; i++)
    {
      Double_t B=(-49/8-21*E4_ref[i]/8-28*E2_ref[i]/8)/(-49/8-21*E4[i]/8-28*E2[i]/8);
      A2.push_back(A_ref[0]*(R2[i]*(7+3*E4[i])+R4[i]*3*E4[i])*B/(R2_ref[i]*(7+3*E4_ref[i])+R4_ref[i]*3*E4_ref[i]));
      SqErrA2.push_back((A_ref[0]*A_ref[0]*B*B*(SqErrR2[i]*(7+3*E4[i])*(7+3*E4[i])+SqErrR4[i]*9*E4[i]*E4[i])+A2[i]*A2[i]*((7+3*E4_ref[i])*(7+3*E4_ref[i])*SqErrR2_ref[i]+9*E4_ref[i]*E4_ref[i]*SqErrR4_ref[i]))/((R2_ref[i]*(7+3*E4_ref[i])+R4_ref[i]*3*E4_ref[i])*(R2_ref[i]*(7+3*E4_ref[i])+R4_ref[i]*3*E4_ref[i])));
     
    }

  return A2;
  // return A_ref[0]*R2/R2_ref;
}

vector <Double_t> Valeurs::A4(Double_t W0_ref, Double_t W90_ref, Double_t W180_ref, Double_t W270_ref, Double_t W0, Double_t W90, Double_t W180, Double_t W270, Double_t ErrW0_ref, Double_t ErrW90_ref, Double_t ErrW180_ref, Double_t ErrW270_ref, Double_t ErrW0, Double_t ErrW90, Double_t ErrW180, Double_t ErrW270, vector<Double_t> & SqErrA4) const
{
  vector <Double_t> R2;
  vector <Double_t> SqErrR2;
  vector <Double_t> R2_ref;
  vector <Double_t> SqErrR2_ref;
  vector <Double_t> R4;
  vector <Double_t> SqErrR4;
  vector <Double_t> R4_ref;
  vector <Double_t> SqErrR4_ref;
  vector <Double_t> E2;
  vector <Double_t> E2_ref;
  vector <Double_t> E4;
  vector <Double_t> E4_ref;
  vector <Double_t> A4;

  R2.push_back((1-W0)*3/8+(W90-1));
  R2.push_back((1-W180)*3/8+(W90-1));
  R2.push_back((1-W180)*3/8+(W270-1));
  R2.push_back((1-W0)*3/8+(W270-1));

  SqErrR2.push_back(9*ErrW0*ErrW0/64+ErrW90*ErrW90);
  SqErrR2.push_back(9*ErrW180*ErrW180/64+ErrW90*ErrW90);
  SqErrR2.push_back(9*ErrW180*ErrW180/64+ErrW270*ErrW270);
  SqErrR2.push_back(9*ErrW0*ErrW0/64+ErrW270*ErrW270);

  R2_ref.push_back((1-W0_ref)*3/8+(W90_ref-1));
  R2_ref.push_back((1-W180_ref)*3/8+(W90_ref-1));
  R2_ref.push_back((1-W180_ref)*3/8+(W270_ref-1));
  R2_ref.push_back((1-W0_ref)*3/8+(W270_ref-1));

  SqErrR2_ref.push_back(9*ErrW0_ref*ErrW0_ref/64+ErrW90_ref*ErrW90_ref);
  SqErrR2_ref.push_back(9*ErrW180_ref*ErrW180_ref/64+ErrW90_ref*ErrW90_ref);
  SqErrR2_ref.push_back(9*ErrW180_ref*ErrW180_ref/64+ErrW270_ref*ErrW270_ref);
  SqErrR2_ref.push_back(9*ErrW0_ref*ErrW0_ref/64+ErrW270_ref*ErrW270_ref);

  R4.push_back(0.5*(1-W0)-(W90-1));
  R4.push_back(0.5*(1-W180)-(W90-1));
  R4.push_back(0.5*(1-W180)-(W270-1));
  R4.push_back(0.5*(1-W0)-(W270-1));

  SqErrR4.push_back(ErrW0*ErrW0/4+ErrW90*ErrW90);
  SqErrR4.push_back(ErrW180*ErrW180/4+ErrW90*ErrW90);
  SqErrR4.push_back(ErrW180*ErrW180/4+ErrW270*ErrW270);
  SqErrR4.push_back(ErrW0*ErrW0/4+ErrW270*ErrW270);

  R4_ref.push_back(0.5*(1-W0_ref)-(W90_ref-1));
  R4_ref.push_back(0.5*(1-W180_ref)-(W90_ref-1));
  R4_ref.push_back(0.5*(1-W180_ref)-(W270_ref-1));
  R4_ref.push_back(0.5*(1-W0_ref)-(W270_ref-1));

  SqErrR4_ref.push_back(ErrW0_ref*ErrW0_ref/4+ErrW90_ref*ErrW90_ref);
  SqErrR4_ref.push_back(ErrW180_ref*ErrW180_ref/4+ErrW90_ref*ErrW90_ref);
  SqErrR4_ref.push_back(ErrW180_ref*ErrW180_ref/4+ErrW270_ref*ErrW270_ref);
  SqErrR4_ref.push_back(ErrW0_ref*ErrW0_ref/4+ErrW270_ref*ErrW270_ref);

  E2.push_back((Q2[1]-Q2[0])/Q2[0]);
  E2.push_back((Q2[1]-Q2[2])/Q2[2]);
  E2.push_back((Q2[3]-Q2[2])/Q2[2]);
  E2.push_back((Q2[3]-Q2[0])/Q2[0]);

  E4.push_back((Q4[1]-Q4[0])/Q4[0]);
  E4.push_back((Q4[1]-Q4[2])/Q4[2]);
  E4.push_back((Q4[3]-Q4[2])/Q4[2]);
  E4.push_back((Q4[3]-Q4[0])/Q4[0]);

  E2_ref.push_back((Q2_ref[1]-Q2_ref[0])/Q2_ref[0]);
  E2_ref.push_back((Q2_ref[1]-Q2_ref[2])/Q2_ref[2]);
  E2_ref.push_back((Q2_ref[3]-Q2_ref[2])/Q2_ref[2]);
  E2_ref.push_back((Q2_ref[3]-Q2_ref[0])/Q2_ref[0]);

  E4_ref.push_back((Q4_ref[1]-Q4_ref[0])/Q4_ref[0]);
  E4_ref.push_back((Q4_ref[1]-Q4_ref[2])/Q4_ref[2]);
  E4_ref.push_back((Q4_ref[3]-Q4_ref[2])/Q4_ref[2]);
  E4_ref.push_back((Q4_ref[3]-Q4_ref[0])/Q4_ref[0]);

  for(Int_t i=0; i<4; i++)
    {
      Double_t B=(-49/8-21*E4_ref[i]/8-28*E2_ref[i]/8)/(-49/8-21*E4[i]/8-28*E2[i]/8);
      A4.push_back(A_ref[1]*(R4[i]*(7+4*E2[i])+R2[i]*4*E2[i])*(-49/8-21*E4_ref[i]/8-28*E2_ref[i]/8)/((R4_ref[i]*(7+4*E2_ref[i])+R2_ref[i]*4*E2_ref[i])*(-49/8-21*E4[i]/8-28*E2[i]/8)));
      SqErrA4.push_back((A_ref[1]*A_ref[1]*B*B*(SqErrR4[i]*(7+4*E2[i])*(7+4*E2[i])+SqErrR2[i]*16*E2[i]*E2[i])+A4[i]*A4[i]*((7+4*E2_ref[i])*(7+4*E2_ref[i])*SqErrR4_ref[i]+16*E2_ref[i]*E2_ref[i]*SqErrR2_ref[i]))/((R4_ref[i]*(7+4*E2_ref[i])+R2_ref[i]*4*E2_ref[i])*(R4_ref[i]*(7+4*E2_ref[i])+R2_ref[i]*4*E2_ref[i])));
    }

  return A4;
  // return A_ref[1]*R4/R4_ref;
}

vector<vector<Double_t> > Valeurs::Delta_2(Double_t W0_ref, Double_t W90_ref, Double_t W180_ref, Double_t W270_ref, Double_t W0, Double_t W90, Double_t W180, Double_t W270, Double_t ErrW0_ref, Double_t ErrW90_ref, Double_t ErrW180_ref, Double_t ErrW270_ref, Double_t ErrW0, Double_t ErrW90, Double_t ErrW180, Double_t ErrW270, vector<vector<Double_t> > & ErrDelta2) const
{
  vector<vector<Double_t> > delta;
  vector<Double_t> SqErrA2;
  vector<Double_t> A2 = this->A2(W0_ref, W90_ref, W180_ref, W270_ref, W0, W90, W180, W270, ErrW0_ref, ErrW90_ref, ErrW180_ref, ErrW270_ref, ErrW0, ErrW90, ErrW180, ErrW270, SqErrA2); 
  for(Int_t i=0; i<4; i++)
    {
      delta.push_back(vector<Double_t>(0));
      delta[i].push_back((-F2[1]+sqrt(F2[1]*F2[1]-(F2[2]-A2[i])*(F2[0]-A2[i])))/(F2[2]-A2[i]));
      delta[i].push_back((-F2[1]-sqrt(F2[1]*F2[1]-(F2[2]-A2[i])*(F2[0]-A2[i])))/(F2[2]-A2[i]));
      ErrDelta2.push_back(vector<Double_t>(0));
      ErrDelta2[i].push_back(sqrt(SqErrA2[i]*((delta[i][0]+((F2[0]-A2[i]+F2[2]-A2[i])/(2*sqrt(F2[1]*F2[1]-(F2[2]-A2[i])*(F2[0]-A2[i])))))/(F2[2]-A2[i]))*((delta[i][0]+((F2[0]-A2[i]+F2[2]-A2[i])/(2*sqrt(F2[1]*F2[1]-(F2[2]-A2[i])*(F2[0]-A2[i])))))/(F2[2]-A2[i]))));
      ErrDelta2[i].push_back(sqrt(SqErrA2[i]*((delta[i][1]+(-(F2[0]-A2[i]+F2[2]-A2[i])/(2*sqrt(F2[1]*F2[1]-(F2[2]-A2[i])*(F2[0]-A2[i])))))/(F2[2]-A2[i]))*((delta[i][1]+(-(F2[0]-A2[i]+F2[2]-A2[i])/(2*sqrt(F2[1]*F2[1]-(F2[2]-A2[i])*(F2[0]-A2[i])))))/(F2[2]-A2[i]))));
      
    }
  return delta;
}

vector<vector<Double_t> > Valeurs::Delta_4(Double_t W0_ref, Double_t W90_ref, Double_t W180_ref, Double_t W270_ref, Double_t W0, Double_t W90, Double_t W180, Double_t W270, Double_t ErrW0_ref, Double_t ErrW90_ref, Double_t ErrW180_ref, Double_t ErrW270_ref, Double_t ErrW0, Double_t ErrW90, Double_t ErrW180, Double_t ErrW270, vector<vector<Double_t> > & ErrDelta4) const
{
  vector<vector<Double_t> > delta;
  vector<Double_t> SqErrA4;
  vector<Double_t> A4 = this->A4(W0_ref, W90_ref, W180_ref, W270_ref, W0, W90, W180, W270, ErrW0_ref, ErrW90_ref, ErrW180_ref, ErrW270_ref, ErrW0, ErrW90, ErrW180, ErrW270, SqErrA4);
  for(Int_t i=0; i<4; i++)
    {
      delta.push_back(vector<Double_t>(0));
      delta[i].push_back((-F4[1]+sqrt(F4[1]*F4[1]-(F4[2]-A4[i])*(F4[0]-A4[i])))/(F4[2]-A4[i]));
      delta[i].push_back((-F4[1]-sqrt(F4[1]*F4[1]-(F4[2]-A4[i])*(F4[0]-A4[i])))/(F4[2]-A4[i]));
      ErrDelta4.push_back(vector<Double_t>(0));
      ErrDelta4[i].push_back(sqrt(SqErrA4[i]*((delta[i][0]+((F4[0]-A4[i]+F4[2]-A4[i])/(2*sqrt(F4[1]*F4[1]-(F4[2]-A4[i])*(F4[0]-A4[i])))))/(F4[2]-A4[i]))*((delta[i][0]+((F4[0]-A4[i]+F4[2]-A4[i])/(2*sqrt(F4[1]*F4[1]-(F4[2]-A4[i])*(F4[0]-A4[i])))))/(F4[2]-A4[i]))));
      ErrDelta4[i].push_back(sqrt(SqErrA4[i]*((delta[i][1]+(-(F4[0]-A4[i]+F4[2]-A4[i])/(2*sqrt(F4[1]*F4[1]-(F4[2]-A4[i])*(F4[0]-A4[i])))))/(F4[2]-A4[i]))*((delta[i][1]+(-(F4[0]-A4[i]+F4[2]-A4[i])/(2*sqrt(F4[1]*F4[1]-(F4[2]-A4[i])*(F4[0]-A4[i])))))/(F4[2]-A4[i]))));
    }
  return delta;
}
