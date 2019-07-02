#include <media/rc-map.h>
#include <linux/module.h>

static struct rc_map_table hceng_nec[] = {
    { 0x45, KEY_CHANNELDOWN},
    { 0x46, KEY_CHANNEL},
    { 0x47, KEY_CHANNELUP},
    { 0x44, KEY_PREVIOUS},
    { 0x40, KEY_NEXT},
    { 0x43, KEY_PLAYPAUSE}, //
    { 0x07, KEY_VOLUMEDOWN},
    { 0x15, KEY_VOLUMEUP},
    { 0x09, KEY_EQUAL},
    
    { 0x16, KEY_0},
    { 0x19, KEY_F1},
    { 0x0d, KEY_F2},
    
    { 0x0c, KEY_1},
    { 0x18, KEY_2},
    { 0x5e, KEY_3},
    { 0x08, KEY_4},
    { 0x1c, KEY_5},
    { 0x5a, KEY_6},
    { 0x42, KEY_7},
    { 0x52, KEY_8}, //
    { 0x4a, KEY_9},
};

static struct rc_map_list nec_100ask_map = {
    .map = {
        .scan    = hceng_nec,
        .size    = ARRAY_SIZE(hceng_nec),
        .rc_type = RC_TYPE_NEC, //RC_TYPE_UNKNOWN //echo nec > /sys/class/rc/rc0/protocols
        .name    = "rc-100ask-nec",
    }
};

static int __init init_rc_map_100ask_nec(void)
{
    return rc_map_register(&nec_100ask_map);
}

static void __exit exit_rc_map_100ask_nec(void)
{
    rc_map_unregister(&nec_100ask_map);
}

module_init(init_rc_map_100ask_nec)
module_exit(exit_rc_map_100ask_nec)

MODULE_LICENSE("GPL");
MODULE_AUTHOR("www.100ask.org");
