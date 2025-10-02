# Changelog

## Version 1.1

### Updated driver
- Updated I/O driver

### Updated command
- Updated "help" command:
1. It now automatically searches for available commands (specified in the command file), rather than those specified in help.c
2. Added descriptions to commands (specified in the file with the command function)

### Added new commands
- Added "poweroff" command for shutting down the virtual machine
- Added "reboot" command for rebooting the virtual machine

### Updated information output
- Kernel:
1. Now has colored output
2. Added a success log
- Driver startup file:
1. Added a log about the start of initialization
2. Added a log about the successful start of the driver and at the end about successful execution
- Plugin startup file:
1. Added a log about the start of initialization
2. Added a log about the successful start of plugins and at the end Successful completion

### Bootloader and project build
- The GRUB configuration file is now located in boot/grub/grub.cfg, rather than being created by a Makefile
