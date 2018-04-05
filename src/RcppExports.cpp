// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include "../inst/include/ggum.h"
#include <Rcpp.h>

using namespace Rcpp;

// ggumMC3
NumericMatrix ggumMC3(IntegerMatrix data, int iters, int N, int W, Nullable<NumericVector> Temps);
RcppExport SEXP _ggum_ggumMC3(SEXP dataSEXP, SEXP itersSEXP, SEXP NSEXP, SEXP WSEXP, SEXP TempsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< IntegerMatrix >::type data(dataSEXP);
    Rcpp::traits::input_parameter< int >::type iters(itersSEXP);
    Rcpp::traits::input_parameter< int >::type N(NSEXP);
    Rcpp::traits::input_parameter< int >::type W(WSEXP);
    Rcpp::traits::input_parameter< Nullable<NumericVector> >::type Temps(TempsSEXP);
    rcpp_result_gen = Rcpp::wrap(ggumMC3(data, iters, N, W, Temps));
    return rcpp_result_gen;
END_RCPP
}
// ggumMCMC
NumericMatrix ggumMCMC(IntegerMatrix responseMatrix, int iterations, int burn_iterations);
RcppExport SEXP _ggum_ggumMCMC(SEXP responseMatrixSEXP, SEXP iterationsSEXP, SEXP burn_iterationsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< IntegerMatrix >::type responseMatrix(responseMatrixSEXP);
    Rcpp::traits::input_parameter< int >::type iterations(iterationsSEXP);
    Rcpp::traits::input_parameter< int >::type burn_iterations(burn_iterationsSEXP);
    rcpp_result_gen = Rcpp::wrap(ggumMCMC(responseMatrix, iterations, burn_iterations));
    return rcpp_result_gen;
END_RCPP
}
// ggumProbability
NumericVector ggumProbability(NumericVector k, double theta, double alpha, double delta, NumericVector tau);
RcppExport SEXP _ggum_ggumProbability(SEXP kSEXP, SEXP thetaSEXP, SEXP alphaSEXP, SEXP deltaSEXP, SEXP tauSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type k(kSEXP);
    Rcpp::traits::input_parameter< double >::type theta(thetaSEXP);
    Rcpp::traits::input_parameter< double >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< double >::type delta(deltaSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type tau(tauSEXP);
    rcpp_result_gen = Rcpp::wrap(ggumProbability(k, theta, alpha, delta, tau));
    return rcpp_result_gen;
END_RCPP
}
// prob
double prob(const int choice, const double th, const double a, const double d, const NumericVector& t);
RcppExport SEXP _ggum_prob(SEXP choiceSEXP, SEXP thSEXP, SEXP aSEXP, SEXP dSEXP, SEXP tSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const int >::type choice(choiceSEXP);
    Rcpp::traits::input_parameter< const double >::type th(thSEXP);
    Rcpp::traits::input_parameter< const double >::type a(aSEXP);
    Rcpp::traits::input_parameter< const double >::type d(dSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type t(tSEXP);
    rcpp_result_gen = Rcpp::wrap(prob(choice, th, a, d, t));
    return rcpp_result_gen;
END_RCPP
}
// probCol
NumericVector probCol(const IntegerVector& choices, const NumericVector& thetas, const double a, const double d, const NumericVector& t);
RcppExport SEXP _ggum_probCol(SEXP choicesSEXP, SEXP thetasSEXP, SEXP aSEXP, SEXP dSEXP, SEXP tSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const IntegerVector& >::type choices(choicesSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type thetas(thetasSEXP);
    Rcpp::traits::input_parameter< const double >::type a(aSEXP);
    Rcpp::traits::input_parameter< const double >::type d(dSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type t(tSEXP);
    rcpp_result_gen = Rcpp::wrap(probCol(choices, thetas, a, d, t));
    return rcpp_result_gen;
END_RCPP
}
// probRow
NumericVector probRow(const IntegerVector& choices, const double th, const NumericVector& a, const NumericVector& d, const List& t);
RcppExport SEXP _ggum_probRow(SEXP choicesSEXP, SEXP thSEXP, SEXP aSEXP, SEXP dSEXP, SEXP tSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const IntegerVector& >::type choices(choicesSEXP);
    Rcpp::traits::input_parameter< const double >::type th(thSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type a(aSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type d(dSEXP);
    Rcpp::traits::input_parameter< const List& >::type t(tSEXP);
    rcpp_result_gen = Rcpp::wrap(probRow(choices, th, a, d, t));
    return rcpp_result_gen;
END_RCPP
}
// log_prob
double log_prob(const int choice, const double th, const double a, const double d, const NumericVector& t);
RcppExport SEXP _ggum_log_prob(SEXP choiceSEXP, SEXP thSEXP, SEXP aSEXP, SEXP dSEXP, SEXP tSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const int >::type choice(choiceSEXP);
    Rcpp::traits::input_parameter< const double >::type th(thSEXP);
    Rcpp::traits::input_parameter< const double >::type a(aSEXP);
    Rcpp::traits::input_parameter< const double >::type d(dSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type t(tSEXP);
    rcpp_result_gen = Rcpp::wrap(log_prob(choice, th, a, d, t));
    return rcpp_result_gen;
END_RCPP
}
// log_probCol
NumericVector log_probCol(const IntegerVector& choices, const NumericVector& thetas, const double a, const double d, const NumericVector& t);
RcppExport SEXP _ggum_log_probCol(SEXP choicesSEXP, SEXP thetasSEXP, SEXP aSEXP, SEXP dSEXP, SEXP tSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const IntegerVector& >::type choices(choicesSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type thetas(thetasSEXP);
    Rcpp::traits::input_parameter< const double >::type a(aSEXP);
    Rcpp::traits::input_parameter< const double >::type d(dSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type t(tSEXP);
    rcpp_result_gen = Rcpp::wrap(log_probCol(choices, thetas, a, d, t));
    return rcpp_result_gen;
END_RCPP
}
// log_probRow
NumericVector log_probRow(const IntegerVector& choices, const double th, const NumericVector& a, const NumericVector& d, const List& t);
RcppExport SEXP _ggum_log_probRow(SEXP choicesSEXP, SEXP thSEXP, SEXP aSEXP, SEXP dSEXP, SEXP tSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const IntegerVector& >::type choices(choicesSEXP);
    Rcpp::traits::input_parameter< const double >::type th(thSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type a(aSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type d(dSEXP);
    Rcpp::traits::input_parameter< const List& >::type t(tSEXP);
    rcpp_result_gen = Rcpp::wrap(log_probRow(choices, th, a, d, t));
    return rcpp_result_gen;
END_RCPP
}
// tune_proposals
List tune_proposals(const IntegerMatrix& responseMatrix, NumericVector& thetas, NumericVector& alphas, NumericVector& deltas, List& taus, const IntegerVector& K, const int burn_iters, int n, int m);
RcppExport SEXP _ggum_tune_proposals(SEXP responseMatrixSEXP, SEXP thetasSEXP, SEXP alphasSEXP, SEXP deltasSEXP, SEXP tausSEXP, SEXP KSEXP, SEXP burn_itersSEXP, SEXP nSEXP, SEXP mSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const IntegerMatrix& >::type responseMatrix(responseMatrixSEXP);
    Rcpp::traits::input_parameter< NumericVector& >::type thetas(thetasSEXP);
    Rcpp::traits::input_parameter< NumericVector& >::type alphas(alphasSEXP);
    Rcpp::traits::input_parameter< NumericVector& >::type deltas(deltasSEXP);
    Rcpp::traits::input_parameter< List& >::type taus(tausSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type K(KSEXP);
    Rcpp::traits::input_parameter< const int >::type burn_iters(burn_itersSEXP);
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< int >::type m(mSEXP);
    rcpp_result_gen = Rcpp::wrap(tune_proposals(responseMatrix, thetas, alphas, deltas, taus, K, burn_iters, n, m));
    return rcpp_result_gen;
END_RCPP
}
// update_alpha_MCMC
double update_alpha_MCMC(const IntegerVector& responses, const NumericVector& thetas, const double cv, const double delta, const NumericVector& taus, const double SD);
RcppExport SEXP _ggum_update_alpha_MCMC(SEXP responsesSEXP, SEXP thetasSEXP, SEXP cvSEXP, SEXP deltaSEXP, SEXP tausSEXP, SEXP SDSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const IntegerVector& >::type responses(responsesSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type thetas(thetasSEXP);
    Rcpp::traits::input_parameter< const double >::type cv(cvSEXP);
    Rcpp::traits::input_parameter< const double >::type delta(deltaSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type taus(tausSEXP);
    Rcpp::traits::input_parameter< const double >::type SD(SDSEXP);
    rcpp_result_gen = Rcpp::wrap(update_alpha_MCMC(responses, thetas, cv, delta, taus, SD));
    return rcpp_result_gen;
END_RCPP
}
// update_delta_MCMC
double update_delta_MCMC(const IntegerVector& responses, const NumericVector& thetas, const double alpha, const double cv, const NumericVector& taus, const double SD);
RcppExport SEXP _ggum_update_delta_MCMC(SEXP responsesSEXP, SEXP thetasSEXP, SEXP alphaSEXP, SEXP cvSEXP, SEXP tausSEXP, SEXP SDSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const IntegerVector& >::type responses(responsesSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type thetas(thetasSEXP);
    Rcpp::traits::input_parameter< const double >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< const double >::type cv(cvSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type taus(tausSEXP);
    Rcpp::traits::input_parameter< const double >::type SD(SDSEXP);
    rcpp_result_gen = Rcpp::wrap(update_delta_MCMC(responses, thetas, alpha, cv, taus, SD));
    return rcpp_result_gen;
END_RCPP
}
// update_tau_MCMC
double update_tau_MCMC(const int k, const IntegerVector& responses, const NumericVector& thetas, const double alpha, const double delta, const NumericVector& taus, const double SD);
RcppExport SEXP _ggum_update_tau_MCMC(SEXP kSEXP, SEXP responsesSEXP, SEXP thetasSEXP, SEXP alphaSEXP, SEXP deltaSEXP, SEXP tausSEXP, SEXP SDSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const int >::type k(kSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type responses(responsesSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type thetas(thetasSEXP);
    Rcpp::traits::input_parameter< const double >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< const double >::type delta(deltaSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type taus(tausSEXP);
    Rcpp::traits::input_parameter< const double >::type SD(SDSEXP);
    rcpp_result_gen = Rcpp::wrap(update_tau_MCMC(k, responses, thetas, alpha, delta, taus, SD));
    return rcpp_result_gen;
END_RCPP
}
// update_theta_MC3
double update_theta_MC3(const double cv, const IntegerVector& choices, const NumericVector& a, const NumericVector& d, const List& t, const double temp, const double SD);
RcppExport SEXP _ggum_update_theta_MC3(SEXP cvSEXP, SEXP choicesSEXP, SEXP aSEXP, SEXP dSEXP, SEXP tSEXP, SEXP tempSEXP, SEXP SDSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const double >::type cv(cvSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type choices(choicesSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type a(aSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type d(dSEXP);
    Rcpp::traits::input_parameter< const List& >::type t(tSEXP);
    Rcpp::traits::input_parameter< const double >::type temp(tempSEXP);
    Rcpp::traits::input_parameter< const double >::type SD(SDSEXP);
    rcpp_result_gen = Rcpp::wrap(update_theta_MC3(cv, choices, a, d, t, temp, SD));
    return rcpp_result_gen;
END_RCPP
}
// update_alpha_MC3
double update_alpha_MC3(const double cv, const IntegerVector& choices, const NumericVector& th, const double d, const NumericVector& t, const double temp, const double SD);
RcppExport SEXP _ggum_update_alpha_MC3(SEXP cvSEXP, SEXP choicesSEXP, SEXP thSEXP, SEXP dSEXP, SEXP tSEXP, SEXP tempSEXP, SEXP SDSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const double >::type cv(cvSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type choices(choicesSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type th(thSEXP);
    Rcpp::traits::input_parameter< const double >::type d(dSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type t(tSEXP);
    Rcpp::traits::input_parameter< const double >::type temp(tempSEXP);
    Rcpp::traits::input_parameter< const double >::type SD(SDSEXP);
    rcpp_result_gen = Rcpp::wrap(update_alpha_MC3(cv, choices, th, d, t, temp, SD));
    return rcpp_result_gen;
END_RCPP
}
// update_delta_MC3
double update_delta_MC3(const double cv, const IntegerVector& choices, const NumericVector& th, const double a, const NumericVector& t, const double temp, const double SD);
RcppExport SEXP _ggum_update_delta_MC3(SEXP cvSEXP, SEXP choicesSEXP, SEXP thSEXP, SEXP aSEXP, SEXP tSEXP, SEXP tempSEXP, SEXP SDSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const double >::type cv(cvSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type choices(choicesSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type th(thSEXP);
    Rcpp::traits::input_parameter< const double >::type a(aSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type t(tSEXP);
    Rcpp::traits::input_parameter< const double >::type temp(tempSEXP);
    Rcpp::traits::input_parameter< const double >::type SD(SDSEXP);
    rcpp_result_gen = Rcpp::wrap(update_delta_MC3(cv, choices, th, a, t, temp, SD));
    return rcpp_result_gen;
END_RCPP
}
// update_tau_MC3
double update_tau_MC3(const int k, const IntegerVector& choices, const NumericVector& th, const double a, const double d, const NumericVector& t, const double temp, const double SD);
RcppExport SEXP _ggum_update_tau_MC3(SEXP kSEXP, SEXP choicesSEXP, SEXP thSEXP, SEXP aSEXP, SEXP dSEXP, SEXP tSEXP, SEXP tempSEXP, SEXP SDSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const int >::type k(kSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type choices(choicesSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type th(thSEXP);
    Rcpp::traits::input_parameter< const double >::type a(aSEXP);
    Rcpp::traits::input_parameter< const double >::type d(dSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type t(tSEXP);
    Rcpp::traits::input_parameter< const double >::type temp(tempSEXP);
    Rcpp::traits::input_parameter< const double >::type SD(SDSEXP);
    rcpp_result_gen = Rcpp::wrap(update_tau_MC3(k, choices, th, a, d, t, temp, SD));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_ggum_ggumMC3", (DL_FUNC) &_ggum_ggumMC3, 5},
    {"_ggum_ggumMCMC", (DL_FUNC) &_ggum_ggumMCMC, 3},
    {"_ggum_ggumProbability", (DL_FUNC) &_ggum_ggumProbability, 5},
    {"_ggum_prob", (DL_FUNC) &_ggum_prob, 5},
    {"_ggum_probCol", (DL_FUNC) &_ggum_probCol, 5},
    {"_ggum_probRow", (DL_FUNC) &_ggum_probRow, 5},
    {"_ggum_log_prob", (DL_FUNC) &_ggum_log_prob, 5},
    {"_ggum_log_probCol", (DL_FUNC) &_ggum_log_probCol, 5},
    {"_ggum_log_probRow", (DL_FUNC) &_ggum_log_probRow, 5},
    {"_ggum_tune_proposals", (DL_FUNC) &_ggum_tune_proposals, 9},
    {"_ggum_update_alpha_MCMC", (DL_FUNC) &_ggum_update_alpha_MCMC, 6},
    {"_ggum_update_delta_MCMC", (DL_FUNC) &_ggum_update_delta_MCMC, 6},
    {"_ggum_update_tau_MCMC", (DL_FUNC) &_ggum_update_tau_MCMC, 7},
    {"_ggum_update_theta_MC3", (DL_FUNC) &_ggum_update_theta_MC3, 7},
    {"_ggum_update_alpha_MC3", (DL_FUNC) &_ggum_update_alpha_MC3, 7},
    {"_ggum_update_delta_MC3", (DL_FUNC) &_ggum_update_delta_MC3, 7},
    {"_ggum_update_tau_MC3", (DL_FUNC) &_ggum_update_tau_MC3, 8},
    {NULL, NULL, 0}
};

RcppExport void R_init_ggum(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
