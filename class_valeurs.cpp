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

vector <Double_t> Valeurs::A2(Double_t W0_ref, Double_t W90_ref, Double_t W180_ref, Double_t W270_ref, Double_t W0, Double_t W90, Double_t W180, Double_t W270) const
{
  vector <Double_t> R2;
  vector <Double_t> R2_ref;
  vector <Double_t> R4;
  vector <Double_t> R4_ref;
  vector <Double_t> E2;
  vector <Double_t> E2_ref;
  vector <Double_t> E4;
  vector <Double_t> E4_ref;
  vector <Double_t> A2;

  R2.push_back((1-W0)*3/8+(W90-1));
  R2.push_back((1-W180)*3/8+(W90-1));
  R2.push_back((1-W180)*3/8+(W270-1));
  R2.push_back((1-W0)*3/8+(W270-1));

  R2_ref.push_back((1-W0_ref)*3/8+(W90_ref-1));
  R2_ref.push_back((1-W180_ref)*3/8+(W90_ref-1));
  R2_ref.push_back((1-W180_ref)*3/8+(W270_ref-1));
  R2_ref.push_back((1-W0_ref)*3/8+(W270_ref-1));

  R4.push_back(0.5*(1-W0)-(W90-1));
  R4.push_back(0.5*(1-W180)-(W90-1));
  R4.push_back(0.5*(1-W180)-(W270-1));
  R4.push_back(0.5*(1-W0)-(W270-1));

  R4_ref.push_back(0.5*(1-W0_ref)-(W90_ref-1));
  R4_ref.push_back(0.5*(1-W180_ref)-(W90_ref-1));
  R4_ref.push_back(0.5*(1-W180_ref)-(W270_ref-1));
  R4_ref.push_back(0.5*(1-W0_ref)-(W270_ref-1));

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
      A2.push_back(A_ref[0]*(R2[i]*(7+3*E4[i])+R4[i]*3*E4[i])*(-49/8-21*E4_ref[i]/8-28*E2_ref[i]/8)/((R2_ref[i]*(7+3*E4_ref[i])+R4_ref[i]*3*E4_ref[i])*(-49/8-21*E4[i]/8-28*E2[i]/8)));
    }

  return A2;
  // return A_ref[0]*R2/R2_ref;
}

vector <Double_t> Valeurs::A4(Double_t W0_ref, Double_t W90_ref, Double_t W180_ref, Double_t W270_ref, Double_t W0, Double_t W90, Double_t W180, Double_t W270) const
{
 vector <Double_t> R2;
  vector <Double_t> R2_ref;
  vector <Double_t> R4;
  vector <Double_t> R4_ref;
  vector <Double_t> E2;
  vector <Double_t> E2_ref;
  vector <Double_t> E4;
  vector <Double_t> E4_ref;
  vector <Double_t> A4;

  R2.push_back((1-W0)*3/8+(W90-1));
  R2.push_back((1-W180)*3/8+(W90-1));
  R2.push_back((1-W180)*3/8+(W270-1));
  R2.push_back((1-W0)*3/8+(W270-1));

  R2_ref.push_back((1-W0_ref)*3/8+(W90_ref-1));
  R2_ref.push_back((1-W180_ref)*3/8+(W90_ref-1));
  R2_ref.push_back((1-W180_ref)*3/8+(W270_ref-1));
  R2_ref.push_back((1-W0_ref)*3/8+(W270_ref-1));

  R4.push_back(0.5*(1-W0)-(W90-1));
  R4.push_back(0.5*(1-W180)-(W90-1));
  R4.push_back(0.5*(1-W180)-(W270-1));
  R4.push_back(0.5*(1-W0)-(W270-1));

  R4_ref.push_back(0.5*(1-W0_ref)-(W90_ref-1));
  R4_ref.push_back(0.5*(1-W180_ref)-(W90_ref-1));
  R4_ref.push_back(0.5*(1-W180_ref)-(W270_ref-1));
  R4_ref.push_back(0.5*(1-W0_ref)-(W270_ref-1));

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
      A4.push_back(A_ref[1]*(R4[i]*(7+4*E2[i])+R2[i]*4*E2[i])*(-49/8-21*E4_ref[i]/8-28*E2_ref[i]/8)/((R4_ref[i]*(7+4*E2_ref[i])+R2_ref[i]*4*E2_ref[i])*(-49/8-21*E4[i]/8-28*E2[i]/8)));
    }

  return A4;
  // return A_ref[1]*R4/R4_ref;
}

vector<vector<Double_t> > Valeurs::Delta_2(Double_t W0_ref, Double_t W90_ref, Double_t W180_ref, Double_t W270_ref, Double_t W0, Double_t W90, Double_t W180, Double_t W270) const
{
  vector<vector<Double_t> > delta;
  vector<Double_t> A2 = this->A2(W0_ref, W90_ref, W180_ref, W270_ref, W0, W90, W180, W270); 
  for(Int_t i=0; i<4; i++)
    {
      delta.push_back(vector<Double_t>(0));
      delta[i].push_back((-F2[1]+sqrt(F2[1]*F2[1]-(F2[2]-A2[i])*(F2[0]-A2[i])))/(F2[2]-A2[i]));
      delta[i].push_back((-F2[1]-sqrt(F2[1]*F2[1]-(F2[2]-A2[i])*(F2[0]-A2[i])))/(F2[2]-A2[i]));
    }
  return delta;
}

vector<vector<Double_t> > Valeurs::Delta_4(Double_t W0_ref, Double_t W90_ref, Double_t W180_ref, Double_t W270_ref, Double_t W0, Double_t W90, Double_t W180, Double_t W270) const
{
  vector<vector<Double_t> > delta;
  vector<Double_t> A4 = this->A4(W0_ref, W90_ref, W180_ref, W270_ref, W0, W90, W180, W270);
  for(Int_t i=0; i<4; i++)
    {
      delta.push_back(vector<Double_t>(0));
      delta[i].push_back((-F4[1]+sqrt(F4[1]*F4[1]-(F4[2]-A4[i])*(F4[0]-A4[i])))/(F4[2]-A4[i]));
      delta[i].push_back((-F4[1]-sqrt(F4[1]*F4[1]-(F4[2]-A4[i])*(F4[0]-A4[i])))/(F4[2]-A4[i]));
    }
  return delta;
}
