/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef _RT_DTB_HEAD_H
#define _RT_DTB_HEAD_H
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void *get_fdt_blob(void);
struct dtb_node *get_dtb_node_head(void);
bool dtb_node_active(void);
int device_tree_setup(void *mem_addr);
#endif