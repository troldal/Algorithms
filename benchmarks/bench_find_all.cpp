//
// Created by Troldal on 17/01/2020.
//

#include <random>
#include <vector>
#include <execution>
#include <benchmark/benchmark.h>
#include <troldalgo.hpp>

// ========================================================================= //

template<typename Policy>
static void bench_find(benchmark::State& state,
                       Policy execution_policy) {
    std::random_device                 device;
    std::mt19937                       generator(device());
    std::uniform_int_distribution<int> distribution(0, 8);

    std::vector<int>   numbers;
    for (unsigned long i = 0; i < 10000000; ++i)
        numbers.emplace_back(distribution(generator));
    numbers.emplace_back(9);

    std::vector<decltype(numbers.begin())> results;

    for (auto _ : state) {
        std::find(execution_policy, numbers.begin(), numbers.end(), 9);
    }
}

BENCHMARK_CAPTURE(bench_find, std_seq, std::execution::seq);
BENCHMARK_CAPTURE(bench_find, std_par, std::execution::par);


// ========================================================================= //

static void bench_find_all(benchmark::State& state) {
    std::random_device                 device;
    std::mt19937                       generator(device());
    std::uniform_int_distribution<int> distribution(0, 9);

    std::vector<int>   numbers;
    for (unsigned long i = 0; i < 10000000; ++i)
        numbers.emplace_back(distribution(generator));

    std::vector<decltype(numbers.begin())> results;

    for (auto _ : state) {
        trl::find_all(numbers.begin(), numbers.end(), std::back_inserter(results), 1);
    }
}

BENCHMARK(bench_find_all);

// ========================================================================= //

template<typename Policy>
static void bench_find_all_par(benchmark::State& state,
                               Policy execution_policy) {
    std::random_device                 device;
    std::mt19937                       generator(device());
    std::uniform_int_distribution<int> distribution(0, 9);

    std::vector<int>   numbers;
    for (unsigned long i = 0; i < 10000000; ++i)
        numbers.emplace_back(distribution(generator));

    std::vector<decltype(numbers.begin())> results;

    for (auto _ : state) {
        trl::find_all(execution_policy, numbers.begin(), numbers.end(), std::back_inserter(results), 1);
    }
}

BENCHMARK_CAPTURE(bench_find_all_par, std_seq, std::execution::seq);
BENCHMARK_CAPTURE(bench_find_all_par, std_par, std::execution::par);

BENCHMARK_MAIN();