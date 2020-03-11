//
// Created by Troldal on 17/01/2020.
//

#include <random>
#include <vector>
#include <execution>
#include <benchmark/benchmark.h>
#include <troldalgo.hpp>

static void bench_find(benchmark::State& state) {
    std::random_device                 device;
    std::mt19937                       generator(device());
    std::uniform_int_distribution<int> distribution(0, 8);

    std::vector<int>   numbers;
    for (unsigned long i = 0; i < 1000000; ++i)
        numbers.emplace_back(distribution(generator));
    numbers.emplace_back(9);

    std::vector<decltype(numbers.begin())> results;

    for (auto _ : state) {
        std::find(std::execution::par, numbers.begin(), numbers.end(), 9);
    }
}
// Register the function as a benchmark
BENCHMARK(bench_find);

static void bench_find_all(benchmark::State& state) {
    std::random_device                 device;
    std::mt19937                       generator(device());
    std::uniform_int_distribution<int> distribution(0, 9);

    std::vector<int>   numbers;
    for (unsigned long i = 0; i < 1000000; ++i)
        numbers.emplace_back(distribution(generator));

    std::vector<decltype(numbers.begin())> results;

    for (auto _ : state) {
        trl::find_all(std::execution::par, numbers.begin(), numbers.end(), std::back_inserter(results), 1);
    }
}
// Register the function as a benchmark
BENCHMARK(bench_find_all);

BENCHMARK_MAIN();