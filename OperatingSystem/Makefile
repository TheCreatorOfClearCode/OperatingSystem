TARGET = kernel.bin
ISO = OperatingSystem.iso
CC = gcc
CFLAGS = -m32 -ffreestanding -nostdlib -fno-builtin -fno-stack-protector -Wall -Wextra
ASM = nasm

OBJS = \
	boot/boot.o \
	kernel/kernel.o \
	kernel/drivers/VGA/vga.o \
	kernel/drivers/keyboard/keyboard.o \
	kernel/init/start_drivers/start_drivers.o \
    kernel/init/start_commands/start_commands.o \
    kernel/init/configs/drivers_config/drivers_config.o \
    kernel/init/configs/commands_config/commands_config.o \
	shell/shell/shell.o \
	shell/commands_execute/commands_execute.o \
	commands/about.o \
	commands/help.o  \
	commands/clear.o \
	libraries/string/string.o 

all: $(ISO)

boot/boot.o: boot/boot.s
	$(ASM) -f elf32 $< -o $@

kernel/%.o: kernel/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	ld -m elf_i386 -T linker.ld $^ -o $(TARGET)

$(ISO): $(TARGET)
	mkdir -p iso/boot/grub
	cp $(TARGET) iso/boot/kernel.bin
	echo 'set timeout=10' > iso/boot/grub/grub.cfg
	echo 'set default=0' >> iso/boot/grub/grub.cfg
	echo 'menuentry "Start OperatingSystem by TheCreatorOfClearCode" {' >> iso/boot/grub/grub.cfg
	echo '  echo "Starting OperatingSystem..."' >> iso/boot/grub/grub.cfg
	echo '  echo "Loading kernel..."' >> iso/boot/grub/grub.cfg
	echo '  multiboot /boot/kernel.bin' >> iso/boot/grub/grub.cfg
	echo '  echo "Booting..."' >> iso/boot/grub/grub.cfg
	echo '  boot' >> iso/boot/grub/grub.cfg
	echo '}' >> iso/boot/grub/grub.cfg
	grub-mkrescue -o $(ISO) iso -d /usr/lib/grub/i386-pc

clean:
	rm -f $(OBJS) $(TARGET) $(ISO)
	rm -rf iso