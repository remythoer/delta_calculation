#include "class_valeurs.h"
#include <map>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
  ifstream input_peak;
  input_peak.open("peak_ref.txt");
  
  Int_t peak, ref;
  Double_t A2, A4;
  Double_t Q2_ref_0, Q2_ref_90, Q2_ref_180, Q2_ref_270;
  Double_t Q4_ref_0, Q4_ref_90, Q4_ref_180, Q4_ref_270;  
  



  ifstream input_w;
  input_w.open("file_w_sum.dat");
  input_w.close();
  



}
