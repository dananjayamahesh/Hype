#ifndef HEADER_OPTF_H
#define HEADER_OPTF_H

class OptFunctions{
   private:

   public:
   		int M;
   		int R;
   		int lrm;
   		int T;
   		int *Nr;

   	    OptFunctions(int M, int R, int lrm, int T, int * Nr);
   	    ~OptFunctions();
   		int revenueFunction();
   		double functionGaussian(double *x);
};

#endif /* HEADER_OPTF_H */