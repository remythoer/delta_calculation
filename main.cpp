#include "class_valeurs.h"
#include <map>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char *argv[])
{
  map<int, Valeurs> valeurs_list;
  map<int, vector<Double_t> > peak_list; 
  ifstream input_peak;
  input_peak.open("peak_ref.txt");
  string ligne;
  if(input_peak)
    {  
      while(getline(input_peak, ligne))
	{ 
	  istringstream iss (ligne);
      
	  Int_t peak, ref;
	  Double_t A2, A4;
	  Double_t Q2_ref_0, Q2_ref_90, Q2_ref_180, Q2_ref_270;
	  Double_t Q4_ref_0, Q4_ref_90, Q4_ref_180, Q4_ref_270;  
	  Double_t F2_1, F2_2, F2_3;
	  Double_t F4_1, F4_2, F4_3;
	  Double_t Q2_0, Q2_90, Q2_180, Q2_270;
	  Double_t Q4_0, Q4_90, Q4_180, Q4_270;

	  iss>>peak>>ref>>Q2_ref_0>>Q2_ref_90>>Q2_ref_180>>Q2_ref_270>>Q4_ref_0>>Q4_ref_90>>Q4_ref_180>>Q4_ref_270>>A2>>A4>>F2_1>>F2_2>>F2_3>>F4_1>>F4_2>>F4_3>>Q2_0>>Q2_90>>Q2_180>>Q2_270>>Q4_0>>Q4_90>>Q4_180>>Q4_270;

	  Valeurs temp_val(ref, A2, A4, Q2_ref_0, Q2_ref_90, Q2_ref_180, Q2_ref_270, Q4_ref_0, Q4_ref_90, Q4_ref_180, Q4_ref_270, F2_1, F2_2, F2_3, F4_1, F4_2, F4_3, Q2_0, Q2_90, Q2_180, Q2_270, Q4_0, Q4_90, Q4_180, Q4_270);

	  valeurs_list[peak]=temp_val;
      	}
    }
  else{cout<<"input_peak not open"<<endl;}
  input_peak.close();

  ifstream input_w;
  input_w.open("file_w_sum.dat");
  if(input_w)
    {
      while(getline(input_w, ligne))
	{
	  istringstream iss (ligne);
	  Double_t W0, W90, W180, W270;
	  vector<Double_t> W;
	  TString ref;
	  Int_t peak;
	  
	  iss>>ref>>W0>>W90>>W180>>W270;
	  ref=ref.Remove(0,5);
	  peak=atoi(ref);
	  
	  W.push_back(W0);
	  W.push_back(W90);
	  W.push_back(W180);
	  W.push_back(W270);
	  
	  peak_list[peak]=W; 
	  
	  getline(input_w, ligne);
	}
    }
  else{cout<<"input_w not open"<<endl;}
  input_w.close();
  
  ofstream output_delta;
  output_delta.open("delta.dat");
  
  for(map<int, vector<Double_t> >::iterator it=peak_list.begin(); it!=peak_list.end(); it++)
    {
      Int_t peak=it->first;
      map<int, Valeurs>::iterator search_peak = valeurs_list.find(peak);
      if(search_peak==valeurs_list.end()){continue;}
      else
	{
	  Int_t ref=valeurs_list[peak].get_ref();
	  map<int, vector<Double_t> >::iterator search_ref = peak_list.find(ref);
	  if(search_ref==peak_list.end())
	    {
	      cout<<"no data for the reference peak "<<ref<<endl;
	      continue;
	    }
	  else
	    {
	      vector<Double_t> W;
	      vector<Double_t> W_ref;
	      vector<Double_t> delta2;
	      vector<Double_t> delta4;
	      
	      W=peak_list[peak];
	      W_ref=peak_list[ref];
	     
	      
	      delta2=valeurs_list[peak].Delta_2(W_ref[0], W_ref[1], W_ref[2], W_ref[3], W[0], W[1], W[2], W[3]);
	      delta4=valeurs_list[peak].Delta_4(W_ref[0], W_ref[1], W_ref[2], W_ref[3], W[0], W[1], W[2], W[3]);

	      output_delta<<"peak "<<peak<<" ref "<<ref<<" delta2 +/- "<<delta2[0]<<" "<<delta2[1]<<" delta4 +/- "<<delta4[0]<<" "<<delta4[1]<<endl;
	    }

	}
    }
  output_delta.close();


}
