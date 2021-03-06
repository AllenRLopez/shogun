/*
 * This software is distributed under BSD 3-clause license (see LICENSE file).
 *
 * Authors: Viktor Gal
 */

#include <benchmark/benchmark.h>

#include "shogun/mathematics/linalg/LinalgNamespace.h"

namespace shogun
{

template<typename T>
void BM_LinAlg_SGVector_scale(benchmark::State& state)
{
	for (auto _ : state)
	{
		SGVector<T> v(state.range(0));
		linalg::scale(v, T(12.3));
	}
}

template<typename T>
void BM_SGVector_scale(benchmark::State& state)
{
	for (auto _ : state)
	{
		SGVector<T> v(state.range(0));
		v.scale(T(12.3));
	}
}

BENCHMARK_TEMPLATE(BM_LinAlg_SGVector_scale, int32_t)->Range(8, 8<<10);
BENCHMARK_TEMPLATE(BM_LinAlg_SGVector_scale, int64_t)->Range(8, 8<<10);
BENCHMARK_TEMPLATE(BM_LinAlg_SGVector_scale, float32_t)->Range(8, 8<<10);
BENCHMARK_TEMPLATE(BM_LinAlg_SGVector_scale, float64_t)->Range(8, 8<<10);

BENCHMARK_TEMPLATE(BM_SGVector_scale, int32_t)->Range(8, 8<<10);
BENCHMARK_TEMPLATE(BM_SGVector_scale, int64_t)->Range(8, 8<<10);
BENCHMARK_TEMPLATE(BM_SGVector_scale, float32_t)->Range(8, 8<<10);
BENCHMARK_TEMPLATE(BM_SGVector_scale, float64_t)->Range(8, 8<<10);

}
