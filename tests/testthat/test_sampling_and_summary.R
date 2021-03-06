context("GGUM posterior sampling and summarization")

n <- 100
m <- 10
K <- 2
set.seed(123)
ggum_sim   <- ggum_simulation(n, m, K)
response_matrix <- ggum_sim$response_matrix
response_matrix[1, 1] <- NA
mcmc_chain <- ggumMCMC(response_matrix,
                       tune_iterations = 100,
                       burn_iterations = 100,
                       sample_iterations = 100)
mcmc_chain <- ggumMCMC(response_matrix,
                       tune_iterations = 0,
                       burn_iterations = 100,
                       sample_iterations = 100)
mc3_chain  <- ggumMC3(response_matrix,
                      sd_tune_iterations = 100,
                      burn_iterations = 100,
                      sample_iterations = 100,
                      temps = c(1, 0.999),
                      theta_init = ggum_sim$theta,
                      alpha_init = ggum_sim$alpha,
                      delta_init = ggum_sim$delta,
                      tau_init = ggum_sim$tau)
mc3_chain  <- ggumMC3(response_matrix,
                      sd_tune_iterations = 100,
                      burn_iterations = 100,
                      sample_iterations = 100,
                      n_temps = 2,
                      temp_tune_iterations = 100,
                      temp_n_draws = 50)
mc3_chain  <- ggumMC3(response_matrix,
                      sd_tune_iterations = 0,
                      burn_iterations = 100,
                      sample_iterations = 100,
                      n_temps = 2,
                      optimize_temps = FALSE)
processed_chain <- post_process(mc3_chain, which.min(ggum_sim$theta), "-")
mcmc_summary  <- summary(mcmc_chain)
list_summary  <- summary(list(mc3_chain, mc3_chain))
list_summary2 <- summary(list(mc3_chain, mc3_chain), combine = FALSE)
list_summary3 <- summary(list(1:10))

test_that("ggumMCMC() produces expected output", {
    expect_s3_class(mcmc_chain, "ggum")
    expect_s3_class(mcmc_chain, "mcmc")
    expect_equal(colnames(mcmc_chain),
                 c(paste0("theta", 1:n), paste0("alpha", 1:m),
                   paste0("delta", 1:m), paste0("tau", 1:m, "_1")))
    expect_length(attr(mcmc_chain, "proposal_sds"), 4)
    expect_length(attr(mcmc_chain, "proposal_sds")[[1]], n)
    expect_length(attr(mcmc_chain, "proposal_sds")[[2]], m)
    expect_length(attr(mcmc_chain, "proposal_sds")[[3]], m)
    expect_length(attr(mcmc_chain, "proposal_sds")[[4]], m)
})

test_that("ggumMC3() produces expected output", {
    expect_s3_class(mc3_chain, "ggum")
    expect_s3_class(mc3_chain, "mcmc")
    expect_equal(colnames(mc3_chain),
                 c(paste0("theta", 1:n), paste0("alpha", 1:m),
                   paste0("delta", 1:m), paste0("tau", 1:m, "_1")))
    expect_length(attr(mc3_chain, "proposal_sds"), 4)
    expect_length(attr(mc3_chain, "proposal_sds")[[1]], n)
    expect_length(attr(mc3_chain, "proposal_sds")[[2]], m)
    expect_length(attr(mc3_chain, "proposal_sds")[[3]], m)
    expect_length(attr(mc3_chain, "proposal_sds")[[4]], m)
    expect_length(attr(mc3_chain, "temps"), 2)
    expect_error(ggumMC3(response_matrix, n_temps = 1, sd_tune_iterations = 0),
                 "Please provide a vector of temperatures")
})

test_that("post_process() produces expected output", {
    expect_error(post_process(1, 1, "-"),
                 "Provide output from ggumMCMC\\(\\) or ggumMC3\\(\\) as sample")
    expect_error(post_process(mc3_chain, 1, "x"),
                 "Provide \\+ or - as expected_sign.")
    expect_s3_class(processed_chain, "ggum")
    expect_s3_class(processed_chain, "mcmc")
    expect_length(processed_chain, length(mc3_chain))
    processed_aic_draws <- processed_chain[ , which.min(ggum_sim$theta)]
    unprocessed_aic_draws <- mc3_chain[ , which.min(ggum_sim$theta)]
    idx <- which(unprocessed_aic_draws > 0)
    expect_equal(processed_aic_draws[idx], -unprocessed_aic_draws[idx])
})

