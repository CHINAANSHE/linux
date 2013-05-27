/*
 *  linux/drivers/mmc/host/jz_mmc/jz_mmc_host.h
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Copyright (c) Ingenic Semiconductor Co., Ltd.
 */

#ifndef __JZ_MMC_HOST_H__
#define __JZ_MMC_HOST_H__

#include <linux/semaphore.h>

#include <asm/mach-jz4770/dma.h>


#define USE_DMA_DESC
//#define USE_DMA_UNCACHE
//#define MSC_DEBUG_DMA

#define JZ_MSC_DMA_DESC jz_dma_desc_8word
#define USE_DMA_BUSRT_64

#define MMC_CLOCK_SLOW    400000      /* 400 kHz for initial setup */
#define MMC_CLOCK_FAST  20000000      /* 20 MHz for maximum for normal operation */
#define SD_CLOCK_HIGH   48000000      /* 24 MHz for SD Cards */
#define SD_CLOCK_FAST   24000000      /* 24 MHz for SD Cards */
#define MMC_NO_ERROR  0

#define MSC_1BIT_BUS 0
#define MSC_4BIT_BUS 1
#define MSC_8BIT_BUS 2

#define SZ_4K                           0x00001000


struct clk;

struct jz_mmc_host {
	struct mmc_host *mmc;
	// TODO(MtH): If it is a semaphore, name it as such.
	//            This naming confusion used to exist all over the kernel
	//            but has already been cleaned up in mainline.
	struct semaphore mutex;

	struct clk *clk;

	/* host resources */
	void __iomem *base;
	unsigned int pdev_id;
	int irq;
	int dma_id;
	struct jz_mmc_platform_data *pdata;

	/* mmc request related */
	unsigned int cmdat;
	struct mmc_request *curr_mrq;
	int curr_res_type;

	/* data transter related */
	struct {
		int len;
		int dir;
		int channel;
	} dma;
#ifdef USE_DMA_DESC
#ifdef MSC_DEBUG_DMA
	int num_desc;
	int last_direction;
#endif
	JZ_MSC_DMA_DESC *dma_desc;
#endif
	wait_queue_head_t data_wait_queue;
	volatile int data_ack;
	volatile int data_err;

	/* card detect related */
	int card_detect_irq;

	/* labels for gpio pins */
	char *label_card_detect;
	char *label_read_only;
	char *label_power;
};

void jz_mmc_finish_request(struct jz_mmc_host *host, struct mmc_request *mrq);

#endif /* __JZ_MMC_HOST_H__ */
