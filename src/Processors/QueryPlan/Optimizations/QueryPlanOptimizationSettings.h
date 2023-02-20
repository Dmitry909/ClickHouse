#pragma once

#include <Interpreters/Context_fwd.h>

#include <cstddef>

namespace DB
{

struct Settings;

struct QueryPlanOptimizationSettings
{
    /// If not zero, throw if too many optimizations were applied to query plan.
    /// It helps to avoid infinite optimization loop.
    size_t max_optimizations_to_apply = 0;

    /// If disabled, no optimization applied.
    bool optimize_plan = true;

    /// If filter push down optimization is enabled.
    bool filter_push_down = true;

    /// if distinct in order optimization is enabled
    bool distinct_in_order = false;

    /// If read-in-order optimisation is enabled
    bool read_in_order = true;

    /// If aggregation-in-order optimisation is enabled
    bool aggregation_in_order = false;

    /// Optimize full_sorting_merge if it is possible
    bool join_in_order = true;

    /// If removing redundant sorting is enabled, for example, ORDER BY clauses in subqueries
    bool remove_redundant_sorting = true;

    bool aggregate_partitions_independently = false;

    /// If removing redundant distinct steps is enabled
    bool remove_redundant_distinct = true;

    /// Insert filtering step before sorting for full_sorting_merge JOIN with specified set size.
    size_t max_rows_in_set_to_optimize_join = 0;

    static QueryPlanOptimizationSettings fromSettings(const Settings & from);
    static QueryPlanOptimizationSettings fromContext(ContextPtr from);
};

}