test_that("summarize_matrix() produces expected output", {
    set.seed(123)
    mat <- matrix(rnorm(300), ncol = 3)
    qs1 <- t(apply(mat, 2, function(x) {
        q <- function(x, p) quantile(x, p, type = 8)
        return(c(q(x, 0.025), median(x), mean(x), q(x, 0.975), sd(x)))
    }))
    qs2 <- summarize_matrix(mat)
    dimnames(qs1) <- NULL
    expect_equal(qs1, qs2)
})

test_that("summary.ggum() produces expected output", {
    expect_s3_class(mcmc_summary, "summary.ggum")
    expect_named(mcmc_summary, c("estimates", "sds", "statistics"))
    expect_named(mcmc_summary$estimates, c("theta", "alpha", "delta", "tau"))
    expect_named(mcmc_summary$estimates$theta, paste0("theta", 1:n))
    expect_named(mcmc_summary$estimates$alpha, paste0("alpha", 1:m))
    expect_named(mcmc_summary$estimates$delta, paste0("delta", 1:m))
    expect_named(mcmc_summary$estimates$tau, paste0("tau", 1:m))
    expect_named(mcmc_summary$sds, paste0(c("theta", "alpha", "delta", "tau"), "_sds"))
    expect_named(mcmc_summary$sds$theta_sds, paste0("theta", 1:n))
    expect_named(mcmc_summary$sds$alpha_sds, paste0("alpha", 1:m))
    expect_named(mcmc_summary$sds$delta_sds, paste0("delta", 1:m))
    expect_named(mcmc_summary$sds$tau_sds, paste0("tau", 1:m))
    expect_equal(rownames(mcmc_summary$statistics),
                 c(paste0("theta", 1:n), paste0("alpha", 1:m),
                   paste0("delta", 1:m), paste0("tau", 1:m, "_1")))
    expect_equal(colnames(mcmc_summary$statistics),
                 c("Quantile 0.025", "Median", "Mean", "Quantile 0.975",
                   "Posterior SD"))
    expect_error(summary.ggum(1), "Please provide an object returned")
})

test_that("summary.list() produces expected output", {
    expect_s3_class(list_summary, "summary.ggum")
    expect_named(list_summary, c("estimates", "sds", "statistics"))
    expect_named(list_summary$estimates, c("theta", "alpha", "delta", "tau"))
    expect_named(list_summary$estimates$theta, paste0("theta", 1:n))
    expect_named(list_summary$estimates$alpha, paste0("alpha", 1:m))
    expect_named(list_summary$estimates$delta, paste0("delta", 1:m))
    expect_named(list_summary$estimates$tau, paste0("tau", 1:m))
    expect_named(list_summary$sds, paste0(c("theta", "alpha", "delta", "tau"), "_sds"))
    expect_named(list_summary$sds$theta_sds, paste0("theta", 1:n))
    expect_named(list_summary$sds$alpha_sds, paste0("alpha", 1:m))
    expect_named(list_summary$sds$delta_sds, paste0("delta", 1:m))
    expect_named(list_summary$sds$tau_sds, paste0("tau", 1:m))
    expect_equal(rownames(list_summary$statistics),
                 c(paste0("theta", 1:n), paste0("alpha", 1:m),
                   paste0("delta", 1:m), paste0("tau", 1:m, "_1")))
    expect_equal(colnames(list_summary$statistics),
                 c("Quantile 0.025", "Median", "Mean", "Quantile 0.975",
                   "Posterior SD"))
    expect_length(list_summary2, 2)
    expect_s3_class(list_summary2[[1]], "summary.ggum")
    expect_s3_class(list_summary2[[1]], "summary.ggum")
    expect_s3_class(list_summary3, "summaryDefault")
})
