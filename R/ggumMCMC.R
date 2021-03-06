#' GGUM MCMC Sampler
#'
#' MCMC sampler for the generalized graded unfolding model (GGUM), utilizing
#' a Metropolis-Hastings algorithm
#'
#' \code{ggumMCMC} provides \code{R} implementation of an MCMC sampler for
#' the GGUM, based heavily on the algorithm given in de la Torre et al (2006);
#' though the package allows parameter estimation from \code{R},
#' the functions are actually written in \code{C++} to allow for reasonable
#' execution time.
#' Some details are provided in this help file, but please see the vignette
#' (via \code{vignette("bggum")}) for a full in-depth practical guide to
#' Bayesian estimation of GGUM parameters.
#'
#' Our sampler creates random initial values for the parameters of the model,
#' according to their prior distributions.
#' At each iteration, new parameter values are proposed
#' from a normal distribution with a mean of the current parameter value,
#' and the proposal is accepted probabilistically using a standard
#' Metropolis-Hastings acceptance ratio.
#' During burn-in, parameter draws are not stored.
#' Before burn-in, the standard deviation of the proposal densities can be
#' tuned to ensure that the acceptance rate is neither too high nor too low
#' (we keep the acceptance rate between 0.2 and 0.25).
#' This is done if proposal standard deviations are not provided as an argument
#' and \code{sd_tune_iterations} is greater than 0.
#'
#' @param data An integer matrix giving the response by each respondent to
#'   each item; note the item options should be of the form 0, 1, ...
#'   (an example of preparing data for analysis is given in the vignette,
#'   available via \code{vignette("bggum")})
#' @param sample_iterations An integer vector of length one;
#'   the number of iterations the sampler should store (default is 50000)
#' @param burn_iterations An integer vector of length one; the number of
#'   "burn-in" iterations to run, during which parameter draws are not
#'   stored (default is 50000).
#' @param tune_iterations An integer vector of length one; the number of
#'   iterations to use to tune the proposals before the burn-in period
#'   begins (default is 5000). If 0 is given, the proposals are not tuned.
#' @param flip_interval (Optional) If given, provides the number of iterations
#'   after which the sign of the thetas and deltas should be changed.
#'   For example, if \code{flip_interval = 1000},
#'   every 1000 iterations the theta and delta parameters will be multiplied
#'   by -1 (a valid parameter value change as discussed in Geyer (1991)).
#' @param proposal_sds (Optional) A list of length four where is element is a
#'   numeric vector giving standard deviations for the proposals;
#'   the first element should be a numeric vector with a standard deviation
#'   for the proposal for each respondent's theta parameter (the latent trait),
#'   the second a vector with a standard deviation for each item's alpha
#'   (discrimination) parameter, the third a vector with a standard deviation
#'   for each item's delta (location) parameter, and the fourth a vector with
#'   a standard deviation for each item's tau (option threshold) parameters.
#'   If not given, the standard deviations are all set to 1.0 before any
#'   tuning begins.
#' @param theta_init (Optional) A numeric vector giving an initial value
#'   for each respondent's theta parameter;
#'   if not given, the initial values are drawn from the prior distribution
#' @param alpha_init (Optional) A numeric vector giving an initial value
#'   for each item's alpha parameter;
#'   if not given, the initial values are drawn from the prior distribution
#' @param delta_init (Optional) A numeric vector giving an initial value
#'   for each item's delta parameter;
#'   if not given, the initial values are drawn from the prior distribution
#' @param tau_init (Optional) A list giving an initial value
#'   for each item's tau vector;
#'   if not given, the initial values are drawn from the prior distribution
#' @param theta_prior_params A numeric vector of length two;
#'   the mean and standard deviation of theta parameters' prior distribution
#'   (where the theta parameters have a normal prior; the default is 0 and 1)
#' @param alpha_prior_params A numeric vector of length four;
#'   the two shape parameters and a and b values for alpha parameters' prior
#'   distribution (where the alpha parameters have a four parameter beta prior;
#'   the default is 1.5, 1.5, 0.25, and 4)
#' @param delta_prior_params A numeric vector of length four;
#'   the two shape parameters and a and b values for delta parameters' prior
#'   distribution (where the delta parameters have a four parameter beta prior;
#'   the default is 2, 2, -5, and 5)
#' @param tau_prior_params A numeric vector of length four;
#'   the two shape parameters and a and b values for tau parameters' prior
#'   distribution (where the tau parameters have a four parameter beta prior;
#'   the default is 2, 2, -6, and 6)
#' @param return_sds A logical vector of length one; if TRUE, the proposal
#'   standard deviations are stored in an attribute of the returned object
#'   named "proposal_sds." The default is TRUE.
#'
#' @return A numeric matrix with \code{sample_iterations} rows
#'   and one column for every parameter of the model, so that each element
#'   of the matrix gives the value of a parameter for a particular iteration
#'   of the MCMC algorithm.
#'   The matrix will additionally have classes "ggum"
#'   (so that \code{\link{summary.ggum}} can be called on the result)
#'   and "mcmc" with an "mcpar" attribute
#'   (so that functions from the \code{coda} package can be used, e.g.
#'   to assess convergence).
#'   If \code{return_sds} is \code{TRUE}, the result also has an attribute
#'   "proposal_sds", which will be a list of length four giving the standard
#'   deviations of the proposal densities for the theta, alpha, delta, and
#'   tau parameters respectively.
#'
#' @seealso \code{\link{ggumProbability}}, \code{\link{ggumMC3}}
#'
#' @references de la Torre, Jimmy, Stephen Stark, and Oleksandr S.
#'   Chernyshenko. 2006. \dQuote{Markov Chain Monte Carlo Estimation of Item
#'   Parameters for the Generalized Graded Unfolding Model.} \emph{Applied
#'   Psychological Measurement} 30(3): 216--232.
#' @references Geyer, Charles J. 1991. \dQuote{Markov Chain Monte Carlo Maximum
#'   Likelihood.} In Computing Science and Statistics. Proceedings of the 23rd
#'   Symposium on the Interface, edited by E. M. Keramides, 156–63. Fairfax
#'   Station, VA: Interface Foundation.
#' @references Roberts, James S., John R. Donoghue, and James E. Laughlin. 2000.
#'   \dQuote{A General Item Response Theory Model for Unfolding Unidimensional
#'   Polytomous Responses.} \emph{Applied Psychological Measurement}
#'   24(1): 3--32.
#'
#' @examples
#' ## NOTE: This is a toy example just to demonstrate the function, which uses
#' ## a small dataset and an unreasonably low number of sampling interations.
#' ## For a longer practical guide on Bayesian estimation of GGUM parameters,
#' ## please see the vignette ( via vignette("bggum") ).
#' ## We'll simulate data to use for this example:
#' set.seed(123)
#' sim_data <- ggum_simulation(100, 10, 2)
#' ## Now we can generate posterior draws:
#' ## (for the purposes of example, we use 100 iterations,
#' ## though in practice you would use much more)
#' draws <- ggumMCMC(data = sim_data$response_matrix,
#'                   tune_iterations = 100,
#'                   burn_iterations = 100,
#'                   sample_iterations = 100)
#'
#' @export
ggumMCMC <- function(data, sample_iterations = 50000, burn_iterations = 50000,
                     tune_iterations = 5000, flip_interval = NA,
                     proposal_sds = NULL,
                     theta_init = NULL, alpha_init = NULL, delta_init = NULL,
                     tau_init = NULL, theta_prior_params = c(0.0, 1.0),
                     alpha_prior_params = c(1.5, 1.5, 0.25, 4.0),
                     delta_prior_params = c(2.0, 2.0, -5.0, 5.0),
                     tau_prior_params = c(2.0, 2.0, -6.0, 6.0),
                     return_sds = TRUE) {
    n <- nrow(data)
    m <- ncol(data)
    K <- integer(m)
    if ( is.na(flip_interval) ) {
        flip_interval <- sample_iterations + 1
    }
    for ( j in 1:m ) {
        K[j] = length(unique(na.omit(data[ , j])))
    }
    if ( is.null(theta_init) ) {
        theta_init <- init_thetas(n, theta_prior_params[1],
                                  theta_prior_params[2])
    }
    if ( is.null(alpha_init) ) {
        alpha_init <- init_alphas(m, alpha_prior_params[1],
                                  alpha_prior_params[2],
                                  alpha_prior_params[3],
                                  alpha_prior_params[4])
    }
    if ( is.null(delta_init) ) {
        delta_init <- init_deltas(m, delta_prior_params[1],
                                  delta_prior_params[2],
                                  delta_prior_params[3],
                                  delta_prior_params[4])
    }
    if ( is.null(tau_init) ) {
        tau_init <- init_taus(m, tau_prior_params[1], tau_prior_params[2],
                              tau_prior_params[3], tau_prior_params[4], K)
    }
    if ( is.null(proposal_sds) ) {
        if ( tune_iterations > 0 ) {
            proposal_sds <- tune_proposals(data, tune_iterations, K, theta_init,
                                           alpha_init, delta_init, tau_init,
                                           theta_prior_params, alpha_prior_params,
                                           delta_prior_params, tau_prior_params)
        }
        else {
            proposal_sds <- list(rep(1.0, n), rep(1.0, m), rep(1.0, m), rep(1.0, m))
        }
    }
    result <- .ggumMCMC(data, n, m, sample_iterations, burn_iterations,
                        flip_interval,
                        theta_init, alpha_init, delta_init, tau_init, K,
                        theta_prior_params[1], theta_prior_params[2],
                        alpha_prior_params[1], alpha_prior_params[2],
                        alpha_prior_params[3], alpha_prior_params[4],
                        delta_prior_params[1], delta_prior_params[2],
                        delta_prior_params[3], delta_prior_params[4],
                        tau_prior_params[1], tau_prior_params[2],
                        tau_prior_params[3], tau_prior_params[4],
                        proposal_sds)
    colnames(result) <- c(paste0("theta", 1:n),
                          paste0("alpha", 1:m),
                          paste0("delta", 1:m),
                          paste(paste0("tau", rep(1:m, times = K-1)),
                                unlist(c(sapply(K-1, seq_len))),
                                sep = "_"))
    class(result) <- c("ggum", "mcmc", class(result))
    attr(result, "mcpar") <- c(1, sample_iterations, 1)
    attr(result, "proposal_sds") <- "if"(return_sds, proposal_sds, NULL)
    return(result)
}
