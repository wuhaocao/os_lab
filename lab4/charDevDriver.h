#ifndef charDevDriver_H
#define charDevDriver_H

#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <asm/uaccess.h>

#define DEVICE_NAME "charMsgDriver"
#define CLASS_NAME "charMsg"
#define MSG_COUNT 1024

static int majorNumber;
static char msg[MSG_COUNT] = {0};
static short size_of_msg;
static int DeviceOpenNumbers = 0;
static struct class *pcharMsgDriverClass = NULL;
static struct device *pCharMsgDriverDevice = NULL;

#endif
