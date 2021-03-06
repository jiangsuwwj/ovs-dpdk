/*
 * Copyright (c) 2019 Mellanox Technologies, Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef NETDEV_OFFLOAD_DPDK_PRIVATE_H
#define NETDEV_OFFLOAD_DPDK_PRIVATE_H

#include "openvswitch/match.h"

#include <rte_flow.h>

struct netdev;

struct flow_actions {
    struct rte_flow_action *actions;
    int cnt;
    int current_max;
};

int
netdev_dpdk_flow_patterns_add(struct rte_flow_item **patterns,
                              const struct match *match,
                              struct offload_info *info);
void
netdev_dpdk_flow_actions_free(struct flow_actions *actions);
void
netdev_dpdk_flow_actions_add_mark_rss(struct flow_actions *actions,
                                      struct netdev *netdev,
                                      uint32_t mark_id);
int
netdev_dpdk_flow_actions_add(struct flow_actions *actions,
                             const struct match *m,
                             struct nlattr *nl_actions,
                             size_t nl_actions_len,
                             struct offload_info *info);
struct ds *
netdev_dpdk_flow_ds_put_flow(struct ds *s,
                             const struct rte_flow_attr *attr,
                             const struct rte_flow_item *items,
                             const struct rte_flow_action *actions);

#endif /* NETDEV_OFFLOAD_DPDK_PRIVATE_H */
