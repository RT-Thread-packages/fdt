/*
 * Copyright (c) 2006-2022, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include "dtb_node.h"
#include "dtb_head.h"

#define FDT_DEFAULT_PATH "fdt/examples/bsta1000-evb.dtb"
static void *fdt = NULL;
static struct dtb_node *dtb_node_list = NULL;
void *get_fdt_blob(void)
{
    return fdt;
}

struct dtb_node *get_dtb_node_head(void)
{
    return dtb_node_list;
}

bool dtb_node_active(void)
{
    return dtb_node_list != NULL;
}

int device_tree_setup(void *mem_addr)
{
    if(mem_addr)
    {
        if ((fdt = dtb_node_load_from_memory(mem_addr,1)) != NULL)
        {
            dtb_node_list = dtb_node_get_dtb_list(fdt);
            if (dtb_node_list != NULL)
            {
                return -1;
            }
        }
        return 0;
    }

    return -1;
}