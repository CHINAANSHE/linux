#ifndef __JZ4770_PLATFORM_H__
#define __JZ4770_PLATFORM_H__

#include <linux/platform_device.h>

extern struct platform_device jz_i2c0_device;
extern struct platform_device jz_i2c1_device;
extern struct platform_device jz_i2c2_device;
extern struct platform_device jz_lcd_device;
extern struct platform_device jz_adc_device;

/* Platform calling board. */
extern void __init board_msc_init(void);
extern void __init board_i2c_init(void);
extern void __init board_pdata_init(void);
extern void __init board_devices_init(void);

/* Board calling platform. */
struct jz_mmc_platform_data;
extern int __init jz_add_msc_devices(unsigned int controller,
				     struct jz_mmc_platform_data *plat);

#endif /* __JZ4770_PLATFORM_H__ */
