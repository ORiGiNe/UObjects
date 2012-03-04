CC = g++
INCLUDES = -I $${URBI_ROOT}/include -I ../userspace-usb-serie/commun
CFLAGS = -shared -fPIC
TARGET = ULib.so
SOURCES = \
	../userspace-usb-serie/commun/Peripherique.cpp \
	../userspace-usb-serie/commun/Commande.cpp \
	../userspace-usb-serie/pc/GaopProtocol.cpp \
	UGaop.cpp \
	../userspace-usb-serie/pc/Led.cpp \
        ULed.cpp

default: target

target: $(SOURCES)
	$(CC) $(INCLUDES) $(CFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	urbi-launch --start $(TARGET) -- main.u

interactive: $(TARGET)
	urbi-launch --start $(TARGET) -- --interactive

clean:
	rm $(TARGET)
